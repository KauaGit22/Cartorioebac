#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
 	//final da criação de variáveis
 	
	printf("digite o cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%S refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // abre o arquivo
	fprintf(file,","); // separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //separa as variaveis
	fclose(file); //fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", cargo); //%S refere-se a string
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //limpar a tela
}

int consulta()
{
	//inicio da criação de variaveis
	char cpf[40];
	char conteudo[200];
	//final da criação de variaveis
	
	printf("digite o cpf a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Não foi possível abrir o arquivo,não localizado!.\n"); //passar informação para o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são informações do usuário: "); //passar informações para o usuário
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause"); //limpar a tela
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL);
	{
		printf("O usuario não se encontra no sistema!.\n"); //coletando imformações do usuário
		system("pause"); //limpar a tela
	}
	
	
}

int main()
{
	int opcao=0; //defenindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //função de limpar a tela para o usuário
	
	    setlocale(LC_ALL, "Portuguese"); //defenindo linguagem
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("escolha a opção desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n"); 
	    printf("opção:"); //fim do menu
	
	    scanf("%d", &opcao); //armazenando escolha do usuário
	
	    system ("cls"); //função de limpar a tela para o usuário
	    
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
		    break;
		    
		    case 2:
		    consulta(); //chamada de funções
		    break;
		    
		    case 3:
		    deletar(); //chamada de funções
		    break;
					    
		    default:
		    printf("essa opção não está disponivel!\n"); //passar informação para o usuário
		    system("pause"); // limpar a tela
		    break;
		    
		}
	
}
}

