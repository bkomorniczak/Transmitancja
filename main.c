#include <stdio.h>


void withoutZeroesCaseInputData(){
    int withoutZeroesNumerator = 0;
    int n = 0;                                                      // number of both factor and states in denominator
    int denominatorFactors[n];



    printf("Podaj wspolczynnik licznika\n");
    scanf("%d", &withoutZeroesNumerator);

    printf("Podaj liczbe wspolczynnikow z mianownika.\n");
    scanf("%d", &n);

    printf("Podaj kolejne wspolczynniki:\n");
    for(int i=0; i < n; i++){
        scanf("%d",&denominatorFactors[i]);
    }


    printf("Rownanie stanow:\n");
    for (int i=0; i<n; i++){
        printf("s^%d",n-i);
        printf("+");
        printf("%d",denominatorFactors[i]);
    }
    printf(" = 0\n");

    printf("Wektor stanu")


}

void withZeroes(){

}

void getUserData(){
    int numberOfFactorsInNumerator = 0;

    printf("Podaj liczbe wspolczynnikow w liczniku");
    scanf("%d",&numberOfFactorsInNumerator);
    if(numberOfFactorsInNumerator==1){
        printf("Podaj wartosc z licznika.");

    }
    int factorsInNumerator[numberOfFactorsInNumerator];
    printf("Podaj kolejne wspolczynniki");
    for(int i =0;i<numberOfFactorsInNumerator;i++){

    }

}


int main() {
    int numberOfFactorsInNumerator = 0;
    printf("Podaj liczbe wspolczynnikow w liczniku\n");
    scanf("%d",&numberOfFactorsInNumerator);
    if(numberOfFactorsInNumerator==1){
        withoutZeroesCaseInputData();
    }else{
        withZeroes();
    }
    return 0;
}
