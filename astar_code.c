#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
unsigned long id;          // Node identification
char *name;
double lat, lon;           // Node position
unsigned short nsucc;      // Number of node successors; i. e. length of successors
unsigned long *successors;
}
node;

node *Open, *Close;

typedef char Queue;
enum whichQueue {NONE, OPEN, CLOSED};

typedef struct {double g, h;
unsigned long parent;
Queue whq;
} AStarStatus;

void main(int argc, char* argv[]){

      Open    = (node*) malloc( (100)*sizeof(node) );
      Close   = (node*) malloc( (100)*sizeof(node) );

//while(*Open=!NULL){

}



