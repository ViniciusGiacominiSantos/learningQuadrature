#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
// Vamos integrar a função (x + x² + x³) no intervalo de 0 a 1.

/*
Tentar criar classe e continuar deixando o progama rodar certo;
Se der tempo, criar um sistema que calcule os pesos w.
*/

double erro = pow(10,-4);
int ordem = 10000;
int ponto = (ordem+1)/2;
double a = 0; // Limite inferior do intervalo
double b = 5; // Limite superior do intervalo
double J = (b-a)/2; //Jacobiano


double f(double x);
int main(){
    
    //listas do tipo xn=[x0,x1,x2,...]
    double x1[]={0};
    long double x2[]={1/sqrt(3),-1/sqrt(3)};
    long double x3[]={0,sqrt(3.L/5.L),-sqrt(3.L/5.L)};
    long double x4[]={sqrt((3.L/7.L)-((2.L/7.L)*sqrt(6.L/5.L))),-sqrt((3.L/7.L)-((2.L/7.L)*sqrt(6.L/5.L))),sqrt((3.L/7.L)+((2.L/7.L)*sqrt(6.L/5.L))),-sqrt((3.L/7.L)+((2.L/7.L)*sqrt(6.L/5.L)))};
    //listas do tipo wn=[w0,w1,w2,...]
    int w1[]={2};
    int w2[]={1};
    long double w3[]={8.L/9.L,5.L/9.L};
    long double w4[]={((18.L+sqrt(30.L))/36.L),((18.L-sqrt(30.L))/36.L)};
    double integral = 0;
    double integ[4]={};
    integ[0] = w1[0]*f(x1[0]);
    integ[1] = w2[0]*f(x2[0])+w2[0]*f(x2[1]);
    integ[2] = w3[0]*f(x3[0])+w3[1]*f(x3[1])+w3[1]*f(x3[2]);
    integ[3] = w4[0]*f(x4[0])+w4[0]*f(x4[1])+w4[1]*f(x4[2])+w4[1]*f(x4[3]); 
    if(ponto <= 1 && ponto >= 0){
        integral = integ[0];
    } else if(ponto <= 2){
        integral = integ[1];
    } else if(ponto <= 3){
        integral = integ[2];
    } else if(ponto <= 4){
        integral = integ[3];
    } else {                    //Se n for polinomio, fazer abs|ponto(k-1)-ponto(k)| < erro, ideia: while <erro ou ponto>4
        int i = 0;
        if(integ[i]-integ[i+1] <= erro){
            integral=integ[0];
        } else {
            while(abs(integ[i]-integ[i+1]) > erro && i<=3){
                std::cout<<i<<std::endl;
                std::cout<<integ[i]<<std::endl;
                std::cout<<integ[i+1]<<std::endl;
                integral = integ[i];
                i+=1;
            }
        }       
    }
    integral *= J;
    std::cout << integral << std::endl;
    return 0;
}
double f(double x){
    double result = 0;
    x=((b-a)/2)*x + (a+b)/2; //Mapeamento
    //result = (1/x) + x+ x*x + x*x*x; // item a
    //result = sin(x); // item b
    result = pow(x,-0.5); // item c
    return result;
}   