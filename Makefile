## DEFINE SOURCE FILES
SRC= main.cpp function.cpp vettore.cpp
## substitute .cpp with .o in files stored in variable STR
OBJ=$(subst .cpp,.o,$(SRC))

## DEFINE COMPILER FLAGS
FLAGS= -std=c++11

## BUILD THE PROGRAM
main: $(OBJ)
	g++ -o PROVA $(OBJ)

## COMPILE MAIN FILE generates main.o
main.o: main.cpp function.h vettore.h
	g++ $(FLAGS) -c main.cpp

## COMPILE FUNCTION FILE generates function.o
function.o: function.cpp function.h
	g++ $(FLAGS) -c function.cpp

## COMPILE VETTORE FILE generates vettore.o
vettore.o: vettore.cpp vettore.h
	g++ $(FLAGS) -c vettore.cpp


## CLEAN COMPILATION FILES AND EXECUTABLE
# run $ make clean to delete objects and executable
clean:
	rm *.o PROVA
