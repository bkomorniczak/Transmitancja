#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>



void withoutZeroesCaseInputData(){
    int withoutZeroesNumerator = 0;
    int n = 0;                                                      // number of both factor and states in denominator

    bool isStable = true;
    int *temp[n];




    printf("Podaj wspolczynnik licznika\n");
    scanf("%d", &withoutZeroesNumerator);

    printf("Podaj liczbe wspolczynnikow z mianownika.\n");
    scanf("%d", &n);
    int denominatorFactors[n];


    printf("Podaj kolejne wspolczynniki:\n");
    for(int i=0; i < n; i++){
        scanf("%d",&denominatorFactors[i]);
    }
    int statesVector[n];

    printf("Rownanie stanow:\n");
    for (int i=0; i<n; i++){
        printf("s^%d",n-i);
        printf("+");
        printf("%d",denominatorFactors[i]);
    }
    printf(" = 0\n");

    printf("Rownanie stanu w postaci wektorowo macierzowej\n");

    printf("x'1 =  0\t 1 \t |x1(t)|\t\t0\n\t\t\t\t\t+\nx'2 = ");

    //statesVector i denominatorFactors wskazuja na ten sam obszar w pamieci TODO: zrob tak,  zeby tak nie było
    // to moze pomoc https://stackoverflow.com/questions/20409931/how-to-copy-values-from-an-array-into-a-new-one
    //memcpy(temp,denominatorFactors,n *sizeof(int));
    memmove(statesVector,denominatorFactors,n *sizeof(int));
  //  free(temp);
    for(int i = 0; i<n;i++){
        statesVector[i] = -1 * statesVector[i];
    }
    for(int i = 0; i<n;i++){
        printf("%d\t",statesVector[i]);
    }
    printf(" |x2(t)|\t\t1u(t)\n");


    printf("\n");
    //Badanie stabilności - TODO: wrzuc do osobnej funckji
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
