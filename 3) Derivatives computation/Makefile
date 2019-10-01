## DEFINE SOURCE FILES
SRC= main.cpp functions.cpp Grid.cpp FiniteDifferenceClass.cpp
## substitute .cpp with .o in files stored in variable STR
OBJ=$(subst .cpp,.o,$(SRC))

## DEFINE COMPILER FLAGS
FLAGS= -std=c++11

## BUILD THE PROGRAM
main: $(OBJ)
	g++ -o finDiff $(OBJ)

## COMPILE MAIN FILE generates main.o
main.o: main.cpp functions.h Grid.h
	g++ $(FLAGS) -c main.cpp

## COMPILE FUNCTION FILE generates functions.o
functions.o: functions.cpp functions.h
	g++ $(FLAGS) -c functions.cpp

## COMPILE GRID FILE generates Grid.o
Grid.o: Grid.cpp Grid.h
	g++ $(FLAGS) -c Grid.cpp

## COMPILE FINITEDIFFERENCECLASS FILE generates FiniteDifferenceClass.o
FiniteDifferenceClass.o: FiniteDifferenceClass.cpp FiniteDifferenceClass.h Grid.h
	g++ $(FLAGS) -c FiniteDifferenceClass.cpp


## CLEAN COMPILATION FILES AND EXECUTABLE
# run $ make clean to delete objects and executable
clean:
	rm *.o finDiff
