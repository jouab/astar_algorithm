
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


void ExitError(char miss, int errcode )
{
    fprintf ("stderr, \nERROR: %s.\nStopping...\n\n", miss);
    exit(errcode);
}

int main (int argc,char*argv[], int fin, int NULL)
{
    //FILE *fin;
    unsigned long nnodes;
    node *nodes;

    if((fin = fopen (argv[1], "r")) == NULL)
        ExitError(1, 11);
}


