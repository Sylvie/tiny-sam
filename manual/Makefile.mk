manual_filename = manual.tex
manual_directory := "manual/"
manual_sources := $(top_srcdir)/manual/$(manual_filename) $(top_srcdir)/manual/bibliography.bib
manual_pdf := $(builddir)/manual/manual.pdf

EXTRA_DIST += $(manual_sources) $(top_srcdir)/manual/latexmkrc

if HAVE_LATEXMK
EXTRA_DIST += $(manual_pdf)
endif

LATEXMK_BUILD = $(LATEXMK) -r $(top_srcdir)/manual/latexmkrc -output-directory=$(manual_directory)
LATEXMK_CLEAN = $(LATEXMK) -r ../$(top_srcdir)/manual/latexmkrc

prepare_manual_directory:
	if [ "$(top_srcdir)" != "$(top_builddir)" ]; then \
		mkdir -p $(manual_directory) && \
		cp $(top_srcdir)/manual/bibliography.bib $(manual_directory) && \
		cp $(top_srcdir)/manual/manual.tex $(manual_directory); \
	fi

pdf-local-manual : $(manual_pdf)

%.pdf : %.tex | prepare_manual_directory
	$(LATEXMK_BUILD) -pdf $^

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
