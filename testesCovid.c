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
    int aux;
    int testesCancelados;
    char nome[50];
    Pessoa dataPeople[100]; // Passando uma variavél correspondente ao struct Pessoa para acessar os campos

    numeroDeTestes = 0;
    testesCancelados=0;

    // Enquanto o a opção digitada não for 0 as opções são executadas
    do {

        opcao = menu();

        clscr();

        // Fazendo as opções do menu funcionar
        switch(opcao) {

            case 1:

                // Mensagem de Saudação da opção de Cadastro de testes
                printf("Ola, bem vindo a sessao de cadastro de testes!\n\n");

                // Pegando a quantidade de testes que o usuario informou
                printf("Para proseguir com o registro, por favor informe quantos testes voce deseja cadastrar: ");
                scanf("%d", &aux);

                numeroDeTestes += aux;

                getchar(); // Limpando o Buffer
                clscr(); // Função que limpa a tela

                /* De acordo com o numero de testes informado pelo usário, vai fazer um loop que contém as informações nome, data de nascimento, cpf, rua, idaderesultado e sexo não nesta ordem e calcula a idade */
                for(i = 0; i < aux; i++) {
                    
                    dataPeople[i] = regNewTests();
                    dataPeople[i].idade = yearsOld(dataPeople[i]);

                }
                
                clscr();

                printf("Cadastro realizado com sucesso!");

                enter();

            break;

            case 2:
                
                printf("\nInforme um nome para consultar os testes: ");
                gets(nome);
                clscr();

                consultTests(nome, dataPeople, numeroDeTestes);

            break;

            case 3:
                
                printf("\nInforme o nome da pessoa que voce deseja apagar do sistema: ");
                gets(nome);
                clscr();

                // Remove a pessoa com o nome digitado do sistema.
                aux = removePerson(nome, dataPeople, &numeroDeTestes);

                // verifica se alguma pessoa foi ou não apagada do sistema.
                if(aux == 1){

                    testesCancelados++;

                }

            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break; 

        }

    } while(opcao != 0); 

    // Mensagem para teclar ENTER para fechar o programa
    endProg();

    return 0;

}
