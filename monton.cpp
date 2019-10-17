/**
 * @file monton.cpp
 * @brief Implementacion de los metodos de la clase Monton.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>
#include "ficha.hpp"
#include "monton.hpp"

// Genera todas las fichas posibles del domino en un orden aleatorio.
void Monton::inicializar() {

    // Se eliminan las fichas existentes en el monton.
    monton_.clear();

    // Se crean las fichas en orden creciente.
    std::vector<Ficha> fichas (28);
    for (unsigned i, k = 0; i < 7; i++) {
        for (int j = i; j < 7; j++, k++) {
            fichas[k].setNumIzda(i);
            fichas[k].setNumDcha(j);
        }
    }

    // Se reordenan aleatoriamente las fichas.
    std::random_device rd;
    std::shuffle(fichas.begin(), fichas.end(), rd);

    // Se insertan en el monton en el nuevo orden.
    for (unsigned i = 0; i < 28; i++) {
        monton_.push_back(fichas[i]);
    }

    assert(getCuantas() == 28);
}
