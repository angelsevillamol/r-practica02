/**
 * @file tablero.cpp
 * @brief Implementacion de los metodos de la clase Tablero.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <list>
#include <cassert>
#include "ficha.hpp"
#include "tablero.hpp"

// Coloca una ficha a la izquierda del tablero.
void Tablero::colocarIzda(Ficha f) {
    assert(f.getNumDcha() == getNumIzda() or f.getNumIzda() == getNumIzda() 
        or tablero_.empty());

    // Si coincide.
    if (f.getNumDcha() == getNumIzda()) {
        tablero_.push_front(f);
    }
    // Si hay que girarla.
    else if (f.getNumIzda() == getNumIzda()) {
        f.girar();
        tablero_.push_front(f);
    }
    // Si es la primera ficha a jugar.
    else if (tablero_.empty()) {
        tablero_.push_front(f);
    }
}

//Coloca una ficha a la derecha del tablero.
void Tablero::colocarDcha(Ficha f) {
    assert(f.getNumIzda() == getNumDcha() or f.getNumDcha() == getNumDcha() 
        or tablero_.empty());

    // Si coincide.
    if (f.getNumIzda() == getNumDcha()) {
        tablero_.push_back(f);
    }
    // Si hay que girarla.
    else if (f.getNumDcha() == getNumDcha()) {
        f.girar();
        tablero_.push_back(f);
    } 
    // Si es la primera ficha a jugar.
    else if (tablero_.empty()) {
        tablero_.push_back(f);
    }
}
