## Process this file with automake to produce Makefile.in

EXTRA_DIST = $(top_srcdir)/.version
BUILT_SOURCES = $(top_srcdir)/.version
$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version

bin_PROGRAMS = hello
hello_SOURCES = src/hello.cpp

pdf-local: pdf-local-manual

archive_basename = $(builddir)/$(PACKAGE)-OSX
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
REPOCLEANFILES = $(addprefix $(srcdir)/, aclocal.m4 Makefile.in configure depcomp install-sh missing)

clean-local: clean-local-manual

distclean-local: distclean-local-manual

repo-clean: maintainer-clean
	rm -rf $(REPOCLEANFILES)

include manual/Makefile.mk
