/* 5330504 */

#include "../include/pila.h"
#include "../include/lista.h"
#include "../include/utils.h"
#include "../include/cola.h"
#include "../include/mapping.h"
#include <assert.h>
#include <stdio.h>

struct _rep_mapping {
  nat asociaciones;
  info_t pares[MAX];
};

/*
  Devuelve un elemento de tipo 'TMapping' vacío (sin elementos).
 */
TMapping crearMapping(){
  TMapping res = new _rep_mapping;
  (*res).asociaciones = 0;
  return res;
}

TMapping imprimirMapping(TMapping map){
  nat tope = (*map).asociaciones;
  for( nat i = 0; i < tope; i++){
    printf("\n");
    printf("clave: ");
    printf("%d",(*map).pares[i].natural);
    printf("\n");
    printf("valor: ");
    printf("%f",(*map).pares[i].real);
    printf("\n");
    printf("asociaciones: ");
    printf("%d",(*map).asociaciones);
    printf("\n");
  }
  /*for(nat i = 0; i < 10; i++){
    printf("%d",(*map).pares[i].natural);
    printf("\n");
  }*/
  return map;
}

/*
  Si en 'map' hay menos de MAX (definido en utils.h) asociaciones y 'clave'
  no tiene un valor asociado en 'map' agrega en 'map' la asociación
  (clave,valor). En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping asociar(nat clave, double valor, TMapping map){
  nat pos = (*map).asociaciones;
  if( ((*map).asociaciones < MAX) && (!esClave(clave, map))){
    (*map).pares[pos].natural = clave;
    (*map).pares[pos].real = valor;
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
    }else{
      i++;
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
    }else{
    i++;
    }
  }
  return ( (*map).pares[i].real );
}

/*
  Si 'clave' tiene un valor asociado en 'map' remueve de `map' la asociación de
  'clave'. En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping desasociar(nat clave, TMapping map){
  nat i = 0;
  bool encontrado = false;
  while( i < (*map).asociaciones && !encontrado){
    if(  (*map).pares[i].natural == clave ){
      encontrado = true;
    }else{ 
      i++;
    }
  }
  if(encontrado){
    for(nat j = i; j < (*map).asociaciones; j++){
      (*map).pares[j] = (*map).pares[j+1]; 
    }
    (*map).asociaciones--;
  }
  return map;
}

