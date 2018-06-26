#ifndef TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H
#define TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H

#include <string>

class TinySamIntegrationTestUtils {
public:
    static std::string computePlatformSpecificProgramName(const std::string &baseProgramName);
    static std::string runCommand(const std::string &commandLine);
};

#endif //TINY_SAM_TINYSAMINTEGRATIONTESTUTILS_H
