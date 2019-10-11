#ifndef STABLO_H
#define STABLO_H
#include <iostream>

using namespace std;

struct Cvor
{  
  public: 
    Cvor *lijevi, *desni;
    int prioritet, element;  
    
    Cvor()
    {
      this->element = 0;
      this->lijevi = this;
      this->desni = this;
      this->prioritet = 1000;         
    }    
      
    Cvor(int element)
    {
      Cvor(element, nullptr, nullptr);         
    }
        
    Cvor(int element, Cvor *lijevi, Cvor *desni)         
    {
      this->element = element;
      this->lijevi = lijevi;
      this->desni = desni;
      this->prioritet = rand() % 100;
    }  

    Cvor(int element, Cvor *lijevi, Cvor *desni, bool imaPrioritet)  {
      this->element = element;
      this->lijevi = lijevi;
      this->desni = desni;
      this->prioritet = 1000;
    }  
        
};
 

class Stablo
{
  private: 
 
    Cvor *korijen;
        
  public:

    Stablo() { korijen = nullptr; }
    void Umetni(int X) { Umetni(X, 0); }
    void Umetni(int X, bool h) 
    {
      korijen = Umetni(X, korijen, h);
    }
    bool Pretraga(int element)
    {
      return Pretraga(korijen, element);
    }
    void inorder() { inorder(korijen); }
    void preorder() { preorder(korijen); }
    void postorder() { postorder(korijen); }

    void Obrisi(int X)
    {
      korijen = Obrisi(X, korijen);
    }

    Cvor *desnaRotacija(Cvor *y) 
    { 
      Cvor *x = y->lijevi,  *T2 = x->desni; 
        x->desni = y; 
        y->lijevi = T2; 
      return x; 
    } 

    Cvor *lijevaRotacija(Cvor *x) 
    { 
      Cvor *y = x->desni, *T2 = y->lijevi; 
        y->lijevi = x; 
        x->desni = T2; 
      return y; 
    } 

    Cvor *Umetni(int X, Cvor *T, bool h);
    bool Pretraga(Cvor *T, int vrijednost);
    void inorder(Cvor *T);
    void preorder(Cvor *T);
    void postorder(Cvor *T);
    Cvor* spoji(Cvor* p, Cvor* q);
    Cvor* Obrisi(int k, Cvor* p);
    pair<Stablo, Stablo> razdvoji(Stablo s, int X);
    

};



#endif
