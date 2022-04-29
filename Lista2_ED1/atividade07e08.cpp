#include <stdio.h>
#include <windows.h>

/*
Escreva um programa que implemente uma lista circular que armazena números
reais. Implemente as operações de inserir no início, inserir no fim, remoção e
consulta (impressão) dos valores da lista.
*/

struct Lista {
	Lista * prx;
	float num;
};

Lista * insere_fim(Lista * lista, float num) {
	Lista * nova = new Lista();
	nova->prx = nova;
	nova->num = num;
	if (lista == NULL) return nova;
	Lista * aux = lista;
	while (aux->prx != lista) {
		aux = aux->prx;
	}
	nova->prx = lista;
	aux->prx = nova;
	return lista;
}

Lista * insere_inicio(Lista * lista, float num) {
	Lista * nova = new Lista();
	nova->prx = nova;
	nova->num = num;
	if (lista == NULL) return nova;

	nova->prx = lista;
	Lista * aux = lista;
	while (aux->prx != lista) {
		aux = aux->prx;
	}
	aux->prx = nova;
	return nova;
}

Lista * remover(Lista * lista, float num) {
	if (lista == NULL) return NULL;
	
	Lista * aux = lista;
	if (lista->num == num && lista->prx == lista) return NULL;
	
	if (lista->num == num) {
		while (aux->prx != lista) {
			aux = aux->prx;
		}
		aux->prx = lista->prx;
		lista = lista->prx;
		return lista;
	}
	
	while (aux->prx != lista) {
		if (aux->prx->num == num) {
			aux->prx = aux->prx->prx;
		}
		aux = aux->prx;
	}
	
	return lista;
}

void imprime_lista(Lista * lista) {
	if (lista == NULL) {
		printf("[] <- lista vazia\n");
		return;
	}
	Lista * aux = lista;
	printf("[");
	while (aux->prx != lista) {
		printf("%.3f ", aux->num);
		aux = aux->prx;
	}
	printf("%.3f]\n", aux->num);
}

void comparar_listas(Lista * lista, Lista * lista2) {
	Lista * aux = lista;
	Lista * aux2 = lista;
	while (aux != lista && aux2 != lista2) {
		if (aux->num != aux2->num) {
			printf("Listas sao diferentes!");
			return;
		}
		aux = aux->prx;
		aux2 = aux2->prx;
	}
	if (aux->prx == lista && aux2->prx == lista2) {
		printf("Listas sao diferentes!");
	}
}

int main() {
	Lista * lista = NULL;
	Lista * lista2 = NULL;
	lista2 = insere_fim(lista2, 10.0f);
	lista2 = insere_fim(lista2, 20.0f);
	lista2 = insere_fim(lista2, 30.0f);
	
	int op = -1;
	float num;
	
	while (op != 0) {
		system("cls");
		imprime_lista(lista2);
		imprime_lista(lista);
		printf("\nInserir no inicio da lista -> 1\n");
		printf("Inserir no fim da lista -> 2\n");
		printf("Remover da lista -> 3\n");
		
		printf("\nInforme a opcao: \n");
		
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				printf("Informe um numero a ser adicionado: ");
				scanf("%f", &num);
				lista = insere_inicio(lista, num);
				break;
			case 2:
				printf("Informe um numero a ser adicionado: ");
				scanf("%f", &num);
				lista = insere_fim(lista, num);
				break;
			case 3:
				printf("Informe um numero a ser removido: ");
				scanf("%f", &num);
				lista = remover(lista, num);
				break;
			default:
				return 0;
		}
	}
}
