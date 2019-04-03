#include <stdio.h>
#include <string.h>
/*

Да се креира структура Proizvod во која се чуваат податоци за кодот напрозиводот (низа од 20 знаци), 
единична цена на производ (цел број), бројот на достапни производи кои ги има во еден магацин (цел број) .

Потоа да се креирa структура Narachka во која се чуваат податоци за името лицето кое ја прави нарачката 
(низи од 15 знаци), низа од Proizvodi (максимум 10) кои ги има во нарачката, низа од бројот на нарачани 
производи за секоја производ посебно (максимум10) и бројот на производи во нарачката .

Треба да се направи функција со потпис

void pecatiFaktura(Narachka n)

која што ќе ги отпечати една фактура за една нарачка (n) .

Во фактурата во првиот ред се печати: Faktura za XXXXX, каде XXXXX е името на лицето кое ја прави нарачката.

Ако сите производи може да се нарачаат печатат нарачаните производи, подредени по азбучен ред според кодот на 
производот. Во следните редови, во секој ред посебно се печати кодот на производот, единична цена на производот,
број на нарачани производи и вкупната цена на производот (сите се одделени со едно празно место) . Исто така бројот 
на достапни производи од тој производ да се ажурира (да се намали за бројот на нарачани производи од тој производ).
 Во последниот ред да се отпечати: Vkupnata suma na fakturata e XXX, каде XXX е вкупната сума за цените за сите нарачани производи.

Ако постои производ кој не може да биде нарачан затоа што во магацинот не се достапни нарачаниот број производи тогаш 
не може да се изготви фактура за нарачката. На екранот да се отпечати: Fakturata ne moze da se izgotvi.
*/
//место за вашиот код
typedef struct Proizvod{
	char kod[20];
    int cena;
    int lager;
}Proizvod;

typedef struct Narachka{
	char ime[15];
    Proizvod proizvodi[10];
    int narProizvodi[10];
    int n;
}Narachka;

void pecatiFaktura(Narachka n){
	printf("Faktura za %s\n" , n.ime);
    int i,flag=0,j;
    for(i=0;i<n.n;i++)
        if(n.proizvodi[i].lager-n.narProizvodi[i]<0)
        	flag=1;
    if(flag)
        printf("Fakturata ne moze da se izgotvi");
    else {
        for(i=0;i<n.n-1;i++){
            for(j=i+1;j<n.n;j++){
                if(strcmp(n.proizvodi[i].kod,n.proizvodi[j].kod)>0){
                	Proizvod temp=n.proizvodi[i];
                    n.proizvodi[i]=n.proizvodi[j];
                    n.proizvodi[j]=temp;
                }
            }
        }
    int s=0;
    for(i=0;i<n.n;i++){
    	printf("%s %d %d %d\n",n.proizvodi[i].kod,n.proizvodi[i].cena,n.narProizvodi[i],n.proizvodi[i].cena*n.narProizvodi[i]);
    	s+=n.proizvodi[i].cena*n.narProizvodi[i];
    }
    printf("Vkupnata suma na fakturata e %d",s);
    }
}
int main() {

    Narachka narachka;
	char ime[15],kod[20];
    int cena,lager,n,i,j;
    // внеси го името лицето кое ја прави нарачката
    // внеси го бројот на порачани производи во нарачката
    Proizvod proizvodi[30];
    scanf("%s" , narachka.ime);
    scanf("%d",&narachka.n);
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.n; ++i) {
        scanf("%s",proizvodi[i].kod);
        scanf("%d",&proizvodi[i].cena);
        scanf("%d",&proizvodi[i].lager);
        narachka.proizvodi[i]=proizvodi[i];
    }
    for (j = 0; j < narachka.n; ++j) {
       scanf("%d",&narachka.narProizvodi[j]);
    }
	pecatiFaktura(narachka);

    // повик на функцијата pecatiFaktura


    return 0;
}
