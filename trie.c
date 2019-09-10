#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

node* leDicionario()
	{
		int qtdDic, i, j;
		char *palavra;
		palavra = (char*)malloc(sizeof(char)*15);
		node *root = (node*) malloc(sizeof(node));
		root->filho = (node*) malloc(sizeof(node));
		node *aux = root->filho;
		aux->c = 0;
		aux->santo = NULL;
		aux->pai = root;
		aux->espirito = NULL;
		aux->filho = NULL;
		aux->fim = 0;
		node *pai = root;
		scanf("%d",&qtdDic);

		for(i= 0; i<qtdDic;i++) //Lê as palavras do dicionario
		{
			scanf("%s",palavra);
			aux = root->filho;
			if(aux->c == 0)
				aux->c = palavra[0];
			for(j = 0; j < strlen(palavra) && aux != NULL; j++) //caminha pela palavra para inserir na trie
			{
				while((aux != NULL) && aux->santo != NULL && aux->c != palavra[j]){
					aux = aux->santo;
				}
				
				if(aux->c == palavra[j] && j < strlen(palavra) - 1){
					pai = aux;
					aux = aux->filho;
					if(aux != NULL)
						aux->pai = pai;

				}else if(aux->santo == NULL && j < strlen(palavra) - 1){
					aux->santo = (node*) malloc(sizeof(node));
					aux->santo->fim = 0;
					aux->santo->santo = NULL;
					aux->santo->filho = NULL;
					aux->santo->espirito = aux;
					aux->santo->pai = pai;
					aux->santo->c = palavra[j];
					aux = aux->santo;
					pai = aux;
					aux = aux->filho;
				}
			}
			if(aux == NULL){
				for(; j < strlen(palavra); j++){
					pai->filho = (node*)malloc(sizeof(node));
					aux = pai->filho;
					aux->fim = 0;
					aux->c = palavra[j];
					aux->santo = NULL;
					aux->espirito = NULL;
					aux->pai = pai;
					pai = aux;
				}
			}
			aux->fim = 1;
			aux->ind = i;
		}
		root->ind = qtdDic;
		return root;
	}

	int* contaFreq(node *dict){
		int *freq = (int*) malloc(sizeof(int) * dict->ind);
		memset(freq, 0, sizeof(int)*(dict->ind));
		int qtdText, i, j;
		scanf("%d",&qtdText);
		char *palavra;
		node *aux = dict->filho;
		palavra = (char*)malloc(sizeof(char)*15);
		for(i= 0; i<qtdText;i++) //Lê as palavras do dicionario
		{
			scanf("%s",palavra);
			aux = dict->filho;
			for(j = 0; j < strlen(palavra) && aux != NULL; j++){
				while(aux->santo != NULL && aux->c != palavra[j])
					aux = aux->santo;
				if(aux->c == palavra[j]){
					if(aux->fim == 1 && j == (strlen(palavra) -1)){
						freq[aux->ind]++;
					}else{
						aux = aux->filho;
					}
				}else
					aux = aux->santo;
			}
		}
			return freq;

	}