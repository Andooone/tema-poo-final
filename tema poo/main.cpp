#include <iostream>
#include "nod.h"
#include "Lista.h"
#include <cstdlib>
#include "graf.h"
# include <algorithm>
#include <fstream>

using namespace std;
ifstream fin("teste.in");
/*inline bool cmp(const graf &gr,const graf &gr2)
{ return gr<gr2;
}
*/
/*
int Pivot(int s,int d,graf *g)
{ int p=((s+rand()%(d-s+1))+(s+rand()%(d-s+1))+(s+rand()%(d-s+1)))/3;
    int i=s-1,j;graf aux;
    aux=g[p];
    //aux=a[p];
    g[p]=g[d];
    g[d]=aux;
    for(j=s;j<=d;j++)
     if(g[j]<g[d])
     { i++;
          aux=g[i];
          g[i]=g[j];
          g[j]=aux;

    }
    aux=g[i+1];
    g[i+1]=g[d];
    g[d]=aux;
    return i+1;
}
void QS(int s,int d,graf *g)
{ if(s<d)
   { int p=Pivot(s,d,g);
     QS(s,p-1,g);
     QS(p+1,d,g);
   }
}
*/
int main()
{
 graf *g;int n;graf p;
 fin>>n;
// fin>>g[0]>>g[1]>>g[2];
 g=new graf[10];
 for(int i=0;i<n;i++)
  fin>>g[i];
  g[0].ADD(4,fin);
   sort(g,g+n);
for(int i=0;i<n;i++)
cout<<g[i]<<"\n";

  return 0;
}
