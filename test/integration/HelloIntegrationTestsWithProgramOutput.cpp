#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <stdlib.h>
#include "strsafe.h"

#define BUFSIZE 4096

HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;

void CreateChildProcess(TCHAR szCmdline[]);
void ReadFromPipe(void);

void runCommandWithOutput(const std::string& command) {

    char commandCString[command.size() + 1];
    command.copy(commandCString, command.size());
    commandCString[command.size()] = '\0';



    SECURITY_ATTRIBUTES saAttr;

    printf("\n->Start of parent execution.\n");

// Set the bInheritHandle flag so pipe handles are inherited.

    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

// Create a pipe for the child process's STDOUT.

    if ( ! CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0) )
    {
        printf("CreatePipe: %u\n", GetLastError());
        return;    }

// Ensure the read handle to the pipe for STDOUT is not inherited.

    if ( ! SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0) )
    {
        printf("SetHandleInformation: %u\n", GetLastError());
        return;
    }

// Create the child process.

    CreateChildProcess(commandCString );

    CloseHandle(g_hChildStd_OUT_Wr);



    // Read from pipe that is the standard output for child process.

    printf( "\n->Contents of child process STDOUT:\n\n");
    ReadFromPipe();

    printf("\n->End of parent execution.\n");

    // The remaining open handles are cleaned up when this process terminates.
    // To avoid resource leaks in a larger application, close handles explicitly.


    CloseHandle(g_hChildStd_OUT_Rd);


    //return "";
}

void CreateChildProcess(TCHAR szCmdline[])
// Create a child process that uses the previously created pipes for STDIN and STDOUT.
{
    PROCESS_INFORMATION piProcInfo;
    STARTUPINFO siStartInfo;
    BOOL bSuccess = FALSE;

// Set up members of the PROCESS_INFORMATION structure.

    ZeroMemory( &piProcInfo, sizeof(PROCESS_INFORMATION) );

// Set up members of the STARTUPINFO structure.
// This structure specifies the STDIN and STDOUT handles for redirection.

    ZeroMemory( &siStartInfo, sizeof(STARTUPINFO) );
    siStartInfo.cb = sizeof(STARTUPINFO);
    siStartInfo.hStdError = g_hChildStd_OUT_Wr;
    siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

// Create the child process.

    bSuccess = CreateProcess(NULL,
                             szCmdline,     // command line
                             NULL,          // process security attributes
                             NULL,          // primary thread security attributes
                             TRUE,          // handles are inherited
                             0,             // creation flags
                             NULL,          // use parent's environment
                             NULL,          // use parent's current directory
                             &siStartInfo,  // STARTUPINFO pointer
                             &piProcInfo);  // receives PROCESS_INFORMATION


    // If an error occurs, exit the application.
    if ( ! bSuccess )
        {
            printf("CreateProcess: %u\n", GetLastError());
            return;
        }
    else
    {
        std::cout << "Waiting for the child to finish" << std::endl;
        //WaitForSingleObject( piProcInfo.hProcess, INFINITE );

        // Close handles to the child process and its primary thread.
        // Some applications might keep these handles to monitor the status
        // of the child process, for example.

        CloseHandle(piProcInfo.hProcess);
        CloseHandle(piProcInfo.hThread);
    }
}

void ReadFromPipe(void)

// Read output from the child process's pipe for STDOUT
// and write to the parent process's pipe for STDOUT.
// Stop when there is no more data.
{
    DWORD dwRead, dwWritten;
    CHAR chBuf[BUFSIZE];
    BOOL bSuccess = FALSE;
    HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    for (;;)
    {
        bSuccess = ReadFile( g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, NULL);
        if( ! bSuccess || dwRead == 0 ) break;

        bSuccess = WriteFile(hParentStdOut, chBuf,
                             dwRead, &dwWritten, NULL);
        if (! bSuccess ) break;
    }
}

#else
void runCommandWithOutput(const std::string& command) {

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
std::string computePlatformSpecificProgramName(const std::string &baseProgramName);
/*
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
*/
SCENARIO("Tests can run external programs and redirect standard output", "[run_program]") {

    std::cout << "Starting there: ";
    runCommandWithOutput("pwd");
    std::cout << std::endl;
    std::cout << "Variable: " << tiny_sam_executable_extension << std::endl;

    GIVEN("A program to run and its expected output file") {
        std::string program(computePlatformSpecificProgramName("./src/hello"));

        std::string fileName("hello.txt");

        WHEN("we look for the program") {
            std::cout << "Here we are: ";
            runCommandWithOutput("pwd");
            std::cout << std::endl;

            std::ifstream programFile(program.c_str());

            THEN("the program is found") {
                REQUIRE(programFile.good());
                REQUIRE(programFile.is_open());
            }
        }

        WHEN("the program is run") {
            runCommandWithOutput(program);

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
