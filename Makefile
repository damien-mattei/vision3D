
#------------------------------------------------------------------------------

OBJECT=Panorama.o Point2D.o Point3D.o Edge2D.o Edge3D.o Vector3D.o Matrix3x3.o Face3D.o Object.o ObjFile.o Universe.o Vision3D.o  main.o
MYPROGRAM=vision3d

# for Mac OS
MYINCLUDES=/opt/homebrew/Cellar/boost/1.90.0/include # . seems to be by default

MYLIBRARIES=

CC=g++

#CFLAGS=-Wall -std=c++0x
#CFLAGS=-Wall -std=c++11
#CFLAGS=-Wall -std=c++14
CFLAGS=-Wall -std=c++17
#CFLAGS=-Wall -std=gnu++17 # idem c++17

LDFLAGS=

#DEFVAR=-DNOT_DISPLAY_CONSTRUCTOR -DDEBUG -DREF_OR_PTR
#DEFVAR=-DDISPLAY_CONSTRUCTOR -DDEBUG
#DEFVAR=-DDISPLAY_CONSTRUCTOR
DEFVAR=-DDEBUG_BUILD -DDISPLAY_CONSTRUCTOR -DCHECK_MEMORY

#------------------------------------------------------------------------------


all: $(MYPROGRAM)




%.o: %.cpp %.hpp
	@echo COMPILING	$<
	$(CC) -c -o $@ $< $(CFLAGS) -I$(MYINCLUDES) $(DEFVAR)


$(MYPROGRAM): $(OBJECT)
	@echo
	@echo LINKING $(OBJECT)	
	$(CC) $(LDFLAGS) -o $@ $^ #-l$(MYLIBRARIES) 


clean:

	rm -f $(MYPROGRAM) *~ *.o


