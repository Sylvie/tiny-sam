#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "utils/TinySamIntegrationTestUtils.h"

SCENARIO("Tests can run external programs", "[run_program][hide]") {

    std::cout << "Starting there: " << TinySamIntegrationTestUtils::runCommand("pwd") << std::endl;
    std::cout << "Variable: " << tiny_sam_executable_extension << std::endl;

    GIVEN("A program to run and its expected output file") {
        std::string program(TinySamIntegrationTestUtils::computePlatformSpecificProgramName("./src/hello"));

        std::string fileName("hello.txt");

        WHEN("we look for the program") {
            std::cout << "Here we are: " << TinySamIntegrationTestUtils::runCommand("pwd") << std::endl;

            std::ifstream programFile(program.c_str());

            THEN("the program is found") {
                REQUIRE(programFile.is_open());
//                REQUIRE(programFile.good());
            }

            programFile.close();
        }

        WHEN("the program is run") {
            TinySamIntegrationTestUtils::runCommand(program);

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

