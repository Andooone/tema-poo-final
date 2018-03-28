#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nod.h"
using namespace std;

class Lista
{
    private:
     nod *prim;

    public:
        Lista();
        ~Lista();
        Lista(const Lista &L);
        Lista&operator=(const Lista&L);
        void addelem(int info);
        int firstinfo();
        nod *first();
        void afisarelista();
        friend class graf;
};

#endif // LISTA_H
