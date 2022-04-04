//ALUNOS: RODRIGO DO NASCIMENTO BORGES E RIAN GÁLATAS MACÊDO BRANDÃO
//DC/CCN026 - PROGRAMAÇÃO ESTRUTURADA - Turma: 01 (2019.2)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CLIENTES 50
#define MAX_CONTAS 100
//::::::::::::::::::::DEFINIÇÃO DE ESTRUTIRAS:::::::::::::::::::::::
typedef struct //ESTRUTURA DOS CLIENTES
{
	char nome[51];
	char cpf[16];
	char endereco[101];
	char telefone[16];//pode armazenar parênteses e hífens
	char email[51];
	int qtd_contas;
	int contador;
} tCliente;

typedef struct //ESTRUTURA DAS CONTAS
{
	int agencia;
	int conta_num;
	float saldo;
	char cpf_cliente[16];
	int conta_existe;
} tConta;
//::::::::::::::::::::::::DECLARAÇAO DE VARIÁVEIS GLOBAIS::::::::::::::::::::::::
tCliente cliente[MAX_CLIENTES];//VETOR PARA OS CLIENTES
tConta conta[MAX_CONTAS];//VETOR PARA AS CONTAS
//:::::::::::::::::::::::FUNÇÕES AUXILIARES::::::::::::::::::::::::
float leNaoNeg()//LÊ APENAS VALORES POSITIVOS
{
	float n;
	do
	{
		printf("INSIRA UM VALOR PARA MOVIMENTACAO: ");
		scanf("%f", &n);
		if(n < 0)
			printf("Erro: Valor negativo!\n");
	}
	while(n < 0);
	return n;
}
void zeroclientes(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS])//ATRIBUI UM VALOR INICIAL PARA ALGUMAS VARIÁVEIS DOS VETORES ESTRUTURA.
{
	int x;
	for(x = 0; x < MAX_CLIENTES; x++)
	{
		cliente[x].qtd_contas = 0;
		cliente[x].contador = -1;
	}
	for(x = 0; x < MAX_CONTAS; x++)
	{
		conta[x].conta_existe = 0;
		conta[x].agencia = -1;
		conta[x].conta_num = -1;
		conta[x].saldo = 0;
	}
}
int aumentaconta(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS], int *j) //ESSA FUNÇÃO AUMENTA O VALOR DA VARIAVEL INTEIRA qtd_contas TODA VEZ QUE UMA CONTA É CADASTRADA EM UM CPF JA EXISTENTE
{
	int i, reg = 0;
	for(i = 0; i < MAX_CLIENTES; i++)
	{
		if (strcmp(conta[*j].cpf_cliente, cliente[i].cpf) == 0)
		{
			cliente[i].qtd_contas++;
			reg++;
			return 1;
		}
		else
		{
			if(reg == 0)
			{
				printf("CPF NAO CORRESPONTE A NENHUM CLIENTE CADASTRADO!\n\n");
				printf("[Volte para a tela inicial e cadastre o cliente primeiro!]\n\n");
				system("pause");
				return 0;
			}
		}
	}
}
//:::::::::::::::::::::::::::::FUNÇÕES PARA OS MENUS:::::::::::::::::::::::::::::::
void  menuPrincipal(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU PRINCIPAL
{
	int menu;//armazena a opção digitada pelo usuário
	printf(":::::::::::MENU PRINCIPAL::::::::::::");
	printf("\n\n\t   >1 - Cliente<\n\n\t");
	printf("    >2 - Conta<\n\n\t  >3 - Movimento<\n\n\t");
	printf("  >4 - Relatorio<\n\n\t");
	printf("    >0 - Sair<\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu; //variável da função alterando a variável do main
}
void menuCliente(int*p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE MANIPULAÇÃO DE CLIENTES
{
	int menu;
	printf(":::::::::::MENU DO CLIENTE::::::::::::");
	printf("\n\n\t   >1 - Cadastrar Cliente<\n\n\t    >2 - Alterar Cliente<\n\n\t    >0 - Sair<\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
void menuConta(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE MANIPULAÇÃO DE CONTAS
{
	int menu;
	printf(":::::::::::MENU CONTA::::::::::::");
	printf("\n\n\t   >1 - Cadastrar Conta<\n\n\t    >2 - Alterar Conta<\n\n\t  >3 - Remover Conta\n\n\t    >0 - Sair<\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
void menuMovimento(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE MOVIMENTAÇÃO DE CONTAS
{
	int menu;
	printf(":::::::::::MENU MOVIMENTO::::::::::::");
	printf("\n\n\t   >1 - Deposito<\n\n\t    >2 - Saque<\n\n\t  >3 - Transferencia<\n\n\t  >4 - Saldo<\n\n\t    >0 - Sair<\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
void menuRelatorio(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE RELATORIOS
{
	int menu;
	printf(":::::::::::MENU RELATORIO::::::::::::");
	printf("\n\n\t>1 - Contas de um Cliente<");
	printf("\n\n\t>2 - Dados dos clientes com saldo inferior, superior ou igual a um valor<");
	printf("\n\n\t>3 - Lista os dados cadastrais de todos clientes (ativos ou nao)<");
	printf("\n\n\t>4 - Listar as informacoes de todas as contas<");
	printf("\n\n\t>5 - Listas as informacoes de todos os clientes (inclusive as informacoes referentes as suas contas)<");
	printf("\n\n\t>6 - Listar os dados cadastrais de todos clientes de uma agencia(ativos) ordenados pelo CPF<");
	printf("\n\n\t>0 - Sair<");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
void menuAltera_Cliente(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE ALTERAR CLIENTE
{
	int menu;
	printf(":::::::::::ALTERAR DADOS DO CLIENTE:::::::::::");
	printf("\n\n\t   >1 - Nome<\n\n\t    >2 - CPF<\n\n\t    >3 - Endereco<\n\n\t     >4 - Telefone Principal\n\n\t    >5 - e-mail principal<\n\n\t   >0 - Sair<\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
void menuAlteraConta(int *p_opcao)//FUNÇÃO PARA IMPRIMIR NA TELA O MENU DE ALTERAR CONTA
{
	int menu;
	printf(":::::::::::ALTERAR DADOS DA CONTA:::::::::::");
	printf("\n\n\t   >1 - Numero da Agencia\n\n\t   >2 - Numero da Conta<\n\n\t   >3 - CPF<\n\n\t   0 - Sair\n");
	printf("\n\nDigite uma opcao do menu: ");
	scanf("%d", &menu);
	*p_opcao = menu;
}
//::::::::::::::::::::::FUNÇÕES DO CADASTRO:::::::::::::::::::::::::::::::::::::::::::
void cadastro_Cliente(tCliente cliente[MAX_CLIENTES], int *p)//FUNÇÃO QUE RECEBE OS DADOS CADASTRAIS DE UM CLIENTE E ARMAZENA NO VETOR ESTRUTURA tCliente cliente[MAX_CLIENTES] EM UMA POSIÇÃO ESPECIFICA. PARÂMETROS: tCliente cliente[MAX_CLIENTES], int *p
{
	int i, compara, erro = 0;
	char temp[16];
	system("cls");
	printf("::::::::CADASTRO DE CLIENTE::::::::\n\n");
	printf("\t  >Cliente [%d]<\n", *p + 1);

	if(*p == 0)
	{
		printf("\nCPF NO MODELO xxx.xxx.xxx-xx: ");
		scanf("%s", cliente[*p].cpf);
		printf("Nome: ");
		scanf("%s", cliente[*p].nome);
		printf("\nEndereco: ");
		scanf("%s", cliente[*p].endereco);
		printf("\nTelefone/Celular: ");
		scanf("%s", cliente[*p].telefone);
		printf("\ne-mail: ");
		scanf("%s", cliente[*p].email);
		printf("\n");
		cliente[*p].contador = *p;
		(*p)++;

	}
	else
	{
		printf("\nCPF: ");
		scanf("%s", temp);
		printf("\n");

		for(i = 0; i < (*p); i++)
		{

			compara = strcmp(cliente[i].cpf, temp);

			if(compara == 0)
			{
				printf(">ERRO<:[Este CPF ja foi cadastrado! Insira um diferente!]\n\n");
				system("pause");
				break;
			}
			else
			{
				erro++;
			}
		}
		if(erro == *p)
		{
			strcpy(cliente[*p].cpf, temp);
			printf("Nome: ");
			scanf("%s", cliente[*p].nome);
			printf("\nEndereco: ");
			scanf("%s", cliente[*p].endereco);
			printf("\nTelefone/Celular: ");
			scanf("%s", cliente[*p].telefone);
			printf("\ne-mail: ");
			scanf("%s", &cliente[*p].email);
			cliente[*p].contador = *p;
			(*p)++;
		}
	}

	system("cls");
}
void cadastro_Conta(tConta conta[MAX_CONTAS], tCliente cliente[MAX_CLIENTES], int *p)//FUNÇÃO QUE RECEBE OS DADOS CADASTRAIS DE UMA CONTA E ASSOCIA AOS DADOS CADASTRAIS DO CLIENTE E ARMAZENA NO VETOR ESTRUTURA tConta conta[MAX_CONTAS]. PARÂMETROS: tConta conta[MAX_CONTAS], tCliente cliente[MAX_CLIENTES], int *p
{
	int i, j, a, n, compara_ag, compara_co, compara_cpf, erro = 0, erro_2 = 0, erro_3 = 0;
	int temp_conta, temp_agencia;
	char temp_cpf[16];
	system("cls");
	printf("::::::::CADASTRO DE NOVA CONTA::::::::\n\n");
	printf("\t  >Conta [%d]<\n", *p + 1);
	if(*p == 0)
	{
		printf("CONTA: ");
		scanf("%d", &conta[*p].conta_num);
		printf("AGENCIA: ");
		scanf("%d", &conta[*p].agencia);
		printf("CPF DO CLIENTE: ");
		scanf(" %[^\n]", conta[*p].cpf_cliente);
		for(i = 0; i < MAX_CLIENTES; i++)
		{
			if(strcmp(conta[*p].cpf_cliente, cliente[i].cpf) == 0)
			{
				cliente[i].qtd_contas++;
			}
			else
			{
				erro_3++;
			}
		}
		if(erro_3 == MAX_CLIENTES)
		{
			printf("\n[ERRO]: >CPF NAO CADASTRADO NO SISTEMA<\n\n");
			conta[*p].cpf_cliente[0] = '\0';
			conta[*p].agencia = 0;
			conta[*p].conta_num = 0;
			system("pause");
		}
		else
		{
			printf("\n[CADASTRO BEM SUCEDIDO!]\n\n");
			conta[*p].conta_existe = 1;
			(*p)++;
			system("pause");
		}
	}
	else
	{
		printf("CONTA: ");
		scanf("%d", &temp_conta);
		printf("AGENCIA: ");
		scanf("%d", &temp_agencia);

		for(i = 0, erro = 0; i < MAX_CONTAS; i++)
		{


			if((conta[i].conta_num == temp_conta) && (conta[i].agencia == temp_agencia))
			{
				printf("\n[ERRO]: >Esta conta ja existe! informe uma conta e/ou agencia diferentes!<\n\n");
				system("pause");
				break;
			}
			else
			{
				erro++;
			}
		}
		if(erro == MAX_CONTAS)
		{
			printf("CPF DO CLIENTE: ");
			scanf(" %[^\n]", temp_cpf);

			for(j = 0; j < MAX_CLIENTES; j++)
			{

				compara_cpf = strcmp(cliente[j].cpf, temp_cpf);
				if(compara_cpf == 0)
				{
					conta[*p].conta_num = temp_conta;
					conta[*p].agencia = temp_agencia;
					strcpy(conta[*p].cpf_cliente, temp_cpf);
					printf("\n[CADASTRO BEM SUCEDIDO]\n\n");
					cliente[j].qtd_contas++;
					conta[*p].conta_existe = 1;
					(*p)++;
					system("pause");
				}
				else
				{
					erro_2++;
				}
			}
			if(erro_2 == MAX_CLIENTES)
			{
				printf("\n[ERRO]: >CPF NAO CADASTRADO NO SISTEMA<\n\n");
				conta[*p].cpf_cliente[0] = '\0';
				conta[*p].agencia = 0;
				conta[*p].conta_num = 0;
				system("pause");
			}
		}
	}
	system("cls");
}
//::::::::::::::::::::::::::::FUNÇÕES DE MOVIMENTAÇÃO::::::::::::::::::::::::::::::::::
void deposito(tConta conta[MAX_CONTAS])//RECEBE UM VALOR REAL NAO NEGATIVO E ARMAZENA NO VETOR ESTRUTURA (CONTA) ESPECIFICADO PELO USUÁRIO POR MEIO DOS NÚMEROS DE AGENCIA E DE CONTA
{
	int i, diferenca;
	int aux_conta, aux_agencia;
	float val;
	system("cls");
	printf("::::::::DEPOSITO::::::::\n\n");
	printf("INSIRA O NUMERO DA CONTA: ");
	scanf("%d", &aux_conta);
	printf("\nINSIRA O NUMERO DA AGENCIA: ");
	scanf("%d", &aux_agencia);
	for(i = 0; i < MAX_CONTAS; i++)
	{

		diferenca = (aux_conta - conta[i].conta_num) + (aux_agencia - conta[i].agencia);
		if(diferenca == 0)
		{
			val = leNaoNeg();
			conta[i].saldo += val;
			printf("\nSALDO SERA: R$ %.2f\n", conta[i].saldo);
			system("pause");
			break;
		}
		else
		{
			if(i == MAX_CONTAS - 1)
			{
				printf("\nDADOS DA CONTA INCORRETOS");
				system("pause");
				break;
			}
		}

	}

}
void saque(tConta conta[MAX_CONTAS])//RECEBE UM VALOR REAL NAO NEGATIVO QUE É SUBTRAIDO DO SALDO DE UMA CONTA
{
	int i;
	int auc, aua;
	float val;
	system("cls");
	printf("::::::::::SAQUE::::::::::\n\n");
	printf("INSIRA O NUMERO DA CONTA: ");
	scanf("%d", &auc);
	printf("\nINSIRA O NUMERO DA AGENCIA: ");
	scanf("%d", &aua);
	for(i = 0; i < MAX_CONTAS; i++)
	{
		if(auc - conta[i].conta_num == 0 && aua - conta[i].agencia == 0)
		{
			val = leNaoNeg();
			if(conta[i].saldo - val < 0)
			{
				printf("\nSALDO INSUFICIENTE\n");
				system("pause");
				break;
			}
			else
			{
				printf("\nSALDO SERA: R$ %.2f\n", conta[i].saldo - val);
				conta[i].saldo -= val;
				system("pause");
			}
			break;
		}
		else
		{
			if(i == MAX_CONTAS - 1)
			{
				printf("\nDADOS DA CONTA INCORRETOS\n");
				system("pause");
				break;
			}
		}

	}

}
void transfere(tConta conta[MAX_CONTAS])//RECEBE UM VALOR REAL NAO NEGATIVO E SUBITRAI DO SALDO DA CONTA ORIGEM DEPOIS SOMA ESSE VALOR AO SALDO DA CONTA DESTINO. LOCALIZAÇÃO FEITA POR MEIO DOS NÚMEROS DE CONTA E AGENCIA
{

	int i, iX, reg, erro = 0;
	int auc, aucX, auaX, aua, comparaX, compara;
	float val;
	system("cls");
	printf("::::::::TRANSFERENCIA::::::::\n\n");
	printf("INSIRA O NUMERO DA CONTA DE ORIGEM: ");
	scanf("%d", &auc);
	printf("\nINSIRA O NUMERO DA AGENCIA DE ORIGEM: ");
	scanf("%d", &aua);
	for(i = 0; i < MAX_CONTAS; i++)
	{
		compara = (auc - conta[i].conta_num) + (aua - conta[i].agencia);
		if(compara == 0)
		{
			val = leNaoNeg();
			if(conta[i].saldo - val < 0)
			{
				printf("\nSALDO INSUFICIENTE\n");
				erro++;
				system("pause");
				break;
			}
			else
			{
				conta[i].saldo -= val;
				reg = i;
				printf("\nO SALDO DA CONTA SERA: R$ %.2f\n", conta[i].saldo);
				break;
			}
		}
		else
		{
			if(i == MAX_CONTAS - 1)
			{
				erro++;
			}
		}

	}
	if(erro == 0)
	{
		printf("\nINSIRA O NUMERO DA CONTA DESTINO: ");
		scanf("%d", &aucX);
		printf("\nINSIRA O NUMERO DA AGENCIA DESTINO: ");
		scanf("%d", &auaX);
		for(iX = 0; iX < MAX_CONTAS; iX++)
		{
			comparaX = (aucX - conta[iX].conta_num) + (auaX - conta[iX].agencia);
			if(comparaX == 0)
			{
				conta[iX].saldo += val;
				printf("\nTRANSFERENCIA REALIZADA");
				printf("\nSALDO NA CONTA DE ORIGEM: R$ %.2f", conta[reg].saldo);
				printf("\nSALDO NA CONTA DESTINO: R$ %.2f\n", conta[iX].saldo);
				system("pause");
				break;
			}
			else
			{
				if(iX == MAX_CONTAS - 1)
				{
					conta[reg].saldo += val;
					printf("\nDADOS DA CONTA INCORRETOS\n");
					system("pause");
					break;
				}
			}
		}
	}
	else
	{
		printf("%.2f", conta[reg]);
		printf("\nDADOS DA CONTA INCORRETOS\n");
		system("pause");
	}

}

void saldo(tConta conta[MAX_CONTAS])//RECEBE UM NÚMERO DE AGENCIA E DE CONTA E IMPRIME NA TELA O SALDO DESSA CONTA
{
	int i;
	int auc, aua;
	system("cls");
	printf("::::::::TRANSFERENCIA::::::::\n\n");
	printf("INSIRA O NUMERO DA CONTA: ");
	scanf("%d", &auc);
	printf("\nINSIRA O NUMERO DA AGENCIA: ");
	scanf("%d", &aua);
	for(i = 0; i < MAX_CONTAS; i++)
	{
		if(auc - conta[i].conta_num == 0 && aua - conta[i].agencia == 0)
		{
			printf("\nSALDO: R$ %.2f\n", conta[i].saldo);
			system("pause");
			break;
		}
		else
		{
			printf("\nCONTA NAO EXISTE\n");
			system("pause");
			break;
		}
	}
}
//::::::::::::::::::::::::::::::::RELATORIOS::::::::::::::::::::::::::::::::::::::::::
void contas_Cliente(tConta conta[MAX_CONTAS], tCliente cliente[MAX_CLIENTES])//RECEBE O CPF DE UM CLIENTE E IMPRIME OS DADOS DAS CONTAS NESSE CPF(PERCORRE O VETOR DE CONTAS EM BUSCA DE UM CPF IGUAL AO QUE FOI RECEBIDO E IMPRIME OS DADOS DAS CONTAS QUE FORAM ENCONTRADAS)
{
	char aux[16];
	int i, j, erro = 0, reg = 0;
	printf("INFORME O CPF DO CLIENTE: ");
	scanf(" %[^\n]", aux);
	for(i = 0; i < MAX_CLIENTES; i++)
	{
		if (strcmp(cliente[i].cpf, aux) == 0)
		{
			printf("\nNome do CLIENTE: %s\n", cliente[i].nome);
			break;
		}
		else
		{
			erro++;
		}
	}
	if(erro == MAX_CLIENTES)
	{
		printf("\nCPF DO CLIENTE NAO FOI CADASTRADO\n");
		system("pause");
	}
	else
	{
		for(j = 0; j < MAX_CONTAS; j++)
		{
			if (strcmp(conta[j].cpf_cliente, aux) == 0)
			{
				printf("\nNUMERO DA CONTA: %d", conta[j].conta_num);
				printf("\nNUMERO DA AGENCIA: %d", conta[j].agencia);
				printf("\nSALDO: R$ %.2f\n", conta[j].saldo);
			}
			else
			{
				reg++;
			}
		}
		if(reg == MAX_CONTAS)
		{
			printf("\n[CLIENTE INATIVO]]\n");
			system("pause");
		}
	}
}
void dadosCliente_porSaldo(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS], int *p_co, int *p_cl)//RECEBE UM SALDO ESPECIFICO E IMPRIME UM MENU PARA QUE O USUARIO ESCOLHA SE QUER PROCURAR UM VALOR MENOR, MAIOR OU IGUAL E IMPRIME TODAS AS CONTAS QUE ATENDEM AS EXIGENCIAS
{
	int iX, i, meu, reg = 0;
	float aus;
	printf("INSIRA O SALDO PARA COMPARACAO: ");
	scanf("%f", &aus);
	printf("\nESCOLHA UM PARAMETRO DE COMPARACAO: \n");
	printf("\n\t1- VALOR MAIOR\n\t0- VALOR IGUAL\n\t-1 -VALOR MENOR\n\t2 -SAIR\n");
	printf(": ");
	scanf("%d", &meu);
	switch(meu)
	{
	case 1 :
		for(i = 0; i < (*p_co); i++)
		{
			if(conta[i].saldo > aus)
			{
				for(iX = 0; iX < (*p_cl); iX++)
				{
					if(strcmp(conta[i].cpf_cliente, cliente[iX].cpf) == 0)
					{
						printf("\nNOME DO CLIENTE: %s", cliente[iX].nome);
						printf("\nCPF DO CLIENTE: %s", cliente[iX].cpf);
						printf("\nNUEMRO DA CONTA: %d", conta[i].conta_num);
						printf("\nNUMERO DA AGENCIA: %d", conta[i].agencia);
						printf("\nSALDO: %.2f\n\n", conta[i].saldo);
					}

					reg++;
				}
			}
			else
			{
				if(reg == 0)
				{
					printf("\nNAO EXISTE NENHUMA CONTA QUE CORRESPONDE AS EXIGENCIAS\n");
					system("pause");
					break;
				}
			}
		}
		break;
	case -1 :
		for(i = 0; i < (*p_co); i++)
		{
			if(conta[i].saldo < aus)
			{
				for(iX = 0; iX < (*p_cl); iX++)
				{
					if(strcmp(conta[i].cpf_cliente, cliente[iX].cpf) == 0)
					{
						printf("\nNOME DO CLIENTE: %s", cliente[iX].nome);
						printf("\nCPF DO CLIENTE: %s", cliente[iX].cpf);
						printf("\nNUEMRO DA CONTA: %d", conta[i].conta_num);
						printf("\nNUMERO DA AGENCIA: %d", conta[i].agencia);
						printf("\nSALDO: %.2f\n\n", conta[i].saldo);
					}

					reg++;
				}
			}
			else
			{
				if(reg == 0)
				{
					printf("\nNAO EXISTE NENHUMA CONTA QUE CORRESPONDE AS EXIGENCIAS\n");
					system("pause");
					break;
				}
			}
		}
		break;
	case 0 :
		for(i = 0; i < (*p_co); i++)
		{
			if(conta[i].saldo = aus)
			{
				for(iX = 0; iX < (*p_cl); iX++)
				{
					if(strcmp(conta[i].cpf_cliente, cliente[iX].cpf) == 0)
					{
						printf("\nNOME DO CLIENTE: %s", cliente[iX].nome);
						printf("\nCPF DO CLIENTE: %s", cliente[iX].cpf);
						printf("\nNUEMRO DA CONTA: %d", conta[i].conta_num);
						printf("\nNUMERO DA AGENCIA: %d", conta[i].agencia);
						printf("\nSALDO: %.2f\n\n", conta[i].saldo);
					}

					reg++;
				}
			}
			else
			{
				if(reg == 0)
				{
					printf("\nNAO EXISTE NENHUMA CONTA QUE CORRESPONDE AS EXIGENCIAS\n");
					system("pause");
					break;
				}
			}
		}
		break;
	case 2 :
		break;
	default :
		printf("\nOPCAO INVALIDA\n");
	}
}
void listaDados_ALLclientes(tCliente cliente[MAX_CLIENTES])//LISTA OS DADOS CADASTRAIS DE TODOS OS CLIENTES DO BANCO(PERCORRE O VETOR DE CLIENTES E IMPRIME AS ESTRUTURAS QUE FORAM PREENCHIDAS)
{
	int i, reg = 0;
	for(i = 0; i < MAX_CLIENTES; i++)
	{
		if(cliente[i].contador >= 0)
		{
			printf("NOME DO CLIENTE: %s", cliente[i].nome);
			printf("\nCPF DO CLIENTE: %s", cliente[i].cpf);
			printf("\nENDERECO: CLIENTE: %s", cliente[i].endereco);
			printf("\nTELEFONE DO CLIENTE: %s", cliente[i].telefone);
			printf("\nE-MAIL DO CLIENTE: %s", cliente[i].email);
			printf("\nQUANTIDADE DE CONTAS: %d\n\n", cliente[i].qtd_contas);
			reg++;
		}
		else
		{
			if(reg == 0)
			{
				printf("\nNAO ESXITE NENHUM CLIENTE CADASTRADO\n");
				system("pause");
				break;
			}
		}
	}
}
void lista_Contas_ALL (tConta conta[MAX_CONTAS])//LISTA OS DADOS CADASTRAIS DE TODOS AS CONTAS DO BANCO(PERCORRE O VETOR DE CONTAS IMPRIME AS ESTRUTURAS QUE FORAM PREENCHIDAS)
{
	int i, reg = 0;
	for(i = 0; i < MAX_CONTAS; i++)
	{
		if(conta[i].conta_existe == 1)
		{
			printf("CPF DO CLIENTE: %s", conta[i].cpf_cliente);
			printf("\nAGENCIA: %d", conta[i].agencia);
			printf("\nNUMERO DA CONTA: %d", conta[i].conta_num);
			printf("\nSALDO: %.2f\n\n", conta[i].saldo);
			reg++;
		}
		else
		{
			if(reg == 0)
			{
				printf("\nNAO EXISTE NENHUMA CONTA CADASTRADA\n");
				system("pause");
				break;
			}

		}
	}
}
void lista_CLIENTES_CONTAS(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS])//LISTA OS DADOS DE TODOS OS CLIENTES JUNTAMENTE COM SUAS CONTAS (PERCORRE OS VETORES conta[MAX_CONTAS] E cliente[MAX_CLIENTES] USANDO O CPF COMO CRITERIO DE COMPARAÇÃO)
{
	int i, iX, reg = 0, regX = 0;
	for(i = 0; i < MAX_CLIENTES; i++)
	{
		if(cliente[i].contador >= 0)
		{
			printf("NOME DO CLIENTE: %s", cliente[i].nome);
			printf("\nCPF DO CLIENTE: %s", cliente[i].cpf);
			printf("\nENDERECO: CLIENTE: %s", cliente[i].endereco);
			printf("\nTELEFONE DO CLIENTE: %s", cliente[i].telefone);
			printf("\nE-MAIL DO CLIENTE: %s", cliente[i].email);
			printf("\nQUANTIDADE DE CONTAS: %d\n\n", cliente[i].qtd_contas);
			reg++;
			for(iX = 0; iX < MAX_CONTAS; iX++)
			{
				if(strcmp(cliente[i].cpf, conta[iX].cpf_cliente) == 0)
				{
					printf("\nCPF DO CLIENTE: %s", conta[iX].cpf_cliente);
					printf("\nAGENCIA: %d", conta[iX].agencia);
					printf("\nNUMERO DA CONTA: %d", conta[iX].conta_num);
					printf("\nSALDO: %.2f\n\n", conta[iX].saldo);
					regX++;
				}
				else
				{
					if(regX == 0)
					{
						printf("\nO CLIENTE NAO POSSUI NENHUMA CONTA\n");
						system("pause");
						goto irpara;
					}
				}
			}
		}
		else
		{
			if(reg == 0)
			{
				printf("\nNAO EXISTE NENHUM CLIENTE CADASTRADO\n");
				system("pause");
				goto irpara;
			}
		}
irpara:
		;
	}
}
void lista_Ativos_porCPF(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS]) //LISTA TODOS OS DADOS CADASTRAIS DOS CLIENTES DE UMA AGENCIA(PERCORRE O VETOR conta[MAX_CONTAS] E BUSCANDO TODAS AS CONTAS DE UMA MESMA AGENCIA)
{
	int i, iX, reg = 0, regX = 0, aux;
	printf("INFORME O NUMERO DA AGENCIA: ");
	scanf("%d", &aux);
	for(i = 0; i < MAX_CONTAS; i++)
	{
		if(conta[i].conta_existe == 1)
		{
			if((aux - conta[i].agencia) == 0)
			{
				for(iX = 0; iX < MAX_CLIENTES; iX++)
				{
					if(strcmp(conta[i].cpf_cliente, cliente[iX].cpf) == 0)
					{
						printf("NOME DO CLIENTE: %s", cliente[iX].nome);
						printf("\nCPF DO CLIENTE: %s", cliente[iX].cpf);
						printf("\nENDERECO: %s", cliente[iX].endereco);
						printf("\nTELEFONE DO CLIENTE: %s", cliente[iX].telefone);
						printf("\nE-MAIL DO CLIENTE: %s", cliente[iX].email);
						printf("\nQUANTIDADE DE CONTAS: %d\n\n", cliente[iX].qtd_contas);
						reg++;
					}
					else
					{
						if(reg == 0)
						{
							printf("\nVOCE NAO DEVERIA ESTAR AQUI\n");
							system("pause");
							break;
						}
					}
				}
				regX++;
			}
		}
		else
		{
			if(regX == 0)
			{
				printf("\nAGENCIA INCORRETA OU NAO CADASTRADA\n");
				system("pause");
				break;
			}
		}
	}

}
//:::::::::::::::::::::::::FUNÇÕES MENU::::::::::::::::::::::::::::
void altera_Cliente(tCliente cliente[MAX_CLIENTES], int *p)//FUNÇÃO QUE EXECUTA O MENU DE ALTERAR CLIENTE E SUAS FUNÇÕES CORRESPONDENTES
{
	int menu, i, j, compara_busca, compara_alt, erro = 0;
	char aux_compara[16], aux_altera[16];
	system("cls");
	printf("CPF: ");
	scanf(" %[^\n]", aux_compara);

	for(i = 0; i < (*p); i++)
	{

		compara_busca = strcmp(cliente[i].cpf, aux_compara);
		if(compara_busca == 0)
			break;
		else
			erro++;
	}
	if(erro == *p)
	{
		printf(">ERRO<:[Este CPF nao esta cadastrado no sistema!]\n\n");
		system("pause");
	}
	else
	{
		do
		{
			menuAltera_Cliente(&menu);
			switch(menu)
			{
			case 1:
				printf("NOVO NOME: ");
				scanf(" %[^\n]", cliente[i].nome);
				break;
			case 2:
				erro = 0;
				printf("NOVO CPF: ");
				scanf(" %[^\n]", aux_altera);

				for(j = 0; j < (*p); j++)
				{

					compara_alt = strcmp(cliente[j].cpf, aux_altera);
					if(compara_alt == 0)
					{
						printf(">ERRO<:[Este CPF ja foi cadastrado! Insira um diferente!]\n\n");
						break;
					}
					else
					{
						erro++;
					}
				}
				if(erro == *p)
				{
					strcpy(cliente[i].cpf, aux_altera);
					printf("\n\n\t[ALTERADO COM SUCESSO]\n\n");
				}
				break;
			case 3:
				printf("NOVO ENDERECO: ");
				scanf(" %[^\n]", cliente[i].endereco);
				break;
			case 4:
				printf("NOVO TELEFONE/CELULAR: ");
				scanf(" %[^\n]", cliente[i].telefone);
				break;
			case 5:
				printf("NOVO e-mail: ");
				scanf(" %[^\n]", cliente[i].email);
				break;
			case 0:
				break;
			default:
				printf("Opcao Invalida!\n");
			}
		}
		while(menu != 0);
	}
}
void f_cliente(tCliente cliente[MAX_CLIENTES], int *j)//FUNÇÃO QUE EXECUTA O MENU CLIENTE E SUAS FUNÇÕES CORRESPONDENTES
{
	int i = 0;
	int p = *j;
	int menu;
	do
	{
		system("cls");
		menuCliente(&menu);
		switch(menu)
		{
		case 1:
			cadastro_Cliente(cliente, &p);
			break;
		case 2:
			altera_Cliente(cliente, &p);
			break;
		case 0:
			break;
		default:
		{
			printf("Opcao Invalida!\n");
			system("pause");
			system("cls");
		}
		}
	}
	while(menu != 0);
	*j = p;

}
void altera_Conta(tConta conta[MAX_CONTAS], tCliente cliente[MAX_CLIENTES], int *p)//FUNÇÃO QUE EXECUTA O MENU DE ALTERAR CONTA E SUAS FUNÇÕES CORRESPONDENTES
{
	int menu, i, j, k, compara, compara_2, compara_cpf, erro = 0, erro_2 = 0;
	int aux_conta, aux_agencia;
	char aux_cpf[16];
	system("cls");
	printf("CONTA: ");
	scanf("%d", &aux_conta);
	printf("AGENCIA: ");
	scanf("%d", &aux_agencia);

	for(i = 0; i < MAX_CLIENTES; i++)
	{

		compara = (conta[i].conta_num - aux_conta) + (conta[i].agencia - aux_agencia);
		if(compara == 0)
		{
			break;
		}
		else
			erro++;
	}
	if(erro == MAX_CLIENTES)
	{
		printf(">ERRO<:[Esta conta nao existe no sistema!]\n\n");
		system("pause");
	}
	else
	{
		do
		{
			menuAlteraConta(&menu);
			switch(menu)
			{
			case 1:
			{
				printf("NOVA AGENCIA: ");
				scanf("%d", &aux_agencia);

				break;
			}
			case 2:
			{
				printf("NOVA CONTA: ");
				scanf("%d", &aux_conta);
				printf("[%d] ", aux_agencia);

				for(j = 0, erro = 0; j < (*p); j++)
				{

					compara_2 = (conta[j].conta_num - aux_conta) + (conta[j].agencia - aux_agencia);
					printf("[%d] ", compara);
					if(compara_2 == 0)
					{
						printf(">ERRO<:[Esta conta ja foi cadastrada! Insira uma diferente!]\n\n");
						break;
					}
					else
						erro++;
				}
				break;
			}
			case 3:
				printf("NOVO CPF: ");
				scanf(" %[^\n]", aux_cpf);
				break;
			case 0:
				break;
			default:
				printf("Opcao Invalida!\n");
			}

			if(erro == *p)
			{
				for(j = 0; j < MAX_CLIENTES; j++)
				{

					compara_cpf = strcmp(cliente[j].cpf, aux_cpf);
					if(compara_cpf == 0)
					{
						conta[i].conta_num = aux_conta;
						conta[i].agencia = aux_agencia;
						strcpy(conta[i].cpf_cliente, aux_cpf);
						printf("\n[CADASTRO BEM SUCEDIDO]\n\n");
						for(k = 0; k < MAX_CLIENTES; k++)
						{
							if(strcmp(conta[i].cpf_cliente, cliente[k].cpf) == 0)
							{
								cliente[i].qtd_contas++;
							}
						}
						conta[i].conta_existe = 1;
						system("pause");
					}
					else
					{
						erro_2++;
					}
				}
				if(erro_2 == MAX_CLIENTES)
				{
					printf("\n[ERRO]: >CPF NAO CADASTRADO NO SISTEMA<\n\n");
					conta[i].cpf_cliente[0] = '\0';
					conta[i].agencia = 0;
					conta[i].conta_num = 0;
					system("pause");
				}

			}
		}
		while(menu != 0);
	}
}
void remove_Conta(tConta conta[MAX_CONTAS], int *p)//FUNÇÃO FEITA PARA REMOVER UMA CONTA REALOCANDO A POSIÇÃO DOS VETORES QUE FORAM PREENCHIDOS(REMOVE OS VALORES DO VETOR ESTRUTURA ESCOLHIDO PELO USUÁRIO E REPOSICIONA OS VETORES SEGUINTES PARA SUA POSIÇÃO ANTERIOR)
{
	int i, n, erro = 0, compara;
	int cnt, age;
	system("cls");
	printf("::::::::::::REMOCAO DE CADASTRO:::::::::::\n\n");
	printf(">INFORME A CONTA E A AGENCIA RESPECTIVAMENTE<\n\n");
	printf("CONTA: ");
	scanf("%d", &cnt);
	printf("\nAGENCIA: ");
	scanf("%d", &age);
	for(i = 0; i < (*p); i++)
	{
		compara = (conta[i].conta_num - cnt) + (conta[i].agencia - age);

		if(compara == 0)
		{
			for(n = i; n < (*p); n++)
			{
				conta[n].agencia = conta[n + 1].agencia;
				conta[n].conta_num = conta[n + 1].conta_num;
				conta[n].saldo = conta[n + 1].saldo;
				strcpy(conta[n].cpf_cliente, conta[n + 1].cpf_cliente);
				conta[n].conta_existe = conta[n + 1].conta_existe;

				conta[*p - 1].cpf_cliente[0] = '\0';
				conta[*p - 1].saldo = 0;
				conta[*p - 1].conta_existe = 0;
				conta[*p - 1].agencia = -1;
				conta[*p - 1].conta_num = -1;
			}
			printf("\n[CONTA REMOVIDA COM SUCESSO!]\n");
			(*p)--;
		}
		else
		{
			erro++;
		}
		if(erro == *p)
		{
			printf("\n>ERRO<:[INFORMACOES DA CONTA NAO CADASTRADAS!]\n\n");
		}
	}

	system("pause");
	system("cls");
}
void f_conta(tConta conta[MAX_CONTAS], int *j)//FUNÇÃO QUE EXECUTA O MENU CONTA E SUAS FUNÇÕES CORRESPONDENTES
{
	int menu;
	int p = *j;
	do
	{
		system("cls");
		menuConta(&menu);
		switch(menu)
		{
		case 1:
			cadastro_Conta(conta, cliente, &p);
			break;
		case 2:
			altera_Conta(conta, cliente, &p);
			break;
		case 3:
			remove_Conta(conta, &p);
			break;
		case 0:
			break;
		default:
		{
			printf("Opcao Invalida!\n");
			system("pause");
			system("cls");
		}
		}
	}
	while(menu != 0);
	*j = p;
}
void movimento(tConta conta[MAX_CONTAS])//FUNÇÃO QUE EXECUTA O MENU MOVIMENTO E SUAS FUNÇÕES CORRESPONDENTES
{
	int menu;
	do
	{
		system("cls");
		menuMovimento(&menu);
		switch(menu)
		{
		case 1:
			deposito(conta);
			break;
		case 2:
			saque(conta);
			break;
		case 3:
			transfere(conta);
			break;
		case 4:
			saldo(conta);
			break;
		case 0:
			break;
		default:
			printf("Opcao Invalida!\n");
		}
	}
	while(menu != 0);
}
void relatorio(tCliente cliente[MAX_CLIENTES], tConta conta[MAX_CONTAS], int *p1, int *p2)//FUNÇÃO QUE EXECUTA O MENU RELATORIO E SUAS FUNÇÕES CORRESPONDENTES
{
	int menu;
	int c = *p1, p = *p2;
	do
	{
		menuRelatorio(&menu);
		switch(menu)
		{
		case 1:
			contas_Cliente(conta, cliente);
			break;
		case 2:
			dadosCliente_porSaldo(cliente, conta, &c, &p);
			break;
		case 3:
			listaDados_ALLclientes(cliente);
			break;
		case 4:
			lista_Contas_ALL(conta);
			break;
		case 5:
			lista_CLIENTES_CONTAS(cliente, conta);
			break;
		case 6:
			lista_Ativos_porCPF(cliente, conta);
		case 0:
			break;
		default:
			printf("Opcao Invalida!\n");
		}
	}
	while(menu != 0);
}
//:::::::::::::::::::::::::::::MAIN::::::::::::::::::::::::::::::::
int main(void)//FUNÇÃO MAIN
{
	int pos_cliente = 0;
	int pos_conta = 0;
	int menu;
	zeroclientes(cliente, conta);
	do
	{
		system("cls");
		menuPrincipal(&menu);
		switch(menu)
		{
		case 1:
			f_cliente(cliente, &pos_cliente);
			break;
		case 2:
			f_conta(conta, &pos_conta);
			break;
		case 3:
			movimento(conta);
			break;
		case 4:
			relatorio(cliente, conta, &pos_conta, &pos_cliente);
			break;
		case 0:
			break;
		default:
		{
			printf("Opcao Invalida!\n");
			system("pause");
		}
		}
	}
	while(menu != 0);
	system("cls");
	return 0;
}
