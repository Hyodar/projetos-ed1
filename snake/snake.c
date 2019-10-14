#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "deck.h"
 
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
 
typedef struct {
    Point p;
    int isEaten;
} Food;
 
int kbhit(void) {
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF) {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}
 
void initialize_field (char field[SIZE][SIZE]) {
   int i, j;
   for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
         field[i][j] = ' ';
      }
   }
}
 
void print_field (char field[SIZE][SIZE]) {
   int i, j;
   printf("  ");
   for (i = 0; i < SIZE; i++) {
      printf(" #");
   }
   printf("\n");
   for (i = 0; i < SIZE; i++) {
      printf(" # ");
      for (j = 0; j < SIZE; j++) {
         printf("%c ", field[i][j]);
      }
      printf("#\n");
   }
   printf("  ");
   for (i = 0; i < SIZE; i++) {
      printf(" #");
   }
   printf("\n");
}
 
void placeFood(Food* food, char field[SIZE][SIZE]) {
   if(food->isEaten) {
      food->p = (Point) {rand() % (SIZE-2), rand() % (SIZE-2)};
      food->isEaten = 0;
   }
   
   field[food->p.x][food->p.y] = '@';
}

Food* createFood(char field[SIZE][SIZE]) {
    Food* food = (Food*) malloc(sizeof(Food));
    
    food->p = (Point) {rand() % (SIZE-2), rand() % (SIZE-2)};
    food->isEaten = 0;
    
    field[food->p.x][food->p.y] = '@';
    
    return food;
}
 
Point getHead(Deck* d, int reversed) {
   return (reversed)? getFront(d) : getRear(d);
}
 
void eatFood(Deck* snake, int reversed, Food* food, char field[SIZE][SIZE]) {
   Point head = getHead(snake, reversed);
   if(head.x == food->p.x && head.y == food->p.y) {
      food->isEaten = 1;
      field[food->p.x][food->p.y] = ' ';
   }
}
 
int finish (Deck *d, Point head) {
   if (head.y < 1 || head.y > SIZE-2 || head.x < 1 || head.x > SIZE-1) {
      return 1;                                                        
   } else {
      return 0;                                                        
   }
}
 
int main () {
 
   int center = SIZE/2;
   int snake_size = 5;
 
   char field[SIZE][SIZE];
   
   initialize_field (field);
   Deck *d = createDeck ();
 
   int i;
   for (i = center-snake_size/2; i <= center+snake_size/2; i++) {
      d = insertFront (d, (Point){center, i}, field);
   }
 
   char pressionou_prv = ' ';
   char pressionou_act = LEFT;
   int reverse = 0; /*variável para inverter cabeça com cauda (e vice-versa)*/
 
   Food* food = createFood(field);
 
   while (!finish(d, getHead(d, reverse))) {
     while((!kbhit()) && (!finish(d, getHead(d, reverse)))) {
       if (reverse) {
           Point p = getFront (d);
           if (pressionou_act == UP) { d = insertFront (d, (Point){p.x-1, p.y}, field); }
           else if (pressionou_act == DOWN) { d = insertFront (d, (Point){p.x+1, p.y}, field); }
           else if (pressionou_act == LEFT) { d = insertFront (d, (Point){p.x, p.y-1}, field); }
           else { d = insertFront (d, (Point){p.x, p.y+1}, field); }
           d = deleteRear (d, field);
        }
        else {
           Point p = getRear (d);
           if (pressionou_act == UP) { d = insertRear (d, (Point){p.x-1, p.y}, field); }
           else if (pressionou_act == DOWN) { d = insertRear (d, (Point){p.x+1, p.y}, field); }
           else if (pressionou_act == LEFT) { d = insertRear (d, (Point){p.x, p.y-1}, field); }
           else { d = insertRear (d, (Point){p.x, p.y+1}, field); }
           d = deleteFront (d, field);
        }
        eatFood(d, reverse, food, field);
 
        print_field (field);
        placeFood(food, field);
        usleep(250000);
        system("clear");
     }
     if (!finish(d, getHead(d, reverse))) {
        /*Cada vez que uma tecla é pressionada o controle executa esse trecho: */
        pressionou_prv = pressionou_act;
        pressionou_act = getchar();
        if ((pressionou_act ==  DOWN) && (pressionou_prv ==  UP)) { reverse = !reverse; }
        else if ((pressionou_act ==  UP) && (pressionou_prv ==  DOWN)) { reverse = !reverse; }
        else if ((pressionou_act ==  LEFT) && (pressionou_prv ==  RIGHT)) { reverse = !reverse; }
        else if ((pressionou_act ==  RIGHT) && (pressionou_prv ==  LEFT)) { reverse = !reverse; }
   
        eatFood(d, reverse, food, field);
     }
   }
   
   printf ("#### Perdeu :(  \n");
   return 0;
}