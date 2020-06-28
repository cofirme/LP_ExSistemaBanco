#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define QUANTIDADE_DE_CLIENTES 1


struct cliente {
        char nome[256];
        int cpf;
};

struct conta {
        int numero_da_conta;
        int cpf_do_cliente;
        float  saldo;
};

    struct cliente clientes[1];
    struct conta contas[1];

int main(){

    setlocale(LC_ALL,"Portuguese");

    menu();
}

void menu(){

    int opcoes;

        printf("MENU \n\n");
        printf("1- Cadastrar \n");
        printf("2- Operações \n");
        printf("3- Sair \n");

        scanf("%d", &opcoes);

        switch(opcoes){
    case 1:
        cadastrar();
        break;
    case 2:
        opr();
        break;
    case 3:
        system("CLS");
        printf("\nSaindo...\n");
        exit(0);
    default:
        system("CLS");
        printf("Opção inválida! Digite novamente\n\n");
        menu();
        }

}


void cadastrar(){
    for(int i=0; (i < QUANTIDADE_DE_CLIENTES); i++){
        printf("\nDigite os seguintes dados para cadastrar:\n\n");

        printf("\nDigite o nome:\n");
        scanf("%s",&clientes[i].nome);

        printf("\nDigite o CPF:\n");
        scanf("%d",&clientes[i].cpf);

        printf("\nDigite o saldo inicial:\n");
        scanf("%f",&contas[i].saldo);

        contas[i].numero_da_conta = i;
        contas[i].cpf_do_cliente = clientes[i].cpf;

        printf("\nCliente: %s Conta: %d Saldo inicial: %1.2f\n\n",
        clientes[i].nome, contas[i].numero_da_conta, contas[i].saldo);
    }
    printf("Pressione uma tecla para continuar!\n\n");
    getch();
    system("CLS");
    opr();
}


void opr(){

int opcoes;
int num_conta;
float valor;

    printf("\nMENU OPERAÇÕES\n");
    printf("\nInforme a operação:\n");
    printf("\n1-Saque\n");
    printf("\n2-Deposito\n");
    printf("\n3-Sair \n");
    scanf("%d", &opcoes);

        switch(opcoes){

    case 1:

      printf("\nInforme o número da conta:\n ");
      scanf("%d", &num_conta);

      printf("\nInforme o valor para saque:\n ");
      scanf("%f",&valor);

      while(valor<=0){
        printf("\nValor Inválido! Insira um valor positivo!:\n ");
        scanf("%f",&valor);
      }

      for(int i=0; (i < QUANTIDADE_DE_CLIENTES); i++){
        if (contas[i].numero_da_conta == num_conta) {
            if(contas[i].saldo > valor){
            contas[i].saldo -= valor;
            printf("\nSAQUE: %1.2f\n", valor);

                for(int j=0; j < QUANTIDADE_DE_CLIENTES; j++){
                    if (clientes[j].cpf == contas[i].cpf_do_cliente)
                    printf("\n Saldo atual: %1.2f\n",contas[i].saldo);
                }
            }else{
                system("CLS");
                printf("Não foi possivel completar a transação! Saldo Insuficiente.\n");
                opr();
            }

        }else{
            system("CLS");
            printf("Conta inválida! Repita a operação!\n");
            opr();
        }

      }
        break;

    case 2:
      printf("\nInforme o número da conta:\n ");
      scanf("%d", &num_conta);

      printf("\nInforme o valor para depósito:\n ");
      scanf("%f",&valor);

    while(valor<=0){
        printf("\nValor Inválido! Insira um valor positivo!:\n ");
        scanf("%f",&valor);
      }

        for(int i=0; (i < QUANTIDADE_DE_CLIENTES); i++){
            contas[i].saldo += valor;
            printf("\nDEPOSITO: %1.2f\n", valor);

            for(int j=0; j < QUANTIDADE_DE_CLIENTES; j++){
                if (clientes[j].cpf == contas[i].cpf_do_cliente)
                printf("\nCliente: %s Saldo atual: %1.2f\n",
                clientes[j].nome, contas[i].saldo);
            }
        }

        break;
    case 3:
        system("CLS");
        printf("\nSaindo...\n");
        exit(0);
    default:
        system("CLS");
        printf("Opção inválida!Digite novamente\n");
        opr();
    }
}
