#include "stablo.h"
#ifndef STABLO_CPP
#define STABLO_CPP


// -----------Funkcija koja dodaje novi element -----------//

Cvor* Stablo::Umetni(int X, Cvor *T, bool h)
{
  if (T == nullptr){
    if(h==true) 
      return new Cvor(X, nullptr, nullptr, 1);
    else 
      return new Cvor(X, nullptr, nullptr);
  }
                
  if (X <= T->element) 
  { 
    T->lijevi = Umetni(X, T->lijevi, h); 
        
    if (T->lijevi->prioritet > T->prioritet) 
      T = desnaRotacija(T); 
  }      
            
  else 
  { 
    T->desni = Umetni(X, T->desni, h); 
    
    if (T->desni->prioritet > T->prioritet) 
      T = lijevaRotacija(T); 
  } 
  
  return T;
}

// -----------Funkcija koja vrši pretragu stabla -----------//

bool Stablo::Pretraga(Cvor *T, int element)
{
  bool postoji = false;
  while ((T != nullptr) && !postoji)
  {
    int broj = T->element;
    
    if (element < broj)
      T = T->lijevi;

    else if (element > broj)
      T = T->desni;

    else
    {
      postoji = true;
      break;
    }

      postoji = Pretraga(T, element);
  }

  return postoji;
}

// -----------Funkcije za obilazak stabala -----------//

void Stablo::inorder(Cvor *T)
{
  if (T != nullptr)
  {
    inorder(T->lijevi);
    cout<<T->element <<"  ";
    inorder(T->desni);
  }
}


void Stablo::preorder(Cvor *T)
{
  if (T != nullptr)
  {
    cout<<"Element:  "<<T->element <<"  sa prioritetom: "<<T->prioritet<<endl;
    //cout<<T->element<<" ";
    preorder(T->lijevi);             
    preorder(T->desni);
  }
}


void Stablo::postorder(Cvor *T)
{
  if (T != nullptr)
  {
    postorder(T->lijevi);             
    postorder(T->desni);
    cout<<T->element <<"  ";
  }
}


// -----------Funkcija koja spaja dva stabla -----------//

Cvor* Stablo::spoji(Cvor* p, Cvor* q) 
{
  if (!p) return q;
  if (!q) return p;
  if (q->prioritet < p->prioritet) 
    {
      p->desni = spoji(p->desni,q);  
      return p; 
    }  
  else 
    {
      q->lijevi = spoji(p,q->lijevi); 
      return q; 
    }
}

// -----------Funkcija koja briše element stabla -----------//


Cvor* Stablo::Obrisi(int k, Cvor* p)  
{
  
  if (!p) 
  {
    cout<<"Element: "<<k<<" se ne nalazi u stablu."<<endl;
    return p;
  } 
  
    
  if (p->element == k) 
    {
      Cvor* q = spoji(p->lijevi, p->desni); 
      delete p; 
      return q; 
    }

  else if (k < p->element) 
    p->lijevi = Obrisi(k, p->lijevi); 

  else 
    p->desni = Obrisi(k, p->desni); 
  
  return p; 
}

// -----------Funkcija koja vraća dva stabla -----------//

pair <Stablo, Stablo> Stablo::razdvoji(Stablo s, int k) 
{ 

  
  Stablo prvo, drugo;

  Cvor * lijevi=s.korijen->lijevi;
  Cvor * desni= s.korijen->desni;

  prvo.korijen=lijevi; 
  drugo.korijen=desni;
  
 return make_pair(prvo, drugo);
} 

#endif 
