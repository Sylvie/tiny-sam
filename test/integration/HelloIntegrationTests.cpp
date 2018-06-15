#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>

std::string runCommand(std::string cmd) {

    std::string data;
    FILE *stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    return data;
}


SCENARIO("Tests can run external programs", "[run_program]") {

    //std::cout << "Starting there: " + runCommand("pwd") << std::endl;

    GIVEN("A program to run and its expected output file") {
        std::string program("./src/hello");
        std::string fileName("hello.txt");

        WHEN("we look for the program") {
            std::cout << "Here we are: " + runCommand("pwd") << std::endl;

            std::ifstream programFile(program.c_str());

            THEN("the program is found") {
                REQUIRE(programFile.good());
                REQUIRE(programFile.is_open());
            }
        }

        WHEN("the program is run") {
            runCommand(program);

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
            std::remove(fileName.c_str());

        }


    }
}
