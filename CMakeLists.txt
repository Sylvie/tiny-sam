cmake_minimum_required(VERSION 3.10)
project(tiny_sam)

set(CMAKE_CXX_STANDARD 11)

add_definitions(
        -Dtiny_sam_executable_extension="${CMAKE_EXECUTABLE_SUFFIX}"
        -Dtiny_sam_top_source_dir="${PROJECT_SOURCE_DIR}"
)

include_directories(src)
include_directories(test test/utils test/integration/utils)

add_executable(hello
        src/GreetingsProvider.cpp
        src/GreetingsProvider.hpp
        src/hello.cpp
        )

add_executable(writeModels
        src/writeModels.cpp)

set_target_properties(hello
        writeModels
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
        )

set(CATCH_SRCS
        test/utils/catch.hpp
        test/utils/main-catch.cpp
        )

set(TestUtils
        ${CATCH_SRCS}
        test/utils/TinySamRegressionResults.h
        test/utils/TinySamRegressionResults.cpp
        )

set(FactorialTests
        test/unit/factorial.cpp
        )

set(GreetingsProviderTests
        test/unit/GreetingsProviderTests.cpp
        src/GreetingsProvider.cpp
        src/GreetingsProvider.hpp
        )

add_executable(UnitTests
        ${FactorialTests}
        ${GreetingsProviderTests}
        ${CATCH_SRCS}
        )

set_target_properties(UnitTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/unit"
        )

set(IntegrationTestUtils
        test/integration/utils/TinySamIntegrationTestUtils.h
        test/integration/utils/TinySamIntegrationTestUtils.cpp
        )

if (WIN32)
    set(IntegrationTestUtils
            ${IntegrationTestUtils}
            test/integration/utils/TinySamIntegrationTestUtilsWindows.cpp
            )
else ()
    set(IntegrationTestUtils
            ${IntegrationTestUtils}
            test/integration/utils/TinySamIntegrationTestUtilsUnix.cpp
            )
endif (WIN32)

set(IntegrationTests
        test/integration/HelloIntegrationTests.cpp
        test/integration/WriteModelsTests.cpp
        test/integration/CompareModelsTests.cpp
        )

add_executable(IntegrationTests
        ${IntegrationTests}
        ${IntegrationTestUtils}
        ${TestUtils}
        )

set_target_properties(IntegrationTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/integration"
        )

add_dependencies(IntegrationTests
        hello
        writeModels
        )

if (WIN32)
    add_executable(CreateParentProcess
            test/integration/createprocess/CreateParentProcess.cpp
            test/integration/createprocess/strsafe.h)

    add_executable(CreateChildProcess
            test/integration/createprocess/CreateChildProcess.cpp)

    set_target_properties(
            CreateParentProcess
            CreateChildProcess
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/integration/createprocess"
    )
endif (WIN32)
