## DEFINE SOURCE FILES
SRC= main.cpp Numerics.cpp Grid.cpp Solver.cpp
## substitute .cpp with .o in files stored in variable STR
OBJ=$(subst .cpp,.o,$(SRC))

## DEFINE COMPILER FLAGS
FLAGS= -std=c++11

## BUILD THE PROGRAM
main: $(OBJ)
	g++ -o linearHyperbolic $(OBJ)

## COMPILE MAIN FILE generates main.o
main.o: main.cpp Solver.h
	g++ $(FLAGS) -c main.cpp

## COMPILE NUMERICS FILE generates Numerics.o
Numerics.o: Numerics.cpp Numerics.h Grid.h
	g++ $(FLAGS) -c Numerics.cpp

## COMPILE GRID FILE generates Grid.o
Grid.o: Grid.cpp Grid.h
	g++ $(FLAGS) -c Grid.cpp

## COMPILE SOLVER FILE generates Solver.o
Solver.o: Solver.cpp Solver.h numerics.h
	g++ $(FLAGS) -c Solver.cpp


## CLEAN COMPILATION FILES AND EXECUTABLE
# run $ make clean to delete objects and executable
clean:
	rm *.o linearHyperbolic
