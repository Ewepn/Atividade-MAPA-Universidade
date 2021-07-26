#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 200 //*ALTERAR NUMERO LIMITE DE PROJETOS//
//*EWERTON PAZ DO NASCIMENTO//

typedef struct dados{
    int codigo;
    int ano;
    int status;
    int qtdfuncionarios; //*NOVO CAMPO ADICIONADO//
    float orcamento; //*NOVO CAMPO ADICIONADO//
    char cliente[30]; //*NOVO CAMPO ADICIONADO//
    char titulo[30];
    char descricao[50];
    char gerente[30];
}base_projetos;
int posicao = 0;

void cadastrarprojeto(base_projetos cadastro[MAX]);
void projetoscadastrados(base_projetos cadastro[MAX]);
void pesquisaporcodigo(base_projetos cadastro[MAX]);
void pesquisaporgerente(base_projetos cadastro[MAX]); //*NOVA PESQUISA ADICIONADA//
void pesquisa_afazer(base_projetos cadastro[MAX]);
void pesquisa_fazendo(base_projetos cadastro[MAX]);
void pesquisa_concluido(base_projetos cadastro[MAX]);

int main(){
    setlocale(LC_ALL, "portuguese");
    base_projetos cadastro[MAX];
    int selecione;
    system("cls");
    //*MENU DO SISTEMA//
    do{
    	system("cls");
        printf("\n***************************************");
        printf("\nDigite 1 para Cadastro");
        printf("\nDigite 2 para Projetos Cadastrados");
        printf("\nDigite 3 para Pesquisar por Código");
        printf("\nDigite 4 para Pesquisar por Gerente");
        printf("\nDigite 5 para Projetos com status - A Fazer");
        printf("\nDigite 6 para Projetos com status - Fazendo");
        printf("\nDigite 7 para Projetos com status - Concluído");
        printf("\nDigite 0 para Sair");
        printf("\n***************************************\n");
        fflush(stdin);
        scanf("%d", &selecione);
        switch (selecione){
            case 1:
                printf("CADASTRO\n");
                cadastrarprojeto(cadastro);
            break;
            case 2:
                printf("PROJETOS CADASTRADOS\n");
                projetoscadastrados(cadastro);
            break;
            case 3:
                printf("PESQUISA POR CÓDIGO\n");
                pesquisaporcodigo(cadastro);
            break;
            case 4:
                printf("PESQUISA POR GERENTE\n");
                pesquisaporgerente(cadastro);
            break;
            case 5:
                printf("PESQUISA POR STATUS - A FAZER\n");
                pesquisa_afazer(cadastro);
            break;
            case 6:
                printf("PESQUISA POR STATUS - fAZENDO\n");
                pesquisa_fazendo(cadastro);
            break;
            case 7:
                printf("PESQUISA POR STATUS - CONCLUÍDO\n");
                pesquisa_concluido(cadastro);
            break;
            case 0:
                printf("ENCERRAMENTO DO PROGRAMA\n");
                system("pause");
            break;
            default:
                printf("OPÇÃO INVÁLIDA\n");
            break;
        }
    } while (selecione != 0);
return 0;
}
//*CADASTRO DE PROJETOS//
void cadastrarprojeto(base_projetos cadastro[MAX]){
	system("cls");
    int stat, i;
	char resposta = 's';
	while(resposta== 's' || resposta== 'S' && posicao <= MAX){
		posicao++;
		printf("\nCódigo:%d ", posicao);
		cadastro[posicao].codigo = posicao;
		printf("\nDigite o ano do projeto:");
		fflush(stdin);
		scanf("%d", &cadastro[posicao].ano);
        printf("\nInforme a quantidade de funcionários para o projeto:");
        fflush(stdin);
        scanf("%d", &cadastro[posicao].qtdfuncionarios);
        printf("\nInforme o orçamento para o projeto:");
        fflush(stdin);
        scanf("%f", &cadastro[posicao].orcamento);
        printf("\nInforme o nome do Cliente:");
        fflush(stdin);
        gets(cadastro[posicao].cliente); 
        i=0;
        while(i==0){
            printf("\nQual o status do projeto?: [1]A fazer [2]Fazendo [3]Concluído:");
            fflush(stdin);
            scanf("%d", &stat);
            if (stat==1){
                cadastro[posicao].status = 1;
                i++;
            }if (stat==2){
                cadastro[posicao].status = 2;
                i++;
            }if (stat==3){
                cadastro[posicao].status = 3;
                i++;
            }else if (stat<=0 || stat>=4){
                printf("\nOPÇÃO INVÁLIDA"); 
            }  
        }
        printf("\nInforme o titulo do projeto:");
        fflush(stdin);
        gets(cadastro[posicao].titulo);
        printf("\nInforme uma descrição para o projeto:");
        fflush(stdin);
        gets(cadastro[posicao].descricao);
        printf("\nInforme o nome do Gerente:");
        fflush(stdin);
        gets(cadastro[posicao].gerente);
   
        if (posicao < MAX){
            printf("\nDeseja Cadastrar um novo projeto? [s] SIM [n] NAO:");
            fflush(stdin);
            scanf("%c", &resposta);
            system("cls");
        }else{
            printf("\nSua base de dados já está cheia");
            resposta = 'n';
        }       
	}
}
//*LISTA DE PROJETOS CADASTRADOS//
void projetoscadastrados(base_projetos cadastro[MAX]){
    system("cls");
    printf("\n***************************************");
    printf("\n PROJETOS CADASTRADOS");
    printf("\n***************************************\n");
    int y =1;
    if (posicao>=1){
        while (y <=posicao){
            printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n", 
            cadastro[y].codigo, cadastro[y].ano, cadastro[y].qtdfuncionarios, cadastro[y].orcamento);
            if (cadastro[y].status == 1)
            {
                printf("Status: A Fazer\n");
            }else if (cadastro[y].status == 2)
            {
                printf("Status: Fazendo\n");
            }else if (cadastro[y].status == 3)
            {
                printf("Status: Concluido\n");
            }   
            printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
            cadastro[y].cliente, cadastro[y].titulo, cadastro[y].descricao,cadastro[y].gerente);
            y++;
        }
    }else{
        printf("\nNENHUM PROJETO ENCONTRADO\n");
    }
    system("pause");
}
//*PESQUISA POR CÓDIGO//
void pesquisaporcodigo(base_projetos cadastro[MAX]){
    system("cls");
    int codigo, achou;
    printf("\n***************************************");
    printf("\nPESQUISA DE PROJETOS");
    printf("\n***************************************\n");
    printf("\nDigite o código do projeto:");
    scanf("%d", &codigo);
    achou =0;
    int x =0;
    while ((achou == 0) && (x <=posicao)){
        if (codigo== cadastro[x].codigo){
            printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n",
            cadastro[x].codigo, cadastro[x].ano, cadastro[x].qtdfuncionarios, cadastro[x].orcamento);
            if (cadastro[x].status == 1)
            {
                printf("Status: A Fazer\n");
            }else if (cadastro[x].status == 2)
            {
                printf("Status: Fazendo\n");
            }else if (cadastro[x].status == 3)
            {
                printf("Status: Concluido\n");
            }   
            printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
            cadastro[x].cliente, cadastro[x].titulo, cadastro[x].descricao,cadastro[x].gerente);
            achou = 1;
            system("pause");
        }
        x++;
    }
    if (achou==0){
    printf("\nNENHUM PROJETO ENCONTRADO COM ESTE CÓDIGO\n");
    system("pause");
    }   
} 
//*PESQUISA POR GERENTE//
void pesquisaporgerente(base_projetos cadastro[MAX]){
    system("cls");
    char nomegerente[30];
    int achar, z;
    printf("\n***************************************");
    printf("\nPESQUISA POR GERENTE");
    printf("\n***************************************\n");
    printf("\nDigite o nome do Gerente(idêntico ao cadastrado):");
    fflush(stdin);
    gets(nomegerente);
    achar=0;
    z=0;
    while ((achar==0) && (z < MAX)){
        if (strcmp(cadastro[z].gerente, nomegerente)==0){
            printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n",
            cadastro[z].codigo, cadastro[z].ano, cadastro[z].qtdfuncionarios, cadastro[z].orcamento);
            if (cadastro[z].status == 1)
            {
                printf("Status: A Fazer\n");
            }else if (cadastro[z].status == 2)
            {
                printf("Status: Fazendo\n");
            }else if (cadastro[z].status == 3)
            {
                printf("Status: Concluído\n");
            }   
            printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
            cadastro[z].cliente, cadastro[z].titulo, cadastro[z].descricao,cadastro[z].gerente);
            achar = 1;
            system("pause");
        }
        z++;      
    }
    if (achar==0){
        printf("\nNENHUM PROJETO ENCONTRADO COM ESTE GERENTE\n");
        system("pause");
    }  
}
//*PESQUISA STATUS A FAZER//
void pesquisa_afazer(base_projetos cadastro[MAX]){
    system("cls");
    printf("\n***************************************");
    printf("\n PROJETOS A FAZER");
    printf("\n***************************************\n");
    int cont=0;
    int a=0;
    int achou=0;
    if (posicao>=1){
        while ((achou == 0) && (a <=posicao))
        {
            if (cadastro[a].status==1)
            {
                printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n",
                cadastro[a].codigo, cadastro[a].ano, cadastro[a].qtdfuncionarios, cadastro[a].orcamento);
                printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
                cadastro[a].cliente, cadastro[a].titulo, cadastro[a].descricao,cadastro[a].gerente);
                cont++;  
            }
        a++; 
        } 
    }
    if ((cont==0) && (cont<=MAX)){
        printf("\nNENHUM PROJETO COM STATUS - A FAZER - ENCONTRADO\n");
    }
system("pause");          
}
//*PROJETOS COM STATUS - FAZENDO//
void pesquisa_fazendo(base_projetos cadastro[MAX]){
    system("cls");
    printf("\n***************************************");
    printf("\n PROJETOS EM ANDAMENTO");
    printf("\n***************************************\n");
    int cont=0;
    int b=0;
    int achou=0;
    if (posicao>=1){
        while ((achou == 0) && (b <=posicao))
        {
            if (cadastro[b].status==2)
            {
                printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n",
                cadastro[b].codigo, cadastro[b].ano, cadastro[b].qtdfuncionarios, cadastro[b].orcamento);
                printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
                cadastro[b].cliente, cadastro[b].titulo, cadastro[b].descricao,cadastro[b].gerente);
                cont++;  
            }
        b++; 
        } 
    }
    if ((cont==0) && (cont<=MAX)){
        printf("\nNENHUM PROJETO COM STATUS - FAZENDO - ENCONTRADO\n");
    }
system("pause");          
}
//*PROJETOS COM STATUS - CONCLUÍDO//
void pesquisa_concluido(base_projetos cadastro[MAX]){
    system("cls");
    printf("\n***************************************");
    printf("\n PROJETOS CONCLUÍDOS");
    printf("\n***************************************\n");
    int cont=0;
    int c=0;
    int achou=0;
    if (posicao>=1){
        while ((achou == 0) && (c <=posicao))
        {
            if (cadastro[c].status==3)
            {
                printf("\nCódigo: %d\nAno: %d\nQuantidade de Funcionários: %d\nOrçamento: %.2f\n",
                cadastro[c].codigo, cadastro[c].ano, cadastro[c].qtdfuncionarios, cadastro[c].orcamento);
                printf("Cliente: %s\nTitulo: %s\nDescrição: %s\nGerente: %s\n",
                cadastro[c].cliente, cadastro[c].titulo, cadastro[c].descricao,cadastro[c].gerente);
                cont++;  
            }
        c++; 
        }
    }
    if ((cont==0) && (cont<=MAX)){
        printf("\nNENHUM PROJETO COM STATUS - CONCLUÍDO - ENCONTRADO\n"); 
    }
system("pause");             
}