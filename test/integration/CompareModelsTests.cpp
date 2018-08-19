#include "catch.hpp"
#include "TinySamRegressionResults.h"
#include "TinySamIntegrationTestUtils.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

SCENARIO("Tests can read and verify models from files", "[read_models]") {

    GIVEN("A program to run, its expected output file, and the file of expected results")
    {
        std::string program(TinySamIntegrationTestUtils::computePlatformSpecificProgramName("./src/writeModels"));

        std::string fileName("cattle-mark-Out-1.txt");

        std::string fileNameExpectedResults(TinySamIntegrationTestUtils::getTopSourceDirectory() + "test/integration/expected-cattle-mark-Out-1.txt");

        std::ifstream lecteurCorrige(fileNameExpectedResults.c_str());
        REQUIRE(lecteurCorrige.good());
        REQUIRE(lecteurCorrige.is_open());
        TinySamRegressionResults expectedResults(TinySamIntegrationTestUtils::readRegressionResults(lecteurCorrige, true, 1));
        expectedResults.verifieTailles(true, 1 ,9);

        WHEN("the program is run")
        {
            TinySamIntegrationTestUtils::runCommand(program);

            std::ifstream lecteur(fileName.c_str());

            THEN("the output file is found")
            {
                REQUIRE(lecteur.good());
                REQUIRE(lecteur.is_open());
            }

            AND_WHEN("the file is read")
            {
                TinySamRegressionResults results(TinySamIntegrationTestUtils::readRegressionResults(lecteur, true, 1));

                THEN("the results have the expected size")
                {
                    results.verifieTailles(true, 1, 9);
                }

                AND_THEN("the results match the expectation")
                {
                    results.compare(expectedResults);
                }
            }

            lecteur.close();
            std::remove(fileName.c_str());
        }
    }
}

