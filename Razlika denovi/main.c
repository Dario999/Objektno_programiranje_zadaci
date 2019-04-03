#include <stdio.h>
#include <stdlib.h>
typedef struct datum{
    int den;
    int mesec;
    int godina;
}datum;

short sporedba(datum d1,datum d2)
{
    if(d1.den==d2.den && d1.mesec==d2.mesec && d1.godina==d2.godina)
        return 0;
    if(d1.godina>d2.godina)
        return 1;
    else if(d1.godina<d2.godina)
        return -1;
    else
    {
        if(d1.mesec>d2.mesec)
            return 1;
        else if(d1.mesec<d2.mesec)
            return -1;
        else
        {
            if(d1.den>d2.den)
                return 1;
            else
                return -1;
        }
    }
}

long razlika(datum d1,datum d2)
{
    long denovi;
    denovi=d1.den-d2.den;
    denovi+=(d1.mesec-d2.mesec)*30;
    denovi+=(d1.godina-d2.godina)*360;
    return denovi;
}
int main()
{
    datum d1={12,12,1989};
    datum d2;
    d2.den=16;
    d2.mesec=12;
    d2.godina=1989;
    if(sporedba(d1,d2)==0)
        printf("Isti");
    else if(sporedba(d1,d2)==1)
        printf("Razlikata pomegu datuite e %d dena." , razlika(d1,d2));
    else
        printf("Razlikata pomegu datumite e %d dena." , razlika(d2,d1));
}
