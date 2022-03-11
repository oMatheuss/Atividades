#include <stdio.h>
#include <conio.h>
#include <iostream>

//Ex 01
struct LISTA {
	int num;
	LISTA *next;
};

//Ex 01
LISTA * insert_start (LISTA * list) {
	LISTA *newList = new LISTA ();
	printf ("Informe o numero a ser adicionado:");
	 scanf ("%d", &newList->num);

	if (list == NULL)
   	 newList->next = NULL;
	else
		newList->next = list;

	return newList;
}

//Ex 02
void printLISTA (LISTA * list) {
	printf ("[");
	if (list != NULL) {
		printf ("%d", list->num);
		list = list->next;
	}
	while (list != NULL)  {
	   printf (" %d", list->num);
	   list = list->next;
    }
    printf ("]\n");
}

//Ex 02
void find_number(LISTA * list) {
	int n;
	printf("informe o numero que deseja procurar: ");
	scanf("%d", &n);
	while (true) {
		if (list->num == n) {
			printf("o numero esta na lista");
			getch();
			return;
		}
		if (list->next == NULL) {
			printf("o numero nao esta na lista");
			getch();
			return;
		}
		list = list->next;
	}
}

int find_number_bool(LISTA * list, int n) {
	 if (list == NULL) return 0;
	 do {
		if (list->num == n) return 1;
		list = list->next;
	} while (list != NULL);
	return 0;
}

//Ex 02
LISTA * insert_end (LISTA * list) {
	LISTA * newList = new LISTA;
	LISTA * aux = list;
	printf ("Informe o numero a ser adicionado:");
	scanf ("%d", &newList->num);
	newList->next = NULL;
	if (list == NULL) return newList;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = newList;
	return list;
}

//Ex 02
LISTA * remove_num (LISTA * list) {
	if (list == NULL) {
		printf("lista vazia");
		return list;
	}
	int t;
	printf("Informe o numero que deseja remover: ");
	scanf("%d", &t);
	if (find_number_bool(list, t) == 0) {
		printf("o numero nao esta na lista");
		getch();
		return list;
	}
	if(list->num == t) return list->next;
	LISTA * aux = list;
	while (aux->next->num != t) aux = aux->next;
	aux->next = aux->next->next;
	return list;
}

//Ex 03
void size(LISTA * list) {
	int count = 0;
	if (list == NULL) {
		printf("A lista esta vazia!");
		getch();
		return;
	}
	while (true) {
		if (list != NULL)
			count++;
		if (list->next == NULL) break;
		list = list->next;
	}
	printf("A lista tem %d elementos!", count);
	getch();
}

int length(LISTA * list) {
	int count = 0;
	if (list == NULL) {
		return 0;
	}
	while (true) {
		if (list != NULL)
			count++;
		if (list->next == NULL) break;
		list = list->next;
	}
	return count;
}

//Ex 04
LISTA * replace(LISTA * list) {
	LISTA * aux = list;
	if (list == NULL) {
		printf("lista vazia");
		return list;
	}
	int num;
	printf("Informe o numero que deseja substituir: ");
	scanf("%d", &num);
	while (aux != NULL) {
		if (aux->num == num) {
			printf("Informe o novo numero: ");
			int newNum;
			scanf("%d", &newNum);
			aux->num = newNum;
			return list;
		}
		aux = aux->next;
	}
	printf("o numero nao esta na lista");
	getch();
	return list;
}
//Ex 05
LISTA * fromVector(int* vec, int len) {
	LISTA * list = new LISTA();
	LISTA * aux = list;
	int i;
	for (i = 0; i < len; i++) {
		aux->num = vec[i];
		aux->next = new LISTA();
		aux  = aux->next;
	}
	aux = NULL;
	return list;
}

//Ex 06
int* toVector(LISTA * list) {
	int size = length(list), i;
	int* vec = new int[size];
	for(i = 0; i < size; i++) {
		vec[i] = list->num;
		list = list->next;
	}
	return vec;
}

void printVector(int* vec, int len) {
	printf("[");
	int i;
	for (i = 0; i < len-1; i++) {
		printf("%d, ", vec[i]);
	}
	printf("%d]", vec[++i]);
	getch();
}

//Ex 07
void compare(LISTA * list, LISTA * list2) {
	while(true) {
		if (list == NULL && list2 == NULL) {
			printf("As listas sao iguais!");
			getch();
			return;
		}
		if ((list == NULL || list2 == NULL) && !(list == NULL && list2 == NULL)) {
			printf("As listas sao diferentes!");
			getch();
			return;
		}
		if (list->num != list2->num) {
			printf("As listas sao diferentes!");
			getch();
			return;
		}
		list = list->next;
		list2 = list2->next;
	}
}

LISTA * copia(LISTA * list) {
	if(list == NULL) return NULL;
	
	LISTA * newList = new LISTA();
	LISTA * aux = newList;
	
	while(list->next != NULL) {
		aux->num = list->num;
		aux->next = new LISTA();
		aux = aux->next;
		list = list->next;
	}
	aux->num = list->num;
	aux->next = NULL;
	return newList;
}

//Ex 08
LISTA * separa(LISTA * list, int n) {
	if (list == NULL) return NULL;
	while(list->num != n) {
		list = list->next;
		if (list == NULL) return NULL;
	}
	
	return copia(list);
}

//Ex 09
LISTA * concatena(LISTA * list, LISTA * list2) {
	LISTA * aux = list;
	while(aux->next != NULL) {
		aux = aux->next;
	}
	aux->next = list2;
	return list;
}

//Ex 10
LISTA * remove_prefixo(LISTA * list, int n) {
	if (n > length(list)) return NULL;
	int i;
	for (i = 0; i < n; i++) list = list->next;
	return copia(list);
}

int main () {
	LISTA * list = NULL;
	LISTA * list2 = NULL;
	
	int op = 0;
	while (op != 99) {
		printf("Matheus Silva Moura - 5152442\n");
		printLISTA(list);
		printLISTA(list2);
		printf("selecione uma opcao\n");
		printf("1 -> add no comeco da lista 1\n");
		printf("2 -> add no final da lista 1\n");
		printf("3 -> excluir da lista 1\n");
		printf("4 -> buscar na lista 1\n");
		printf("5 -> tamanho da lista 1\n");
		
		printf("\n");
		
		printf("6 -> add no comeco da lista 2\n");
		printf("7 -> add no final da lista 2\n");
		printf("8 -> excluir da lista 2\n");
		printf("9 -> buscar na lista 2\n");
		printf("10 -> tamanho da lista 2\n");
		
		printf("\n");
		
		printf("11 -> comparar listas\n");
		printf("12 -> concatena lista 2 na 1\n");
		printf("13 -> separar lista da lista 1 nas 2\n");
		printf("14 -> remover numero prefixo da lista 1\n");
		printf("15 -> lista 1 para vetor\n");
		printf("16 -> de vetor para a lista 1\n");
		
		
		int i, n, tam;
		int* vec;
		
		scanf("%d", &op);
		switch (op) {
			case 1:
				list = insert_start(list);
				break;
			case 2:
				list = insert_end(list);
				break;
			case 3:
				list = remove_num(list);
				break;
			case 4:
				find_number(list);
				break;
			case 5:
				size(list);
				break;
			case 6:
				list2 = insert_start(list2);
				break;
			case 7:
				list2 = insert_end(list2);
				break;
			case 8:
				list2 = remove_num(list2);
				break;
			case 9:
				find_number(list2);
				break;
			case 10:
				size(list2);
				break;
			case 11:
				compare(list, list2);
				break;
			case 12:
				list = concatena(list, list2);
				list2 = NULL;
				break;
			case 13:
				printf("Informe a onde deseja separar:");
				scanf("%d", &n);
				list2 = separa(list, n);
				break;
			case 14:
				printf("Informe o numero de numeros que deseja remover: ");
				int n;
				scanf("%d", &n);
				list = remove_prefixo(list, n);
				break;
			case 15:
				vec = toVector(list);
				printVector(vec, length(list));
				break;
			case 16:
				printf("informe a quantidade de elemntos para o vetor 1: ");
				scanf("%d", &tam);
				if (tam <= 0) break;
				vec = new int[tam];
				printf("Informe os elementos: ");
				for (i = 0; i < tam; i++) { scanf("%d", &vec[i]); }
				
				// do vetor para lista:
				list = fromVector(vec, tam);
				break;
			default:
				break;
		}
		system("cls");
		//fim while
	}
	return 0;
}
