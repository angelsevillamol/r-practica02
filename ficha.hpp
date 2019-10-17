/**
 * @file ficha.hpp
 * @brief Fichero de cabecera de la clase ficha.
 * @author Angel Sevilla Molina y Juan Pedro Muñoz Jimenez.
 * @date 2019/10/12
 */

#include <cassert>

#ifndef FICHA_HPP_
#define FICHA_HPP_

/**
 * @brief Representa una ficha de domino.
 */
class Ficha {
 public:

  /**
   * @brief Constructor por defecto de la clase Ficha.
   */
  inline Ficha() {
    setNumIzda(0);
    setNumDcha(0);
  }

  /**
   * @brief Constructor de la clase Ficha.
   * @param numIzda es el valor izquierdo de la ficha (tipo int).
   * @param numDcha es el valor derecho de la ficha (tipo int).
   * @pre numIzda >= 0 and numIzda <= 6.
   * @pre numDcha >= 0 and numDcha <= 6.
   */
  inline Ficha(int numIzda, int numDcha) {
    setNumIzda(numIzda);
    setNumDcha(numDcha);
  }

  /**
   * @brief Devuelve el numero a la izquierda de la ficha.
   * @return Valor izquierdo de la ficha (tipo int).
   */
  inline int getNumIzda() const { 
    return numIzda_; 
  }

  /**
   * @brief Devuelve el numero a la derecha de la ficha.
   * @return Valor derecho de la ficha (tipo int).
   */
  inline int getNumDcha() const { 
    return numDcha_; 
  }

  /**
   * @brief Comprueba si los valores de las fichas son iguales.
   * @return true si getNumIzda() == getNumDcha().
   */
  inline bool sonIguales() const {
    return getNumIzda() == getNumDcha();
  }

  /**
   * @brief Modifica el numero a la izquierda de la ficha.
   * @param numIzda es el valor izquierdo de la ficha (tipo int).
   * @pre numIzda >= 0 and numIzda <= 6.
   */
  inline void setNumIzda(int numIzda) { 
    assert(numIzda >= 0 and numIzda <= 6);
    numIzda_ = numIzda; 
  }

  /**
   * @brief Modifica el numero a la derecha de la ficha.
   * @param numDcha es el valor derecho de la ficha (tipo int).
   * @pre numDcha >= 0 and numDcha <= 6.
   */
  inline void setNumDcha(int numDcha) { 
    assert(numDcha >= 0 and numDcha <= 6);
    numDcha_ = numDcha; 
  }

  /**
   * @brief Gira la ficha.
   */
  inline void girar() {
    int aux = getNumIzda();
    setNumIzda(getNumDcha());
    setNumDcha(aux);
  }

  /**
   * @brief Compara dos fichas de domino.
   * @param f ficha a comparar (tipo Ficha).
   */
  inline bool operator==(const Ficha& f) {
    if (getNumIzda() == f.getNumIzda() and getNumDcha() == f.getNumDcha()) {
      return true;
    } 
    else if (getNumIzda() == f.getNumDcha() and getNumDcha() == f.getNumIzda()) {
      return true;
    }
    
    return false;
  }

 private:
  int numIzda_; //!< Valor izquierdo de la ficha.
  int numDcha_; //!< Valor derecho de la ficha.
};

#endif // FICHA_HPP_
