#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


/* 
===============================================
            DEFINIÇÃO DE FUNÇÕES
===============================================
*/

/* Função que limpa a tela do terminal, nome abreviado de clearScreen (Limpa Tela) */
void clscr() {

    // Comando da lib stdlib.h que executa varios comandos dos prompts (Linux, Mac, Windows ...)
    system("cls || clear");

}

/* Função que imprime o menu e retorna a opção escolhida */
int menu() {

    int opcao;

    do {

        clscr();
    
        // Imprimindo linha decorativa 
        printf("-----------------------------------------------------------\n\n");

        // Imprimindo Menu de Opções
        printf("\t\t#### TESTES COVID-19 ####\n\n");

        printf("Menu de Opcoes:\n\n");

        printf("1 - Cadastrar novos testes\n");
        printf("2 - Consultar teste\n");
        printf("3 - Cancelar teste\n");
        printf("4 - Salvar informacoes em arquivo\n");
        printf("5 - Visualizar informacoes de testes realizados\n");
        printf("6 - Relatorio de testes realizados\n");
        printf("0 - Sair\n");

        // Imprimindo linha decorativa 
        printf("\n-----------------------------------------------------------\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        getchar();

    } while(!((opcao >= 0) && (opcao <= 6)));

    return opcao;
    
}

// Mensagem para prosseguir o programa.
void enter() {

    printf("\n \n");

    printf("Pressione \"Enter\" para prosseguir\n");
    
    getchar();
    clscr();

}

/* Função de encerramento do programa, endProg (Fim do Programa) */
void endProg() {
    
    printf("Creditos:\n");
    printf("-----------------------------------------------------------\n\n");
    printf("Repositorio: https://github.com/Pedroemanuelavelar/Testes-COVID-19\n\n");
    printf("Programa Desenvolvido por:\n\n");
    printf("* Carlos Eduardo Maximo - 6962\n");
    printf("* Pedro Emanuel de Avelar Sousa de Almeida - 6965\n");
    printf("* Vinicius do Carmo Gomes - 6953\n\n");
    printf("-----------------------------------------------------------\n\n");
    printf("Agradecimentos especiais:\n\n");
    printf("* Joao Lucas Mayrinck D'Oliveira\n");
    printf("* Leandro Henrique Furtado Pinto Silva\n");
    printf("* Matheus Nohra Haddad\n\n");
    printf("-----------------------------------------------------------\n\n");

    printf("Pressione \"Enter\" para finalizar o programa\n");
    
    getchar();
    clscr();

}

// Imprime "pontinhos" em um determinado tempo.
void saving(int pontinhos, int miliSegundos) {
    
    int i;

    for(i = 0; i < pontinhos; i++) {

        printf(".");
        usleep(miliSegundos * 1000);

    }

}

// Efeito de barra de pogresso
void loading(int i, int total, long int miliSegundos) {

    int j;
    float porcentagem, ultimaPosicao;
    miliSegundos *= 1000; // Converte pra micro segundos

    porcentagem = (((i + 1.0) / total) * 100); // Calculo de porcentagem
    
    // Define até onde vai ser preenchido
    ultimaPosicao = ((20 * porcentagem) / 100);

    printf("%.0f%% ", porcentagem); // imprime por exemplo 50%

    // Preenche a barra
    for(j = 0; j < ultimaPosicao; j++) {

        printf("%c", 219); // Printando a barra

    }

    printf("\n\n");

    usleep(miliSegundos);
    system("cls || clear");

}
