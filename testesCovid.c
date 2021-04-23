/*
    Integrantes: Carlos Eduardo Máximo, Pedro Emanuel de Avelar Sousa de Almeida e Vinicius do Carmo Gomes
    Matriculas: 6962, 6965, 6953;
    Nome do Programa: testesCovid.c;
    Nome da Base de Dados: testes.c;
*/


#include "./components/libs/cadastro.h" // Custom lib

int main() {

    // Declaração de variavéis
    int i, numeroDeTestes;
    int opcao;
    int posicao;
    int aux;
    int testesCancelados;
    char nome[50], detalhes[31];
    FILE *arq;
    Pessoa dataPeople[1000]; // Passando uma variavél correspondente ao struct Pessoa para acessar os campos

    numeroDeTestes = 0;
    testesCancelados = 0;

    clscr();
    
    // Abre o arquivo no modo leitura.
    arq = fopen("testes.txt", "r");

    // Verfica a existencia do arquivo "txt".
    if(arq != NULL) {
        
        checksFile(dataPeople, &numeroDeTestes);
    }

    fclose(arq);

    strcpy(detalhes, " Para voltar ao menu digite 0 ");

    // Enquanto o a opção digitada não for 0 as opções são executadas.
    do {

        opcao = menu();

        clscr();

        // Fazendo as opções do menu funcionar.
        switch(opcao) {

            case 1:

                printf("\t\t------------------------------\n\n");
                printf("\t\t\t   Aviso!!!\n\n");
                printf("\t\t");
                puts(detalhes);
                printf("\n");


                printf("\t\t");
                // Imprime o traço 
                for(i = 0; detalhes[i] != '\0'; i++) {

                    printf("-");

                }

                printf("\n\n\n");

                // Evitando entrada de números negativos
                do {

                    // Mensagem de Saudação da opção de Cadastro de testes.
                    printf("Ola, bem vindo a sessao de cadastro de testes!\n\n");

                    // Pegando a quantidade de testes que o usuario informou.
                    printf("Para proseguir com o registro, por favor informe quantos testes voce deseja cadastrar: ");
                    scanf("%d", &aux);

                    getchar(); // Limpando o Buffer.
                    clscr(); // Função que limpa a tela.

                } while(!(aux >= 0));

                /* De acordo com o numero de testes informado pelo usário, vai fazer um loop que contém as informações nome, data de nascimento, cpf, rua, idaderesultado e sexo não nesta ordem e calcula a idade. */
                for(i = numeroDeTestes; i < numeroDeTestes + aux; i++) {
                    
                    dataPeople[i] = regNewTests();
                    dataPeople[i].idade = yearsOld(dataPeople[i]);

                }
                
                if(aux != 0) {

                    numeroDeTestes += aux;

                    clscr();

                    printf("Cadastro realizado com sucesso!");

                    enter();

                }
                
            break;

            case 2:
                
                printf("\nInforme um nome para consultar os testes: ");
                gets(nome);
                clscr();

                consultTests(nome, dataPeople, numeroDeTestes);

            break;

            case 3:
                
                printf("\nInforme a posicao do teste que deseja cancelar: ");
                scanf("%d", &posicao);
                getchar();
                clscr();

                // Remove a pessoa com o nome digitado do sistema.
                aux = removePerson(posicao, dataPeople, &numeroDeTestes);

                // verifica se alguma pessoa foi ou não apagada do sistema.
                if(aux == 1) {

                    testesCancelados++;

                }

            break;

            case 4:
            
                // Limpa os "pontinhos" imprimidos.
                for(i = 0; i < 2; i++){

                    clscr();
                    printf("\nSalvando os arquivos em 'testes.txt'");
                    saving(3, 400);

                }

                savingTests(dataPeople, numeroDeTestes, testesCancelados);

                clscr();
                printf("Arquivo salvo!");
                enter();

            break;

            case 5:

                printAll(dataPeople, numeroDeTestes);

            break;

            case 6:

                printReport(dataPeople, numeroDeTestes);

            break; 

        }

    } while(opcao != 0); 

    // Mensagem para teclar ENTER para fechar o programa
    endProg();

    return 0;

}
