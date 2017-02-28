INCLUDE = /home/lash/programming/include/
LIBS = /home/lash/programming/lib/
BINDIR = ./bin/
SRCDIR = ./src/
BUILDDIR = ./build/

all:
	gcc -Wall -g -I$(INCLUDE) -gdwarf-2 -g3 -c $(SRCDIR)instruction.c -o $(BUILDDIR)instruction.o
	gcc -Wall -g -I$(INCLUDE) -gdwarf-2 -g3 -c $(SRCDIR)http.c -o $(BUILDDIR)http.o
	gcc -Wall -g -I$(INCLUDE) -gdwarf-2 -g3 -c $(SRCDIR)midi.c -o $(BUILDDIR)midi.o
	gcc -Wall -g -I$(INCLUDE) -gdwarf-2 -g3 -c $(SRCDIR)main.c -o $(BUILDDIR)main.o
	gcc -Wall -g -o -I$(INCLUDE) -L$(LIBS) -o $(BINDIR)midinetworksim $(BUILDDIR)main.o $(BUILDDIR)midi.o $(BUILDDIR)instruction.o $(BUILDDIR)http.o -lasound -llashdebug

clean:
	rm $(BUILDDIR)* -rf
	rm $(BINDIR)* -rf
