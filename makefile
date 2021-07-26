# Jacob Schneck
# CS 120
# Module-Four: Runner

CC = g++ -std=c++17

libs = -lglut -lGL -lGLU

make: 
	${CC} *.cpp 3D_Shapes/*.cpp -o graphics ${libs}
	./graphics
	rm graphics
