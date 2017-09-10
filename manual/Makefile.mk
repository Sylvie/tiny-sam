manual_filename = manual.tex
manual_directory := "manual/"
manual_sources := $(top_srcdir)/manual/$(manual_filename) $(top_srcdir)/manual/bibliography.bib
manual_pdf := $(builddir)/manual/manual.pdf

EXTRA_DIST += $(manual_sources) $(top_srcdir)/manual/latexmkrc_template $(builddir)/manual/latexmkrc

if HAVE_LATEXMK
EXTRA_DIST += $(manual_pdf)
endif

LATEXMK_BUILD = $(LATEXMK) -r $(builddir)/manual/latexmkrc -output-directory=$(manual_directory)
LATEXMK_CLEAN = $(LATEXMK) -r ../$(builddir)/manual/latexmkrc

prepare_manual_directory:
	if [ "$(top_srcdir)" != "$(top_builddir)" ]; then \
		mkdir -p $(manual_directory) && \
		cp $(top_srcdir)/manual/bibliography.bib $(manual_directory) && \
		cp $(top_srcdir)/manual/manual.tex $(manual_directory); \
	fi
	sed "s/%versionNumber%/$(VERSION)/g; s/%releaseDate%/$(tinysam_releasedate)/g" $(top_srcdir)/manual/latexmkrc_template > $(builddir)/manual/latexmkrc ;

pdf-local-manual : $(manual_pdf)

%.pdf : %.tex | prepare_manual_directory
	$(LATEXMK_BUILD) -pdf $^

binary-archive-local-manual:
	cp $(manual_pdf) $(archive_basename)

clean-local-manual:
	if [ -d "$(manual_directory)" ] && [ -e "$(manual_directory)$(manual_filename)" ] ; then \
		cd $(manual_directory) && \
		pwd && \
		$(LATEXMK_CLEAN) -c $(manual_filename) ; \
	fi

distclean-local-manual:
	if [ -d "$(manual_directory)" ] && [ -e "$(manual_directory)$(manual_filename)" ]; then \
		cd $(manual_directory) && \
		$(LATEXMK_CLEAN) -C $(manual_filename) ; \
	fi
	if [ -d "$(manual_directory)" ] && [ "$(top_srcdir)" != "$(top_builddir)" ]; then \
		rm -f manual/bibliography.bib ; \
		rm -f manual/manual.tex ; \
	fi
	if [ -d "$(manual_directory)" ]; then \
		rm -f manual/latexmkrc ; \
	fi
