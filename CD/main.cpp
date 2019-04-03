#include <iostream>
#include <cstring>
using namespace std;
/*

Да се дефинира класата Pesna во која се чуваат информации за (5 поени):

    име на песна (динамички алоцирано поле од знаци)
    времетраење на песната во минути
    тип на песна кој може да биде: поп, рап или рок (енумерација tip)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (10 поени)

Дополнително за оваа класа да се дефинира методот:

    pecati() - функција во која ќе се печатат одделени со цртичка(-): името на песната во наводници и времетраењето на песната со постфикс min. (5 поени)

Да се креира класата CD во која се чуваат информации за (5 поени):

    низа од песни снимени на CD-то (Поле од најмногу 10 објекти од класата Pesna )
    број на песни снимени на CD-то
    максимално времетраење на песните на CD-то (во минути)

Да се обезбедат сите потребни методи за класата за правилно функционирање на програмата. (5 поени)

Дополнително за оваа класа да се дефинираат методите:

    dodadiPesna (Pesna p) - со кој се додава песната p на CDто, но само ако има доволно преостанато место (земајќи го предвид максималното времетраење на песните на CDто и времетраењата на песните на CD-то) и ако има помалку од 10 песни на CD-то. (10 поени)
    pecatiPesniPoTip(tip t) – со кој се печатат информациите за сите песни од тип t (поп, рап или рок). (10 поени)

Комплетна функционалност (5 поени).
*/
enum tip{
    pop,rap,rok
};

class Pesna{
private:
    char *ime;
    int vremetraenje;
    tip muzika;
public:
    Pesna(){
    }
    Pesna(const char *ime,int vremetraenje,const tip muzika){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->vremetraenje=vremetraenje;
        this->muzika=muzika;
    }

    Pesna(const Pesna &p){
        ime = new char[strlen(p.ime)+1];
        strcpy(ime,p.ime);
        vremetraenje = p.vremetraenje;
        muzika = p.muzika;
    }

    Pesna &operator=(const Pesna &p){
        if(this!=&p){
            ime = new char[strlen(p.ime)+1];
            strcpy(ime,p.ime);
            vremetraenje = p.vremetraenje;
            muzika = p.muzika;
        }
        return *this;
    }

    int get_vremetraenje(){
        return vremetraenje;
    }

    void pecati(){
        cout<<"\""<<ime<<"\""<<"-"<<vremetraenje<<"min"<<endl;
    }

    tip getTip(){
        return (tip)muzika;
    }
};

class CD{
private:
    Pesna cd[10];
    int brojPesni;
    int maxVremetraenje;
public:
    CD(int broj){
    	maxVremetraenje = broj;
        brojPesni=0;
    }
    CD(Pesna *c=0,int brojPesni=0,int maxVremetraenje=0){
        this->brojPesni=brojPesni;
        this->maxVremetraenje=maxVremetraenje;
        for(int i=0;i<10;i++){
            cd[i]=c[i];
        }
    }

    CD(const CD &c){
        brojPesni = c.brojPesni;
        maxVremetraenje = c.maxVremetraenje;
        for(int i=0;i<brojPesni;i++){
            cd[i] = c.cd[i];
        }
    }

    CD &operator=(const CD &c){
        if(this!=&c){
            brojPesni = c.brojPesni;
            maxVremetraenje = c.maxVremetraenje;
            for(int i=0;i<brojPesni;i++){
                cd[i] = c.cd[i];
        }
        }
        return *this;
    }
    Pesna getPesna(int i){
        return cd[i];
    }

    int getBroj(){
        return brojPesni;
    }

    void dodadiPesna(Pesna p){
        brojPesni++;
        int sum=0;
        for(int i=0;i<brojPesni-1;i++)
            sum+=cd[i].get_vremetraenje();
        sum+=p.get_vremetraenje();
        if(brojPesni<10&&sum<maxVremetraenje)
        	cd[brojPesni-1] = p;
        else
            --brojPesni;
    }

    void pecatiPesniPoTip(tip t){
        for(int i=0;i<brojPesni;i++){
            if(cd[i].getTip()==t)
                cd[i].pecati();
        }
    }


};

int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;

	int n, minuti, kojtip;
	char ime[50];

	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        for (int i=0; i<n; i++)
            (omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);

    }

return 0;
}
