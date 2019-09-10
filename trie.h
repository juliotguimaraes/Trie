#ifndef TRIE_H_
#define TRIE_H_

typedef struct node{
	struct node *pai, *filho, *espirito, *santo; //espirito esq, santo dir
	char c;
	int fim, ind;
}node;

node* leDicionario();
int* contaFreq(node *dict);


#endif