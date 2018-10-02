#include <signal.h>
#include <stdio.h>

// Esse processo deve ser aberto paralelamente ao processo que irá escutar o signal
main(){
    while(1){
        kill( 2485 ,SIGINT); // 2485 é o PID
        sleep(2);
    }
}


//PORQUE QUANDO ENVIO o sinal sigInt, aparece o ultimo 

//TRAZER EM UMA FOLHA A4 PARA ENTREGAR E APRESENTAR A EXPLICACAO DO MOTIVO.