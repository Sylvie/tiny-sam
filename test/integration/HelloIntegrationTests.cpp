#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <stdlib.h>

void runCommand(const std::string& path, const std::string& program, const std::string& arguments) {

   // char szPath[] = *cmd[0];
    std::string programWithPath(path + program);

    std::string command(path + program + arguments);

    char pathCString[path.size() + 1];
    path.copy(pathCString, path.size());
    pathCString[path.size()] = '\0';

    char commandCString[command.size() + 1];
    command.copy(commandCString, command.size());
    commandCString[command.size()] = '\0';

    // Gives info on the thread and process for the new process
    PROCESS_INFORMATION pif;

    // Defines how to start the program
    STARTUPINFO si;

    // Zero the STARTUPINFO struct
    ZeroMemory( &si, sizeof( si ) );

    // Must set size of structure
    si.cb = sizeof( si );

    BOOL bRet = CreateProcess( programWithPath.c_str(), // Path to executable file
                               commandCString,   // Command string - not needed here
                               NULL,   // Process handle not inherited
                               NULL,   // Thread handle not inherited
                               FALSE,  // No inheritance of handles
                               0,      // No special flags
                               NULL,   // Same environment block as this prog
                               path.c_str(),   // Current directory - no separate path
                               &si,    // Pointer to STARTUPINFO
                               &pif ); // Pointer to PROCESS_INFORMATION

    if( FALSE == bRet )
    {
        MessageBox( HWND_DESKTOP, "Unable to start program", "", MB_OK );
        //return "";
    }

    // Close handle to process
    CloseHandle( pif.hProcess );

    // Close handle to thread
    CloseHandle( pif.hThread );

    //return "";
}

#else
void runCommand(const std::string& path, const std::string& program, const std::string& arguments) {

    string command(path + program + arguments);

    std::string data;
    FILE *stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    command.append(" 2>&1");

    stream = popen(command.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
   // return data;
}
#endif

std::string computePlatformSpecificProgramName(const std::string &baseProgramName) {
    std::string programName(baseProgramName);
    std::string programExtension("");
#ifdef tiny_sam_executable_extension
    programExtension = tiny_sam_executable_extension;
#endif
    if (programExtension.size() > 0)
    {
        programName += programExtension;
    }
    return programName;
}

SCENARIO("Tests can run external programs", "[run_program]") {

    std::cout << "Starting there: ";
    runCommand("", "pwd", "");
    std::cout << std::endl;
    std::cout << "Variable: " << tiny_sam_executable_extension << std::endl;

    GIVEN("A program to run and its expected output file") {
        std::string path("./src/");
        std::string program(computePlatformSpecificProgramName("hello"));

        std::string fileName("./src/hello.txt");

        WHEN("we look for the program") {
            std::cout << "Here we are: ";
            runCommand("", "pwd", "");
            std::cout << std::endl;

            std::ifstream programFile((path+program).c_str());

            THEN("the program is found") {
                REQUIRE(programFile.good());
                REQUIRE(programFile.is_open());
            }
        }

        WHEN("the program is run") {
            runCommand(path, program, "");

            std::ifstream lecteur(fileName.c_str());

            THEN("the output file is found") {
                REQUIRE(lecteur.good());
                REQUIRE(lecteur.is_open());
            }

            AND_WHEN("the file is read") {
                std::string readValue("");
                std::getline(lecteur, readValue);

                THEN("the output file contains the expected text") {
                    REQUIRE(readValue == "Hello World !");
                }
            }

            std::cout << "This line was executed!" << std::endl;
            lecteur.close();
           // std::remove(fileName.c_str());

        }


    }
}
