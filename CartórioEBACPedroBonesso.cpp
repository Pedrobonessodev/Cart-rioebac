#include <stdio.h>	//Biblioteca de comunicação com o usuário
#include <stdlib.h>	// biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função para cadastro de usuário do sistemna
{
	//criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tRegistro de nomes\n");
	
	printf("Digite o CPF do novo cadastro:");  //coletando informações do usuário
	scanf("%s", cpf);  //%s se refere á string
	
	strcpy(arquivo, cpf);  //responsável por copiar os valores das string
	
	FILE *file;  //chamando a função FILE e mandando criar o arquivo file 
	file = fopen(arquivo, "w"); //abrir o arquivo com oque tem na variável e "w" para escrever algo no arquivo
		fprintf(file,cpf); // salvo o valor da variável dentro do arquivo
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arqui file novamente para colocar informações nova por isso apenas "a" e não "w"
	fprintf(file,".\n ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	 
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	printf("Digite o cargo do novo cadastro:");
	scanf("%s",cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	system("pause");
	
}
int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Consulta de cadastros\n\n");
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen(cpf,"r"); //"r" é para ler oque esta no arquivo cpf
	
	if(file == NULL) // para se não existir cadastro com o numero digitado
	{
		printf("Nenhum cadastro com este CPF foi encontrado.\n");
	}
	while(fgets(conteudo, 200, file) != NULL) //enquanto tiver conteudo dentro do arquivo ele armazena na variável conteudo
	{
        printf("\nCPF- %s", conteudo);

        if (fgets(conteudo, 200, file) != NULL)
            printf("Nome- %s", conteudo);

        if (fgets(conteudo, 200, file) != NULL)
            printf("Sobrenome- %s", conteudo);

        if (fgets(conteudo, 200, file) != NULL)
            printf("Cargo- %s", conteudo);

        printf("\n");
    }
	
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("\t Remoção de cadastros\n\n");
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; // acesse a função file e puxe os arquivos
	file = fopen (cpf, "r");
	
	if(file == NULL );
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	system("pause");
	
}

int main() // Função, tudo que estiver nas chaves estão dentro da função
{
	int opcao=0; // Definindo a variável opcao e setando ela como 0, um = serve para atribuição
	int loop=1;
	
	for(loop=1;loop=1;) // a variavel loop é = a 1 e deve ficar até que loop seja =1 ou seja estamos criando um loop
	{
		system("cls"); // comando para o sistema limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); // colocanco a localização afim de usar caracteres especiais e especificos
		
		printf("====Lista de cadastrados====\n\n"); //O \n Tem a função de pular linha
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 - Registrar novo cadastro\n"); // O \t Tem a função de espaçar o texto
		printf("\t2 - Consultar cadastros\n");
		printf("\t3 - Remover cadastros\n\n");
		printf("Opção: ");

		scanf("%d", &opcao); //"scanf" é para analisar a decisão tomada pelo usuário no caso oque foi digitado ""%d"" serve para variável do tipo inteiro e o ", &" serve para setar em qual variavel deve ser armazenada a informação
	
		system("cls"); // comando para o sistema para limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();
			break;
			case 2:
			consulta();
			break;
			case 3:
			deletar();
			break;
			default:
			printf("Esta opção não está disponível\n\n");
			system("pause");
			break;
		}	//fim da seleção
		
	}
}
