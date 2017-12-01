noinst_PROGRAMS += test/factorial test/GreetingsProviderTests test/total
TESTS += test/factorial test/GreetingsProviderTests test/total

test_factorial_SOURCES = test/factorial.cpp test/main-catch.cpp test/catch.hpp
test_GreetingsProviderTests_SOURCES = test/GreetingsProviderTests.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp test/main-catch.cpp test/catch.hpp
test_total_SOURCES = test/factorial.cpp test/GreetingsProviderTests.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp test/main-catch.cpp test/catch.hpp
