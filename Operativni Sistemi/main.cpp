#include <iostream>
#include <cstring>
using namespace std;
enum Tip{
    LINUX,UNIX,WINDOWS
};
class OperativenSistem{
private:
    char *ime;
    float verzija;
    Tip t;
    float golemina;
public:

    OperativenSistem(const char *ime="",float verzija=0.0,Tip t=(Tip) 0,float golemin=0.0){
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime,ime);
        this->verzija= verzija;
        this->t = t;
        this->golemina = golemin;
    }
    OperativenSistem(const OperativenSistem &os){
        ime = new char[strlen(os.ime)+1];
        strcpy(ime,os.ime);
        verzija = os.verzija;
        golemina = os.golemina;
        t = os.t;
    }
    ~OperativenSistem(){
        delete[] ime;
    }
    OperativenSistem &operator=(const OperativenSistem &os){
        if(this!=&os){
            delete[] ime;
            ime = new char[strlen(os.ime)+1];
            strcpy(ime,os.ime);
            verzija = os.verzija;
            golemina= os.golemina;
            t = os.t;
        }
        return *this;
    }
    void pecati(){
        cout << "Ime: " << this->ime << " Verzija: " << this->verzija << " Tip: " << this->t << " Golemina:" << this->golemina << "GB" << endl;
    }
    bool ednakviSe(const OperativenSistem &os){
        return strcmp(ime,os.ime)==0&&verzija == os.verzija && t==os.t && golemina == os.golemina;
    }
    int sporediverzija(const OperativenSistem &os){
        if(verzija == os.verzija)
            return 0;
        else if(os.verzija>verzija)
            return -1;
        else
            return 1;
    }
    bool istaFamilija(const OperativenSistem &sporedba){
        if(strcmp(ime,sporedba.ime)==0 && t==sporedba.t)
            return true;
        else
            return false;
    }

    float getVerzija(){
        return verzija;
    }
};

class Repozitorium{
private:
    char ime[20];
    OperativenSistem *os;
    int broj;
public:
    Repozitorium(const char *ime){
        strcpy(this->ime,ime);
        os = new OperativenSistem[0];
        broj =0;
    }
    ~Repozitorium(){
        delete[] os;
    }

    Repozitorium(const Repozitorium &r){
        strcpy(ime,r.ime);
        broj = r.broj;
        os = new OperativenSistem[broj];
        for(int i=0;i<broj;i++)
            os[i] = r.os[i];
    }
    void pecatiOperativniSistemi(){
        cout<<"Repozitorium: "<<ime<<endl;
        for(int i=0;i<broj;i++)
            os[i].pecati();
    }
    void izbrishi(const OperativenSistem &izbr){
        int index = -1;
        for(int i=0;i<broj;i++)
            if(os[i].ednakviSe(izbr)){
                index = i;
                break;
            }

    if(index == -1)
        return;

    OperativenSistem *tmp = new OperativenSistem[broj-1];
    int j=0;
    for(int i=0;i<broj;i++){
        if(i!=index){
            tmp[j]=os[i];
            j++;
        }
        else
            continue;
    }
    broj--;
    delete[] os;
    os = tmp;
    }

    void dodadi(const OperativenSistem &os1){
        for(int i=0;i<broj;i++){
            if(os[i].istaFamilija(os1) && os[i].sporediverzija(os1)==-1){
                os[i]=os1;
                return;
            }
        }
        OperativenSistem *tmp = new OperativenSistem[broj+1];
        for(int i=0;i<broj;i++)
            tmp[i] = os[i];
        tmp[broj++]=os1;
        delete[] os;
        os = tmp;
    }

};

int main() {
    char repoName[20];
    cin>>repoName;
    Repozitorium repozitorium=Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin>>brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i<brojOperativniSistemi; i++){
        cin>>ime;
        cin>>verzija;
        cin>>tip;
        cin>>golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
     cin>>ime;
    cin>>verzija;
    cin>>tip;
    cin>>golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout<<"=====Brishenje na operativen sistem====="<<endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}
