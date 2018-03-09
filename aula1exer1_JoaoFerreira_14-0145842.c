#include <stdio.h>
#include <stdlib.h>


struct Register{

	char name[30];
	char rg[20];
	char cpf[21];
	char qtd[9];
	char car[50];

};
	struct Register aux;


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

void registerFile()

{

	FILE *file;
	file = openFile('a', "register.txt");
	fprintf(file, "Nome: %s", aux.name);
	fprintf(file, "Rg: %s", aux.rg);
	fprintf(file, "Cpf: %s", aux.cpf);
	fprintf(file, "Número de carros: %s", aux.qtd);
	fprintf(file, "Nome(s) do(s) carro(s): %s\n", aux.car);

	closeFile(file);
}

void list()
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

int main(void)
{
	int option;
	char name[30], rg[20], cpf[21], car[50], qtd[9];


	do
	{
		
		printf("\n\n BEM VINDO AO BANCO DE DADOS PRIMITIVO!!!\n\n");
		printf("\nMENU\n");
		printf("\n1 - REGISTRAR PROPRIETÁRIO DO VEICULO");
		printf("\n2 - LISTAR REGISTROS");
		printf("\n3 - SAIR");

		printf("\n\nESCOLHA SUA OPÇÃO: ");
		scanf("%d", &option);


		switch(option)
		{
			case 1: 
				printf("\nNome: ");
				setbuf(stdin, NULL);
				fgets(aux.name, 31, stdin);
				printf("\nRG: ");
				setbuf(stdin, NULL);
				fgets(aux.rg, 21, stdin);
				printf("\nCPF: ");
				setbuf(stdin, NULL);
				fgets(aux.cpf, 21, stdin);
				printf("\nNº DE CARROS: ");
				setbuf(stdin, NULL);
				fgets(aux.qtd, 10, stdin);
				printf("\nNome(s) dos automóvei(s): ");
				setbuf(stdin, NULL);
				fgets(aux.car, 51, stdin);
				registerFile();
				
				break;				

			case 2:
				printf("************INICIO LISTA************\n");
				list();
				printf("************FIM DA LISTA************");

				break;

			case 3:
				printf("BYE-BYE\n");
				break;

			default:
				printf("INVALID OPTION");

		}

	}while(option!=3);



	return 0;
}            
