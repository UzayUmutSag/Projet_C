# compilateur
CC := gcc
# options de compilation
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb 

# règle de compilation --- exécutables
all : main

main : main.o arbre_binaire.o combinaison.o noeud.o
	$(CC) $(CFLAGS) -o $@ $^	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

# options de compilation
clean:
	rm *.o main
