#include <iostream>
#include <cstring>
/*

Да се креира структура Воз во која се чуваат податоци за релацијата по која се движи возот (низа од најмногу 50 знаци),
 предвиден бројот на километри што треба да се поминат (реален број), како и бројот на патници во возот (цел број).

Потоа да се креирa структура ZeleznickaStanica во која се чуваат податоци за градот во кој се наоѓа (низа од 20 знаци),
 низа од возови што поаѓаат од станицата (најмногу 30) и бројот на возови (цел број).

Треба да се направи функција со потпис

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad)

во која се печати релацијата и бројот на километри на возот што поминува најкратка релација (најмалку километри), 
а поаѓа од железничката станица од градот што се проследува како влезен аргумент. Ако има повеќе возови со ист најмал 
број на километри, да се испечати релацијата на последниот таков.

Забелешка: Задачата да се реши во програмскиот јазик C++
*/
using namespace std;

struct voz{
	char relation[50];
    float kmToPass;
    int passengerNo;
};

struct ZeleznickaStanica{
	char city[20];
    voz t[30];
    int trainNo;
};

int istGrad(char *l,char *r){
    int lenL=strlen(l),lenR=strlen(r);
    for(int i=0;i<lenR;i++){
        if(l[i]!=r[i])
            return 0;
    }
    return 1;
}

void najkratkaRelacija(ZeleznickaStanica* z,int n,char *city){
	float min=99999;
	int indexI,indexJ;
	for(int i=0;i<n;i++){
        for(int j=0;j<z[i].trainNo;j++)
        {
            if(istGrad(z[i].t[j].relation,city))
            {
                if(z[i].t[j].kmToPass<min){
                    min=z[i].t[j].kmToPass;
                    indexI=i;
                    indexJ=j;
                }
                if(z[i].t[j].kmToPass==min)
                {
                    min=z[i].t[j].kmToPass;
                    indexI=i;
                    indexJ=j;
                }
            }
        }
	}
	cout<<"Najkratka relacija: "<<z[indexI].t[indexJ].relation<<" ("<<min<<" km)"<<endl;
}


int main(){

    int n;
    cin>>n;
    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        cin>>zStanica[i].city;
        cin>>zStanica[i].trainNo;
        for(int j=0; j<zStanica[i].trainNo; j++)
        {
            cin>>zStanica[i].t[j].relation;
            cin>>zStanica[i].t[j].kmToPass;
            cin>>zStanica[i].t[j].passengerNo;
        }
    }
    char grad[25];
    cin>>grad;
    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
