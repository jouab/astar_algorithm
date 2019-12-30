#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib_Astar.h"

node *Vector;

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
float w(node node[],unsigned long i, unsigned long j){
float w;
w= sqrt(pow((node[i].lat-node[j].lat),2)+pow((node[i].lon-node[j].lon),2));
return w;
}

void main(int argc, char* argv[]){

map OPENlist, CLOSEDlist;
InicialitzaLlista (&OPENlist);
InicialitzaLlista (&CLOSEDlist);

unsigned long Index_primer, Index_ultim;
Index_primer=binarySearch(Vector,8670491,842755875,771979683);
Index_ultim=binarySearch(Vector,8670491,842755875,429854583);
InsereixNodeInicial(&OPENlist);
node_map *primer_node;
primer_node =InicideLlista(OPENlist);
(primer_node->f)=h(Vector,Index_primer);/*funcio que calcula f per al node inicial*/
(primer_node->h)=h(Vector,Index_primer);
(primer_node->g)=0;
(primer_node->id)=771979683;
(primer_node->parentid)=NULL;

node_map *node_suc, *node_cu;

while(EsPlena(OPENlist)){

node_cu = InicideLlista(OPENlist);
unsigned long index_curr;
index_curr = binarySearch(Vector,8670491,842755875,(node_cu->id));
    if((node_cu->id) == 429854583){
    printf(("s'ha arribat al desti!!"));
    break;
    }
node_map nod;
//for (nod=OPENlist.start; nod<OPENlist.end; nod=nod->seg){

unsigned long index_succ=binarySearch(Vector,8670491,842755875,(node_suc->id));
double successor_current_cost=(node_cu->g)+w(Vector,index_curr,index_succ);
    if(CercaSequencial_id(node_suc->id, OPENlist)!=NULL){
        if((node_suc->g)<=successor_current_cost){
            continue;
             }
        }
    else if(CercaSequencial_id(node_suc->id, CLOSEDlist)!=NULL){
        if((node_suc->g)<=successor_current_cost){
            InsereixNodeFinal(&OPENlist);
            node_map *node_suop = FinaldeLlista(OPENlist);
            (node_suop->f)=(node_suc->f)/*funcio que calcula f per al node inicial*/ ,
            (node_suop->id)=(node_suc->id);
            (node_suop->parentid)=(node_suc->parentid);
            (node_suop->g)=(node_suc->g);
            (node_suop->h)=(node_suc->h);
            BorraNode(node_suc, &CLOSEDlist);

            continue;

            //Move node_successor from the CLOSED list to the OPEN list
             }
        }
    else{//Add node to the open list
            InsereixNodeFinal(&OPENlist);
            node_suc =FinaldeLlista(OPENlist);
            (node_suc->id)=index_succ;
            (node_suc->h)=h(Vector,index_succ);
        }
    (node_suc->parentid)=(node_cu->id);
    (node_suc->g)=successor_current_cost;
    (node_suc->f)=(node_suc->g)+(node_suc->h);

    //}
    //Add current node to the closed list,
    if(EsBuida(CLOSEDlist)){
        InsereixNodeInicial(&CLOSEDlist);
        node_map *node_cuclos = InicideLlista(CLOSEDlist);
        (node_cuclos->h)=(node_cu->h);
        (node_cuclos->g)=(node_cu->g);
        (node_cuclos->f)=(node_cu->f)/*funcio que calcula f per al node inicial*/;
        (node_cuclos->id)=(node_cu->id);
        (node_cuclos->parentid)=(node_cu->parentid);
        }
    else{InsereixNodeFinal(&CLOSEDlist);
        node_map *node_cuclos = FinaldeLlista(CLOSEDlist);
        (node_cuclos->h)=(node_cu->h);
        (node_cuclos->g)=(node_cu->g);
        (node_cuclos->f)=(node_cu->f)/*funcio que calcula f per al node inicial*/;
        (node_cuclos->id)=(node_cu->id);
        (node_cuclos->parentid)=(node_cu->parentid);
    }
    // delite the node from the open list
    BorraNode(node_cu, &OPENlist);
    // and order the open list.
    int err=OrdenaUsantIndex(&OPENlist, Comparaf);
    if(err){printf("\nError en ordenar la llista");}
}

if((node_suc->id) != 429854583){
    printf("\nError, La llista OPEN esta buida");
}
}
