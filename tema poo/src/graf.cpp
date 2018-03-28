#include "graf.h"
#include "Lista.h"
#include "nod.h"
#include <iostream>
using namespace std;
//constructorul
graf::graf()
{ noduri=0;
  muchii=0;
  g=new Lista;
  viz=new int;
}

//destructorul
graf::~graf()
{ nod*p;
  nod *q;
  for(int i=0;i<=noduri;i++)
  { p=g[i].prim;
    while(p)
     { q=p;
       p=p->geturm();
       delete q;
     }
  }
  delete p;
  delete q;
  delete[]viz;
}

//constructorul de copiere
graf::graf(const graf&gr)
{ noduri=gr.noduri;
  muchii=gr.muchii;
  this->g=new Lista[noduri+1];
  for(int i=0;i<=noduri;i++)
  this->g[i]=gr.g[i];

}

//operatorul de atribuire
graf& graf::operator=(const graf &gr)
{
  for(int i=0;i<=noduri;i++)
  {nod *q;
   nod *p;
   p=g[i].prim;
   while(p!=NULL)
    { q=p;
     p=p->geturm();
     delete q;
    }
    g[i].prim=new nod;
    g[i].prim=NULL;
  }

  delete []g;
  g=new Lista[gr.noduri+1];
  noduri=gr.noduri;
  muchii=gr.muchii;
  /*for(int i=0;i<=noduri;i++)
  this->g[i]=gr.g[i];*/
  for(int i=1;i<=noduri;i++)
   for(nod*p=gr.g[i].prim;p!=NULL;p=p->geturm())
    { this->g[i].addelem(p->info);

    }
  return *this;
}

//operatorul de citire
istream& operator>>(istream &in,graf &gr)
{ in>>gr.noduri;
  in>>gr.muchii;
  int x;
  int y;
  delete gr.viz;
  gr.viz=new int [gr.noduri+1];
  for(int i=1;i<=gr.noduri;i++) gr.viz[i]=0;
  gr.g=new Lista [gr.noduri+1];
  for(int i=0;i<gr.muchii;i++)
   {in>>x>>y;
    gr.g[x].addelem(y);
    gr.g[y].addelem(x);
   }
   return in;
}

//operatorul de afisare
ostream& operator<<(ostream &out,const graf &gr)
{ out<<gr.noduri<<"\n";
  out<<gr.muchii<<"\n";

    for(int i=1;i<=gr.noduri;i++)
   {
    gr.g[i].afisarelista();
   }
return out;
}

//BFS
void graf::BFS(int x)
{ int *c=new int [noduri+1];
    int *vizz=new int [noduri+1];
  for(int i=0;i<=noduri;i++) vizz[i]=0;

    int prim,ultim,nodcurent;
    prim=ultim=1;
    c[prim]=x;
    vizz[x]=1;

    while(prim<=ultim)
    { nodcurent=c[prim];
      vizz[nodcurent]=1;
      for(nod*p=g[nodcurent].prim;p!=NULL;p=p->geturm())
        { if(vizz[p->getinfo()]==0)
              { ultim++;
                c[ultim]=p->getinfo();
              }

        }
        prim++;
    }
    cout<<"\nParcurgerea BFS:\n";
    for(int i=1;i<=ultim;i++) cout<<c[i]<<" ";
  delete []c;
  delete []vizz;
}

//DFS
void graf::DFS(int x)
{
    cout<<x<<" ";
    viz[x]=1;
    for(nod*p=g[x].prim;p!=NULL;p=p->geturm())
       if(viz[p->getinfo()]==0)
             DFS(p->getinfo());
}
//RF
void graf::RoyFloyd()
{
    int **mat=new int* [noduri];
    for(int i=0;i<=noduri;i++)
    mat[i]=new int [noduri];
   //initializare
     for(int i=0;i<=noduri;i++)
      for(int j=0;j<=noduri;j++)
       mat[i][j]=0;

     for(int i=1;i<=noduri;i++)
       for(nod*p=g[i].prim;p!=NULL;p=p->geturm())
         {mat[i][p->getinfo()]=1;
          mat[p->getinfo()][i]=1;
         }
   //RF
     for(int k=1;k<=noduri;k++)
       for(int i=1;i<=noduri;i++)
         for(int j=1;j<=noduri;j++)
          if(k!=i&&k!=j&&i!=j&&mat[i][k]==1&&mat[k][j]==1)
           mat[i][j]=1;
    //afisare
cout<<"\nRoyFloyd: \n";
  for(int i=1;i<=noduri;i++)
   {for(int j=1;j<=noduri;j++)
    cout<<mat[i][j]<<" ";
    cout<<"\n";
   }
   for(int i=0;i<noduri;i++)
    delete []mat[i];
   delete []mat;
}
//Componente conexe
void graf::CompConexe()
{
    for(int i=1;i<=noduri;i++) viz[i]=0;
     cout<<"Componentele conexe sunt:\n";
     for(int i=1;i<=noduri;i++)
       if(viz[i]==0)
         {DFS(i);cout<<"\n";}
}

//conex sau nu
 void graf::Conex()
 {
   int *c=new int [noduri+1];
   int *vizz=new int [noduri+1];
  for(int i=0;i<=noduri;i++) vizz[i]=0;

    int prim,ultim,nodcurent;
    prim=ultim=1;
    c[prim]=1;
    vizz[1]=1;

    while(prim<=ultim)
    { nodcurent=c[prim];
      for(nod*p=g[nodcurent].prim;p!=NULL;p=p->geturm())
        { if(vizz[p->getinfo()]==0)
              { ultim++;
                c[ultim]=p->getinfo();
                vizz[p->getinfo()]=1;
              }

        }
        prim++;
    }
    if(ultim==noduri) cout<<"\nGraful este conex\n";
    else cout<<"\nGraful nu este conex\n";
  delete []c;
  delete []vizz;
 }

//operatorul ==
bool graf::operator==(const graf &gr)
{

   if(this->noduri!=gr.noduri||this->muchii!=gr.muchii) return 0;

  int *vizz=new int [this->noduri];
  int *vizzz=new int[this->noduri];

  for(int i=1;i<=noduri;i++)
  {
      for(int j=1;j<=noduri;j++)
     {vizz[j]=0;vizzz[j]=0;}

    nod *p=g[i].prim;
    while(p)
    { vizz[p->getinfo()]=1;
      p=p->geturm();
    }

    p=gr.g[i].prim;
    while(p)
    { vizzz[p->getinfo()]=1;
      p=p->geturm();
    }
    for(i=1;i<=noduri;i++)
    if(vizz[i]!=vizzz[i]) {delete []vizz;delete []vizzz;return 0;}
  }
  delete []vizz;delete []vizzz;
   return 1;
}

//operatorul !=
bool graf::operator!=(const graf &gr)
{ if(this->noduri!=gr.noduri||this->muchii!=gr.muchii) return 1;

  int *vizz=new int [this->noduri];
  int *vizzz=new int[this->noduri];

  for(int i=1;i<=noduri;i++)
  {
      for(int j=1;j<=noduri;j++)
     {vizz[j]=0;vizzz[j]=0;}

    nod *p=g[i].prim;
    while(p)
    { vizz[p->getinfo()]=1;
      p=p->geturm();
    }

    p=gr.g[i].prim;
    while(p)
    { vizzz[p->getinfo()]=1;
      p=p->geturm();
    }
    for(i=1;i<=noduri;i++)
    if(vizz[i]!=vizzz[i]) {delete []vizz;delete[]vizzz; return 1;}
  }
delete []vizz;delete[]vizzz;
  return 0;
}

graf graf::operator+(const graf&gr)
{ graf g2;
  g2.noduri=gr.noduri;
  g2.g=new Lista[noduri+1];
    int *vizz=new int [noduri+1];
int nr=0;
    for(int i=1;i<=noduri;i++)
  {
      for(int j=1;j<=noduri;j++)
     {vizz[j]=0;}

    nod*p;
    p=g[i].prim;
    while(p)
    { vizz[p->getinfo()]=1;
      p=p->geturm();
    }

    p=gr.g[i].prim;
    while(p)
    { vizz[p->getinfo()]=1;
      p=p->geturm();
    }
     for(int j=1;j<=noduri;j++)
        if(vizz[j]==1)
         {g2.g[i].addelem(j);nr++;}
  }
  nr=nr/2;
  g2.muchii=nr;
  delete []vizz;
  return g2;
}

 bool graf::operator< (const graf &graf2) const
{
  if(noduri<graf2.noduri) return 1;
  else if(noduri>graf2.noduri) return 0;
  else
      if(noduri==graf2.noduri)
      {
          if(muchii==graf2.muchii) return 0;
        else if(muchii<graf2.muchii) return 1;
        else return 0;
      }
}

istream& graf::ADD(int index,istream &in)
{ int nrmuchii;
    in>>nrmuchii;
        graf g2=(*this);
      for(int i=0;i<=noduri;i++)
  {nod *q;
   nod *p;
   p=g[i].prim;
   while(p!=NULL)
    { q=p;
     p=p->geturm();
     delete q;
    }
    g[i].prim=new nod;
    g[i].prim=NULL;
  }

  delete []g;

    noduri++;
    muchii=muchii+nrmuchii;
    g=new Lista[noduri+1];


    for(int i=1;i<=noduri;i++)
      for(nod*p=g2.g[i].prim;p!=NULL;p=p->geturm())
    { this->g[i].addelem(p->info);

    }
int x,y;
    for(int i=1;i<=nrmuchii;i++)
    { in>>x>>y;
       this->g[x].addelem(y);
       this->g[y].addelem(x);
    }
    return in;
}




