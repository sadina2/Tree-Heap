#include <iostream>
#include <cstdlib>  
#include "stablo.h" 

using namespace std;

int main()
{    

  Stablo stablo; 
     
  stablo.Umetni(5);
  stablo.Umetni(6);
  stablo.Umetni(1);
  stablo.Umetni(15);
  stablo.Umetni(2);
  stablo.Umetni(121);

 int broj=12;
  
  cout<<"\n~~~~ Obilazak stabla ~~~~ \n\n";  
  stablo.preorder();

  cout<<endl;
  cout<<endl;
 
  cout<<"~~~~  Brisanje elemenata ~~~~  \n";
  stablo.Obrisi(broj);
  stablo.Obrisi(121);
  cout<<endl<<endl;


  cout<<"~~~~  Pretraga stabla ~~~~ \n ";
  if(stablo.Pretraga(broj))
    cout<<"Element: "<<broj<<" je pronađen. \n";
  else
    cout<<"Element: "<<broj<<" nije pronađen.\n ";


  cout<<"\n~~~~  Razdvajanje stabla ~~~~  \n\n";

  stablo.Umetni(broj, 1);
  stablo.Umetni(26);
  stablo.Umetni(30);

  
  pair<Stablo, Stablo> par = stablo.razdvoji(stablo, broj);

 
  cout<<"Prvo podstablo \n";
  par.first.postorder();
  cout<<endl;
  
  cout<<"\nDrugo podstablo\n ";
  
  par.second.inorder();
  cout<<endl;




}
