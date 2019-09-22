## DEFINE SOURCE FILES
SRC= main.cpp function.cpp
## substitute .cpp with .o in files stored in variable STR
OBJ=$(subst .cpp,.o,$(SRC))

## BUILD THE PROGRAM
main: $(OBJ)
	g++ -o PROVA $(OBJ)

## COMPILE MAIN FILE generates main.o
main.o: main.cpp function.h
	g++ -c main.cpp

## COMPILE FUNCTION FILE generates function.o
function.o: function.cpp function.h
	g++ -c function.cpp

## CLEAN COMPILATION FILES AND EXECUTABLE
# run $ make clean to delete objects and executable
clean:
	rm *.o PROVA
