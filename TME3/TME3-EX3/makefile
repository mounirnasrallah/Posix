CC=gcc
CFLAGS=-c -Wall -I.
LDFLAGS=
SOURCES=affiche1.c affiche2.c affiche3.c affiche4.c affiche-main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=affiche

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o *~
