#include <iostream>
#include <cstring>
/*Да се дефинира класа Potpisuvac во која се чуваат информации за:

име (низа од максимум 20 знаци)
презиме (низа од максимум 20 знаци)
ЕМБГ (низа од максимум 14 знаци)
За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.

Да се дефинира класа Dogovor, во која се чуваат информации за:

број на договор (int),
категорија на договор (низа од 50 знаци),
поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).*/
using namespace std;

class Potpisuvac{
private:
    char ime[20];
    char prezime[20];
    char embg[14];
public:
    Potpisuvac(){};
    Potpisuvac(char ime[],char prezime[20],char embg[]){
        strncpy(this->ime,ime,20);
        strncpy(this->prezime,prezime,20);
        strncpy(this->embg,embg,14);
    }

    Potpisuvac(const Potpisuvac &pot){
        strncpy(ime,pot.ime,20);
        strncpy(prezime,pot.prezime,20);
        strncpy(embg,pot.embg,14);
    }

    char* get_embg(){
        return embg;
    }
};

class Dogovor{
private:
    int broj;
    char kategorija[50];
    Potpisuvac pot[3];
public:
    Dogovor(){};
    Dogovor(int broj,char kategorija[],Potpisuvac pot[]){
        this->broj=broj;
        strncpy(this->kategorija,kategorija,50);
        this->pot[0]=pot[0];
        this->pot[1]=pot[1];
        this->pot[2]=pot[2];
    }

    bool proverka(){
        if(strcmp(pot[0].get_embg(),pot[1].get_embg())==0)
            return 1;
        else if(strcmp(pot[0].get_embg(),pot[2].get_embg())==0)
            return 1;
        else if(strcmp(pot[1].get_embg(),pot[2].get_embg())==0)
            return 1;
        else
            return 0;
    }
};

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        if(d.proverka() == true)
            cout << "Dogovor "<<i+1<<":"<<endl<<"Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Dogovor "<<i+1<<":"<<endl<<"Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}

