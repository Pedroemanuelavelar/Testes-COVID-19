#include "menu.h"

/* 
===============================================
            DEFINIÇÃO DE STRUCTS
===============================================
*/

/* Definindo os campos dados para o struct Pessoa */
typedef struct rotuloPessoa {

    char fullName[100], cpf[20];
    int dia, mes, ano;
    char sexo;
    char bairro[100], resultadoTeste;
    int idade;
    int valido;

} Pessoa;

/* 
===============================================
            DEFINIÇÃO DE FUNÇÕES
===============================================
*/


/* Função que retorna o primeiro nome(firstName) ex: Pedro Emanuel => Pedro */
void firstName(char nomeCompleto[], char name[]) {

    int i;

    /* Pegando o primeiro nome */
    for(i = 0; !(nomeCompleto[i] == ' ' || nomeCompleto[i] == '\0'); i++) {

        name[i] = nomeCompleto[i];
        
    }

    /* Evita de imprimir lixo depois do '\0 */
    name[i] = '\0'; 

}

/* Função que cadastra novos testes, regNewTests => Registrar novos testes */
Pessoa regNewTests() {

    Pessoa pessoa;
    char name[15];

    pessoa.valido = 1;

    printf("Digite o seu nome: ");
    gets(pessoa.fullName);

    clscr();

    firstName(pessoa.fullName, name);

    printf("%s, digite o seu CPF: ", name);
    gets(pessoa.cpf);

    clscr();

    /* Avisando ao usuário que agora a data de nascime nto terá que ser armazenada */
    printf("%s, agora e preciso ser armazendo sua data de nascimento: \n\n", name);

    /* Pegando o dia */
    printf("Dia: ");
    scanf("%d", &pessoa.dia);


    /* Pegando o Mês */
    printf("Mes: ");
    scanf("%d", &pessoa.mes);


    /* Pegando o Ano */
    printf("Ano: ");
    scanf("%d", &pessoa.ano);

    getchar(); // Limpa o buffer

    do {

        clscr();

        /* Pegando o sexo M para masculino e F para feminino */
        printf("Digite o seu sexo \"M\" para masculino e \"F\" feminino: ");
        scanf("%c", &pessoa.sexo);

        getchar();

        // Converte de minusculo para maisculo
        if(pessoa.sexo >= 'a' && pessoa.sexo <= 'z') {

            pessoa.sexo -= 32;

        }

    } while(!(pessoa.sexo == 'M' || pessoa.sexo == 'F'));

    clscr();

    /* Pegando o bairro do usuário */
    printf("%s, informe o bairro: ", name);
    gets(pessoa.bairro);

    do {

        clscr();

        /* Informando ao usuário que agora será armazenado os resultados dos testes */
        printf("%s, agora sera armazenado os resultados dos testes da COVID-19: \n\n", name);

        printf("Digite \"P\" para positivo e \"N\" para negativo: ");
        scanf("%c", &pessoa.resultadoTeste);

        // Converte de minusculo para maiusculo
        if(pessoa.resultadoTeste >= 'a' && pessoa.resultadoTeste <= 'z') {

            pessoa.resultadoTeste -= 32;

        }

        getchar();

    } while(!(pessoa.resultadoTeste == 'P' || pessoa.resultadoTeste == 'N'));

    clscr();
    
    return pessoa;

}

/* Função que calcula a idade da pessoa através da data de nascimento informações de aprendizado retirado do site [https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/]
   e do site [https://www.vivaolinux.com.br/dica/Funcoes-de-data-usando-time.h] - Ambos artigos pesquisados afim de aprendizagem de uso da lib
*/
int yearsOld(Pessoa dataDeNascimento) {

    /* Pegando data atual em segundos */
    time_t tm = time(NULL);
    char *dataAtual = asctime(localtime(&tm)); // Convertendo segundos para string
    int dia, mes, ano; // variaveis para armazenar a conversão de strings para inteiro
    int i, j, resultado; // resultado armazena o calculo
    char month[5]; // Armazena o mes ex: Apr
    char day[3]; // Armazena o dia ex: 15
    char year[6]; // Armazena o ano: 2021 

    j = 0; // auxiliar para o month

    // Pegando o mes atual como string
    for(i = 4; dataAtual[i] != ' '; i++) {

        
        month[j] = dataAtual[i];

        j++;

    }

    month[j] = '\0';

    j = 0;

    // Pegando o dia atual como string
    for(i = 8; dataAtual[i] != ' '; i++) {

        day[j] = dataAtual[i];

        j++;

    }

    day[j] = '\0';

    j = 0;

    // Pegando o ano atual como string
    for(i = 20; dataAtual[i] != '\0'; i++) {

        year[j] = dataAtual[i];

        j++;

    }

    year[j] = '\0';

    /* Convertendo dia e ano de string para inteiro */
    dia = atoi(day);
    ano = atoi(year);

    // Converte mês de string por extenso para inteiro ex: Apr => 4
    if(strcmp(month, "Jan") == 0) {

        mes = 1;

    } else if(strcmp(month, "Feb") == 0) {

        mes = 2;

    } else if(strcmp(month, "Mar") == 0) {

        mes = 3;

    } else if(strcmp(month, "Apr") == 0) {

        mes = 4;

    } else if(strcmp(month, "May") == 0) {

        mes = 5;

    } else if(strcmp(month, "Jun") == 0) {
        
        mes = 6;

    } else if(strcmp(month, "Jul") == 0) {

        mes = 7;

    } else if(strcmp(month, "Aug") == 0) {

        mes = 8;

    } else if(strcmp(month, "Sep") == 0) {

        mes = 9;

    } else if(strcmp(month, "Oct") == 0) {

        mes = 10;

    } else if(strcmp(month, "Nov") == 0) {

        mes = 11;

    } else if(strcmp(month, "Dec") == 0) {

        mes = 12;

    }

    // pegando a idade da pessoa
    resultado = ano - dataDeNascimento.ano;

    // Avalia se o aniversário da pessoa já passou
    if(mes < dataDeNascimento.mes) {

        resultado -= 1;

    } else if(mes == dataDeNascimento.mes) {

        if(!(dia >= dataDeNascimento.dia)) {

            resultado -= 1;

        }

    }

    return resultado;

}

// Retorna o a posição da pessoa buscado pelo nome digitado, caso não econtre retorna -1.
int personSearch(char nome[], Pessoa dataPeople[], int numeroDeTestes) {

    int i;
    int encontrou_pessoa;

    // Valor bool.
    encontrou_pessoa = 0;

    // Verificação da igualdade dos nomes.
    for(i = 0; i < numeroDeTestes; i++) {
        
        if(strcmp(nome, dataPeople[i].fullName) == 0) {

            encontrou_pessoa = 1;
            break;

        }

    }

    if(!encontrou_pessoa) {

        return -1;

    }

    return i;

}

// Imprime os dados da pessoa encontrada, caso não encontre imprime não encontrada.
void consultTests(char nome[], Pessoa dataPeople[], int numeroDeTestes) {

    int posicao;

    if(numeroDeTestes == 0) {
        
        printf("\nNenhuma pessoa foi cadastrada no sistema.");
    
    }else {

        // Chama função para retorna a posição da pessoa.
        posicao = personSearch(nome, dataPeople, numeroDeTestes);

        if(posicao == -1) {

            printf("\nPessoa nao encontrada no sistema.");

        }else {
            
            // Imprime as informações da pessoa encontrada no sistema.
            printf("\nNome = %s", dataPeople[posicao].fullName);
            printf("\nCPF = %s", dataPeople[posicao].cpf);
            printf("\nData de nascimento: ");

            if(dataPeople[posicao].dia < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[posicao].dia);

            if(dataPeople[posicao].mes < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[posicao].mes);
            printf("%d", dataPeople[posicao].ano);
            printf("\nIdade = %d", dataPeople[posicao].idade);
            printf("\nSexo = %c", dataPeople[posicao].sexo);
            printf("\nBairro = %s", dataPeople[posicao].bairro);
            printf("\nResultado do teste = %c", dataPeople[posicao].resultadoTeste);

            if(dataPeople[posicao].valido == 1) {

                printf("\nValido = Sim");

            }else {

                printf("\nValido = Nao");

            }

        }

    }

    enter();

}

// Função que apaga uma pessoa cadrastada no sistema.
int removePerson(int posicao, Pessoa dataPeople[], int *numeroDeTestes) {

    int removido;
    char apagar[2];

    // variavel responsável por dizer se alguma pessoa cadastrada foi removida ou não.
    removido = 0;

    if(*numeroDeTestes == 0) {
        
        printf("\nNenhuma pessoa foi cadrastada no sistema.");
    
    }else {

        if(posicao < 0 || posicao >= *numeroDeTestes){

            printf("\nPessoa nao encontrada no sistema.");

        }else {

            printf("\nNome = %s", dataPeople[posicao].fullName);
            printf("\nCPF = %s", dataPeople[posicao].cpf);
            printf("\nData de nascimento: ");

            if(dataPeople[posicao].dia < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[posicao].dia);

            if(dataPeople[posicao].mes < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[posicao].mes);
            printf("%d", dataPeople[posicao].ano);
            printf("\nIdade = %d", dataPeople[posicao].idade);
            printf("\nSexo = %c", dataPeople[posicao].sexo);
            printf("\nBairro = %s", dataPeople[posicao].bairro);
            printf("\nResultado do teste = %c", dataPeople[posicao].resultadoTeste);

            if(dataPeople[posicao].valido == 1) {

                printf("\nValido = Sim");

            }else {

                printf("\nValido = Nao");
            }

            printf("\n\nVoce deseja realmente cancelar essa pessoa do sistema?(Sim ou Nao):\n");
            gets(apagar);
            uppercase(apagar);
            clscr();

            if(apagar[0] == 'S') {
            
                dataPeople[posicao].valido=0;

                printf("\nO teste na posicao %d foi cancelado.", posicao);

                removido = 1;

            }else {

                printf("\nO teste na posicao %d nao foi cancelado.", posicao);

            }

        }

    }

    enter();
    
    return removido;

}

// Função responsavel para salver os testes em um "txt".
void savingTests(char nomeArquivo[] ,Pessoa dataPeople[], int numeroDeTestes, int testesCancelados) {

    int i;
    char aux;
    FILE *arq;

    txt(nomeArquivo);

    // Variavel que abre o arquivo no modo escrita.
    arq = fopen(nomeArquivo, "w");

    // Imprime os numeros de testes no arquivo.
    fprintf(arq, "%d\n\n", numeroDeTestes - testesCancelados);

    // Imprime os dados no arquivo ".txt".
    for(i = 0; i < numeroDeTestes; i++) {

        if(dataPeople[i].valido) {
            
            fprintf(arq, "%s", dataPeople[i].fullName); // Nome.
            fprintf(arq, "\n%s\n", dataPeople[i].cpf); // CPF.
            
            if(dataPeople[i].dia < 10) {

                fprintf(arq, "0");

            }

            fprintf(arq, "%d/", dataPeople[i].dia); // Dia.
            
            if(dataPeople[i].mes < 10) {

                fprintf(arq, "0");

            }

            fprintf(arq, "%d/", dataPeople[i].mes); // Mes.

            fprintf(arq, "%d", dataPeople[i].ano);// Ano.
            fprintf(arq, "\n%c", dataPeople[i].sexo); // Sexo.
            fprintf(arq, "\n%s", dataPeople[i].bairro);// Bairro.
            fprintf(arq, "\n%c", dataPeople[i].resultadoTeste); // Resultado do teste.

        }

        if(i != numeroDeTestes - 1) {

            fprintf(arq, "\n");

        }
    }

    fclose(arq);

}

int file_number_tests(char nomeArquivo[]){

    FILE *arquivo;
    int testes;
    char number[100];

    arquivo = fopen(nomeArquivo, "r");

    if(arquivo != NULL) {

        fgets(number, 100, arquivo);

        testes = atoi(number);

        fclose(arquivo);

        return testes;

    }

}

// Função responsável por verificar os dados do arquivo "txt".
void checksFile(char nomeArquivo[] ,Pessoa dataPeople[], int *numeroDeTestes) {

    int i, j, miliSegundos;
    FILE *arquivo;
    char aux[100];

    // Abre o arquivo no modo leitura.
    arquivo = fopen(nomeArquivo, "r");

    if(arquivo != NULL) {
        
        // Pega a primeira linha do arquivo.
        fgets(aux, 100, arquivo);

        if(aux[0] >= '0' && aux[0] <= '9') {
            
            // Converte para o numero de testes feitos para inteiro.
            *numeroDeTestes = atoi(aux);
            fgets(aux, 100, arquivo);

            // Definindo quandos segundos o loading vai demorar
            if(*numeroDeTestes > 30) {

                miliSegundos = 0;

            } else {

                miliSegundos = 1000; // 1000 milisegundos => 1 segundo

            }

            // Pega todas as informações do "txt".
            for(i = 0; i < *numeroDeTestes; i++) {

                printf("Carregando os dados\n");
                loading(i, *numeroDeTestes, miliSegundos);

                fgets(dataPeople[i].fullName, 100, arquivo); // Nome.
                killN(dataPeople[i].fullName);

                fgets(dataPeople[i].cpf, 20, arquivo); // CPF.
                killN(dataPeople[i].cpf);

                fgets(aux, 100, arquivo);

                for(j = 0; aux[j] != '\0'; j++) {
                    
                    if(aux[j] == '/') {

                        aux[j] = '\0';

                    }

                }
                
                dataPeople[i].dia = atoi(&aux[0]); // Dia.
                dataPeople[i].mes = atoi(&aux[3]); // Mes.
                dataPeople[i].ano = atoi(&aux[6]); // Ano.

                dataPeople[i].idade = yearsOld(dataPeople[i]);

                fgets(aux, 100, arquivo);
                dataPeople[i].sexo = aux[0]; // Sexo.

                fgets(dataPeople[i].bairro, 100, arquivo);
                killN(dataPeople[i].bairro);
            
                fgets(aux, 100, arquivo);
                dataPeople[i].resultadoTeste = aux[0]; // Resultado dos testes.

                dataPeople[i].valido = 1; // Valor bool para valido ou não.

            }

        }

    }

    // Fecha o arquivo.
    fclose(arquivo);

}

// Imprime todos os testes feitos.
void printAll(Pessoa dataPeople[], int numeroDeTestes) {

    int i;

    printf("\nTestes feitos: %d\n", numeroDeTestes);

    // Percorre e imprime todos os dados.
    for(i = 0; i < numeroDeTestes; i++) {

            printf("\nNome = %s", dataPeople[i].fullName);
            printf("\nCPF = %s", dataPeople[i].cpf);
            printf("\nData de nascimento: ");

            if(dataPeople[i].dia < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[i].dia);

            if(dataPeople[i].mes < 10) {

                printf("0");

            }

            printf("%d/", dataPeople[i].mes);
            printf("%d", dataPeople[i].ano);
            printf("\nIdade = %d", dataPeople[i].idade);
            printf("\nSexo = %c", dataPeople[i].sexo);
            printf("\nBairro = %s", dataPeople[i].bairro);
            printf("\nResultado do teste = %c", dataPeople[i].resultadoTeste);
            printf("\nTeste Valido? ");

            // Imprime se é válido ou não
            if(dataPeople[i].valido) {

                printf("SIM");

            } else {

                printf("NAO");

            }

            printf("\n");

    }

    enter();

}

// Função que verifica a quantidade de pessoas infectados.
int positiveTests(Pessoa dataPeople[], int numeroDeTestes) {

    int i, testesPositivos;

    testesPositivos = 0;

    // Contando o numero de pessoas com o resultado Positivo
    for(i = 0; i < numeroDeTestes; i++) {

        if(dataPeople[i].resultadoTeste == 'P') {

            testesPositivos++;

        }

    }

    return testesPositivos;

}

// Função que verifica a quantidade de jovens infectados.
int infectedsYoungs(Pessoa dataPeople[], int numeroDeTestes) {

    int i, jovensInfectados;

    jovensInfectados = 0;

    for(i = 0; i < numeroDeTestes; i++) {

        if(dataPeople[i].idade < 20) {

            if(dataPeople[i].resultadoTeste == 'P'){

                jovensInfectados++;

            }

        }

    }

    return jovensInfectados;

}

// Função que verifica a quantidade de adultos infectados.
int  infectedsAdults(Pessoa dataPeople[], int numeroDeTestes) {

    int i, adultosInfectados;

    adultosInfectados = 0;

    for(i = 0; i < numeroDeTestes; i++) {

        if(dataPeople[i].idade >= 20 && dataPeople[i].idade < 60){

            if(dataPeople[i].resultadoTeste == 'P'){

                adultosInfectados++;

            }

        }

    }

    return adultosInfectados;

}

// Função responsável para calculo de porcentagem.
float percentage(int valor, int total) {

    float porcentagem;

    porcentagem = ((valor * 100.0) / total);

    return porcentagem;
}

// Imprime os dados da opção 6.
void printReport(Pessoa dataPeople[], int numeroDeTestes) {

    int pessoasInfectadas, pessoasNaoInfectadas, jovensInfectados, adultosInfectados, IdososInfectados;

    pessoasInfectadas = positiveTests(dataPeople, numeroDeTestes);
    pessoasNaoInfectadas = numeroDeTestes - pessoasInfectadas;

    jovensInfectados = infectedsYoungs(dataPeople, numeroDeTestes);

    adultosInfectados = infectedsAdults(dataPeople, numeroDeTestes);
    IdososInfectados = pessoasInfectadas - jovensInfectados - adultosInfectados;

    printf("-----------------------------------------------------------\n\n");
    printf("\t\t  Relatorio Covid - 19\n\n");
    printf("-----------------------------------------------------------\n\n");
    printf("Total de pessoas cadastradas: %d\n", numeroDeTestes);
    printf("Pessoas nao infectadas: %d (%.2f%%)\n", pessoasNaoInfectadas, percentage(pessoasNaoInfectadas, numeroDeTestes));
    printf("Pessoas infectadas: %d (%.2f%%)\n", pessoasInfectadas, percentage(pessoasInfectadas, numeroDeTestes));
    printf("\tJovens infectados: %d (%.2f%%)\n", jovensInfectados, percentage(jovensInfectados, pessoasInfectadas));
    printf("\tAdultos infectados: %d (%.2f%%)\n", adultosInfectados, percentage(adultosInfectados, pessoasInfectadas));
    printf("\tIdosos infectados: %d (%.2f%%)\n\n", IdososInfectados, percentage(IdososInfectados, pessoasInfectadas));
    printf("-----------------------------------------------------------");

    enter();

}