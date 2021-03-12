CC = gcc 
CFLAGS = -Wall -O
LDFLAGS = `sdl-config --libs --cflags`
EXEC = gameOfLife
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC) clean

gameOfLife: $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

Graphique.o: Graphique.c Entetes.h

Main.o: Main.c Entetes.h

CA.o: CA.c Entetes.h

MT.o: MT.c Entetes.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean 
	rm -f $(EXEC)



 