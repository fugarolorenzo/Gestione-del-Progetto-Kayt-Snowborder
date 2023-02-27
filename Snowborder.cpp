/*!
    @file snowborder.cpp
    @brief simulazione di una gara di snowkiting dove vince chi percorre più strada 
    @author fugarolorenzo
*/

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

/*!
    @struct atleta
    @brief contiene i dati riguardanti ogni atleta
*/

struct atleta
{
    /*!
        @var matricola
        @brief matricola dell' atleta
    */
    string matricola;
    
    /*!
        @var cognome
        @brief cognome dell' atleta
    */
    string cognome;
    
    /*!
        @var x1,x2,y1,y2
        @brief array di cordinate rilevate dell' atleta
    */
    int x1[30], x2[30], y1[30], y2[30];
    
    /*!
        @var distanza
        @brief distanza percorsa dall' atleta calcolata secondo le coordinate
    */
    float distanza = 0;
};

/*!
    @brief compara la distanza di due atleti, Se la distanza a è maggiore di b, la funzione restituisce true
*/
bool compareAtleta(atleta a, atleta b) 
{
    return a.distanza > b.distanza;
}

    /*! 
        @var atleti
        @brief atleti è un' array dinamico contenente oggetti atleta
    */
vector<atleta> atleti;


/*!
    @brief genera le coordinate, poi esegue il calcolo per determinare la distanza percorsa
*/
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
            
            // utilizzo del teorema di pitagora per la distanza tra due punti
        atleti[f].distanza += sqrt(pow(atleti[f].x1[i] - atleti[f].x2[i], 2) + pow(atleti[f].y1[i] - atleti[f].y2[i], 2));
        
            
        }
    }
}


/*!
    @brief chiede quanti partecipanti inserire, in seguito riempie le struct
*/
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

/*!
    @brief inserisce l'atleta nel vettore
*/    
    atleti.push_back(a);
    
        
    }
}

/*!
    @brief crea un file con al suo interno tutte le struct
*/
void file()
{
    
    ofstream file("gara.txt");
    
    if (file.is_open()) 
    {
        
        for (auto atleta : atleti) // cicla su tutti gli atleti
        {
            file << atleta.matricola << endl << atleta.cognome << endl << atleta.distanza << " m" << endl << "-------------------------" << endl << endl;
            // scrive i dati dell'atleta nel file
        }
            file.close();
        
        cout << "Dati salvati correttamente nel file 'gara.txt'." << endl;
    } 
    else 
    {
        cout << "Errore nell'apertura del file." << endl;
    }
}



/*!
    @brief crea il podio ovvero fa visualizzare i primi tre classificati
*/
void podio()
{
    
    /*!
        @brief viene usata insieme a compareAtleta, serve ad ordinare il vettore in modo decrescente secondo la distanza
    */
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

/*!
    @brief nel main è contenuto il menu 
*/
int main()
{
    
    /*! 
        @var atleti
        @brief atleti è un' array dinamico contenente oggetti atleta
    */
    
    vector<atleta> atleti;
    
    srand(time(NULL)); //serve alla generazione delle coordinate
    
    /*! 
        @var s
        @brief scelta
    */
    int s;
    
    do{ //output contenente il menu
        cout<<endl<<"••••••••••••••• MENU •••••••••••••••"<<endl;
        cout<<"1 - inserisci atleti"<<endl;
        cout<<"2 - fai partire la gara"<<endl;
        cout<<"3 - crea un file"<<endl;
        cout<<"4 - Visualizza podio"<<endl;
        cout<<"5 - Uscita" <<endl;
        cout<<"••••••••••••••••••••••••••••••••••••" <<endl;
        cout<<endl<<"scegli: ";
        cin>>s;
        
    switch(s) //switch contenente le varie scelte
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
