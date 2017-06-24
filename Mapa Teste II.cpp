#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 15
  
  typedef struct s_no{ 		//Define a struct
  	char pai[TAM];			//String Pai
  	char lesq[TAM];			//String lado esquerdo
  	char ldir[TAM];			//String lado direito
  }s_no;
  
  void AddArvore(struct s_no *noa, int *i, int *a, int *e) //Função para adicionar nome a arvore
  {

  	printf("\nDigite seu nome:");
  		scanf("%s", (*(noa+*i)).pai);
  		
  		do{	
		fflush(stdin);	 								//Limpa o buffer do teclado
		printf("\nNome do Pai de %s:",(*(noa+*i)).pai);	
		scanf("%s",(*(noa+*i)).lesq);					//Adiciona o nome do Pai
		printf("\nNome da Mãe de %s:",(*(noa+*i)).pai);	
		scanf("%s",(*(noa+*i)).ldir);					//Adiciona o nome da Mae
		strcpy ((*(noa+*a)).pai, (*(noa+*i)).lesq);		//Coloca o nome do Pai como proximo filho
		strcpy ((*(noa+*e)).pai, (*(noa+*i)).ldir);		//Coloca o nome da mae logo apos o do pai como filho
		system("cls");									//Limpa a tela
		*a=*a+2;
		*e=*e+2;											//Muda a contagem
		*i++;
		}while(*i<7);
  }
  
  void MostraArvore(struct s_no *noa, int *i)			//Funcao para exibir a arvore
  {

  	printf("\n=============Árvore Genealógica=============");
	for(*i=0; *i<7; *i++){
	printf("\nFilho:%s Pai:%s Mãe:%s",(*(noa+*i)).pai, (*(noa+*i)).lesq, (*(noa+*i)).ldir);	//Exibe os nomes
		}
	printf("\n============================================\n");
  }

  int main(void){
  	setlocale(LC_ALL,"portuguese");						//Libera o uso de acentos do idioma portugues
    s_no noa[TAM];										//Define o vetor do tipo s_no
  	int op=0, i=0, a=1, e=2;							//Variaveis de contagens
  	
  	do{
  	printf("1 Para preencher árvore\n2 Para mostrar árvore\n0 Para sair\nEscolha uma opção:");
  	scanf("%d",&op);
  	
  	switch(op){											//Inicia o Menu
	
  	case 1 :
  	AddArvore(noa, &i, &a, &e);							//Chama a funcao de adicionar nome na arvore
  	break;
  	
  	case 2 :
  		MostraArvore(noa, &i);							//Chama a funcao de mostrar a arvore
  	}
  }while(op!=0);
  	
}

