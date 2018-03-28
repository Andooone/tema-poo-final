#ifndef NOD_H
#define NOD_H
using namespace std;

class nod
{    int info;
     nod *urm;
    public:
        nod();
        nod(int info, nod* urm);
        nod(const nod &n);
        int getinfo();
        void setinfo(int info);
        nod *geturm();
        void seturm(nod *urm);
        nod &operator=(const nod&n);
    friend class Lista;
    friend class graf;
    int operator == (const nod&a);
};

#endif // NOD_H
