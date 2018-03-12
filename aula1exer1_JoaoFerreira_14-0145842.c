#include <stdio.h>
#include <stdlib.h>


typedef struct{

	char name[30];
	char cpf[21];
	
}pessoa;
	
typedef struct{

	char nomeCarro[20];
	char cpfDono[21];
	char placa[10];

}carro;

FILE *openFile(char option, char nameFile[30])
{
	FILE *file; //declaração do ponteiro tipo arquivo

	switch(option)
	{
		case 'o': //openfile
			file = fopen(nameFile, "wt");//"wt" abertura para gravação
			break;
		
		case 'l':
			file = fopen(nameFile, "rt"); //"rt" leitura do arquivo
		break;
		
		case 'a':
			file =fopen(nameFile, "a"); //Abre o arquivo para escrita no final do arquivo. Não apaga o conteúdo pré-existente
			break;
	}

	if(file==NULL)
	{
		printf("openfile error!\n");
		exit(0);
	}


	return file;
}

void closeFile(FILE *file)
{
	fclose(file);
}

void registerFile(pessoa Pessoa)

{
	
	FILE *file;
	file = openFile('a', "register_people.txt");
	printf("Nome: ");
	scanf(" %[^\n]", Pessoa.name);
	printf("CPF: ");
	scanf(" %[^\n]", Pessoa.cpf);
	fprintf(file, "%s | %s\n", Pessoa.cpf, Pessoa.name);
	closeFile(file);
}

void registerFile2(carro Carro)

{	
	FILE *file;
	file = openFile('a', "register_car.txt");
	printf("Nome do carro: ");
	scanf(" %[^\n]", Carro.nomeCarro);
	printf("Placa do carro: ");
	scanf(" %[^\n]", Carro.placa);
	printf("Cpf do dono: ");
	scanf(" %[^\n]", Carro.cpfDono);
	fprintf(file, "%s | %s | %s", Carro.nomeCarro, Carro.placa, Carro.cpfDono);
	closeFile(file);

}

void list_people()
{
	char url[]="register.txt", info[500];
	FILE *file;

	file = fopen(url, "r");
	
	if(file == NULL)
		
		printf("Não foi possivel abrir o arquivo!!\n");


else

	while( (fgets(info, sizeof(info), file)) !=NULL)
		printf("%s", info);

	fclose(file);
}


void list_car()
{
	char url[]="register_car.txt", info[500];
	FILE *file;

	file = fopen(url, "r");

	if(file == NULL)
		printf("Não foi possivel abrir o arquivo!!\n");

	else
		while ((fgets(info, sizeof(info), file))!= NULL)
			printf("%s", info);

		fclose(file);
}


int main(void)
{
	int option;
	pessoa Pessoa;
	carro Carro;
	char name[30],cpf[21];

	do
	{
		
		printf("\n\n BEM VINDO AO BANCO DE DADOS PRIMITIVO!!!\n\n");
		printf("\nMENU\n");
		printf("\n1 - REGISTRAR PESSOA");
		printf("\n2 - REGISTAR CARRO");
		printf("\n3 - LISTAR PESSOAS");
		printf("\n4 - LISTAR CARROS");
		printf("\n5 - SAIR");

		printf("\n\nESCOLHA SUA OPÇÃO: ");
		scanf("%d", &option);


		switch(option)
		{
			case 1: 
							
				registerFile(Pessoa);
				
				break;				

			case 2:
				registerFile2(Carro);

				break;

			case 3:
				printf("************INICIO LISTA************\n\n\n");
				list_people();
				printf("\n\n\n************FIM DA LISTA************");

				break;

			case 4:

				printf("************INICIO LISTA************\n\n\n");
				list_car();
				printf("\n\n\n************FIM DA LISTA************");

				break;

			case 5:
				printf("BYE-BYE\n");
				break;

			default:
				printf("INVALID OPTION");

		}

	}while(option!=3);



	return 0;
}            
