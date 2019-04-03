#include <stdio.h>
 /*

Во програмскиот јазик C да се креира структура Pacient и истата треба да содржи: (5 поени)

    Име и презиме на пациентот ( низа од макс. 100 знаци)
    Дали е здраствено осигуран (1-да, 0-не)
    Број на прегледи во текот на последниот месец (цел број)

Да се креира структура MaticenDoktor, која во себе содржи: (5 поени)

    Име на докторот (низа од 100 знаци)
    Број на пациенти (цел број)
    Листа од пациенти (низа од максимум 200 елементи од структурата Pacient)
    Цена на преглед (децимален број)

Да се креираат метода najuspesen_doktor, која прима низа од променливи од типот 
MaticenDoktor и нивниот број; и го печати името, заработената сума и бројот на 
прегледи на оној доктор кој заработил најголема сума од пациенти кои ги прегледувал 
приватно (не се здраствено осигурани) (10 поени). Доколку два или повеќе доктори имаат
 иста сума, тогаш се печати оној доктор кој има направено најголем број на прегледи вкупно 
 во текот на последниот месец. (20 поени)

Функционалност (5 поени).
*/
typedef struct Pacienti {
    char ime[100];
    int pregledi;
    int zdravstveno;
} Pacienti;

typedef struct MaticenDoktor {
    char ime[100];
    int br_pac;
    float cena;
    Pacienti pacienti[100];
} MaticenDoktor;

void najdobar_doktor(MaticenDoktor *md, int n) {
    int i, j, k;
    int total, final;
    float sum = 0.0f, max = 0.0f;
    for(i = 0; i < n; i++) {
        sum = 0.0;
        total = 0;
        for(j = 0; j < md[i].br_pac; j++) {

            total += md[i].pacienti[j].pregledi;

            if(md[i].pacienti[j].zdravstveno == 0) {
                sum += md[i].cena * md[i].pacienti[j].pregledi;
            }
        }
        if(sum > max) {
            max = sum;
            k = i;
            final = total;
        }
        if(sum == max) {
            if(total > final) {
                k = i;
                final = total;
            }
        }
    }
    printf("%s %.2f %d", md[k].ime, max, final);
}

int main() {

    int i, j, n;
    scanf("%d", &n);
    MaticenDoktor md[n];
    for (i = 0; i < n; i++) {
        //ime na doktor
        scanf("%s", md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++) {
            scanf("%s", md[i].pacienti[j].ime);
            scanf("%d", &md[i].pacienti[j].zdravstveno);
            scanf("%d", &md[i].pacienti[j].pregledi);
        }
    }
    najdobar_doktor(md, n);

    return 0;
}
