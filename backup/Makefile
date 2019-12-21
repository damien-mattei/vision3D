
#------------------------------------------------------------------------------
MAINSOURCE=main.cpp
SOURCE=*.cpp *.hpp
OBJECT=$(MAINSOURCE:.cpp=.o)
MYPROGRAM=vision3d
MYINCLUDES=.
#DEFVAR=-DNOT_DISPLAY_CONSTRUCTOR -DDEBUG -DREF_OR_PTR
#DEFVAR=-DDISPLAY_CONSTRUCTOR -DDEBUG
#DEFVAR=-DDISPLAY_CONSTRUCTOR

MYLIBRARIES=
CC=g++
#CFLAGS=-Wall -std=c++0x
#CFLAGS=-Wall -std=c++11
CFLAGS=-Wall -std=c++14
LDFLAGS=
DEFVAR=-DDEBUG_BUILD
#------------------------------------------------------------------------------



all: $(MYPROGRAM)

$(MYPROGRAM): $(OBJECT) Makefile
	@echo ---------
	@echo LINKING	
	@echo ---------
	$(CC) $(OBJECT) $(LDFLAGS) -o $(MYPROGRAM) #-l$(MYLIBRARIES) 

$(OBJECT): $(SOURCE) Makefile
	@echo ----------
	@echo COMPILING
	@echo ----------
	$(CC) -I$(MYINCLUDES) -c $(CFLAGS) $(DEFVAR) $(MAINSOURCE)



clean:

	rm -f $(MYPROGRAM) *~ *.o


