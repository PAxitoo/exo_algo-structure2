
pendu: pendu.o fonctions.o
	gcc -o pendu pendu.o fonctions.o

pendu.o: pendu.c
	gcc -c pendu.c

fonctions.o: fonctions.c
	gcc -c fonctions.c

testpendu: test_pendu.o fonctions.o
	gcc -o testpendu test_pendu.o fonctions.o 

test_pendu.o: test_pendu.c
	gcc -c test_pendu.c

