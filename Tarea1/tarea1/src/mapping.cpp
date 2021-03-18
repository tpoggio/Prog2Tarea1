
#include "../include/pila.h"
#include "../include/lista.h"
#include "../include/utils.h"
#include "../include/cola.h"
#include "../include/mapping.h"

struct _rep_mapping {
  nat asociaciones;
  info_t pares[MAX];
}

/*
  Devuelve un elemento de tipo 'TMapping' vacío (sin elementos).
 */
TMapping crearMapping(){
  TMapping res = new _rep_mapping;
  (*res).asociaciones = 0;
  return res;
}

/*
  Si en 'map' hay menos de MAX (definido en utils.h) asociaciones y 'clave'
  no tiene un valor asociado en 'map' agrega en 'map' la asociación
  (clave,valor). En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping asociar(nat clave, double valor, TMapping map){
  if((*map).asociaciones < MAX ){
    (*map).pares[(*map).asociaciones].natural = clave;
    (*map).pares[(*map).asociaciones].real = valor;
    (*map).asociaciones++;
  }
  return map;
}

/*
  Devuelve 'true' si y solo si 'clave' tiene un valor asociado en 'map'.
 */
bool esClave(nat clave, TMapping map){
  nat i = 0;
  bool encontrado = false;
  while( i < (*map).asociaciones && !encontrado ){
    if( (*map).pares[i].natural == clave ){
      encontrado = true;
    }
  }
  return encontrado;
}

/*
  Devuelve el valor que en 'map' está asociado a 'clave'.
  Precondición: esClave(clave, map)
 */
double valor(nat clave, TMapping map){
  assert(esClave(clave, map));
  nat i = 0;
  bool encontrado = false;
  while(!encontrado){
    if(  (*map).pares[i].natural == clave ){
      encontrado = true;
      return ( (*map).pares[i].real )
    }
    i++
  }
}

/*
  Si 'clave' tiene un valor asociado en 'map' remueve de `map' la asociación de
  'clave'. En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping desasociar(nat clave, TMapping map){
  nat i = 0;
  bool encontrado = false;
  while(!encontrado){
    if(  (*map).pares[i].natural == clave ){
      encontrado = true;
    }else{ 
      i++;
    }
  }
  for(i; i < (*map).asociaciones; i++){
    (*map).pares[i] = (*map).pares[i+1]; 
  }
  //TODO DELETE LA MEMORIA
  return map;
}

#endif
