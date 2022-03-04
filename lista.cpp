#include <stdio.h>
#include <conio.h>
#include <iostream>

struct LISTA {
	int num;
	LISTA *next;
};

LISTA *
insert_start (LISTA * list) {
	LISTA *newList = new LISTA ();
	printf ("Informe o numero a ser adicionado:");
	 scanf ("%d", &newList->num);

	if (list == NULL)
   	 newList->next = NULL;
	else
		newList->next = list;

	return newList;
}

void
printLISTA (LISTA * list) {
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
	while (true) {
		if (list->num == n) return 1;
		if (list->next == NULL) return 0;
		list = list->next;
	}
}

LISTA * insert_end_rec (LISTA * list, LISTA * to_add) {
	if (list->next == NULL)
		list->next = to_add;
	else
		list->next = insert_end_rec(list->next, to_add);
	
	return list;
}

LISTA *
insert_end (LISTA * list) {
	LISTA * newList = new LISTA();
	printf ("Informe o numero a ser adicionado:");
	scanf ("%d", &newList->num);
	newList->next = NULL;
	if (list == NULL)
		return newList;
	return insert_end_rec(list, newList);
}

LISTA * remove_num_rec(LISTA * list, int num) {
	if (list == NULL) {
		return list;
	} else if (list->num == num) {
		return list->next;
	}
	list->next = remove_num_rec(list->next, num);
	return list;
}

LISTA * remove_num (LISTA * list) {
	int t;
	if (list == NULL) {
		printf("lista vazia");
		return list;
	}
	printf("Informe o numero que deseja remover: ");
	scanf("%d", &t);
	if (find_number_bool(list, t) == 0) {
		printf("o numero nao esta na lista");
		return list;
	}
	return remove_num_rec(list, t);
}

void compare(LISTA * list, LISTA * list2) {
	while(true) {
		if (list == NULL && list2 == NULL) {
			printf("As listas sao iguais!");
			getch();
			return;
		}
		if (list == NULL || list2 == NULL && !(list == NULL && list2 == NULL)) {
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

int lenght(LISTA * list) {
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

int* toVector(LISTA * list) {
	int size = lenght(list), i = 0;
	int vec[size];
	for(i; i < size; i++) {
		vec[i] = list->num;
		list = list->next;
	}
	return vec;
}

void printVector() {
	
}

int main () {
	LISTA * list = NULL;
	LISTA * list2 = NULL;
	
	int op = 0;
	while (op != 99) {
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
		
		printf("\n Listas para vetor: ");
		int* vet = toVector(list);
		int* vet2 = toVector(list2);
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
			default:
				break;
		}
		system("cls");
	}
	return 0;
}

