#include "catch.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "utils/TinySamIntegrationTestUtils.h"

class TinySamRegressionResults {
public:
    bool hasHeader;
    int nbModels;
    int dimension;
    std::vector< std::string> header;
    std::vector< std::vector< std::string> > etiquettes;
    std::vector< std::vector< long double > > valeurs;
};

TinySamRegressionResults readModels(std::ifstream& lecteur, bool hasHeader, int dimension)
{
    TinySamRegressionResults results;
    results.hasHeader = hasHeader;
    results.dimension = dimension;

    if (results.hasHeader)
    {
        std::string header("");
        getline(lecteur, header);

        std::istringstream iss( header );
        std::string lu;
        while( iss >> lu >> std::ws ) {
            results.header.push_back(lu);
        }

        lecteur >> std::ws;
    }
    lecteur >> std::ws;

    while (!lecteur.eof())
    {
        std::vector<std::string> ligne(0);
        for (int i(0); i<=results.dimension; ++i )
        {
            std::string lu("");
            lecteur >> lu >> std::ws;
            ligne.push_back(lu);
            if (lecteur.eof())
            {
                break;
            }
        }
        results.etiquettes.push_back(ligne);

        if (lecteur.eof())
        {
            break;
        }

        std::string concatenatedValues("");
        getline(lecteur, concatenatedValues);

        std::vector<long double> values(0);
        std::istringstream iss( concatenatedValues );
        long double value;
        while( iss >> value >> std::ws ) {
            values.push_back(value);
        }
        results.valeurs.push_back(values);

        lecteur >> std::ws;
    }

    return results;
}

SCENARIO("Tests can read and verify models from files", "[read_models]") {

    std::cout << "Starting there: " << TinySamIntegrationTestUtils::runCommand("pwd") << std::endl;

    GIVEN("A program to run and its expected output file") {
        std::string program(TinySamIntegrationTestUtils::computePlatformSpecificProgramName("./src/writeModels"));

        std::string fileName("cattle-mark-Out-1.txt");

        WHEN("we look for the program") {
            std::ifstream programFile(program.c_str());

            THEN("the program is found") {
                REQUIRE(programFile.good());
                REQUIRE(programFile.is_open());
            }
        }

        WHEN("the program is run") {
            TinySamIntegrationTestUtils::runCommand(program);

            std::ifstream lecteur(fileName.c_str());

            THEN("the output file is found") {
                REQUIRE(lecteur.good());
                REQUIRE(lecteur.is_open());
            }

            AND_WHEN("the file is read") {
                TinySamRegressionResults results(readModels(lecteur, true, 1));

                //std::cout << "Header: " << results.header << endl;

                //std::cout << "Etiquettes: " << results.etiquettes[0]

                THEN("the output file contains the expected text") {
                    REQUIRE(results.etiquettes.size() == 9);
                }
            }

            std::cout << "This line was executed!" << std::endl;
            lecteur.close();
            //std::remove(fileName.c_str());

        }


    }
}

