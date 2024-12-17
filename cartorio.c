#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
 	//final da cria��o de vari�veis
 	
	printf("digite o cpf a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,","); // separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cargo); //%S refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //limpar a tela
}

int consulta()
{
	//inicio da cria��o de variaveis
	char cpf[40];
	char conteudo[200];
	//final da cria��o de variaveis
	
	printf("digite o cpf a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo,n�o localizado!.\n"); //passar informa��o para o usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o informa��es do usu�rio: "); //passar informa��es para o usu�rio
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); //limpar a tela
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL);
	{
		printf("O usuario n�o se encontra no sistema!.\n"); //coletando imforma��es do usu�rio
		system("pause"); //limpar a tela
	}
	
	
}

int main()
{
	int opcao=0; //defenindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //fun��o de limpar a tela para o usu�rio
	
	    setlocale(LC_ALL, "Portuguese"); //defenindo linguagem
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n"); 
	    printf("op��o:"); //fim do menu
	
	    scanf("%d", &opcao); //armazenando escolha do usu�rio
	
	    system ("cls"); //fun��o de limpar a tela para o usu�rio
	    
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
		    break;
		    
		    case 2:
		    consulta(); //chamada de fun��es
		    break;
		    
		    case 3:
		    deletar(); //chamada de fun��es
		    break;
					    
		    default:
		    printf("essa op��o n�o est� disponivel!\n"); //passar informa��o para o usu�rio
		    system("pause"); // limpar a tela
		    break;
		    
		}
	
}
}

