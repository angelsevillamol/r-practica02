/**
 * @file partida.hpp
 * @brief Fichero de cabecera de la clase Partida.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/17
 */

#include <vector>
#include <list>
#include <cassert>
#include "ficha.hpp"
#include "monton.hpp"
#include "tablero.hpp"
#include "jugador.hpp"

#ifndef PARTIDA_HPP_
#define PARTIDA_HPP_

/**
 * @brief Partida de juego de domino.
 */
class Partida {
 public:
  
  /**
   * @brief Constructor de la clase Partida.
   */
  Partida();
  
  /**
   * @brief Devuelve el nombre del jugador actual.
   * @return Nombre del jugador (tipo string).
   */
  inline std::string getNombreJugador() const {
    return jugadores_[turno_].getNombre();
  }

  /**
   * @brief Comprueba si el jugador actual tiene una determinada ficha.
   * @param f es la ficha a comprobar (tipo Ficha).
   * @return true si el jugador tiene la ficha, false en caso contrario.
   */
  inline bool tieneFicha(Ficha f) const {
    return (jugadores_[turno_].buscarFicha(f) != -1);
  }

  /**
   * @brief Comprueba si hay fichas en el monton.
   * @return true si hay fichas en el monton, false en caso contrario.
   */
  inline bool hayFichasMonton() const {
    return (monton_.getCuantas() > 0);
  }

  /**
   * @brief El usuario actual coloca la ficha de domino en la izquierda del tablero.
   * @param f es la ficha de domino a colocar (tipo Ficha).
   * @pre tieneFicha(f).
   */
  void colocarFichaIzda(Ficha f);

  /**
   * @brief El usuario actual coloca la ficha de domino en la derecha del tablero.
   * @param f es la ficha de domino a colocar (tipo Ficha).
   * @pre tieneFicha(f).
   */
  void colocarFichaDcha(Ficha f);

  /**
   * @brief El usuario roba una ficha del monton.
   * @pre hayFichasMonton().
   */
  void robarFicha() {
    assert(hayFichasMonton());
    Ficha f = monton_.sacarFicha();
    jugadores_[turno_].robarFicha(f);
    siguienteTurno();
  }

 private:
  Tablero tablero_; //!< Tablero de juego.
  Monton monton_; //!< Monton con fichas de domino sobrantes.
  std::vector<Jugador> jugadores_; //!< Jugadores de la partida.
  unsigned turno_; //!< Indica el turno de los jugadores.

  inline void siguienteTurno() {
    turno_ = (turno_ + 1) % jugadores_.size();
  }

};

#endif // PARTIDA_HPP_
