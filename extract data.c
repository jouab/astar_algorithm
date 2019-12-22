
typedef struct {
unsigned long id;          // Node identification
char *name;
double lat, lon;           // Node position
unsigned short nsucc;      // Number of node successors; i. e. length of successors
unsigned long *successors;
}
node;



typedef char Queue;
enum whichQueue {NONE, OPEN, CLOSED};

typedef struct {double g, h;
unsigned long parent;
Queue whq;
} AStarStatus;


void ExitError(const char *miss, int errcode )
{
    fprintf ("stderr, \nERROR: %s.\nStopping...\n\n", miss);
    exit(errcode);
}

int main (int argc,char*argv[]){
    FILE *fin;
    unsigned long nnodes=23895681UL
    char name[257];
    node *nodes;

    if((nodes=(node *) malloc(nnodes*sizeof(node)) == NULL)
        ExitError("when allocating memory for the nodes vector", 5);
}

/∗Computing the total number of successors∗/
unsigned long ntotnsucc=0UL;
for (i=0;i<nnodes,i++) ntotnsucc += nodes[i].nsucc

strcpy(name,argv[1]); strcpy(strrchr(name,'.'), "bin")
if ((fin=fopen(name,"wb"))==NULL)
        ExitError("the output binary data file cannot be opened", 31);

if  (fwrite(&nnodes, sizeof(unsigned long),1,fin)+fwrite(&ntotnsucc, sizeof(unsigned long),1,fin)!=2)
        ExitError("when initializing the output binary data file", 32);

if(fwrite(nodes, sizeof(node),nnodes,fin) != nnodes)
        ExitError("when writing nodes to the output binary data file", 32);

for (i=0; i<nnodes; i++) if(nodes[i].nsucc){
        if(fwrite(nodes[i].successors,sizeof(unsigned long), nodes[i].nsucc,fin) != nodes[i].nsucc)
                ExitError("when writing edges to the output binary data file", 32);
}

fclose(fin);