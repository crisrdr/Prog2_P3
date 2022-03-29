####################### VARIABLES #######################

EXE_1 = p3_e1b
OBJ_1 = $(EXE_1).o sorted_queue.o libqueue.a point.o

GCC = gcc -Wall -ansi -pedantic -c -g
GCC_MATH = g++ -L /usr/lib

##################### COMANDOS MAKE ######################

all_1: $(EXE_1)

# EJERCICIO 1 #

p3_e1b: $(OBJ_1)
	$(GCC_MATH) -o $(EXE_1) $(OBJ_1)

p3_e1b.o: $(EXE_1).c sorted_queue.h queue.h types.h point.h
	$(GCC) $(EXE_1).c

sorted_queue.o: sorted_queue.c sorted_queue.h queue.h types.h
	$(GCC) sorted_queue.c

point.o: point.c point.h types.h
	$(GCC) point.c

run1: 
	./$(EXE_1)

val1:
	valgrind --leak-check=full ./$(EXE_1)

clean:
	rm *.o $(EXE_1)