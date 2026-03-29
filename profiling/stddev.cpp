#include <iostream>
#include "../src/core/mathlib.h"

int main(){
    long double x = 0;
    //soucet vsech cisel do jednoho
    long double sum = 0;
    //soucet vsech cisel s druhou mocninou
    long double sum2 = 0;
    //pocet nactenych cisel
    long double n = 0;
    //aritmeticky prumer
    long double avg = 0;
    //výsledek(smerodatna odchylka)
    long double result = 0;
    
    // nacitani cisel ze vstupu
    while (std::cin >> x){
        n = add(n,1);
        sum = add(sum, x);
        sum2= add(sum2, multiply(x, x));
    }

    //musi byt aspon 2 cisla
    if (n<2){
        return 1;
    }

    //prumer
    avg = divide(sum, n);

    //smerodatna odchylka
    result = divide(
        subtract(sum2, multiply(n,multiply(avg,avg))),
        subtract(n,1)
    );

    result = root(result, 2);

    //vypis vysledku
    std::cout << result << std::endl;

    return 0;
}