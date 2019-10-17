/**
 * @file tablero.hpp
 * @brief Fichero de cabecera de la clase Tablero.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <list>
#include <cassert>
#include "ficha.hpp"

#ifndef TABLERO_HPP_
#define TABLERO_HPP_

/**
 * @brief Tablero de juego de una partida de domino.
 */
class Tablero {
 public:
  
  /**
   * @brief Constructor de la clase Monton.
   */
  Tablero() {
    tablero_.clear();
  }

  /**
   * @brief Elimina las fichas del tablero.
   */
  inline void reiniciar() {
    tablero_.clear();
  }

  /**
   * @brief Devuelve el numero a la izquierda del tablero.
   * @return Valor izquierdo del tablero (tipo int).
   */
  inline int getNumIzda() const { 
    return tablero_.front().getNumIzda(); 
  }

  /**
   * @brief Devuelve el numero a la derecha del tablero.
   * @return Valor derecho del tablero (tipo int).
   */
  inline int getNumDcha() const { 
    return tablero_.back().getNumDcha(); 
  }

  /**
   * @brief Coloca una ficha a la izquierda del tablero.
   * @param f ficha a colocar (tipo Ficha).
   * @pre f.getNumDcha() = getNumIzda() or f.getNumIzda() = getNumIzda() or tablero.empty().
   */
  void colocarIzda(Ficha f);

  /**
   * @brief Coloca una ficha a la derecha del tablero.
   * @param f ficha a colocar (tipo Ficha).
   * @pre f.getNumIzda() = getNumDcha() or f.getNumDcha() = getNumDcha() or tablero.empty().
   */
  void colocarDcha(Ficha f);

 private:
  std::list<Ficha> tablero_; //!< Contiene las fichas del tablero.
};

#endif // TABLERO_HPP_
