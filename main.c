#include <stdio.h>

int adicionarArrayVazio(int sequenciaDePaginas[], int estadoFinal[], int frames){
    int falhas = 0;
    for (int i = 0; i < frames; i++) {
        int valor = sequenciaDePaginas[i];
        int existe = verificar(valor, estadoFinal,frames);
        if (existe == 0){
            estadoFinal[i] = sequenciaDePaginas[i];
            falhas++;
        }
        
    }
    return falhas;
}
int verificar(int valor, int estadoFinal[], int frames){
    for (int i = 0; i < frames; i++) {
        if (estadoFinal[i] == valor){
            return 1;
        }
        
    }
    return 0;
}
int adicionarArrayPreenchido(int sequenciaDePaginas[], int tamanho, int estadoFinal[], 
int frames){
    int falhas = 0;
    int proximo = 0;
    for (int i = frames; i < tamanho; i++){
        int valor = sequenciaDePaginas[i];
        int existe = verificar(valor, estadoFinal, frames);
        if (existe == 0){
           estadoFinal[proximo] = sequenciaDePaginas[i];
           falhas++;

            if (proximo < frames){
            proximo = proximo + 1;
            }
            if (proximo >= frames){
            proximo = 0;
            }
        }

    }
    return falhas;
}
void imprimir(int estadoFinal[], int frames, int totalFalhas){
    printf("Estado final da memória: [");
    for (int i = 0; i < frames; i++){
        printf("%d", estadoFinal[i]);

        if (i < frames - 1){
             printf(", ");
        }
        
    }
    printf("]\n");
    printf("Total de falhas de página: %d ", totalFalhas);

    


}
int main(){
    int sequenciaDePaginas[] = {9, 3, 4, 2, 5, 6, 4, 9, 7, 1, 3};
    int frames = 4;
    int estadoFinal[frames];
    int totalFalhas = 0;
    int tamanho = sizeof(sequenciaDePaginas) / sizeof(sequenciaDePaginas[0]);
    int total1 =  adicionarArrayVazio(sequenciaDePaginas, estadoFinal, frames);
    totalFalhas += total1;
    int total2 = adicionarArrayPreenchido(sequenciaDePaginas, tamanho, estadoFinal, frames);
    totalFalhas += total2;
    imprimir(estadoFinal, frames, totalFalhas);
}

