noinst_PROGRAMS += test/factorial
TESTS += test/factorial

test_factorial_SOURCES = test/factorial.cpp test/main-catch.cpp test/catch.hpp
