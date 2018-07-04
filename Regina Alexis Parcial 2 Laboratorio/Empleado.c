#include "Empleado.h"

void em_calcularSueldo(void* p)
{
    printf("fasd");
    getch();
    if(((Empleado*)p)->horasTrabajadas <= 176)
    {
        ((Empleado*)p)->sueldo = ((Empleado*)p)->horasTrabajadas*180;
    }
    if(((Empleado*)p)->horasTrabajadas > 176 && ((Empleado*)p)->horasTrabajadas < 208)
    {
        ((Empleado*)p)->sueldo = ((Empleado*)p)->horasTrabajadas*270;
    }
    if(((Empleado*)p)->horasTrabajadas > 209 && ((Empleado*)p)->horasTrabajadas < 240)
    {
        ((Empleado*)p)->sueldo = ((Empleado*)p)->horasTrabajadas*360;
    }
}
