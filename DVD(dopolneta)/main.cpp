#include <iostream>
#include <cstring>
using namespace std;
enum zanr{
    akcija,komedija,drama
};
class Film{
private:
    char *ime;
    int memorija;
    zanr z;
public:
    Film(){
        ime = new char[0];
        memorija = 0;
        z = (zanr)0;
    }
    Film(const char *i,int memorija,zanr zz){
        ime = new char[strlen(i)+1];
        strcpy(ime,i);
        this->memorija = memorija;
        z = zz;
    }

    Film(const Film &f){
        ime = new char[strlen(f.ime)+1];
        strcpy(ime,f.ime);
        memorija = f.memorija;
        z = f.z;
    }
    Film &operator=(const Film &f){
        if(this!=&f){
            delete[] ime;
            ime = new char[strlen(f.ime)+1];
            strcpy(ime,f.ime);
            memorija = f.memorija;
            z = f.z;
        }
        return *this;
    }

    ~Film(){
        delete[] ime;
    }

    void pecati(){
        cout<<memorija<<"MB"<<"-\""<<ime<<"\""<<endl;
    }

    int getMemorija(){
        return memorija;
    }

    zanr getZhanr(){
        return z;
    }
};

class DVD{
private:
    Film film[5];
    int brFilmovi;
    int kapacitet;
    int momentalno;
public:
    DVD(int memorija){
        brFilmovi=0;
        kapacitet=memorija;
        momentalno=0;
    }
    DVD &operator=(const DVD &d){
        if(this!=&d){
            brFilmovi = d.brFilmovi;
            for(int i=0;i<brFilmovi;i++)
                film[i]=d.film[i];
            kapacitet = d.kapacitet;
            momentalno = d.momentalno;
        }
        return *this;
    }
    Film getFilm(int i){
        return film[i];
    }

    void dodadiFilm(Film f){
        if(momentalno+f.getMemorija()<=kapacitet&&brFilmovi<5){
            film[brFilmovi++]=f;
            momentalno+=f.getMemorija();
        }
    }

    void pecatiFilmoviDrugZanr(const zanr r){
        for(int i=0;i<brFilmovi;i++){
            if(film[i].getZhanr()!=r)
                film[i].pecati();
        }
    }

    int getBroj(){
        return brFilmovi;
    }

    float procentNaMemorijaOdZanr(zanr r){
        float sum=0.0;
        for(int i=0;i<brFilmovi;i++)
            if(film[i].getZhanr()==r)
                sum+=film[i].getMemorija();
        return sum/momentalno*100.0;
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (zanr) kojzanr);
        f.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((zanr) kojzanr);

    } else if (testCase == 6){
		cout<<"===== Testirawe na metodot procentNaMemorijaOdZanr() od klasata DVD =====" <<endl;
		DVD omileno(40);
		cin >> n;
		for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; //se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (zanr) kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout<<"Procent na filmovi od dadeniot zanr iznesuva: "<<omileno.procentNaMemorijaOdZanr((zanr) kojzanr)<<"%\n";

	}

    return 0;
}
