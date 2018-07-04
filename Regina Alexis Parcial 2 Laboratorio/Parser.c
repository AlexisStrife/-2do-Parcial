#include <stdio.h>
#include "Empleado.h"
#include "ArrayList.h"

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int cant, i=0;
	FILE *f;
	Empleado* returnAux;
	if(f=fopen(fileName, "r")==NULL)
	{
	    printf("No se pudo abrir el archivo");
	    return 0;
	}
	while(!feof(f))
    {
        cant=fread(returnAux,sizeof(Empleado),1,f);
        if(cant!=1)
        {
            if(feof(f))
            break;
        else
        {
            printf("No leyo el ultimo registro\n");
            break;
        }
        }
        listaEmpleados->add(listaEmpleados, returnAux);
    }
	fclose(f);
    return 1; // OK
}

