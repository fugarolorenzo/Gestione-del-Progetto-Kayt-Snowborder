#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>

using namespace std;


struct atleta
{
    string matricola;
    
    string cognome;
    
    int x1[30], x2[30], y1[30], y2[30];
    
    float distanza=0;
};

atleta conc[40];
int righe=0;


void riempi_vet()
{
    string app;
    
    ifstream fin("gara.txt");
    if (!fin) cout<<"Errore";
        cout<<"ATLETI e misurazioni"<<endl;
        
        while (!fin.eof())
        {
        getline(fin,conc[righe].matricola,',');
        cout<<conc[righe].matricola<<",";
        getline(fin,conc[righe].cognome);
        cout<<conc[righe].cognome;
        cout<<endl;
        righe++;
        }
        cout<<"-/-/-/-/-/-/-/-/-/-/-/-/-/-"<<endl;
    fin.close();
}


void coordinate()
{
    ofstream fout("garafinita.txt");
    
    for (int f=0; f<righe; f++)
    {
    fout<<conc[f].matricola<<",";
    fout<<conc[f].cognome<<", ";
        
        for(int i=0; i<30; i++)
        {
            conc[f].x1[i]=rand()%101;
            fout<<conc[f].x1[i]<<", ";
            
            conc[f].x2[i]=rand()%101;
            fout<<conc[f].x2[i]<<"; ";
            
            conc[f].y1[i]=rand()%101;
            fout<<conc[f].y1[i]<<", ";
            
            conc[f].y2[i]=rand()%101;
            fout<<conc[f].y2[i]<<" || ";
            
            conc[f].distanza=conc[i].distanza+sqrt(pow(conc[f].x1[i]-conc[f].x2[i],2)+pow(conc[f].y1[i]-conc[f].y2[i],2));
        }
        fout<<conc[f].distanza<<endl;
    }
    fout.close();
}

