#include <stdlib.h>
#include <stdio.h>
#include "trie.h"

int main( int argc , char * argv[]){
	node *a = leDicionario();
	int *frequencia = contaFreq(a);

	int i;
	for(i = 0; i < a->ind; i++)
		printf("%d ", frequencia[i]);
	printf("\n");
	return 0;
}