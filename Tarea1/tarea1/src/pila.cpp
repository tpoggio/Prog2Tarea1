/* 5330504 */

#include "../include/pila.h"
#include "../include/lista.h"
#include "../include/utils.h"

#include <assert.h>

struct _rep_pila {
    TLista lst;
}

/*
  Devuelve un elemento de tipo 'TPila' vacío (sin elementos).
 */
TPila crearPila(){
    Tpila resultado = new _rep_pila;
    (*resultado).lst = crearLista();
    return resultado;
}

/*
  Devuelve 'true' si y solo si 'pila' no tiene elementos.
 */
bool esVaciaPila(TPila pila){
    return longitud((*pila).lst) == 0;
}

/*
  Si en 'pila' hay menos de MAX (definido en utils.h) elementos apila
  'nuevo' en 'pila'. En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila apilar(info_t nuevo, TPila pila){
    (*pila).lst = insertar(longitud(*pila).lst) + 1, nuevo, (*pila).lst);
    return pila;
}

/*
  Devuelve el tope de 'pila'.
  Precondición: 'pila' tiene elementos.
 */
info_t cima(TPila pila){
    assert(!esVaciaPila(pila));
    return infoLista(longitud( (*pila).lst), (*pila).lst);
}

/*
  Si 'pila' tiene elementos desapila el tope de 'pila'.
  En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila desapilar(TPila pila){
    (*pila).lst = remover(longitud(*pila).lst), (*pila).lst);
    return pila
}

#endif
