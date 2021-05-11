/*
    Integrantes: Carlos Eduardo Máximo, Pedro Emanuel de Avelar Sousa de Almeida e Vinicius do Carmo Gomes
    Matriculas: 6962, 6965, 6953;
    Nome do Programa: testesCovid.c;
    Nome da Base de Dados: testes.c;
*/


#include "./components/libs/cadastro.h" // Custom lib

int main(int argc, char *argv[]) {

    // Declaração de variavéis
    int i, numeroDeTestes;
    int opcao;
    int posicao;
    int aux; // variavél auxiliar 
    int testesCancelados;
    char nome[50], detalhes[31];
    FILE *arq;
    Pessoa *dataPeople; // Passando uma variavél correspondente ao struct Pessoa para acessar os campos

    numeroDeTestes = 0;
    testesCancelados = 0;


    // Debug dos parametros da main()
    // printf("%s", argv[1]);
    
    // getchar(); 

    clscr();

    // Verifica se foi passado como parametro o nome do arquivo na execução
    if(argc > 1) {

        txt(argv[1]);

        // Abre o arquivo no modo leitura.
        arq = fopen(argv[1],"r");

        // Verfica a existencia do arquivo "txt".
        if(arq != NULL) {

            numeroDeTestes += file_number_tests();

            dataPeople = (Pessoa *) malloc(numeroDeTestes * sizeof(Pessoa));

            if(dataPeople == NULL){

                printf("Sem espaco suficiente na memoria.\n");
                exit(1);
            }

            checksFile(dataPeople, &numeroDeTestes);
        }

        fclose(arq);

    }

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

                // Mensagem de Saudação da opção de Cadastro de testes.
                printf("Ola, bem vindo a sessao de cadastro de testes!\n\n");

                // Evitando entrada de números negativos
                do {

                    // Pegando a quantidade de testes que o usuario informou.
                    printf("Para proseguir com o registro, por favor informe quantos testes voce deseja cadastrar: ");
                    scanf("%d", &aux);

                    getchar(); // Limpando o Buffer.

                    if(aux > 0) {
                        
                        // Aumentando o vetor para cadastrar mais pessoas
                        dataPeople = (Pessoa *) realloc(dataPeople,(numeroDeTestes + aux) * sizeof(Pessoa));

                        if(dataPeople == NULL) {

                            printf("Sem espaco suficiente na memoria.\n");
                            exit(1);

                        }


                    }
                        
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

                
                printf("\nInforme um nome para consultar os testes: ");
                gets(nome);
                clscr();

                // Se o usuário quiser sair
                if(nome[0] == '0') {

                    //volta para o menu
                    continue;

                }

                consultTests(nome, dataPeople, numeroDeTestes);

            break;

            case 3:

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
                
                printf("\nInforme o numero do teste que deseja cancelar: ");
                scanf("%d", &posicao);
                getchar();
                clscr();

                // Se o usuário quiser sair
                if(posicao == 0) {

                    //volta para o menu
                    continue;

                }
                // Remove a pessoa com o nome digitado do sistema.
                aux = removePerson(posicao - 1, dataPeople, &numeroDeTestes);

                // verifica se alguma pessoa foi ou não apagada do sistema.
                if(aux == 1) {

                    testesCancelados++;

                }

            break;

            case 4:

                printf("Qual o nome do arquivo no qual voce deseja salvar os dados?\n");
                gets(nome);

                // Limpa os "pontinhos" imprimidos.
                for(i = 0; i < 2; i++){

                    clscr();
                    printf("\nSalvando os arquivos em '%s'", nome);
                    saving(3, 400);

                }

                savingTests(nome, dataPeople, numeroDeTestes, testesCancelados);

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

    // Libera o espaço alocado na memória principal
    free(dataPeople);

    // Mensagem para teclar ENTER para fechar o programa
    endProg();

    return 0;

}

