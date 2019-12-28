#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib_Astar.h"

node *Vector, *Open, *Close;

float mini(float a,float b){
if(a>b){return b;}
else{return a;}
      /* #define min(a, b) (((a) < (b)) ? (a) : (b))*/
}
/*Per al cas de catalunya*/
//int Index_ultim=binarySearch(Vector.id, 8670491, 842755875, 429854583);

float h(node_map nod, int i){
float R=6371000, a, c, d;
float diflat, diflong;
diflat= nod.lat - nod.lat;
diflong= nod.lon - nod.lon;

a= sin((diflat)/2)*sin((diflat)/2)+cos((nod.lat))*cos(nod.lat)*sin((diflong)/2)*sin((diflong)/2);
c= 2*asin(mini(1,sqrt(a)));
d=R*c;

return d;
}

float distancia(node *in){


}

void main(int argc, char* argv[]){

map OPENlist;
InicialitzaLlista (&OPENlist);

      Open    = (node*) malloc( (100)*sizeof(node) );
      Close   = (node*) malloc( (100)*sizeof(node) );

InsereixNodeInicial(&OPENlist);
node_map *primer_node;
primer_node =InicideLlista(OPENlist);
(primer_node->f)=1/*funcio que calcula f per al node inicial*/ ,
(primer_node->id)=771979683,
(primer_node->lat)=1/*punter a la latitud del node inicial*/,
(primer_node->lon)=1/*punter a la longitud edl node inicial*/,
(primer_node->name)=1/*punter que va al nom del node inicial*/;


while(EsPlena(OPENlist)){
printf("bucle");
}


}
