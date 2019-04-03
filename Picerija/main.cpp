#include <iostream>
#include <cstring>
/*

Да се дефинира класа Пица за која ќе се чуваат податоци за:

    име на пицата (низа од 15 знаци)
    цена (цел број)
    состојки (динамички алоцирана низа од знаци)
    намалување на цената во проценти (цел број) - ако пицата не е на промоција намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.

За потребите на оваа класа да се креираат потребните конструктори и да се напише соодветен деструктор. Дополнително за оваа класа да се дефинира функцијата:

    pecati() - функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена.
    istiSe(Pica p) - функција за споредба на две пици според состојките :

Да се дефинира класа Picerija во која се чуваат:

    име (низа од максимум 15 знаци)
    динмички алоцирана низа од објекти од класата Pica
    број на пици (цел број)

За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор. Да се имплементираат и следниве методи:

    dodadi(Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
    void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст.

*/
using namespace std;

class Pica{
private:
    char ime[15];
    int cena;
    char* sostojki;
    int popust;
public:
    Pica() {
        cena=0;
        popust=0;
        sostojki=0;
        strcpy(ime,"");
    }

    Pica(const char* ime,int cena,const char* sostojki,int popust){
    this->cena=cena;
    this->popust=popust;
    strcpy(this->ime,ime);
    this->sostojki=new char[strlen(sostojki)+1];
    strcpy(this->sostojki,sostojki);
    }

    Pica(const Pica &p){
    this->cena=p.cena;
    this->popust=p.popust;
    strcpy(this->ime,p.ime);
    this->sostojki=new char[strlen(p.sostojki)+1];
    strcpy(this->sostojki,p.sostojki);
    }

    Pica &operator=(const Pica &p){
    if(this!=&p){
    this->cena=p.cena;
    this->popust=p.popust;
    strcpy(this->ime,p.ime);
    delete[] this->sostojki;
    this->sostojki=new char[strlen(p.sostojki)+1];
    strcpy(this->sostojki,p.sostojki);
        }
        return *this;
    }

    void pecati(){
    cout<<ime<<" - "<<sostojki<<", "<<cena;
    }

    char *getIme(){
      return ime;
     }

    int getCena(){
        return cena;
    }

     int getPopust(){
        return popust;
      }

    bool operator==(Pica p){
    if(strcmp(sostojki,p.sostojki)==0)
        return true;
    return false;
    }


    ~Pica(){
        delete[] sostojki;
        }
};


class Picerija {
private:
    char ime[15];
    Pica* pici;
    int brPici;
public:
    Picerija(const char* ime) {
        strcpy(this->ime,ime);
        brPici=0;
        pici=0;
    }

    Picerija(const char* ime,Pica *pici,int brPici){
    this->brPici=brPici;
    strcpy(this->ime,ime);
    this->pici=new Pica[brPici];
    for(int i=0;i<brPici;++i){
        this->pici[i]=pici[i];
        }
    }

    Picerija(const Picerija &p){
    this->brPici=p.brPici;
    strcpy(this->ime,p.ime);
    this->pici=new Pica[p.brPici];
    for(int i=0;i<p.brPici;++i){
        this->pici[i]=p.pici[i];
        }
    }

    Picerija &operator=(const Picerija &p){
    if(this!=&p){
    this->brPici=p.brPici;
    strcpy(this->ime,p.ime);
    delete[] this->pici;
    this->pici=new Pica[p.brPici];
    for(int i=0;i<p.brPici;++i){
        this->pici[i]=p.pici[i];
            }
        }
    return *this;
    }

    Picerija &operator+=(Pica p){
        bool eDuplikat=false;
        for(int i = 0; i < brPici; ++i) {
            if(this->pici[i]==p)
             eDuplikat=true;
        }
        if(eDuplikat==false) {
            Pica *temp;
            temp = new Pica[brPici + 1];
            for(int i=0;i<brPici;++i){
                temp[i]=pici[i];
            }
            delete[] pici;
            pici=temp;
            pici[brPici++]=p;
        }
        return *this;
    }

    void setIme(const char* ime) {
        strcpy(this->ime, ime);
    }

    char* getIme() {
        return ime;
    }

    void piciNaPromocija(){
    for(int i=0;i<brPici;++i){
          if((pici[i].getPopust() > 0)&&(pici[i].getPopust() < 101)){
            pici[i].pecati();
            float popust = pici[i].getCena() - float(pici[i].getPopust())/100*pici[i].getCena();
            cout<<" "<<popust <<endl;
          }
        }
    }

    ~Picerija(){
    delete[] pici;
    }

};


int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1 += p;
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2 += p;

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}
