.PHONY: clean

CXX += -g -Wall -Wextra -pthread -std=c++11
CXXFLAGS = -g -Wall

MAIN = cliente servidor

all: $(MAIN)

monton.o: ficha.hpp monton.hpp monton.cpp
	$(CXX) $(CXXFLAGS) -c monton.cpp

tablero.o: ficha.hpp tablero.hpp tablero.cpp
	$(CXX) $(CXXFLAGS) -c tablero.cpp

jugador.o: ficha.hpp jugador.hpp jugador.cpp
	$(CXX) $(CXXFLAGS) -c jugador.cpp

partida.o: ficha.hpp partida.hpp partida.cpp monton.o tablero.o jugador.o
	$(CXX) $(CXXFLAGS) -c partida.cpp

cliente.o: cliente.cpp
	$(CXX) $(CXXFLAGS) -c cliente.cpp

servidor.o: servidor.cpp monton.o tablero.o jugador.o partida.o
	$(CXX) $(CXXFLAGS) -c servidor.cpp

cliente: cliente.o
	$(CXX) $(CXXFLAGS) $^ -o $@

servidor: servidor.o monton.o tablero.o jugador.o partida.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o

