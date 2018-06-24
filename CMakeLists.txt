cmake_minimum_required(VERSION 3.10)
project(tiny_sam)

set(CMAKE_CXX_STANDARD 11)

add_definitions(
        -Dtiny_sam_executable_extension="${CMAKE_EXECUTABLE_SUFFIX}"
)

include_directories(src)
include_directories(test)

add_executable(hello
        src/GreetingsProvider.cpp
        src/GreetingsProvider.hpp
        src/hello.cpp
        )

set_target_properties(hello
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
        )

set(CATCH_SRCS
        test/catch.hpp
        test/main-catch.cpp
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

set(IntegrationTests
        test/integration/HelloIntegrationTests.cpp
        )

add_executable(IntegrationTests
        ${IntegrationTests}
        ${CATCH_SRCS}
        )

set_target_properties(IntegrationTests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/integration"
        )

add_dependencies(IntegrationTests
        hello)


