#include <signal.h>

#include <stdio.h>

void rotina(int p){
    printf("Nao vou termianar!");
    sleep(2);
}

// A ROTINA SIGNAL VAI VINCULAR A ROTINA COM O SINAL
// SE CHEGAR O SIGINT, ELE VAI PARAR NAO IMPORTA O QUE ESTA FAZENDO E VAI FAZER A ROTINA
// SIGNAL FAZ NO INICIO DO PROGRAMA, IRA INSTALAR A ROTINA
main(){
    int i = 0;
    signal(SIGINT, rotina);
    signal(SIGHUP, rotina);

    // LOOPING INFINITO, DEVE-SE ABRIR OUTRO TERMINAL E ENVIAR UM SINAL PARA ELE
    // SE ENVIAR OUTRO SINAL QUE NAO SEJA O SIGINT NEM O SIGHUP, NAO OCORRERÁ NADA
    while(1){
        printf("%d \n", i++);
    }
}