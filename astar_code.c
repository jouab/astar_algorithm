#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

float mini(float a,float b){
if(a>b){return b;}
else{return a;}
      /* #define min(a, b) (((a) < (b)) ? (a) : (b))*/
}

float h(node *in){
float R=6371000;

float a, c, d;
float diflat, diflong;
//diflat= latitud node en el que estem - latutud node final
//diflong= longitud node en el que estem - longitud node final

a= sin((in.lat-/*latutud node final*/)/2)*sin((in.lat-/*latutud node final*/)/2)+cos(1(in.lat))*cos(1/*latutud node final*/)*sin((in.lon-/*longitud node final*/)/2)*sin((in.lon-/*longitud node final*/)/2);
c= 2*asin(min(1,sqrt(a)));
d=R*c;

return d;
}

float distancia(node *in){


}

void main(int argc, char* argv[]){

      Open    = (node*) malloc( (100)*sizeof(node) );
      Close   = (node*) malloc( (100)*sizeof(node) );

//while(*Open=!NULL){

}



