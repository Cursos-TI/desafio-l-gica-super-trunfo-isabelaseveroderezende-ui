


#include <stdio.h>

//  1 - Torre: Função recursiva
int mover_torre_recursivo(int casas_torre){
    if (casas_torre <= 0){
        return 0;
    }

    printf("Direita\n");
    mover_torre_recursivo(casas_torre - 1);   
}

//  2 - Bispo: Função recursiva
int mover_bispo_recursivo(int casas_bispo){

    if (casas_bispo <= 0){
        return 0;
    }

    printf("Cima, Direita\n");
    mover_bispo_recursivo(casas_bispo - 1);
    
}


//  2.1 - Bispo: Loops Aninhados (vertical externo, horizontal interno)
int mover_bispo_loops_aninhados (int casas_bispo){

    int passo_vertical = 0;

    while (passo_vertical < casas_bispo){
        int passo_horizontal = 0;

        while (passo_horizontal  < 1){
            printf("Cima, Direita\n");
            passo_horizontal++;
        }

        passo_vertical++;
    }
}



//  3 - Rainha: Função recursiva
int mover_rainha_recursivo(int casas_rainha){

    if (casas_rainha <= 0){
        return 0;
    }

    printf("Esquerda\n");
    mover_rainha_recursivo(casas_rainha - 1);
    
}


//  4 - Cavalo: Movimento com loops complexos (duas casa para cima e uma para direita) ->> Cima, Cima, Direita 

int mover_cavalo_complexo(int repeticoes){

    for (int vez = 1; vez <= repeticoes; vez++){
        
        printf("Movimento em L %d:\n", vez);

        int passo = 0;

        while (passo < 3){
            if (passo < 2){
                printf("Cima\n");
            }else{
                printf("Direita\n");
            }
            passo++;
        }
        printf("\n");
    }
}





int main(){

    int torre = 5, bispo = 5, rainha = 8, cavalo = 2;


    //  1 - Torre: Movimento recursivo (5 casas para a direita)
    printf("\n === Mover a TORRE (5 casas para a direita) - RECURSIVA\n");
    mover_torre_recursivo(torre);



    //  2 - Bispo: Movimento recursivo (5 casas na Diagonal: Cima-Direita)
    printf("\n === Mover o BISPO (5 casas na Diagonal) - RECURSIVA\n");
    mover_bispo_recursivo(bispo);



    //  2.1 - Bispo: Movimento recursivo (5 casas na Diagonal: Cima-Direita)
    printf("\n === Mover o BISPO (5 casas na Diagonal) - LOOPS ANINHADOS\n");
    mover_bispo_loops_aninhados(bispo);



    //  3 - Rainha: Movimento recursivo (8 casas para a Esquerda)
    printf("\n === Mover o RAINHA (8 casas para a Esquerda) - RECURSIVA\n");
    mover_rainha_recursivo(rainha);



    //  4 - Cavalo: Movimento com loops complexos (duas casa para cima e uma para direita)
    printf("\n === Mover o CAVALO (duas casa para cima e uma para direita) - Loops complexo\n");
    mover_cavalo_complexo(cavalo);


    return 0;

}