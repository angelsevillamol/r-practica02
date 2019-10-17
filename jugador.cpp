/**
 * @file jugador.cpp
 * @brief Implementacion de los metodos de la clase Jugador.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <list>
#include <cassert>
#include "ficha.hpp"
#include "jugador.hpp"

// Busca una ficha de dominó en la mano del jugador.
int Jugador::buscarFicha(Ficha f) const {
    for (unsigned i = 0; i < getNumFichas(); i++) {
        if (getFicha(i) == f) {
            return i;
        }
    }

    return -1;
}

// Juega una ficha y la elimina de la mano del jugador.
Ficha Jugador::colocarFicha(unsigned i) {
    assert(i < getNumFichas());
    Ficha f = getFicha(i);
    mano_.erase(mano_.begin() + i);
    return f;
}
