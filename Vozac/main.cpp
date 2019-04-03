#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Vozac{
protected:
    char ime[100];
    int vozrast;
    int brTrki;
    bool daliVeteran;
public:
    Vozac(const char *ime="",int vozrast=0,int brTrki=0,bool daliVeteran=0){
        strcpy(this->ime,ime);
        this->vozrast = vozrast;
        this->brTrki = brTrki;
        this->daliVeteran = daliVeteran;
    }
    friend ostream &operator<<(ostream &out,Vozac &v){
        out<<v.ime<<endl;
        out<<v.vozrast<<endl;
        out<<v.brTrki<<endl;
        if(v.daliVeteran)
            out<<"VETERAN"<<endl;
        return out;
    }

    virtual double zarabotuvacka() = 0;
    virtual double danok() = 0;


    friend bool operator==(Vozac &v1,Vozac &v2){
        return v1.zarabotuvacka() == v2.zarabotuvacka();
    }

    virtual ~Vozac(){
    }
};

class Avtomobilist:public Vozac{
private:
    int cena;
public:
    Avtomobilist(const char *ime="",int vozrast=0,int brTrki=0,bool daliVeteran=0,int cena=0)
        :Vozac(ime,vozrast,brTrki,daliVeteran){
            this->cena = cena;
        }
    double zarabotuvacka(){
        return cena/5;
    }
    double danok(){
        if(brTrki > 10)
            return zarabotuvacka()/100*15;
        else
            return zarabotuvacka()/100*10;
    }

};

class Motociklist:public Vozac{
private:
    int moknost;
public:
    Motociklist(const char *ime="",int vozrast=0,int brTrki=0,bool daliVeteran=0,int moknost=0)
        :Vozac(ime,vozrast,brTrki,daliVeteran){
            this->moknost = moknost;
        }
    double zarabotuvacka(){
        return moknost*20;
    }
    double danok(){
        if(daliVeteran)
            return zarabotuvacka()/100*25;
        else
            return zarabotuvacka()/100*20;
    }

};

int soIstaZarabotuvachka(Vozac **niza,int n,Vozac *pok){
    int sum=0;
    for(int i=0;i<n;i++){
        if(niza[i]->zarabotuvacka() == pok->zarabotuvacka())
            sum++;
    }
    return sum;
}

int main() {
	int n, x;
	cin >> n >> x;
	Vozac **v = new Vozac*[n];
	char ime[100];
	int vozrast;
	int trki;
	bool vet;
	for(int i = 0; i < n; ++i) {
		cin >> ime >> vozrast >> trki >> vet;
		if(i < x) {
			float cena_avto;
			cin >> cena_avto;
			v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
		} else {
			int mokjnost;
			cin >> mokjnost;
			v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
		}
	}
	cout << "=== DANOK ===" << endl;
	for(int i = 0; i < n; ++i) {
		cout << *v[i];
		cout << v[i]->danok() << endl;
	}
	cin >> ime >> vozrast >> trki >> vet;
	int mokjnost;
	cin >> mokjnost;
	Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
	cout << "=== VOZAC X ===" << endl;
	cout << *vx;
	cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
	cout << soIstaZarabotuvachka(v, n, vx);
    for(int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete [] v;
    delete vx;
	return 0;
}
