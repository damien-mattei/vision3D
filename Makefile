
#------------------------------------------------------------------------------

OBJECT=Point2D.o Point3D.o Edge2D.o Edge3D.o Vector3D.o Universe.o Vision3D.o main.o
MYPROGRAM=vision3d
MYINCLUDES=.

MYLIBRARIES=

CC=g++

#CFLAGS=-Wall -std=c++0x
#CFLAGS=-Wall -std=c++11
CFLAGS=-Wall -std=c++14

LDFLAGS=

#DEFVAR=-DNOT_DISPLAY_CONSTRUCTOR -DDEBUG -DREF_OR_PTR
#DEFVAR=-DDISPLAY_CONSTRUCTOR -DDEBUG
#DEFVAR=-DDISPLAY_CONSTRUCTOR
DEFVAR=-DDEBUG_BUILD -DDISPLAY_CONSTRUCTOR

#------------------------------------------------------------------------------



all: $(MYPROGRAM)





%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -I$(MYINCLUDES) $(DEFVAR)


$(MYPROGRAM): $(OBJECT)
	@echo ---------
	@echo LINKING	
	@echo ---------
	@echo $(OBJECT)
	$(CC) $(LDFLAGS) -o $@ $^ #-l$(MYLIBRARIES) 


clean:

	rm -f $(MYPROGRAM) *~ *.o


