manual_directory := "manual/"
manual_sources := $(srcdir)/manual/manual.tex
manual_pdf := $(builddir)/manual/manual.pdf

EXTRA_DIST += $(manual_sources) $(manual_pdf)

LATEXMK = latexmk -r $(srcdir)/manual/latexmkrc -output-directory=$(manual_directory)

prepare_manual_directory:
	if [ "$(srcdir)" != "." ]; then \
	  mkdir -p $(manual_directory); \
	  cp $(srcdir)/manual/bibliography.bib $(manual_directory); \
	fi

pdf-local-manual : $(manual_pdf)

%.pdf : %.tex | prepare_manual_directory
	$(LATEXMK) -pdf $^

dist-local-manual: $(outputFile)
	cp $(manualTargets) ../$(distDir)

clean-local-manual:
	$(LATEXMK) -C
