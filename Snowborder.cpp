#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct atleta
{
    string matricola;
    
    string cognome;
    
    int x1[30], x2[30], y1[30], y2[30];
    
    float distanza = 0;
};

bool compareAtleta(atleta a, atleta b) 
{
    return a.distanza > b.distanza;
}

vector<atleta> atleti;


void coordinate()
{
    for (int f = 0; f < atleti.size(); f++)
    {
        for(int i = 0; i < 30; i++)
        {
            atleti[f].x1[i] = rand() % 101;
            atleti[f].x2[i] = rand() % 101;
            atleti[f].y1[i] = rand() % 101;
            atleti[f].y2[i] = rand() % 101;
            
            
        atleti[f].distanza += sqrt(pow(atleti[f].x1[i] - atleti[f].x2[i], 2) + pow(atleti[f].y1[i] - atleti[f].y2[i], 2));
        
            
        }
    }
}



void insert()
{

int n;
    
    cout << "Quanti atleti partecipano? ";
    cin >> n;
    cout<< "---------------------------" <<endl;
    
    for (int i = 0; i < n; i++)
    {
        atleta a;
        cout << "Inserisci la matricola dell' " << i + 1 << " atleta: ";
        cin >> a.matricola;
        
        cout << "Inserisci il cognome dell' " << i + 1 << " atleta: ";
        cin >> a.cognome;
        
        cout<< "---------------------------" <<endl;
        
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
            file << atleta.matricola << endl << atleta.cognome << endl << atleta.distanza << " m" << endl << "-------------------------" << endl << endl;
        }
        
        file.close();
        
        cout << "Dati salvati correttamente nel file 'gara.txt'." << endl;
    } 
    else 
    {
        cout << "Errore nell'apertura del file." << endl;
    }
}




void podio()
{
    sort(atleti.begin(), atleti.end(), compareAtleta);
    
    cout << "---------------------------PODIO----------------------------" << endl;
    for (int i = 0; i < min((int)atleti.size(), 3); i++)
    {
        cout << i + 1 << "° classificato" << endl;
        cout << atleti[i].matricola << endl;
        cout << atleti[i].cognome << endl;
        cout << atleti[i].distanza << " km" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
}


int main()
{
    vector<atleta> atleti;
    
    srand(time(NULL));
    int s;
    
    do{
        cout<<endl<<"••••••••••••••• MENU •••••••••••••••"<<endl;
        cout<<"1 - inserisci atleti"<<endl;
        cout<<"2 - fai partire la gara"<<endl;
        cout<<"3 - crea un file"<<endl;
        cout<<"4 - Visualizza podio"<<endl;
        cout<<"5 - Uscita" <<endl;
        cout<<"••••••••••••••••••••••••••••••••••••" <<endl;
        cout<<endl<<"scegli: ";
        cin>>s;
        
    switch(s)
        {
            
            case 1:
            {
                cout
            <<endl;
                insert();
            }
            break;
            case 2:
            {
                coordinate();
            }
            break;
            case 3:
            {
                cout<<endl;
                file();
            }
            break;
            case 4:
            {
                cout<<endl;
                podio();
            }
            break;
            
        }
                }while(s!=5);
    return 0;
}
