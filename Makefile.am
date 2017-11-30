## Process this file with automake to produce Makefile.in

EXTRA_DIST = $(top_srcdir)/.version $(top_srcdir)/.releasedate
BUILT_SOURCES = $(top_srcdir)/.version $(top_srcdir)/.releasedate
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
$(top_srcdir)/.releasedate:
	echo $(tinysam_releasedate) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version
	echo $(tinysam_releasedate) > $(distdir)/.tarball-releasedate

bin_PROGRAMS = hello
hello_SOURCES = src/hello.cpp src/GreetingsProvider.cpp src/GreetingsProvider.hpp

pdf-local: pdf-local-manual

archive_basename = $(builddir)/$(PACKAGE)-$(VERSION)-$(system_name)
archive_binaries_basename = $(archive_basename)/binaries

create-archive-folder:
	mkdir -p $(archive_basename)
	mkdir -p $(archive_binaries_basename)

binary-archive: all pdf create-archive-folder
	$(MAKE) binary-archive-local-manual
	cp $(bin_PROGRAMS) $(archive_binaries_basename)
	tar -zcvf $(archive_basename).tar.gz $(archive_basename)

MOSTLYCLEANFILES =
CLEANFILES =
DISTCLEANFILES =
MAINTAINERCLEANFILES =
REPOCLEANFILES = $(addprefix $(srcdir)/, aclocal.m4 configure config.guess config.sub depcomp install-sh Makefile.in missing test-driver)

clean-local: clean-local-manual

distclean-local: distclean-local-manual

repo-clean: maintainer-clean
	rm -rf $(REPOCLEANFILES)

include manual/Makefile.mk

noinst_PROGRAMS =
TESTS =

include test/Makefile.mk

