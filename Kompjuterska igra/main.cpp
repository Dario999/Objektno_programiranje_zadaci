#include<iostream>
using namespace std;
/*

Да се креира структура Igrac во која се чуваат податоци за еден играч на компјутерската игра.
 За играчот се чуваат информации за корисничкото име на играчот (низа од 15 знаци), број на 
 ниво до кој играчот е стигнат (цел број) и број на освоени поени (цел број) (10 поени).

Потоа да се креирa структура KompjuterskaIgra во која се чуваат податоци за името на играта (низа од 20 знаци),
 низа од играчи кои ја играат играта (најмногу 30) и бројот на играчи. (10 поени)

Треба да се направи функција со потпис (15 поени)

void najdobarIgrac(KompjuterskaIgra *lista, int n)

Оваа функција треба да го испечати името на најдобриот играч на онаа игра која има најголема популарност 
(ја играат наjголем број на играчи). Најдобар играч е играчот кој има најголем број на освоени поени. Ако
има повеќе играчи со ист максимален број на освоени поени, најдобар е играчот кој има достигнато најголемо ниво.

Печатењето е во форматот: "Najdobar igrac e igracot so korisnicko ime XXXXX koj ja igra igrata YYYYYY".
 (XXXXXX е корисничкото име на најдобриот играч,а YYYYY е името на играта која ја играат најголем број на играчи)

(Забелешка: секогаш ќе има точно еден најдобар играч)

Функционалност на задачата и дополнување на main функцијата (10 поени)

Забелешка: Задачата да се реши во програмскиот јазик C+
*/

struct Igrac{
	char ime[15];
    int nivo;
    int poeni;
};

struct KompjuterskaIgra{
	char ime[20];
    Igrac igraci[30];
    int brojIgraci;
};

void najdobarIgrac(KompjuterskaIgra *lista,int n){
	KompjuterskaIgra najdobraigra;
	najdobraigra.brojIgraci=0;
    Igrac najdobarigrac;
    najdobarigrac.poeni=0;
    int max=0;
    for(int i=0;i<n;i++){
    	if(lista[i].brojIgraci>najdobraigra.brojIgraci)
            najdobraigra=lista[i];
    }
    for(int i=0;i<najdobraigra.brojIgraci;i++){
        if(najdobraigra.igraci[i].poeni>max){
            najdobarigrac = najdobraigra.igraci[i];
            max = najdobraigra.igraci[i].poeni;
        }
    }
    cout<<"Najdobar igrac e igracot so korisnicko ime "<<najdobarigrac.ime<<" koj ja igra igrata "<<najdobraigra.ime<<endl;
}
int main(){

    int n;
	cin>>n; //se cita brojot na igri

    KompjuterskaIgra igri[100];
    for (int i=0;i<n;i++){
        cin>>igri[i].ime;
        cin>>igri[i].brojIgraci;
        for (int j=0;j<igri[i].brojIgraci;j++){
            cin>>igri[i].igraci[j].ime;
            cin>>igri[i].igraci[j].nivo;
            cin>>igri[i].igraci[j].poeni;
            };
        };


najdobarIgrac(igri,n);
return 0;
}
