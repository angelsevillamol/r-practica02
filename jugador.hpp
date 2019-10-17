/**
 * @file jugador.hpp
 * @brief Fichero de cabecera de la clase Jugador.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/14
 */

#include <vector>
#include <string>
#include <cassert>
#include "ficha.hpp"

#ifndef JUGADOR_HPP_
#define JUGADOR_HPP_

/**
 * @brief Jugador de una partida de domino.
 */
class Jugador {
 public:
  
  /**
   * @brief Constructor de la clase Jugador.
   */
  inline Jugador(std::string nombre) {
    nombre_ = nombre;
  }

  /**
   * @brief Devuelve el nombre del jugador.
   * @return Nombre del jugador (tipo string).
   */
  inline std::string getNombre() const {
    return nombre_;
  }

  /**
   * @brief Devuelve el numero de fichas que tiene en mano el jugador.
   * @return Numero de fichas de la mano (tipo unsigned).
   */
  inline unsigned getNumFichas() const {
    return mano_.size();
  }

  /**
   * @brief Devuelve la ficha i-esima del jugador.
   * @return Ficha i-esima (tipo Ficha).
   * @pre i < getNumFichas().
   */
  inline Ficha getFicha(unsigned i) const {
    assert(i < getNumFichas());
    return mano_[i];
  }

  /**
   * @brief Busca una ficha de dominó en la mano del jugador.
   * @param f es la ficha a buscar (tipo Ficha).
   * @return indice de la ficha si se encuentra, -1 si no la tiene.
   */
  int buscarFicha(Ficha f) const;

  /**
   * @brief Añade una ficha a la mano del jugador.
   * @param f ficha a añadir (tipo Ficha).
   */
  inline void robarFicha(Ficha f) {
    mano_.push_back(f);
  }

  /**
   * @brief Juegua una ficha y la elimina de la mano del jugador.
   * @param i indice de la ficha a jugar (tipo unsigned).
   * @return Ficha i-esima (tipo Ficha).
   * @pre i < getNumFichas().
   */
  Ficha colocarFicha(unsigned i);

 private:
  std::string nombre_; //!< Nombre del jugador.
  std::vector<Ficha> mano_; //!< Contiene las fichas de la mano.
};

#endif // JUGADOR_HPP_
