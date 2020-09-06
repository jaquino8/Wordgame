OBJS = ./bin/wordgame.o ./bin/WordList.o ./bin/Player.o ./bin/TextDisplay.o
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 
INCLUDE_DIRS = -I./include/ -I./src/

# LDFLAGS = "-L/c/SFML-2.5.1/lib"
# CPPFLAGS = "-I/c/SFML-2.5.1/include"

wordgame: $(OBJS) 
	$(CXX) $(INCLUDE_DIRS) -o ./bin/wordgame $(OBJS) $(LDLIBS) $(LDFLAGS)
	./bin/wordgame

./bin/wordgame.o: ./src/wordgame.cpp ./include/*.hpp
	$(CXX) $(INCLUDE_DIRS) -c ./src/wordgame.cpp -o ./bin/wordgame.o $(CXXFLAGS)

./bin/WordList.o: ./include/WordList.hpp ./src/WordList.cpp ./include/*.hpp
	$(CXX) $(INCLUDE_DIRS) -c ./src/WordList.cpp -o ./bin/WordList.o $(CXXFLAGS)

./bin/Player.o: ./include/Player.hpp ./src/Player.cpp ./include/*.hpp
	$(CXX) $(INCLUDE_DIRS) -c ./src/Player.cpp -o ./bin/Player.o $(CXXFLAGS)
	
./bin/TextDisplay.o: ./include/TextDisplay.hpp ./src/TextDisplay.cpp ./include/*.hpp
	$(CXX) $(INCLUDE_DIRS) -c ./src/TextDisplay.cpp -o ./bin/TextDisplay.o $(CXXFLAGS)

#random.o: random.hpp
# enemy.o: enemy.h

run:

clean:
	rm ./bin/*

# player.o: player.cpp player.h
#   g++ -c player.cpp

# target: dependencies
#   command(s)