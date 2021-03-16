/* 5330504 */

#include "../include/pila.h"
#include "../include/lista.h"
#include "../include/utils.h"

#include <assert.h>

struct _rep_cola {
    TLista lst;
}

/*
  Devuelve un elemento de tipo 'TCola' vacío (sin elementos).
 */
TCola crearCola(){
    Tcola resultado = new _rep_cola;
    (*resultado).lst = crearLista();
    return resultado;
}

/*
  Devuelve 'true' si y solo si 'cola' no tiene elementos.
 */
bool esVaciaCola(TCola cola){
    return longitud((*coola).lst) == 0;
}

/*
  Si en 'cola' hay menos de MAX (definido en utils.h) elementos encola
  'nuevo' en 'cola'. En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola encolar(info_t nuevo, TCola cola){
    if( longitud(*cola).lst) < MAX ){
        (*cola).lst = insertar(longitud(*cola).lst) + 1, nuevo, (*cola).lst);
        return cola
    }
}

/*
  Devuelve el frente de 'cola'.
  Precondición: 'cola' tiene elementos.
 */
info_t frente(TCola cola){
    assert(!esVaciaCola(cola));
    pos = 1;
    return infoLista(pos, (*cola).lst);
}

/*
  Si 'cola' tiene elementos desapila el frente de 'cola'.
  En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola desencolar(TCola cola){
    if(!esVaciaCola){
        pos = 1;
        (*cola).lst = remover(pos, (*cola).lst);
        return cola;
    }

}

#endif
