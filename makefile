# Jacob Schneck
# CS 120
# Module-Four: Runner

CC = g++ -std=c++17

libs = -lglut -lGL -lGLU

make: 
	${CC} *.cpp -o graphics ${libs}
	./graphics
	rm graphics
