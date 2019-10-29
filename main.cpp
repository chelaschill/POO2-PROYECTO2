#include <iostream>
#include <fstream>
#include "container.hpp"
#include <list>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "sumarizar.h"
#include "ordenamientos.h"
#include <ctime>

using namespace std;

int main() {
    clock_t time = clock();
    double zeit;
    Container *cont = new Container("sample_data.csv");
    //cont->pruebasTrade_usd();
    cout<<endl;
    quickSort_Trade_usd(cont, 0, cont->getElements()->size()-1, "hola");
    cont->pruebasTrade_usd();
    cout<<endl;
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del quickSort es: " << zeit << "segundos" << endl;

    saveFile(cont->getElements(), "quickSort_Trade_usd.csv");

    heapSort_Trade_usd(cont, cont->getElements()->size());
    cont->pruebasTrade_usd();
    cout<<endl;
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del heapSort es: " << zeit << "segundos" << endl;

    saveFile(cont->getElements(), "heapSort_Trade_usd.csv");

    shellSort_Trade_usd(cont, 0, cont->getElements()->size()-1, "hola");
    cont->pruebasTrade_usd();
    cout<<endl;
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del shellSort es: " << zeit << "segundos" << endl;

    saveFile(cont->getElements(), "shellSort_Trade_usd.csv");

    mergeSort_Trade_usd(cont, 0, cont->getElements()->size()-1);
    cont->pruebasTrade_usd();
    cout<<endl;
    zeit = (clock() - time)/1000.0;
    cout << "El tiempo de ejecucion del mergeSort es: " << zeit << "segundos" << endl;

    saveFile(cont->getElements(), "mergeSort_Trade_usd.csv");

    criterio2(cont);
    //cont->pruebasTrade_usd();
    cout<<endl;

    criterio1(cont);
    //cont->pruebasTrade_usd();
    cout<<endl;


    //PARTE 2 BEBÉ



    return 0;
}


