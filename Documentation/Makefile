.PHONY: all
all:
	./latexrun Dokumentation.tex --latex-cmd=xelatex
	mv Dokumentation.pdf Dokumentation\ Systemnahes\ Programmieren.pdf

.PHONY: clean
clean:
	./latexrun --clean-all && rm -rf latex.out
