inputfile=manual.tex
output=sambadoc

all: manual

manual: $(inputfile)
	latexmk -jobname=$(output) $(inputfile) -pdf

clean:
	latexmk -C -jobname=$(output)