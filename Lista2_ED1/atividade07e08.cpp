#include <stdio.h>
#include <windows.h>
#include <conio.h>

/*
Escreva um programa que implemente uma lista circular que armazena numeros
reais. Implemente as operacoes de inserir no inicio, inserir no fim, remover e
consulta (impressao) dos valores da lista.
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

/*
8 - Escreva uma função que verifique se duas listas circulares são iguais, ou melhor,
se têm o mesmo conteúdo.
*/
void comparar_listas(Lista * lista, Lista * lista2) {
	Lista * aux = lista;
	Lista * aux2 = lista2;

	if (lista == NULL || lista2 == NULL) {
		printf("1Listas diferentes!\n");
		return;
	} else {
		do {
			if ((!(aux == lista) && aux2 == lista2) || (aux == lista && !(aux2 == lista2))) {
				printf("Listas diferentes!\n");
				return;
			}
			if (aux->num != aux2->num) {
				printf("Listas diferentes!\n");
				return;
			}
			aux = aux->prx;
			aux2 = aux2->prx;
		} while (aux != lista && aux2 != lista2);
	}
	if ((!(aux == lista) && aux2 == lista2) || (aux == lista && !(aux2 == lista2))) {
		printf("Listas diferentes!\n");
	} else {
		printf("Listas iguais!\n");
	}
}

int main() {
	Lista * lista = NULL;

	//Lista usada para teste de comparação
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
		printf("Comparar listas -> 4\n");
		
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
			case 4:
				comparar_listas(lista, lista2);
				getch();
				break;
			default:
				return 0;
		}
	}
}
