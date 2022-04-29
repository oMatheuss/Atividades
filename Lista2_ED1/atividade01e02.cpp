#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
Escreva um programa que implemente uma lista duplamente encadeada que
armazena números inteiros. Implemente as operações de inserir no início, inserir
no fim, remoção e impressão dos valores da lista.
*/

/*
Escreva um programa que implemente uma lista duplamente encadeada que
armazena números inteiros. Fazer uma função para buscar um número na lista. 
*/

struct Lista {
	Lista * ant;
	Lista * prx;
	int num;
};

Lista * insere_fim(Lista * lista, int num) {
	Lista * nova = new Lista();
	nova->ant = NULL;
	nova->prx = NULL;
	nova->num = num;
	if (lista == NULL) return nova;
	Lista * aux = lista;
	while (aux->prx != NULL) {
		aux = aux->prx;
	}
	nova->ant = aux;
	aux->prx = nova;
	return lista;
}

Lista * insere_inicio(Lista * lista, int num) {
	Lista * nova = new Lista();
	nova->ant = NULL;
	nova->prx = NULL;
	nova->num = num;
	if (lista == NULL) return nova;

	nova->prx = lista;
	lista->ant = nova;
	return nova;
}

Lista * remover(Lista * lista, int num) {
	if (lista == NULL) return NULL;
	Lista * aux = lista;
	
	if (aux->num == num && aux->prx != NULL) {
		aux->prx->ant = NULL;
		return aux->prx;
	} else if(aux->num == num && aux->prx == NULL) {
		return NULL;
	}
	
	while(aux->prx != NULL) {
		aux = aux->prx;
		if (aux->num == num) {
			if (aux->prx == NULL) {
				aux->ant->prx = NULL;
				return lista;
			}
			aux->prx->ant = aux->ant;
			aux->ant->prx = aux->prx;
			return lista;
		}
	}
	return lista;
}

void imprime_lista(Lista * lista) {
	if (lista == NULL) {
		printf("[] <- lista vazia\n");
		return;
	}
	printf("[");
	while (lista->prx != NULL) {
		printf("%d ", lista->num);
		lista = lista->prx;
	}
	printf("%d]\n", lista->num);
}

void busca(Lista * lista, int num) {
	if (lista->num == num) {
		printf("O numero esta na lista!\n");
		return;
	}
	Lista * aux = lista;
	while (aux->prx != NULL) {
		aux = aux->prx;
		if (aux->num == num) {
			printf("O numero esta na lista!\n");
			return;
		}
	}
	printf("O numero nao esta na lista!\n");
}

int main() {
	Lista * lista = NULL;
	
	int op = -1, num;
	
	while (op != 0) {
		system("cls");
		imprime_lista(lista);
		printf("\nInserir no inicio da lista -> 1\n");
		printf("Inserir no fim da lista -> 2\n");
		printf("remover da lista -> 3\n");
		printf("busca na lista -> 4\n");
		
		printf("\nInforme a opcao: \n");
		
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				printf("Informe um numero a ser adicionado: ");
				scanf("%d", &num);
				lista = insere_inicio(lista, num);
				break;
			case 2:
				printf("Informe um numero a ser adicionado: ");
				scanf("%d", &num);
				lista = insere_fim(lista, num);
				break;
			case 3:
				printf("Informe um numero a ser removido: ");
				scanf("%d", &num);
				lista = remover(lista, num);
				break;
			case 4:
				printf("Informe um numero a ser buscado: ");
				scanf("%d", &num);
				busca(lista, num);
				getch();
				break;
			default:
				return 0;
		}
	}
}
