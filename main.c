/*
*Autor: Code Meo
*Programa: pronto_socorro
*Data: 17/09/2021
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

//estrutura
struct Paciente
{
	int prontuario;
	char data[12];
	char nome[100];
	char endereco[200];
	char fone[50];
	char email[50];
	char descricao[300];
	char status;	
};

//declaração de funções
void gotoxy( int x, int y );
void bordas();
void telaLogin();
void menu();
void sair();
void incluir();
void localizar(); 
void alterar();
void listar();
void excluir();
void relatorio();

//função principal
int main()
{
	system("mode con:cols=80 lines=25");
	telaLogin();
	menu();
	return 0;
}

//funções
void gotoxy( int x, int y )
{
	printf("%c[%d;%df",0x1B,y,x);
}

void bordas()
{
	for( int x = 3; x < 79; x++ )
	{
		gotoxy(x,2);
		printf("%c",196); //borda horizontal superior
		gotoxy(x,24);
		printf("%c",196); //borda horizontal inferior
	}
	
	for( int y = 3; y < 24; y++ )
	{
		gotoxy(2,2);
		printf("%c",218); //canto superior esquerdo
		gotoxy(79,2);
		printf("%c",191); //canto superior direito
		gotoxy(2,y);
		printf("%c",179); //borda vertical do lado direito
		gotoxy(79,y);
		printf("%c",179); //borda vertical do lado esquerdo
		gotoxy(2,24);
		printf("%c",192); //canto inferior esquerdo
		gotoxy(79,24);
		printf("%c",217); //canto inferior direito
		
	}
}

void telaLogin()
{
	char login[10] = "MrHouse";
	char senha[10] = "RobCo";
	char loginUser[10] = {0};
	char senhaUser[10] = {0};
	
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(35,6);
	printf("Tela de Login");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);

	gotoxy(28,11);
	printf("Digite o usuario: ");
	gotoxy(28,12);
	printf("Digite a senha..: ");
	gotoxy(46,11);
	fgets(loginUser,10,stdin);
	loginUser[strcspn(loginUser,"\n")] = 0;
	gotoxy(46,12);
	fgets(senhaUser,10,stdin);
	senhaUser[strcspn(senhaUser,"\n")] = 0;
	if((strcmp(login, loginUser) && (strcmp(senha, senhaUser)))==0)
	{
		menu();
	}
	else
	{
		telaLogin();
	}

	
}

void menu()
{
	system("cls");
	bordas();
	char opcao;
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(35,6);
	printf("Menu Principal");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	gotoxy(28,9);
	printf("[1] Incluir");
	gotoxy(28,10);
	printf("[2] Localizar");
	gotoxy(28,11);
	printf("[3] Alterar");
	gotoxy(28,12);
	printf("[4] Listar");
	gotoxy(28,13);
	printf("[5] Excluir");
	gotoxy(28,14);
	printf("[6] Gerar relatorio");
	gotoxy(28,15);
	printf("[7] Sair");
	gotoxy(28,17);
	printf("Escolha a opcao desejada: ");
	opcao = getche();
	switch(opcao)
	{
		case '1':
			incluir();
			break;
		case '2':
			localizar();
			break;
		case '3':
			alterar();
			break;
		case '4':
			listar();
			break;
		case '5':
			excluir();
			break;
		case '6':
			relatorio();
			break;
		case '7':
			sair();
			break;
		default:
			menu();
			break;		
	}
}

void sair()
{
	system("cls");
	bordas();
	gotoxy(25,12);
	printf("Obrigado por utilizar o nosso sistema!");
	gotoxy(4,23);
	system("pause");
	exit(0);
}

void incluir()
{
	struct Paciente paciente;
	FILE *arquivo;
	int prontuario = 1;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(30,6);
	printf("Cadastro de Atendimento");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	arquivo = fopen("prontuario.dat","ab+");
	if(arquivo == NULL)
	{
		printf("Nao e possível criar ou abrir o arquivo.");
		exit(0);
	}
	else
	{
		fread(&paciente, sizeof(struct Paciente), 1, arquivo);
		while(!feof(arquivo))
		{
			if(prontuario == paciente.prontuario)
			{
				prontuario = prontuario + 1;
			}
			fread(&paciente, sizeof(struct Paciente), 1, arquivo);
		}
		paciente.prontuario = prontuario;
		gotoxy(4,9);
		printf("Nome do paciente: ");
		gotoxy(4,11);
		printf("Endereco do paciente");
		gotoxy(4,13);
		printf("Telefone do paciente: ");
		gotoxy(4,15);
		printf("E-mail: ");
		gotoxy(4,17);
		printf("Ocorrencia: ");
		
		_strdate(paciente.data);
		gotoxy(4,10);
		fgets(paciente.nome, 100, stdin);
		paciente.nome[strcspn(paciente.nome, "\n")] = 0;
		gotoxy(4,12);
		fgets(paciente.endereco, 200, stdin);
		paciente.endereco[strcspn(paciente.endereco, "\n")] = 0;
		gotoxy(4,14);
		fgets(paciente.fone, 50, stdin);
		paciente.fone[strcspn(paciente.fone, "\n")] = 0;
		gotoxy(4,16);
		fgets(paciente.email, 50, stdin);
		paciente.email[strcspn(paciente.email, "\n")] = 0;
		gotoxy(4,18);
		fgets(paciente.descricao, 100, stdin);
		paciente.descricao[strcspn(paciente.descricao, "\n")] = 0;
		
		paciente.status = 'A';
		//gravar dados no arquivo
		fwrite(&paciente, sizeof(struct Paciente), 1, arquivo);
		gotoxy(4,20);
		printf("Dados gravados com sucesso!\n");
	}
	//fechar o arquivo
	fclose(arquivo);
	gotoxy(4,23);
	system("pause");
	menu();
	
}

void localizar()
{
	struct Paciente paciente;
	int prontuario = 0, encontrou = 0;
	FILE *arquivo;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(33,6);
	printf("Localizar Paciente");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	gotoxy(4,9);
	printf("Digite o prontuario: ");
	gotoxy(25,9);
	scanf("%d", &prontuario);
	fflush(stdin);
	
	//abrir o arquivo
	arquivo = fopen("prontuario.dat","rb");
	if(arquivo == NULL)
	{
		printf("Nao e possível criar ou abrir o arquivo.");
		exit(0);
	}
	else
	{
		fread(&paciente, sizeof(struct Paciente), 1, arquivo);
		while(encontrou == 0 && !feof(arquivo))
		{
		    if(paciente.status == 'A' && paciente.prontuario == prontuario)
			{
				encontrou = 1;
				gotoxy(4,12);
				printf("Prontuario: %d", paciente.prontuario);
				gotoxy(4,13);
				printf("Nome......: %s", paciente.nome);
				gotoxy(4,14);
				printf("Endereco..: %s", paciente.endereco);
				gotoxy(4,15);
				printf("Telefone..: %s", paciente.fone);
				gotoxy(4,16);
				printf("E-mail....: %s", paciente.email);
				gotoxy(4,17);
				printf("Descricao.: %s", paciente.descricao);
				gotoxy(4,18);
				printf("Data do atendimento: %s", paciente.data);
			}
			else
			{
				fread(&paciente, sizeof(struct Paciente),1,arquivo);
			}
		}
		if(encontrou == 0)
		{
			gotoxy(4,15);
			printf("Prontuario nao encontrado");
		}
	}
	fclose(arquivo);
	gotoxy(4,23);
	system("pause");
	menu();
}

void alterar()
{
	struct Paciente paciente;
	int prontuario, encontrou;
	FILE *arquivo;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(32,6);
	printf("Alterar prontuario");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	gotoxy(4,9);
	printf("Digite o prontuario: ");
	gotoxy(25,9);
	scanf("%d", &prontuario);
	fflush(stdin);
	
	//abrir arquivo
	arquivo = fopen("prontuario.dat","rb+");
	if(arquivo == NULL)
	{
		printf("Nao e possível criar ou abrir o arquivo.");
		exit(0);
	}
	else
	{
		encontrou = 0;
		while(encontrou == 0 && !feof(arquivo))
		{
			fread(&paciente, sizeof(struct Paciente), 1, arquivo);
			if(!feof(arquivo) && prontuario == paciente.prontuario && paciente.status == 'A')
			{
				encontrou = 1;
				gotoxy(4,10);
				printf("Prontuario: %d", paciente.prontuario);
				gotoxy(4,11);
				printf("Nome......: %s", paciente.nome);
				gotoxy(4,12);
				printf("Endereco..: %s", paciente.endereco);
				gotoxy(4,13);
				printf("Telefone..: %s", paciente.fone);
				gotoxy(4,14);
				printf("E-mail....: %s", paciente.email);
				gotoxy(4,15);
				printf("Descricao.: %s", paciente.descricao);
				
				gotoxy(16,11);
				fgets(paciente.nome, 100, stdin);
				paciente.nome[strcspn(paciente.nome, "\n")] = 0;
				gotoxy(16,12);
				fgets(paciente.endereco, 200, stdin);
				paciente.endereco[strcspn(paciente.endereco, "\n")] = 0;
				gotoxy(16,13);
				fgets(paciente.fone, 50, stdin);
				paciente.fone[strcspn(paciente.fone, "\n")] = 0;
				gotoxy(16,14);
				fgets(paciente.email, 50, stdin);
				paciente.email[strcspn(paciente.email, "\n")] = 0;
				gotoxy(16,15);
				fgets(paciente.descricao, 300, stdin);
				paciente.descricao[strcspn(paciente.descricao, "\n")] = 0;
				
				paciente.prontuario = prontuario;
				paciente.status = 'A';
				
				fseek(arquivo, -sizeof(struct Paciente), SEEK_CUR);
				fwrite(&paciente, sizeof(struct Paciente), 1, arquivo);
				
				gotoxy(4,22);
				printf("Prontuario alterado com sucesso!");
			}
		}
	}
	fclose(arquivo);
	gotoxy(4,23);
	system("pause");
	menu();
}

void listar()
{
	struct Paciente paciente;
	FILE *arquivo;
	int cont = 1;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(31,6);
	printf("Relacao de prontuarios");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	arquivo = fopen("prontuario.dat","rb");
	if(arquivo == NULL)
	{
		printf("Nao e possivel abrir este arquivo.");
	}
	else
	{
		fread(&paciente, sizeof(struct Paciente), 1, arquivo);
		while(!feof(arquivo))
		{
			if(paciente.status == 'A')
			{
				printf("\n\tProntuario.......:%d\n", paciente.prontuario);
				printf("\tNome...............:%s\n", paciente.nome);
				cont++;
			}
			if(cont == 6)
			{
				gotoxy(4,22);
				system("pause");
				system("cls");
				bordas();
				gotoxy(28,2);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
				gotoxy(28,3);
				printf("%c   Hospital Santa Clara   %c",179,179);
				gotoxy(28,4);
				printf("%c       Pronto Socorro     %c",179,179);
				gotoxy(28,5);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
				gotoxy(34,6);
				printf("Relacao de prontuarios");
				gotoxy(28,7);
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
				printf("\n");
				cont = 1;
			}
			fread(&paciente, sizeof(struct Paciente), 1, arquivo);
		}
		fclose(arquivo);
		gotoxy(4,22);
		system("pause");
		menu();
	}
}

void excluir()
{
	int prontuario = 0, encontrou = 0;
	struct Paciente paciente;
	FILE *arquivo;
	int opcao;
	char conf;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(32,6);
	printf("Excluir prontuarios");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	gotoxy(4,9);
	printf("Digite o prontuario a excluir: ");
	gotoxy(35,9);
	scanf("%d", &prontuario);
	fflush(stdin);
	arquivo = fopen("prontuario.dat","rb+");
	if(arquivo == NULL)
	{
		printf("Nao e possivel abrir este arquivo.");
	}
	else
	{
		while(encontrou == 0 && !feof(arquivo))
		{
			fread(&paciente, sizeof(struct Paciente), 1, arquivo);
			if(!feof(arquivo) && prontuario == paciente.prontuario && paciente.status == 'A')
			{
				encontrou = 1;
				gotoxy(4,12);
				printf("Prontuario: %d", paciente.prontuario);
				gotoxy(4,13);
				printf("Nome: %s", paciente.nome);
				gotoxy(4,14);
				printf("Descricao: %s", paciente.descricao);
				
			}
		}
		if(encontrou == 1)
		{
			gotoxy(4,17);
			printf("Deseja excluir este prontuario: (s)sim (n)nao?");
			gotoxy(50,17);
			conf = getche();
			if(conf == 'S' || conf == 's')
			{
				fseek(arquivo, -sizeof(struct Paciente), SEEK_CUR);
				paciente.status = 'E';
				fwrite(&paciente, sizeof(struct Paciente), 1, arquivo);
				gotoxy(4,18);
				printf("Prontuario excluido com sucesso!");
			}
		}
		
	}
	fclose(arquivo);
	gotoxy(4,23);
	system("pause");
	menu();
}

void relatorio()
{
	struct Paciente paciente;
	FILE *arquivo, *temp;
	system("cls");
	bordas();
	gotoxy(28,2);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	gotoxy(28,3);
	printf("%c   Hospital Santa Clara   %c",179,179);
	gotoxy(28,4);
	printf("%c       Pronto Socorro     %c",179,179);
	gotoxy(28,5);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	gotoxy(34,6);
	printf("Gerar Relatorio");
	gotoxy(28,7);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
	
	temp = fopen("relatorio.csv","w+");
	arquivo = fopen("prontuario.dat", "rb");
	
	fputs("Prontuario; Data de atendimento; Nome; Endereco; Telefone; E-mail; Descricao; Situacao;\r", temp);
	
	fread(&paciente, sizeof(struct Paciente), 1, arquivo);
	while(!feof(arquivo))
	{
		fprintf(temp, "%d; %s; %s; %s; %s; %s; %s; %c; \r", paciente.prontuario, paciente.data, paciente.nome, paciente.endereco, paciente.fone, paciente.email, paciente.descricao, paciente.status);
		fread(&paciente, sizeof(struct Paciente), 1, arquivo);
	}
	fclose(temp);
	fclose(arquivo);
	gotoxy(4,12);
	printf("Relatorio gerado com sucesso!");
	gotoxy(4,23);
	system("pause");
	menu();
}





