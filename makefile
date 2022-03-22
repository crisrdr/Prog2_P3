####################### VARIABLES #######################

EXE_1 = p3_e1b
OBJ_1 = libqueue.a $(EXE_1).o

GCC = gcc -Wall -ansi -pedantic -c -g 

##################### COMANDOS MAKE ######################

all_1: $(EXE_1)	

p3_e1b: $(OBJ_1)
        gcc -o $(EXE_1) $(OBJ_1)

p3_e1b.o: p3_e1b.c queue.h types.h sorted_queue.h
    S(GCC) S(EXE_1).c

run1: 
  ./$(EXE_1)

val1:
  valgrind --leak-check=full ./$(EXE_1)

clean:
  rm *.o $(EXE_1)