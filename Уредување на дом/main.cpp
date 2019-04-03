#include <iostream>
#include <cstring>
/*Во оваа задача е потребно да уредите даден дом со маси.

Креирајте класа Masa со следниве атрибути:

должина (целобројна вредност)
ширина (целобројна вредност)
конструктор со и без параметри и метода pecati().

Креирајте класа Soba која содржи:

маса (објект од класата Маса)
должина на собата (целобројна вредност)
ширина на собата (целобројна вредност)
конструктор со и без параметри и метода pecati() во
која се повикува и pecati() за објектот Masa.

Креирајте класа Kukja со атрибути:

соба (објект од класата Soba)
адреса (низа од 50 знаци), и соодветни методи.
конструктор со и без параметри, деструктор и метода pecati()
во која се повикува и pecati() за објектот Soba.*/

using namespace std;

class Masa{
private:
    int dolzina;
    int sirina;
public:
    Masa(){};
    Masa(int d,int s){
        dolzina=d;
        sirina=s;
    }
    void pecati(){
        cout<<"Masa: "<<dolzina<<" "<<sirina<<endl;
    }
};

class Soba{
private:
    Masa masa;
    int dolzinaNaSoba;
    int sirinaNaSoba;
public:
    Soba(){}
    Soba(Masa m,int d,int s){
        masa=m;
        dolzinaNaSoba=d;
        sirinaNaSoba=s;
    }
    void pecati(){
        cout<<"Soba: "<<dolzinaNaSoba<<" "<<sirinaNaSoba<<endl;
        masa.pecati();
    }
};

class Kukja{
private:
    Soba soba;
    char adresa[50];
public:
    Kukja(){}
    Kukja(Soba s,char adresa[]){
        soba=s;
        strcpy(this->adresa,adresa);
    }
    ~Kukja(){}
    void pecati(){
        cout<<"Adresa: "<<adresa<<endl;
        soba.pecati();
    }
};

int main()
{
    return 0;
}
