cmake_minimum_required(VERSION 3.10)
project(tiny_sam)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)
include_directories(test)

add_executable(hello
        src/GreetingsProvider.cpp
        src/GreetingsProvider.hpp
        src/hello.cpp
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
