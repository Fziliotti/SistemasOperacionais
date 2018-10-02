#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//duvidas
//O FILHO DO PAI QUE POSSUI O CANAL, TAMBEM PODERA UTILIAR O RECURSO QUE FOI HERDADO DO PAI
// SE EU ENVIO UMA VARIAVEL INT PARA SER LIDA COMO UM CARACTERE, SERIA TROCADO O VALOR INT PELO VALOR DA TABELA ASCII
// O PROCESSO QUE VAI LER DO CANAL TEM QUE FAZER ISSO SEGUINDO A ORDEM COM QUE OS DADOS FOREM ESCRITOS NO CANAL, O TIPO DE DADO DE LEITURA DEVE SER O MESMO DADO DE ESCRITA
// o sistema operacional garante que oq vc colocar no canal1 vai sair no canal0 por exemplo
main()
{
    int canal[2];
    pid_t pid;

    int a, z;
    char b;
    float c;
    char d[5];
    // tem que sempre criar o canal antes de criar o filho
    // RECEBE COMO ARGUMENTO DE ENTRADA UM VETOR DE 2 INTEIROS
    if (pipe(canal) == -1)
    {
        printf("Erro pipe()");
        return -1;
    }
    // POSSO CRIAR OUTRO PIPE AQUI

    pid = fork();

    // PARA LER DO CANAL USO A POSICAO 0 DO CANAL
    if (pid == 0)
    {
        //O READ DO CANAL É BLOQUEANTE, ELE ESPERA QUE A ENTRADA SEJA COLOCADA, SEMELHANTE AO SCANF
        read(canal[0], &a.sizeof(int));
        read(canal[0], &b.sizeof(char));
        read(canal[0], &c.sizeof(float));
        read(canal[0], d.sizeof(d));

        printf("Valores recebidos pelo Filho do Pai \n");
        printf("A = %d \n B= %c \n C= %f \n D= %s \n", a, b, c, d);

        fflush(stdout);
        close(canal[0]);
        exit(0);
    }
    else if (pid > 0) //A ORDEM QUE EU ESCREVO TEM QUE SER A MESMA QUE EU LEIO
    {

        a = 1;
        b = '@';
        C=5.5;
        strcpy(d, '1234');

        write(canal[1], &a.sizeof(int));
        write(canal[1], &b.sizeof(char*5));
        write(canal[1], &c.sizeof(float));
        write(canal[1], d.sizeof(d));
        close(canal[1]); // APENAS UMA BOA PRATICA MAS NAO IMPLICA NENHUM EFEITO, MAS UMA VEZ FECHADO NAO POSSO ESCREVER MAIS NO CANAL
        wait(&z);
        exit(0);
    }
}