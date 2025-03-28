#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void pausar_um_segundo() {
    #ifdef _WIN32
        Sleep(1000);  
    #else
        sleep(1);  
    #endif
}

void exibir_cronometro(int tempo_restante, int tempo_total) {
    
    int progresso = (tempo_total - tempo_restante) * 50 / tempo_total; 
    printf("\r[");
    for (int i = 0; i < 50; i++) {
        if (i < progresso) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d/%d segundos", tempo_total - tempo_restante, tempo_total); 
    fflush(stdout);  
}

int main () {
    int iniciar;
    int segundos;

    printf("Cronometro\n");
    printf("Aperte (1) para iniciar o cronometro\n");
    printf("Aperte (2) para desligar o cronometro!\n");
    scanf("%d", &iniciar);
    getchar();

    if (iniciar == 1) {
        printf("Quantos segundos voce deseja contar?\n");
        scanf("%d", &segundos);

        printf("Cronometro iniciado. Contando %d segundos...\n", segundos);

       
        for (int i = 0; i < segundos; i++) {
            pausar_um_segundo();
            exibir_cronometro(segundos - i - 1, segundos); 
        }

        printf("\nCronometro finalizado!\n");

    } else if (iniciar == 2) {
        printf("Cronometro desligando...\n");
        printf("...\n");
        printf("...\n");
        printf("...\n");
        printf("Cronometro Desligado com Sucesso!\n");

    } else {
        printf("Opção Inválida\n");
    }
    
    return 0;
}
