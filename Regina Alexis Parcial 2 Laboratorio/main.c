#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"
#include "input.h"

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados);

int main()
{
    char seguir='s';
    char auxOpcion[2];
    int opcion=0;
    int validado;

    // Definir lista de empleados
    ArrayList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados = al_newArrayList();

    while(seguir=='s')
    {
        menu();
        do
        {
            fflush(stdin);
            scanf("%s", auxOpcion);
            validado = validaNumero(auxOpcion);
        }
        while(validado == 0);

        opcion = atoi(auxOpcion);

        switch(opcion)
        {
            case 1:
            // Leer empleados de archivo data.csv
            if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
            {
                // Calcular sueldos
                printf("Calculando sueldos de empleados\n");
                al_map(listaEmpleados,em_calcularSueldo);
            }
            else
                printf("Error leyando empleados\n");
                break;
            case 2:
                // Generar archivo de salida
                if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
                {
                    printf("Archivo generado correctamente\n");
                }
                else
                    printf("Error generando archivo\n");
                break;
            case 3:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Opcion no valida.\n\n");
        }
    }
    return 0;
}

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
	FILE *f;
		f=fopen(fileName,"w");
		if(f == NULL)
		{
			return 0;
		}
	fwrite(listaEmpleados,sizeof(Empleado),listaEmpleados->len(),f);

	fclose(f);

    return 1;
}
