#include<stdio.h>
#include<stdlib.h>

typedef struct conta{
    int id;
    char tipo[30];
    char cliente[30];
    float saldo;
} CONTA;

CONTA coletaDados();
void imprimeDados(CONTA *c, int n);
void liberaMemoria (CONTA *a);

int main(){

int n, i;


printf("digite o numero de contas que deseja criar: ");
scanf("%d", &n);

CONTA *matriz=(CONTA*) malloc(n *sizeof(CONTA));


if(matriz==NULL){
        printf("ERRO: sem memoria");
        exit(1);
}

for(i=0; i<n; i++){
    matriz[i]=coletaDados();
}

imprimeDados(matriz, n);

FILE *registroConta;
registroConta=fopen("arquivo.txt", "wb");

if(registroConta == NULL){
    printf("Erro na abertura do arquivo!!!");
    system("pause");
    exit(1);
}

for(i=0; i<n; i++){
    fwrite(&matriz[i], sizeof(CONTA), n, registroConta);
}

fclose(registroConta);

liberaMemoria(&matriz);

return 0;
}

CONTA coletaDados(){
    CONTA coleta;
    printf("\n\ndigite o id da conta: ");
    scanf("%d", &coleta.id);
    fflush(stdin);
    printf("\ndigite o tipo de conta: ");
    scanf("%s", &coleta.tipo);
    fflush(stdin);
    printf("\ninsira o nome do cliente: ");
    gets(coleta.cliente);
    fflush(stdin);
    printf("\ndigite o o saldo da conta: ");
    scanf("%f", &coleta.saldo);

    return coleta;
}

void imprimeDados(CONTA *c, int n){
    printf("\n\nREGISTRO DE DADOS DE CONTAS BANCARIAS\n\n");
    int i;
    for(i=0; i<n; i++){
        printf("\n\nID: %d", c[i].id);
        printf("\nTipo de conta: %s", c[i].tipo);
        printf("\nNome do cliente: %s", c[i].cliente);
        printf("\nSaldo: %f", c[i].saldo);
        printf("\n---------------------------------\n");
    }
}

void liberaMemoria (CONTA *a){
    free(a);
}

