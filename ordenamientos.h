//
// Created by Macarena Oyague on 2019-10-29.
//

#ifndef PROYECTO_2_ORDENAMIENTOS_H
#define PROYECTO_2_ORDENAMIENTOS_H

void saveFile (vector<Map*>* vector, string name){
    fstream* archivo = new fstream(name, ios_base::out);
    if (archivo) {
        for(auto element: *vector)
            *archivo <<element->getCountry_or_area()<<","<<element->getYear()<<","
                    <<element->getComm_code()<<","<<element->getCommodity()<<","
                    <<element->getFlow()<<","<<element->getTrade_usd()<<","
                    <<element->getWeight_kg()<<","<<element->getQuantity_name()<<","
                    <<element->getQuantity()<<","<<element->getCategory()<<endl;
        archivo->close();
    }
}

void quickSort_Trade_usd(Container* container, int first, int end, string atr){
    auto inicio = first;
    auto fin = end;
    int middle = first + (fin-inicio)/2;
    auto pivote = (*container->getElements())[middle]->getTrade_usd();
    unsigned long int inicioLimite, finLimite;
    do{
        inicioLimite = ((*container->getElements())[inicio])->getTrade_usd();
        finLimite = ((*container->getElements())[fin])->getTrade_usd();
        if ((inicioLimite >= pivote) && (finLimite <= pivote)){
            swap((*container->getElements())[inicio],(*container->getElements())[fin]);
            inicio++;
            fin--;
        }
        if (inicioLimite < pivote){
            inicio++;
        }
        if (finLimite > pivote){
            fin--;
        }
    }while(inicio <= fin);
    if (first < fin){
        quickSort_Trade_usd(container, first, fin, atr);
    }
    if (inicio < end){
        quickSort_Trade_usd(container, inicio, end, atr);
    }
}

void heap(Container* container, int n, int i){
    int temp = i;
    int izq = 2*i + 1;
    int der = 2*i + 2;
    if (izq < n && (*container->getElements())[izq]->getTrade_usd() > (*container->getElements())[temp]->getTrade_usd())
        temp = izq;
    if (der < n && (*container->getElements())[der]->getTrade_usd() > (*container->getElements())[temp]->getTrade_usd())
        temp = der;
    if (temp != i)
    {
        swap((*container->getElements())[i], (*container->getElements())[temp]);
        heap(container, n, temp);
    }
}

void heapSort_Trade_usd(Container* container, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(container, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap((*container->getElements())[0], (*container->getElements())[i]);
        heap(container, i, 0);
    }
}

void shellSort_Trade_usd(Container* container, int first, int end, string atr){
    auto n = 2;
    auto pivot = first + (end - first)/n;
    while(pivot > first){
        auto ordenados = true;
        while(ordenados){
            auto cont = 0;
            auto j = first;
            auto iter = pivot;
            while (iter != end){
                if(((*container->getElements())[j])->getTrade_usd()>((*container->getElements())[iter])->getTrade_usd()){
                    swap((*container->getElements())[j], (*container->getElements())[iter]);
                    iter++;
                    j++;
                    cont++;
                    ordenados = true;
                } else {
                    iter++;
                    j++;
                    ordenados = false;
                    if(cont >= 1){
                        ordenados = true;
                    }
                }
            }
        }
        pivot = first + (pivot-first)/n;
    }
}



void merge(Container* container, int izq, int medio, int der){
    int i, j, k;
    int n1 = medio - izq + 1;
    int n2 =  der - medio;
    auto L = new vector<Map*>;
    auto R = new vector<Map*>;
    for (i = 0; i < n1; i++)
        L->push_back ((*container->getElements())[izq + i]);
    for (j = 0; j < n2; j++)
        R->push_back ((*container->getElements())[medio + 1+ j]);
    i = 0;
    j = 0;
    k = izq;
    while (i < n1 && j < n2){
        if ((*L)[i]->getTrade_usd() <= (*R)[j]->getTrade_usd()){
            (*container->getElements())[k] = (*L)[i];
            i++;
        }
        else{
            (*container->getElements())[k] = (*R)[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        (*container->getElements())[k] = (*L)[i];
        i++;
        k++;
    }
    while (j < n2){
        (*container->getElements())[k] = (*R)[j];
        j++;
        k++;
    }
}


void mergeSort_Trade_usd(Container* container, int izq, int der){

    if (izq < der){
        int medio = izq+(der-izq)/2;
        mergeSort_Trade_usd(container, izq, medio);
        mergeSort_Trade_usd(container, medio+1, der);
        merge(container, izq, medio, der);
    }
}

#endif //PROYECTO_2_ORDENAMIENTOS_H
