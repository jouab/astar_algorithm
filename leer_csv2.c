
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib_Astar.h"
#include <wchar.h>

char temporal[9858];

char ***valores = NULL;	//Valores va a contener todos los valores leidos
int *campos_por_linea = NULL;

char *pivote = NULL;
int lineas = 0;
int campos = 0;
int longitud = 0;
int i,j;



int main(int argc,char *argv[])	{
	FILE *archivo = NULL;
	archivo = fopen(argv[1],"r");

	unsigned long nnodes=3472620UL;
	node *nodes;
    if((nodes=(node *)malloc(nnodes*sizeof(node)) == NULL)) {
            ExitError("when allocating memory for the nodes vector", 5);}

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

		printf("Mostrando valores leidos\n");
		i = 0;

		while(i < lineas)	{
			j = 0;
			printf("Linea %i\n",i+1);
            printf("campos por linea %d\n",campos_por_linea[i]);
            while(j<campos_por_linea[i])	{	// Aqui es donde se procesarian los campos para transformarlos a valores enteres flotantes etc....

                /*printf("Campo %i: %s\n",j+1,valores[i][j]);*/
                printf("Campo %i: %s\n",j+1,valores[i][1]);
                printf("Campo %i: %s\n",j+1,valores[i][9]);
                printf("Campo %i: %s\n",j+1,valores[i][10]);

                nodes[i].id=atol(valores[i][1]);
                nodes[i].lat=atof(valores[i][9]);
                nodes[i].lon=atof(valores[i][10]);

                j++;
            }

            printf("ID number: %d\n",nodes[i].id);
            printf("Ilatitud: %f\n",nodes[i].lat);
            printf("longitud: %f\n",nodes[i].lon);
			i++;

		}
	}
	else	{
		printf("Error leyendo el archivo o fin de nodos\n");
	}
}
