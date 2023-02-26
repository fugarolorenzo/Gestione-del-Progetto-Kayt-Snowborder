#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
#include <vector>

using namespace std;
vector<atleta> atleti;
int righe=0;
int n;

struct atleta
{
    string matricola;
    
    string cognome;
    
    int x1[30], x2[30], y1[30], y2[30];
    
    float distanza=0;
};

int main()
{
    srand(time(NULL));
    int s;
    
    do{
        cout<<endl<<"\t \t MENU"<<endl;
        cout<<"1 - inserisci atleti"<<endl;
        cout<<"2 - fai partire la gara"<<endl;
        cout<<"3 - crea un file"<<endl;
        cout<<"4 - Visualizza risultati finali"<<endl;
        cout<<"5 - Visualizza podio"<<endl;
        cout<<"6 - Uscita";
        cout<<endl<<"scegli: ";
        cin>>s;
        
    switch(s)
        {
            
            case 1:{
                cout<<endl;
                insert();
            }
            break;
            case 2:{
                cooordinate();
            }
            break;
            case 3:{
                cout<<endl;
                file();
            }
            break;
            
        }
                }while(s!=6);
    return 0;
}




void coordinate()
{
    for (int f=0; f<n; f++)
    {
        for(int i=0; i<30; i++)
        {
        atleta a;    
            
            a.x1[i]=rand()%101;
            
            a.x2.x2[i]=rand()%101;
            
            a.y1[i]=rand()%101;
            
            a.y2[i]=rand()%101;
            
            a.distanza=a.distanza+sqrt(pow(a.x1[i]-a.x2[i],2)+pow(a.y1[i]-a.y2[i],2));
            
        atleti.push_back(a);
        
        }
    }
}


void insert()
{
    cout<<"creazione ATLETA";
    
    cout<<"quanti atleti partecipano?";
    cin >> n;
    
    
    for (int i = 0; i < n; i++)
    {
    atleta a;
    
    cout << "Inserisci la matricola dell' " << i + 1 << "atleta : ";
    cin >> a.matricola;
    
    cout << "Inserisci il cogmone dell' " << i + 1 << "atleta : ";
    cin >> a.cognome;
    
    atleti.push_back(a);
    }
    
}



void file()
{
    ofstream file("gara.txt");
  if (file.is_open()) 
  {
      
    for (auto atleta : atleti) 
    {
      file << atleta.matricola << endl <<atleta.cognome <<endl <<atleta.distanza <<endl <<"-------------------------" <<endl <<endl;
      
    }
    
    
    file.close();
    cout << "Dati salvati correttamente nel file 'persone.txt'." << endl;
  } else {
    cout << "Errore nell'apertura del file." << endl;
  }

  return 0;
}
    
    
}
