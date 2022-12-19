CC = g++
FLAGS= -g -lglut -lGL -lGLU -lSOIL
OUTPUT= main
INCLUDEDIR = -I /Header -I /Scopes
all:
		$(CC) $(INCLUDEDIR) -g *.cpp */*/*.cpp $(FLAGS) -o $(OUTPUT)

run: all
	./$(OUTPUT)

clean:
		rm *.o -f