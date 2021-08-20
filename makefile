# Jacob Schneck
# CS 120
# Module-Four: Runner
# ${CC} Experiments/graphics4D.cpp 4D_Shapes/*.cpp -o graphics4D ${libs}

CC = g++ -std=c++17

libs = -lglut -lGL -lGLU

make: 
	@echo "Running Shapoids"
	${CC} *.cpp 3D_Shapes/*.cpp -o graphics ${libs}
	./graphics
	rm graphics

exper:
	@echo "Running Experiments"
# ${CC} Experiments/graphics4D.cpp -o graphics4D ${libs}
	${CC} Experiments/graphics4D.cpp 4D_Shapes/*.cpp -o graphics4D ${libs}
	./graphics4D
	rm graphics4D
