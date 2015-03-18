# Systemnahes Programmieren SS 2015

In our course ''Systemnahes Programmieren'' that we had to take in our 3. semester at HS Karlsruhe, we had to build a compiler for a simple programming language. 

You might want to check out the course's [webpage](http://www.iwi.hs-karlsruhe.de/Intranetaccess/mhb/module/MKIB/MIB%20310/1).

The first part is writing a scanner, that analyzes a given input file and tokenizes it. It checks for errors and will print those with line and row number. The recognized tokens will be saved in a specified output file. 

It is highly recommended to check out the documentation.

## Installation & Requirements
In order to build the project you need a C++ compiler like `g++` and a tool called `make`.

```
git clone https://www.github.com/TobsCore/sysprog
cd sysprog
make
```

To generate the documentation, you need to install LaTeX.  Then simply run:

```
make docu
```
