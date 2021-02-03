#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mem.h>

int withoutZeroesCaseInputData(){
    int withoutZeroesNumerator = 0;
    int n = 0;                                                      // number of both factor and states in denominator

    printf("Program bada stabilnosc wprowadzonych przez uzytkownika rownan stanu\n");
    printf("Podaj wspolczynnik licznika\n");
    scanf("%d", &withoutZeroesNumerator);

    printf("Podaj liczbe wspolczynnikow z mianownika.\n");
    scanf("%d", &n);
    int denominatorFactors[n];

    printf("Podaj kolejne wspolczynniki:\n");
    for(int i=0; i < n; i++){
        scanf("%d",&denominatorFactors[i]);
    }

    printf("Rownanie stanow:\n");
    for (int i=0; i<n; i++){
        printf("%ds^%d",denominatorFactors[i],n-(i+1));
       if(i!=n) {
           printf("+");
       }
    }
    int resultArray[n];
    memccpy(resultArray,denominatorFactors,'#',n * sizeof(int));
    printf(" = 0\n");

    printf("Rownanie stanu w postaci wektorowo macierzowej:\n");

    printf("x'1 =  0\t 1 \t |x1(t)|\t\t0\n\t\t\t\t\t+\nx'2 = ");
    int statesVector[n];
    memmove(statesVector,denominatorFactors,n * sizeof(int));

    for(int i = 0; i<n;i++){
        statesVector[i] = -1 * statesVector[i];
    }
    for(int i = 1; i<n;i++){
        printf("%d\t",statesVector[i]);
    }
    printf(" |x2(t)|\t\t1u(t)\n");
    printf("\n");
    printf("Rownanie wyjscia w postaci wektorowo-macierzowej:\n");
    printf("\t  [x1(t)]\n");
    printf("y(t)=[0\t1][x2(t)]u(t)\n");

   /*
    for(int i = 0;i<3;i++){
        printf("%d",resultArray[i]);
    }*/
    return (int) resultArray;

}



int  withZeroes(int numberOfFactorsInNumerator){
    int numberOfDenominatorFactors = 0;
    int numeratorFactors[numberOfFactorsInNumerator];

    printf("Podaj kolejne wspolczynniki z licznika: \n");
    for(int i=0; i < numberOfFactorsInNumerator; i++){
        scanf("%d",&numeratorFactors[i]);
    }

    printf("Podaj liczbe wspolczynnikow mianownika\n");
    scanf("%d", &numberOfDenominatorFactors);
    int denominatorFactors[numberOfDenominatorFactors];
    printf("Podaj kolejne wspolczynniki mianownika\n");
    for(int i = 0; i<numberOfDenominatorFactors;i++){
        scanf("%d", &denominatorFactors[i]);
    }

    printf("(1)\n\n");
    int statesVectorOfNumerator[numberOfFactorsInNumerator];
    memmove(statesVectorOfNumerator, denominatorFactors, numberOfDenominatorFactors * sizeof(int));
    for(int i = 0; i<numberOfDenominatorFactors;i++){
        statesVectorOfNumerator[i] = -1 * statesVectorOfNumerator[i];
    }
    printf("Rownianie stanu w postaci wektorowo-macierzowej\n");
    printf("x1(t)\t 0\t %d [x1(t)]\t[0]\n",numeratorFactors[0]);
    printf("      =\n");
    printf("x2(t)\t%d\t%d [x2(t)]\t[1] u(t)",statesVectorOfNumerator[2],statesVectorOfNumerator[1]);


    printf("\n\n\n(2)\n\n");

    int vectorMatrixFactors[2];
    vectorMatrixFactors[0] = statesVectorOfNumerator[2] + numeratorFactors[2];
    vectorMatrixFactors[1] = statesVectorOfNumerator[1] + numeratorFactors[1];

    printf("Rownanie wyjscia w postaci wektorowo-macierzowej\n");
    printf("\t\t  x1(t)\n");
    printf("y(t) = [%d\t%d]x2(t) + u(t)\n",vectorMatrixFactors[0], vectorMatrixFactors[1]);


    return (int) denominatorFactors;
}

void checkStability(int  denominatorFactors[]){
    int memArray[4];
    memArray[3] = 0;
    memArray[2] = *denominatorFactors;
    memArray[1] = *denominatorFactors+1;
    memArray[0] = *denominatorFactors+2;

    bool isStable = false;
    bool isNotStable = false;
    bool isOnTheEdgeOfStability = false;
    int submark1 = memArray[0];
    int submark2 =memArray[1] * memArray[2];
    printf("Badanie stabilnosci z zastosowaniem algebraicznego kryterium Hurwitza. \n");
    printf("Badany uklad:\n");
    int n = 4;
    for(int i = 0;i<n;i++){
        printf("%d\t",memArray[i]);
    }
    printf("\n");

    for(int i =0; i < n; i++){
        if(memArray[i] > 0 && submark1 > 0 && submark2 > 0){
            isStable = true;

        }
    }
    if(memArray[n] == 0 ||submark1 == 0 ||submark2 == 0){
        isOnTheEdgeOfStability = true;
        printf("Podwyznacznik1 = %d\nPodwyznacznik2 = %d\nWyraz wolny = %d\n", submark1,submark2, memArray[n]);

    }
    for(int i = 0;i<n;i++){
        if(memArray[i] < 0 || submark1 < 0 || submark2 < 0){
            isNotStable = true;

        }
    }

    if(isStable){
        printf("Uklad stabilny asymptotycznie.\n");
        printf("Wszystkie wspolczynniki rownania charakterystycznego sa wieksze od zera,\n oraz podwyznaczniki - minory wyznacznika glownego sa wieksze od 0\n");
    }
    if(isNotStable){
        printf("Uklad niestabilny.\n");
        printf("Uklad jest niestabilny, gdy ktorys ze wspolczynnikow lub podwyznacznikow jest mniejszy od zera\n");
    }
    if(isOnTheEdgeOfStability){
        printf("Uklad na granicy stabilnosci.\n");
        printf("Uklad jest na granicy stabilnosci, gdy ktorys ze wspolczynnikow rownania charakterystycznego lub ktorys z podwyznacznikow jest rowny 0\n");
    }
}




int main() {
    int numberOfFactorsInNumerator = 0;
    int  arr;
    printf("Program bada stabilnosc wprowadzonych przez uzytkownika rownan stanu\n");
    printf("Podaj liczbe wspolczynnikow w liczniku\n");
    scanf("%d",&numberOfFactorsInNumerator);
    if(numberOfFactorsInNumerator==1){
        printf("Transmitancja bez zer: \n");
       arr= withoutZeroesCaseInputData();
    }else{
        printf("Transmitancja z zerami: \n");
        arr =withZeroes(numberOfFactorsInNumerator);
    }
    checkStability((int *) arr);


    return 0;
}
