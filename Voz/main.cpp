#include<iostream>
#include<cstring>
using namespace std;
 /*Да се креира класа Patnik во која се чуваат податоци за патниците на еден воз и тоа: име (низа од максимум 100 знаци), класа на вагон во која се вози (цел број 1 или 2) и велосипед (булова променлива).

За оваа класа да се преоптоварат:

    Оператор << - за печатење на информациите за патникот во формат:

Име на патник

Бројот на класата (1 или 2)

Дали има велосипед?

Потоа да се креира клaса Voz во која се чува: крајна дестинација (низа од максимум 100 знаци), динамички алоцирана низа од објекти од класата Patnik, како и број на елементи во низата (цел број), број на дозволени велосипеди (цел број).

За класата да се обезбедат:

    Оператор += – за додавање нов патник во воз. Патник со велосипед ќе може да се качи во воз само ако возот го дозволува тоа.
    Оператор << - за печатење на крајната дестинација до која вози и листата на патници
    Функција со потпис: patniciNemaMesto(). Со оваа функција се пресметува вкупниот број на патници (од 1-ва класа и 2-ра класа) за кои нема место да влезат во возот со велосипед. Притоа треба да се внимава дека во пресметувањето на вкупниот број патници со велосипеди кои ќе влезат во возот прво треба да се земат предвид патниците од 1-ва класа, а потоа се дозволува да влегуваат патниците од 2-ра класа се додека не се достигне максималниот број на дозволени велосипеди во возот. На крај се печати бројот на патници со велосипеди кои остануваат (не влегуваат во возот) од 1-ва класа, а потоа од 2-ра класа.
*/
class Patnik{

protected:

public:
    char ime[100];
        int klasaVagon;
        bool velosiped;


    Patnik(){}

    Patnik(char *ime,int klasaVagon , bool velosiped){
        strcpy(this->ime,ime);
        this->klasaVagon=klasaVagon;
        this->velosiped=velosiped;
    }

     Patnik(const Patnik &pt){
        strcpy(this->ime,pt.ime);
        this->klasaVagon=pt.klasaVagon;
        this->velosiped=pt.velosiped;
    }

    Patnik &operator =(const Patnik &pt){
       if(this!=&pt){
        strcpy(this->ime,pt.ime);
        this->klasaVagon=pt.klasaVagon;
        this->velosiped=pt.velosiped;
       }
       return *this;
    }


        friend ostream & operator <<(ostream &out , Patnik &pt){
        out<<pt.ime<<"\n"<<pt.klasaVagon<<"\n"<<pt.velosiped<<endl;

        return out;
        }

        ~Patnik(){}

};

class Voz{

private:
    char destinacija[100];
    Patnik *patnik;
    int brElementi;
    int dzVelosipedi;

public:

        Voz(char *destinacija="" , int dzVelosipedi =0,Patnik *patnik=0 , int brElementi=0 ){
        strcpy(this->destinacija,destinacija);
        this->brElementi=brElementi;
        this->dzVelosipedi=dzVelosipedi;

        this->patnik = new Patnik[brElementi];
       for(int i = 0 ; i < brElementi ; i++){
           this->patnik[i]=patnik[i];
       }
        }

        Voz & operator = (const Voz &vz ){
     if(this!=&vz){
            delete [] patnik;
        strcpy(this->destinacija,vz.destinacija);
        this->brElementi=vz.brElementi;
        this->dzVelosipedi=vz.dzVelosipedi;


            for(int i = 0 ; i < brElementi ; i++){
                this->patnik[i]=vz.patnik[i];
            }
            this->patnik = new Patnik[brElementi];
        }
        return *this;
        }

        Voz &operator +=(Patnik pt){

        Patnik *tmp = new Patnik[brElementi+1];

            if((dzVelosipedi<=0&&!(pt.velosiped)) || dzVelosipedi!=0 ){
                  for(int i = 0 ; i < brElementi ; i++)
                        tmp[i]=patnik[i];

            tmp[brElementi++] = pt;
            delete[]patnik;
            patnik=tmp;
            return *this;

             }

        return *this;
    }


        friend ostream & operator <<(ostream &out , Voz &voz){
        out<<voz.destinacija<<"\n";
        for(int i = 0 ; i < voz.brElementi ; i++){
            out<<voz.patnik[i]<<endl;
        }

        return out;
        }

 void patniciNemaMesto()
    {
        int brPrva=0;
        int brVtora=0;
        int kvota=0;

        for(int i=0 ; i< brElementi;i++){
            if(patnik[i].klasaVagon==1&&patnik[i].velosiped){
                kvota++;
            }
        }
        if(kvota>=dzVelosipedi){
            brPrva=kvota-dzVelosipedi;
            kvota=dzVelosipedi;
        }

        for(int i =0; i< brElementi;i++){
            if(patnik[i].klasaVagon==2&&patnik[i].velosiped){
                kvota++;
            }
        }
        if(kvota>=dzVelosipedi)
            brVtora=kvota-dzVelosipedi;

        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: "<<brPrva<<endl;
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto e: "<<brVtora;
    }

};


int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++){
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
