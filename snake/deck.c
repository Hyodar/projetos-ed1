// Deck.c
#include "deck.h"
 
Deck* createDeck () {
  return NULL;
}
 
Point getFront (Deck *d) {
    return d->p;
}
 
Point getRear (Deck *d) {
    Deck* aux = d;
 
    while(aux->next) aux = aux->next;
    return aux->p;
}
 
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
    Deck* newNode = (Deck*) malloc(sizeof(Deck));
 
    newNode->p = p;
    newNode->prev = NULL;
    newNode->next = d;
 
    if(d != NULL) {
          d->prev = newNode;
    }    
 
   field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/
 
    return newNode;
    // return deleteRear(newNode, field);
}
 
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   
    Deck* newNode = (Deck*) malloc(sizeof(Deck));
    Deck* aux = d;
   
    while(aux->next) aux = aux->next;
 
    newNode->p = p;
    newNode->prev = aux;
    newNode->next = NULL;
 
    if(aux != NULL) {
        aux->next = newNode;
    }
 
   field[p.x][p.y] = '*';
 
    return d;
}
 
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   
    Deck* aux = d->next;
    aux->prev = NULL;
 
    field[d->p.x][d->p.y] = ' ';
    free(d);
   
    return aux;
}
 
Deck* deleteRear (Deck *d, char field[][SIZE]) {
 
    Deck* aux = d;
 
    while(aux->next) aux = aux->next;
 
    aux->prev->next = NULL;
    field[aux->p.x][aux->p.y] = ' ';
    free(aux);
   
    return d;
}