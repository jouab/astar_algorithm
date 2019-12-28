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

float h(node nod[], unsigned long i){
float R=6371000, a, c, d;
float diflat, diflong;
diflat= nod[i].lat - nod[i].lat;
diflong= nod[i].lon - nod[i].lon;

a= sin((diflat)/2)*sin((diflat)/2)+cos((nod[i].lat))*cos(nod[i].lat)*sin((diflong)/2)*sin((diflong)/2);
c= 2*asin(mini(1,sqrt(a)));
d=R*c;

return d;
}
float g(node node[],unsigned long i, unsigned long j){
float g;
g= sqrt(pow((node[i].lat-node[j].lat),2)+pow((node[i].lon-node[j].lon),2));
return g;
}

float f(node node[], unsigned long i, unsigned long j){
float f;
f=g(node,i,j)+h(node, i);
return f;
}

void main(int argc, char* argv[]){

map OPENlist;
InicialitzaLlista (&OPENlist);

      Open    = (node*) malloc( (100)*sizeof(node) );
      Close   = (node*) malloc( (100)*sizeof(node) );

unsigned long Index_primer, Index_ultim;
Index_primer=binarySearch(Vector,8670491,842755875,771979683);
Index_ultim=binarySearch(Vector,8670491,842755875,429854583);
InsereixNodeInicial(&OPENlist);
node_map *primer_node;
primer_node =InicideLlista(OPENlist);
(primer_node->f)=h(Vector,Index_primer)/*funcio que calcula f per al node inicial*/ ,
(primer_node->id)=771979683;
//(primer_node->lat)=1/*punter a la latitud del node inicial*/,
//(primer_node->lon)=1/*punter a la longitud edl node inicial*/,
//(primer_node->name)=1/*punter que va al nom del node inicial*/;

while(EsPlena(OPENlist)){
node_map *node_cu;
node_cu = InicideLlista(OPENlist);
unsigned long index_curr;
index_curr = binarySearch(Vector,8670491,842755875,(node_cu->id));
if((node_cu->id) == 429854583){
    printf(("s'ha arribat al desti!!"));
    break;
}
//for(i=0;i<Vector.nsucc;i++){
//node_map node_suc;
//node
//
//}


}


}
