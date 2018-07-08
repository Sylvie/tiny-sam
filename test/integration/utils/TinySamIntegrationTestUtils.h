#ifndef TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H
#define TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H

#include "TinySamRegressionResults.h"
#include <string>

class TinySamIntegrationTestUtils {
public:
    static std::string computePlatformSpecificProgramName(const std::string &baseProgramName);
    static std::string runCommand(const std::string &commandLine);
    static std::string getTopSourceDirectory();
    static TinySamRegressionResults readRegressionResults(std::ifstream& lecteur, bool hasHeader, int dimension);
};

#endif //TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H
