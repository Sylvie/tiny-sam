#include "TinySamIntegrationTestUtils.h"

#include <fstream>
#include <sstream>

std::string TinySamIntegrationTestUtils::computePlatformSpecificProgramName(const std::string &baseProgramName) {
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

std::string TinySamIntegrationTestUtils::getTopSourceDirectory()
{
    std::string topSourceDirectory="..";
#ifdef tiny_sam_top_source_dir
    topSourceDirectory = tiny_sam_top_source_dir;
#endif
    topSourceDirectory += "/";
    return topSourceDirectory;
}

TinySamRegressionResults TinySamIntegrationTestUtils::readRegressionResults(std::ifstream& lecteur, bool hasHeader, int dimension)
{
    TinySamRegressionResults results;

    if (hasHeader)
    {
        std::string header("");
        getline(lecteur, header);

        std::istringstream iss(header);
        std::string lu;
        while (iss >> lu >> std::ws)
        {
            results.header.push_back(lu);
        }

        lecteur >> std::ws;
    }
    lecteur >> std::ws;

    while (!lecteur.eof())
    {
        std::vector<std::string> ligne(0);
        for (int i(0); i <= dimension; ++i)
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
        std::istringstream iss(concatenatedValues);
        long double value;
        while (iss >> value >> std::ws)
        {
            values.push_back(value);
        }
        results.valeurs.push_back(values);

        lecteur >> std::ws;
    }

    return results;
}
