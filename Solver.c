#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const double PI = 3.14159;

void exitInvalid(){
    printf("-1");
    exit(0);
}

double power(double a, int t)
{
    double temp=1;
    for (int i =0; i<t; i++)
    {
        temp = temp*a;
    }
    return temp;
}

double giaithua(int b)
{
    double temp = 1;
    for (int i = 1; i<=b; i++)
    {
        temp = temp*i;
    }
    return temp;
}

void ketqua( float c, int p)
{
    switch(p) //lam tron
       {
            case 2:
                printf("%.2f", c);
                break;
            case 4:
                printf("%.4f", c);
                break;
            case 7:
                printf("%.7f", c);
                break;
            default:
                exitInvalid();
                break;
       }
}

int main()
{
    int menu_code;
    int n=0, m=0, p=0;
    double x=0;
    double result=0;
    scanf("%d", &menu_code);
    if(menu_code == 1) {
       scanf("%d%d%d", &n, &m, &p);
       if (n!=1 && n!=2 && n!=3){
            exitInvalid();
       }
       if (m!=0 && m!=1){
            exitInvalid();
       }
       if (p!=2 && p!=4 && p!=7){
            exitInvalid();
       }
       scanf("%lf", &x);
       if (m == 0)
       {
           if(0<=x && x<=180){
                x= x*(PI/180);
           } else {exitInvalid();}
       } else{
           if (m==1){
                if(0<=x && x<=PI){
                    x = x;
                } else exitInvalid();
            }
       }
       switch (n)
       {
            case 1:
                result = x - (power(x,3)/giaithua(3)) + (power(x,5)/giaithua(5)) - (power(x,7)/giaithua(7)) + (power(x,9)/giaithua(9)) - (power(x,11)/giaithua(11));
                ketqua(result,p);
                break;
            case 2:
                result = 1 - (power(x,2)/giaithua(2)) + (power(x,4)/giaithua(4)) - (power(x,6)/giaithua(6)) + (power(x,8)/giaithua(8)) - (power(x,10)/giaithua(10));
                ketqua(result,p);
                break;
            case 3:
                if (x == PI/2){
                    exitInvalid();
                }
                else {
                    result = ((x - (power(x,3)/giaithua(3)) + (power(x,5)/giaithua(5)) - (power(x,7)/giaithua(7)) + (power(x,9)/giaithua(9)) - (power(x,11)/giaithua(11)))/
                    (1 - (power(x,2)/giaithua(2)) + (power(x,4)/giaithua(4)) - (power(x,6)/giaithua(6)) + (power(x,8)/giaithua(8)) - (power(x,10)/giaithua(10))));
                    ketqua(result,p);
                }
                break;
        default:
            exitInvalid();
            break;
       }
    }
    else if (menu_code == 2) {
            int m=0, x=0;
            scanf("%d", &m);
            if (m!=1 && m!=2){
                exitInvalid();
            }
            scanf("%d", &x);
            if (x<=1){
                exitInvalid();
            }
            switch(m)
            {
                case 1:
                    for(int i =1;i<x; i++){
                        if (x%i == 0){
                            printf("%d ", i);
                        }
                    }
                    printf("%d", x);
                    break;
                case 2:
                    for(int i = 2; i <= x; i++){
                        int dem = 0;
                        while(x % i == 0){
                            ++dem;
                            x /= i;
                        }
                        if(dem){
                        if(dem >= 1) printf("%d^%d", i, dem);
                        else printf("%d", i);
                        if(x > i){
                            printf("*");
                            }
                        }
                    }
                    break;
                default:
                    exitInvalid();
                    break;
            }
    } else {
        exitInvalid();
    }
}
