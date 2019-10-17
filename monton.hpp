/**
 * @file monton.hpp
 * @brief Fichero de cabecera de la clase Monton.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <list>
#include <cassert>
#include "ficha.hpp"

#ifndef MONTON_HPP_
#define MONTON_HPP_

/**
 * @brief Monton con fichas de domino.
 */
class Monton {
 public:
  
  /**
   * @brief Constructor de la clase Monton.
   */
  inline Monton() {
    inicializar();
  }

  /**
   * @brief Genera todas las fichas posibles del domino en un orden aleatorio.
   * @post getCuantas() = 28.
   */
  void inicializar();

  /**
   * @brief Devuelve el numero de fichas que hay en el monton.
   * @return Numero de fichas del monton (tipo int).
   */
  inline unsigned getCuantas() const {
    return monton_.size();
  }

  /**
   * @brief Extrae la ultima ficha del monton y la devuelve.
   * @return Ultima ficha del monton (tipo Ficha).
   * @pre getCuantas() > 0.
   */
  inline Ficha sacarFicha() {
    assert(getCuantas() > 0);
    Ficha f = monton_.back();
    monton_.pop_back();
    return f;
  }

 private:
  std::list<Ficha> monton_; //!< Contiene las fichas del monton.
};

#endif // MONTON_HPP_
