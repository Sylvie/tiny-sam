builddir=../build/

file=manual

target=$(builddir)/$(file).pdf

all: resources $(target)

resources:
	mkdir -p $(builddir)

$(builddir)/%.pdf: %.tex
	echo Hi
	latexmk -pdf -output-directory=$(builddir) $< 