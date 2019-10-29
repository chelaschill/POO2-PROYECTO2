#ifndef PROYECTO_2_CONTAINER_HPP
#define PROYECTO_2_CONTAINER_HPP

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include<forward_list>
#include <fstream>
#include <sstream>

using namespace std;

#include "map.h"
#include "deserializador.h"


class Container {
protected:
    vector <Map*> *elements;
    //cambiar a generico
    DeserializadorMap deserializador;
public:
    Container(string nombreArhivo){
        elements = new vector<Map*>();
        fstream* archivo = new fstream(nombreArhivo, ios_base::in);
        string linea;
        if (!archivo->is_open()){
            cout << "Archivo fallo en leer"<< std::endl;
        }
        else{
            getline(*archivo,linea); //Para la cabecera
            while (getline(*archivo,linea)){
                    Map* element = deserializador.deserializar(linea, ',');
                    elements->push_back(element);
            }
            archivo->close();
        }
        delete archivo;
    }

    void pruebas (){
        for (Map *element: *elements)
        {
            cout<<element->getCountry_or_area()<<","<<element->getYear()<<","
                <<element->getComm_code()<<","<<element->getCommodity()<<","
                <<element->getFlow()<<","<<element->getTrade_usd()<<","
                <<element->getWeight_kg()<<","<<element->getQuantity_name()<<","
                <<element->getQuantity()<<","<<element->getCategory()<<endl;
        }
    }

    void pruebasTrade_usd (){
        for (Map *element: *elements)
            cout<<element->getTrade_usd()<<endl;
    }

    vector<Map *> *getElements(){
        return elements;
    }

    virtual ~Container() {
        for (auto *element: *elements)
            delete element;
        delete elements;
    }
};




#endif //PROYECTO_2_CONTAINER_HPP
