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



/*typedef char Queue;
enum whichQueue {NONE, OPEN, CLOSED};

typedef struct {double g, h;
unsigned long parent;
Queue whq;
} AStarStatus;*/


void ExitError(const char *miss, int errcode ){
    fprintf ("stderr, \nERROR: %s.\nStopping...\n\n", miss);
    exit(errcode);
}

int main (int argc,char *argv[]){

    FILE *fin, *ini;
    unsigned long nnodes=3472620UL;
    char name[257];
    node *nodes;
    if((nodes=(node *)malloc(nnodes*sizeof(node)) == NULL)) {
        ExitError("when allocating memory for the nodes vector", 5);}

printf ("fitxer %s \n", argv[1]);

/*if((ini=fopen(argv[1],"r"))==NULL){
        ExitError("the data file does not exist or cannot be opened", 11);
}
else{printf("file open\n");}

fread(nodes,sizeof(node),nnodes,ini);
printf ("tots els sucesors %d \n",nnodes);


fread(allsuccessors, sizeof(unsigned long),20,ini);

fclose(ini);

for(int i=0; i<nnodes; i++)if(nodes[i].nsucc){
            nodes[i].successors = allsuccessors; allsuccessors += nodes[i].nsucc;
            printf("nodes %d",nodes[i].successors);}

*/


/* llegir datos binaris

    if((ini=fopen(argv[1],"r"))==NULL){
        ExitError("the data file does not exist or cannot be opened", 11);
    }
    if (fread(&nnodes, sizeof(unsigned long),1,ini)+fread(&ntotsucc, sizeof(unsigned long),1,ini) !=2){
        ExitError("when allocating memory for the nodes vector", 13);
    }
    if ((allsuccessors=(unsigned long *) malloc(ntotnsucc*sizeof(unsigned long))) ==NULL){
        ExitError("when allocating memory for the edges vector", 15);
    }

    if (fread(nodes,sizeof(node),nnodes,ini)!=nnodes){
        ExExitError("when reading nodes from the binary data file", 17);
    }
    if(fread(allsuccessors, sizeof(unsigned long),ntotnsucc,ini)!=ntotnsucc){
        ExitError("when reading sucessors from the binary data file", 18);
    }
    fclose(ini);

    for(i=0; i<nnodes; i++)if(nodes[i].nsucc){
            nodes[i].successors = allsuccessors; allsuccessors += nodes[i].nsucc;
    }
*/
/*escriure binari*/

unsigned long ntotnsucc=0UL;
printf ("sucesors %f \n", ntotnsucc);

printf ("nombre de nodes %d \n", nnodes);

for(int i=0; i<nnodes; i++){
        printf ("iteracio %d \n", i);
        ntotnsucc += nodes[i].nsucc;
        printf ("sucesors %f \n", ntotnsucc);
}

strcpy(name,argv[2]);
strcpy(strrchr(name,'.'), "bin");

if((fin=fopen(name,"wb"))==NULL) {
        ExitError("the output binary data file cannot be opened", 31);
        printf ("ntotnsucc\n");}

if(fwrite(&nnodes, sizeof(unsigned long),1,fin)+fwrite(&ntotnsucc, sizeof(unsigned long),1,fin)!=2){
        ExitError("when initializing the output binary data file", 32);
        printf ("ntotnsucc\n");}

if(fwrite(nodes, sizeof(node),nnodes,fin) != nnodes){
        ExitError("when writing nodes to the output binary data file", 32);
        printf ("ntotnsucc\n");}

for (int i=0; i<nnodes; i++){
    if(nodes[i].nsucc){
        if(fwrite(nodes[i].successors,sizeof(unsigned long), nodes[i].nsucc,fin) != nodes[i].nsucc){
                ExitError("when writing edges to the output binary data file", 32);
                printf ("ntotnsucc\n");}
} }

fclose(fin);

}
