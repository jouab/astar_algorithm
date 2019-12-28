#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
unsigned long id;          // Node identification
char *name;
double lat, lon;           // Node position
unsigned short nsucc;      // Number of node successors; i. e. length of successors
unsigned long *successors;
}node;

typedef struct NODE
{ unsigned long id;
double f;
char *name;
double lat, lon;
struct NODE *prev, *seg;
} node_map;


typedef char Queue;
enum whichQueue {NONE, OPEN, CLOSED};

typedef struct {double g, h;
unsigned long parent;
Queue whq;
} AStarStatus;

//Estruructura del contenidor, mapa
typedef struct
{ node_map *start;
node_map *end;
unsigned long nnodes;
node_map **index;
} map;

//Index de Funcions de una Linkedlist
//-Inicializar llista (s'ha de fer al principi del programa sempre)
//-Funcions per moures en els nodes del mapa:-anar al primer node
//                                           -anar al ultim node
//                                           -anar al seguent node
//                                           -anar al anterior node
//                                           -Saltar N posicions desde un node
//                                           -Saltar a un node determinat
//                                           -Saltar a la posició Nesima del la estructura
//-Cerca sequencial de un id determinat (CercaSequencial_id)
//-Funcions de informació: -Saver si la llista sequencial esta buida (EsBuida)
//                        -Saver la llargaria de la llista sequencial (Llargaria)
//                        -Pertany un node a la llista (pertany)
//-Funció per borrar un node (BorraNode)
//-Funcions per incertar un node:-Incertar node en el principi
//                               -Incertar node al final
//-Funció de cerca binaria.
//-Funció de comparar.
//-Funció de crear index.
//-Funció de ordenar una estructura depenent dels index.


//Inicizlitzar llista
void InicialitzaLlista (map * llista) {
llista->start = llista->end = NULL;
llista->nnodes = 0UL;
llista->index=NULL;
}

//Anar al node inicial, final, seguent i anterior de la Linkedlist us en pg 32 de Tipus Abstractes de Dades Lineals
node_map * InicideLlista(map llista){ return llista.start; }
node_map * FinaldeLlista(map llista){ return llista.end; }
node_map * seguent (node_map * nod_ori) {return ((nod_ori) ? nod_ori->seg : NULL);}
node_map * anterior (node_map * nod_ori) {return ((nod_ori) ? nod_ori->prev : NULL);}

//Saltar N posicions avant o atras pg 35 de Tipus Abstractes de Dades Lineals.
node_map * SaltaN (const long N, node_map * nod_ori) {
register long n; register node_map * curr;
if (N >= 0L) {for (n = 0L, curr = nod_ori; n < N && curr;n++, curr = curr->seg);}
else if (N < 0L) {for (n = 0L, curr = nod_ori; n > N && curr;n--, curr = curr->prev);}
return curr;
}

//Saltar a, necesari per a la funcio Nth
node_map * DeSaltaA (unsigned ori, node_map * nod_ori, unsigned fi) {
register unsigned n; register node_map *curr;
if (fi < ori)
for (n=ori, curr=nod_ori; n > fi; n--, curr=curr->prev);
else
for (n=ori, curr=nod_ori; n < fi; n++, curr=curr->seg);
return curr;
}


//Anar al element Nessim de la llista pg 41 de Tipus Abstractes de Dades Lineals.
node_map * Nth (map llista, register unsigned N) {
if (N > llista.nnodes / 2) {
if (N >= llista.nnodes) return NULL;
return DeSaltaA (llista.nnodes-1, llista.end, N);}
return DeSaltaA (0U, llista.start, N);}

//Cerca sequencial de un parametrede de un id
node_map * CercaSequencial_id (const char *id,
map llista) {
register node_map *nod; unsigned idlen = strlen(id);
for (nod=llista.start; nod; nod=nod->seg)
if (strncmp(id, nod->id, idlen) == 0)
return nod;
return NULL;
}

//Esta la llista buida?? pg 42
bool EsBuida (map llista) {return (llista.start == NULL);}
//Hi ha algo a la llista??
bool EsPlena (map llista) {return (llista.start != NULL);}

//Quina es la largada?? pg 42
unsigned Llargada (map llista) {return (llista.nnodes);}

//pertany un node a la llista??
bool pertany (node_map * node, map llista) {
register node_map *nod;
if (node == NULL || EsBuida(llista)) return false;
for (nod=llista.start; nod; nod=nod->seg)
if (nod == node) return true;
return false;
}

//Borrar un node de la llista pg54 per a veure el us que esta funcio
void BorraNode (node_map * node_a_borrar, map * llista) {
if (!pertany (node_a_borrar, *llista)) return;
if (Llargada (*llista) == 1U) {
free (llista->start); InicialitzaLlista (llista); return;
}
if (node_a_borrar == llista->start) {
llista->start = node_a_borrar->seg;
(llista->start)->prev = NULL;
} else if (node_a_borrar == llista->end) {
llista->end = node_a_borrar->prev;
(llista->end)->seg = NULL;
} else {
(node_a_borrar->seg)->prev = node_a_borrar->prev;
(node_a_borrar->prev)->seg = node_a_borrar->seg;
}
free (node_a_borrar);
llista->nnodes--;
}

//Incertar nodes pg 66 per utilitzacio

bool push (map * llista) { node_map *aux;
if ((aux = (node_map *) malloc (sizeof (node_map))) == NULL) return false;
aux->prev = NULL;
aux->seg = llista->start;
if (llista->start == NULL) llista->end = aux;
else (llista->start)->prev = aux;
llista->start = aux;
llista->nnodes++;
return true;
}

bool InsereixNodeInicial (map * llista) { return push (llista); }

bool InsereixNodeFinal (map * llista) { node_map *aux;
if ((aux = (node_map *) malloc (sizeof (node_map))) == NULL) return false;
aux->seg = NULL;
aux->prev = llista->end;
if (llista->end == NULL) llista->start = aux;
else (llista->end)->seg = aux;
llista->end = aux;
llista->nnodes++;
return true;
}
//espot tambe insertar entre qualsevol node pg 63, pero en el astar de moment creem que no es nesecari


//Funcio de cerca binaria, utilitzacio en la pg 82.
node_map * CercaBinaria_id (const char *id,
map llista) {
register unsigned start = 0UL, afterend = llista.nnodes, middle_ant = 0U, middle;
register node_map *middle_id = llista.start;
register unsigned short idlen = strlen (id);
register int rescom;
while (afterend > start) {
middle = start + ((afterend - start - 1) >> 1);
middle_id = DeSaltaA (middle_ant, middle_id, middle);
middle_ant = middle;
rescom = strncmp (id, middle_id->id, idlen);
if (rescom == 0) return middle_id;
else if (rescom > 0) start = middle + 1;
else afterend = middle;
}
return NULL;
}

//Funcio que compara entre dos id de dos nodes, si el id de a>b,return<0, si id a<b, return>0, si a=b return=0.
//Potser tindriem que canviar id al valor de la funcio f per a ordenarlos amb aquest altre criteri.
int ComparaID (const void *a, const void *b) {
return -strcmp ( (*((node_map **) a))->id,
(*((node_map **) b))->id );
}

//Funcio crear index: pg 91 Tipus Abstractes de Dades Lineals
void CreaIndex (map * list, int (*compare) (const void *, const void *)){
register unsigned long i;
if (list->nnodes < 2 ) {return;}
list->index = (node_map **) malloc(list->nnodes*sizeof(node_map *));
if (list->index == NULL) {return;}
for ( list->index[0]=list->start, i=1;i < list->nnodes;list->index[i]=list->index[i-1]->seg, i++);
qsort(list->index, list->nnodes, sizeof(node_map *), compare);}

//Ordenacio de la estructura pg 95 per veure com s'usa aquesta funció, es una alternetiva a usar la funcio crear index
int OrdenaUsantIndex (map * list, int (*compare) (const void *, const void *))
{ node_map **ptr_list; register unsigned long i;
if (!list || !list->start ) return 1;
if (list->nnodes == 1 ) return 0;
ptr_list = (node_map **) malloc (list->nnodes * sizeof (node_map *));
if (ptr_list == NULL) return 3;
for(ptr_list[0]=list->start, i=1; i < list->nnodes;
ptr_list[i]=ptr_list[i-1]->seg, i++ ) ;
qsort(ptr_list, list->nnodes, sizeof(node_map *), compare);
list->start = ptr_list[0]; list->end=ptr_list[list->nnodes-1];
(list->start)->prev = (list->end)->seg = NULL;
for(i=1 ; i < list->nnodes ; i++) {
ptr_list[i-1]->seg = ptr_list[i]; ptr_list[i]->prev = ptr_list[i-1];
}
free(ptr_list);
return 0;
}
