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

##Fixed Methods / Interfaces:

Buffer:
``` c++
int getchar() //Nullterminator, falls das Ende der Datei erreicht wurde.
void ungetchar(int anzahl) //Der Buffer springt die Anzahl an Zeichen zurück.
```

Automat:
```c++
int checkExpression(char aktuellesZeichen)
// Der Automat merkt sich, in welchem Zustand er ist.
//Gibt Integer Werte zurück, die jeweils für die entsprechenden Arten/Typen stehen.
```
Scanner:
```c++
nextToken() // Gibt das nächste Token Objekt zurück. Falls ein Fehler aufgetaucht ist, ein Fehlertoken, falls es keine Tokens mehr gibt, ein Nullpointer. Speichert aktuelle Zeile und Reihe. Speichert Lexeme in der Symtabelle ab und generiert Tokens.
```

Token:
Art, Name, Zeile, Reihe

Information:
Art (Integer), Namen (Wert)

