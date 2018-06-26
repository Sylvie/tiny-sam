#include "TinySamIntegrationTestUtils.h"

#if defined(_UNIX)

std::string TinySamIntegrationTestUtils::runCommand(const std::string& command) {

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
    return data;
}

#endif