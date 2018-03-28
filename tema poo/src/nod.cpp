#include "nod.h"
#include <iostream>

using namespace std;
//constructorul
nod::nod()
{
    info=0;
    urm=NULL;

}

//constructorul cu parametri
nod::nod(int info, nod*urm)
{
    this->info=info;
    this->urm=urm;
}

//constructorul de copiere
nod::nod(const nod &n)
{ info=n.info;
  urm=n.urm;
}

//extragem informatia din nod
int nod::getinfo()
{
    return info;
}

//operatorul de atribuire
nod & nod::operator=(const nod&n)
{ this->info=n.info;
  this->urm=n.urm;
  return *this;
}

//atribuire informatie
void nod::setinfo(int info)
{
    this->info=info;
}

//returnare next nod
nod* nod::geturm()
{
    return urm;
}

//seteaza urmatorul nod
void nod::seturm(nod *urm)
{
    this->urm=urm;
}

//operatorul ==
int  nod::operator == (const nod &n)
{
 return info==n.info;
}
