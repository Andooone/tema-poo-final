#ifndef GRAF_H
#define GRAF_H
#include "Lista.h"
#include <iostream>
#include "nod.h"
using namespace std;
class graf
{ private:
    int noduri;
    int muchii;
    Lista *g;
    int *viz;
    public:
        graf();
        ~graf();
        graf(const graf &gr);
        graf& operator=(const graf &gr);
        friend istream & operator>>(istream &in, graf &gr);
        friend ostream & operator<<(ostream &out,const graf &gr);
        void BFS(int x);
        void DFS(int x);
        void RoyFloyd();
        void CompConexe();
        void Conex();
        graf operator+(const graf &gr);
        bool operator==(const graf &gr);
        bool operator!=(const graf &gr);
        bool operator<(const graf &graf2) const;
        istream & ADD(int index,istream& in);
};

#endif // GRAF_H
