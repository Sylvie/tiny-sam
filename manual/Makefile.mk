manual_filename = manual.tex
manual_directory := "manual/"
manual_sources := $(srcdir)/manual/$(manual_filename) $(srcdir)/manual/bibliography.bib
manual_pdf := $(builddir)/manual/manual.pdf

EXTRA_DIST += $(manual_sources) $(manual_pdf)

LATEXMK = latexmk -r $(srcdir)/manual/latexmkrc -output-directory=$(manual_directory)
LATEXMK_CLEAN = latexmk -r ../$(srcdir)/manual/latexmkrc

prepare_manual_directory:
	if [ "$(top_srcdir)" != "$(top_builddir)" ]; then \
		mkdir -p $(manual_directory) && \
		cp $(srcdir)/manual/bibliography.bib $(manual_directory) && \
		cp $(srcdir)/manual/manual.tex $(manual_directory); \
	fi

pdf-local-manual : $(manual_pdf)

%.pdf : %.tex | prepare_manual_directory
	$(LATEXMK) -pdf $^

dist-local-manual: $(outputFile)
	cp $(manualTargets) ../$(distDir)

clean-local-manual:
	if [ -d "$(manual_directory)" ] && [ -e "$(manual_directory)$(manual_filename)" ] ; then \
		cd $(manual_directory) && \
		$(LATEXMK_CLEAN) -c $(manual_filename) ; \
	fi


repo-clean-local-manual:
	if [ -d "$(manual_directory)" ] && [ -e "$(manual_directory)$(manual_filename)" ]; then \
		cd $(manual_directory) && \
		$(LATEXMK_CLEAN) -C $(manual_filename) ; \
	fi
	if [ -d "$(manual_directory)" ] && [ "$(top_srcdir)" != "$(top_builddir)" ]; then \
		rm -f manual/bibliography.bib ; \
		rm -f manual/manual.tex ; \
	fi
