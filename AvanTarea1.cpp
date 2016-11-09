#include <iostream>
#include <vector>
#include "sistema.h"
//#include <cassert>
using namespace std;




int main(int argc, char const *argv[])
{

 Persona k(2 ,"17921354-0");
    Sistema sis(10);
    Bus_semicama a("Semi-Cama", 1, "Santiago", "Rancagua", 10000, 10);
    Bus_saloncama b("Salon-Cama", 30, "Santiago", "Valparaiso", 8000, 11);
    Bus_premium c("Premium    ", 10, "Santiago", "Rancagua", 10000, 0);
    Bus_semicama d("Semi-Cama", 27, "La Serena", "Santiago", 8000, 20);
    Bus_semicama e("Semi-Cama", 43,"La Serena", "Santiago", 8000, 20);
    Bus_semicama f("Semi-Cama", 45, "Santiago", "Rancagua", 10000, 9);
    Bus_saloncama g("Salon-Cama", 30, "Santiago", "Valparaiso", 8000, 3);
    Bus_premium h("Premium    ", 20, "Santiago", "Rancagua", 10000, 2);
    Bus_semicama i("Semi-Cama", 43,"La Serena", "Santiago", 8000, 2);
    Bus_semicama j("Semi-Cama", 43,"La Serena", "Santiago", 8000, 22);
    Bus_premium ed("Premium    ", 20, "Santiago", "Rancagua", 10000, 2);
    Bus_saloncama fg("Salon-Cama", 30, "Santiago", "La Serena", 8000, 11);

    sis.agendarBus(a);
    sis.agendarBus(b);
    sis.agendarBus(c);
    sis.agendarBus(d);
    sis.agendarBus(e);
    sis.agendarBus(f);
    sis.agendarBus(g);
    sis.agendarBus(h);
    sis.agendarBus(i);
    sis.agendarBus(j);
    sis.agendarBus(ed);
    sis.agendarBus(fg);

    sis.listarAgenda();
    sis.listarBus(1);
    sis.listarBus(2);
    sis.listarBus(3);
    sis.venderPasaje(1, 4, k);
    sis.venderPasaje(2, 4, k);
    sis.venderPasaje(3, 4, k);
    sis.listarBus(1);
    sis.listarBus(2);
    sis.listarBus(3); 
    sis.listarBus(4);
    sis.listarBus(5);
    sis.listarBus(6);
    sis.listarBus(7);


    sis.estadisticas();
    sis.imprimir_info();
    cout << k.getplata_();

    return 0;
}