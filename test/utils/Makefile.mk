catch_source_files = \
	test/utils/main-catch.cpp \
	test/utils/catch.hpp

noinst_LIBRARIES += test/utils/libTinySamTestUtils.a

test_utils_libTinySamTestUtils_a_SOURCES = \
    test/utils/TinySamRegressionResults.cpp \
    test/utils/TinySamRegressionResults.h
test_utils_libTinySamTestUtils_a_CPPFLAGS = -I $(top_srcdir)/test/utils/

