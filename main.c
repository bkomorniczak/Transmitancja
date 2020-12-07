#include <stdio.h>
#include <stdbool.h>
#include <mem.h>

void withoutZeroesCaseInputData(){
    int withoutZeroesNumerator = 0;
    int n = 0;                                                      // number of both factor and states in denominator
    bool isStable = true;

    printf("Podaj wspolczynnik licznika\n");
    scanf("%d", &withoutZeroesNumerator);

    printf("Podaj liczbe wspolczynnikow z mianownika.\n");
    scanf("%d", &n);
    int denominatorFactors[n];

    printf("Podaj kolejne wspolczynniki:\n");
    for(int i=0; i < n; i++){
        scanf("%d",&denominatorFactors[i]);
    }
    //TODO: wrzucić równanie do char[], żeby móc je ładnie wyświetlić
    printf("Rownanie stanow:\n");
    for (int i=0; i<n; i++){
        printf("%ds^%d",denominatorFactors[i],n-(i+1));
        printf("+");
        //printf("%d",denominatorFactors[i-1]);
    }
    printf(" = 0\n");

    printf("Rownanie stanu w postaci wektorowo macierzowej\n");

    printf("x'1 =  0\t 1 \t |x1(t)|\t\t0\n\t\t\t\t\t+\nx'2 = ");
    int statesVector[n];
    memmove(statesVector,denominatorFactors,n *sizeof(int));

    for(int i = 0; i<n;i++){
        statesVector[i] = -1 * statesVector[i];
    }
    for(int i = 1; i<n;i++){
        printf("%d\t",statesVector[i]);
    }
    printf(" |x2(t)|\t\t1u(t)\n");


    printf("\n");
    //Badanie stabilności - TODO: wrzuc do osobnej funckji
    //TODO: Rozbudować przypadki o podwyznaczniki.
    //Wywalić isStable - sa 3 przypadki, nie ma to sensu. stworzyc zmienne bool do "na granicy stablinosci" "niestabilny" "stabilny"
    //Musi być sprawdzone czy "jest stabliny" nie tylko "nie jest niestabilny"
    if(denominatorFactors[0]==0){
        isStable = false;
        printf("Uklad na granicy stabilnosci");
    }
    for(int i = 0; i<n;i++) {
        if (denominatorFactors[i] < 0) {
            isStable = false;
        }
    }
 if(isStable){
        printf("Uklad stabilny");
    }else{
        printf("uklad niestabilny");
    }
    //Koniec badania stabilności

}

//TODO: sprawdzic czy to działa na przypadkach ogólnych, a nie tylko równaniu 2 stopni

void withZeroes(){}

void getUserData(){}


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
