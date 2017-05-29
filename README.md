# Systemnahes Programmieren
[![Build Status](https://travis-ci.org/TobsCore/sysprog.svg?branch=master)](https://travis-ci.org/TobsCore/sysprog)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/06486b00fd554980aa6120ae4e208eb4)](https://www.codacy.com/app/TobsCore/sysprog?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=TobsCore/sysprog&amp;utm_campaign=Badge_Grade)

In our course ''Systemnahes Programmieren'' that we had to take in our 3. semester at HS Karlsruhe, we had to build a compiler for a simple programming language.

You might want to check out the course's [webpage](http://www.iwi.hs-karlsruhe.de/Intranetaccess/mhb/module/MKIB/MIB%20310/1).

The first part is writing a scanner, that analyzes a given input file and tokenizes it. It checks for errors and will print those with line and row number. The recognized tokens will be saved in a specified output file.

It is highly recommended to check out the documentation.

### Installation & Requirements ###

#### Requirements ####
In order to build the project, you need the following

 * `git`
 * `gcc`
 * `make`
 * `cmake`

### Installation ###

``` shell
git clone https://www.github.com/TobsCore/sysprog.git
cd sysprog
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
```

This creates a makefile, which can be used to compile the sources. From `sysprog/cmake-build-debug` run the following

``` shell
make all
```

This will create the unit tests and the resulting program. If you want to only create the program, run `make sysprogMain`. If you want to create only the unit tests, run `make unitTests`.
After these commands finished without errors, you can run the program by entering:

``` shell
./sysprogMain path/to/filename
./unitTests
```

### Use project in Eclipse ###
Eclipse doesn't support CMake support, but CMake can convert the project into an Eclipse project. Assume you haven't cloned the repository yet and want to use it in Eclipse.

There is a small shell script that should ease the transition by setting up the project structure.

``` shell
git clone https://www.github.com/TobsCore/sysprog.git
cd sysprog
./init_eclipse.sh
```
Done.

Now you need to import the project to Eclipse. Under _File_ -> _Import_ select _General_ -> _Existing projects into workspace_.

Select the location that has been printed by the script (should be called something like _cmake-build-debug_) as _Root Directory` and make sure that _Copy projects into workspace_ is **not** selected.

You can now double click on the build targets to compile and link the project. I.E the unit tests can be run by double clicking on _BuildTargets_ -> _[exe] unitTests_.

In project explorer there's a new file called `unitTests - [x86_64/le]` which you can run by right clicking it and then selecting _Run As_ -> _Local C/C++ Application_.

### Generating the documentation ###

To generate the documentation, you need to install LaTeX. Then simply run:

``` shell
make docu
```
