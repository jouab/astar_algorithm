
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib_Astar.h"

char temporal[9858];

char ***valores = NULL;	//Valores va a contener todos los valores leidos
int *campos_por_linea = NULL;

char *pivote = NULL;
int lineas = 0;
int campos = 0;
int longitud = 0;
int i,j,k;
unsigned long id;
unsigned long posicio;
int nsucc_previ;

int main(int argc,char *argv[])	{
	FILE *archivo = NULL;
	archivo = fopen(argv[1],"r");

	unsigned long nnodes=3472620UL;
	node *nodes;
    /*if((nodes=(node *)malloc(nnodes*sizeof(node)) == NULL)) {
            ExitError("when allocating memory for the nodes vector", 5);}*/

    nodes=(node *)malloc(nnodes*sizeof(node));
	if(archivo != NULL)	{
		do	{
			memset(temporal,0,9858);
			fgets(temporal,9858,archivo);
			lineas++;
			valores = realloc(valores,lineas*sizeof(char*));
			campos_por_linea = realloc(campos_por_linea,lineas*sizeof(int));
			valores[lineas-1] = NULL;
			pivote = strtok(temporal,"|");
			campos = 0;
			while (pivote != NULL)	{
				campos++;
				valores[lineas-1] = realloc(valores[lineas-1],sizeof(char*)*campos);
				longitud = strlen(pivote);
				valores[lineas-1][campos -1] = calloc(longitud+1,sizeof(char));
				strncpy(valores[lineas-1][campos -1],pivote,longitud);
				pivote = strtok(NULL, "|");
			}
			campos_por_linea[lineas-1] = campos;
		}while(feof(archivo) == 0);
		fclose(archivo);

		/*printf("Mostrando valores leidos\n");*/
		i = 0;
        int numero_nodes=0;
		while(i < lineas)	{
			j = 0;
            printf("Linea %i\n",i+1);
			if (strcmp("node",valores[i][0])==0){
                while(j<campos_por_linea[i])	{	// Aqui es donde se procesarian los campos para transformarlos a valores enteres flotantes etc....
                    nodes[i].id=atol(valores[i][1]);
                    nodes[i].lat=atof(valores[i][9]);
                    nodes[i].lon=atof(valores[i][10]);
                    numero_nodes=i;
                    j++;
                }
			}
            else if (strcmp("way",valores[i][0])==0){
                    j=9;
                    /*printf("entre als way\n");*/
                while(j<campos_por_linea[i])	{

                    id=atol(valores[i][j]);
                    if (posicio=binarySearch(nodes,0,3472619, atol(valores[i][j]))!= -1){
                        posicio=binarySearch(nodes,0,3472619, atol(valores[i][j]));
                        printf("id: %d\n campos por linea %d\n linea: %d\n id dels ways: %s\n",id,campos_por_linea[i],i,valores[i][j]);
                        printf("i: %d \n", i);
                        printf("posicio cerca: %d\n", binarySearch(nodes,0,3472619,atol(valores[i][j])));
                        printf("posicio guardada: %d\n", posicio);
                            nsucc_previ=nodes[posicio].nsucc;
                            nodes[posicio].nsucc=nodes[posicio].nsucc+campos_por_linea[i]-8-1;
                           /* printf("nombre de nodes succesors: %d\n",nodes[posicio].nsucc);*/
                        printf("nsucc: %d\n \n",nodes[posicio].nsucc);
                            nodes[posicio].successors=realloc(nodes[posicio].successors,sizeof(unsigned long *)*nodes[posicio].nsucc);
                        printf("realloc\n");

                        for (k=0;k<nodes[posicio].nsucc;k++){

                                if (atol(valores[i][k+9]) != nodes[posicio].id && binarySearch(nodes,0,3472619,atol(valores[i][k+9])) !=-1){
                                    /*printf("posicio dins del for: %d\n", posicio);*/
                                    printf("lina: %d\n valor buscat: %d\n",i,atol(valores[i][k+9]));
                                    printf("valor buscat string: %s\n",valores[i][k+9]);
                                    printf("contador i: %d\n", i);
                                    printf("contador j: %d\n", j);
                                    printf("contador k: %d\n", k);
                                    printf("sucesors previs: %d\n",nsucc_previ);
                                    printf("busqueda de la posicio del sucesor: %d\n",binarySearch(nodes,0,3472619,atol(valores[i][k+9])));
                                    printf("psicio propia: %d\n\n",posicio);
                                    nodes[posicio].successors[k]=binarySearch(nodes,0,3472619,atol(valores[i][k+9]));

                                   /*printf("id: succesor desres de lassginacio: %d\n \n \n",nodes[posicio].successors[k]);*/
                                }
                        }
                        for (k=0;k<nodes[posicio].nsucc;k++){
                                printf("id: succesor desres de lassginacio: %d\n \n \n",nodes[posicio].successors[k]);
                        }
                    }
                    printf("seguent nodes\n");
                    j++;
                }printf("seguent linea\n");
            }
			i++;

		}
		printf("1 %f\n",nodes[601].nsucc);
		printf("2 %f\n",nodes[602].nsucc);
		printf("3 %f\n",nodes[603].nsucc);
		printf("4 %f\n",nodes[604].nsucc);
		printf("5 %f\n",nodes[605].nsucc);
		printf("6 %f\n",nodes[606].nsucc);
		printf("7 %f\n",nodes[607].nsucc);

		printf("1 %f\n",nodes[601].lat);
		printf("2 %f\n",nodes[602].lat);
		printf("3 %f\n",nodes[603].lat);
		printf("4 %f\n",nodes[604].lat);
		printf("5 %f\n",nodes[605].lat);
		printf("6 %f\n",nodes[606].lat);
		printf("7 %f\n",nodes[607].lat);
        printf("NODES CALCULATS CORRECTAMENT");
	}
	else	{
		printf("Error leyendo el archivo o fin de nodos\n");
	}

}
