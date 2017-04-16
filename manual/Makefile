inputFile=manual.tex
output=sambadoc
outputFile=$(output).pdf

all: manual

manual: $(inputfile)
	latexmk -jobname=$(output) $(inputFile) -pdf

dist: $(outputFile)
	cp $(outputFile) ../$(distDir)

clean:
	latexmk -C -jobname=$(output)