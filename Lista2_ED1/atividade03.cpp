#include <stdio.h>

/*
Faça um programa que cadastre 5 alunos. Para cada aluno devem ser
cadastrados nome e nota final. Os dados devem ser armazenados em uma lista
duplamente encadeada. Em seguida, o programa deve mostrar apenas o nome
dos alunos aprovados, ou seja, alunos com nota final de no mínimo 7. Se nenhum
aluno estiver aprovado, mostrar mensagem.
*/

struct String {
    char c;
    String * prx;
};

String* newString(const char* chars) {
    if (chars == NULL) {
        return NULL;
    }
    String * stringFinal = new String();
    String * aux = stringFinal;
    int count = 0;
    aux->c = chars[count++];
    while (chars[count] != '\0') {
        String * node = new String();
        node->c = chars[count++];
        aux->prx = node;
        aux = node;
    }
    aux->prx = NULL;
    return stringFinal;
}

void printS(String * string) {
    String * aux = string;
    do {
        printf("%c", aux->c);
		aux = aux->prx;
	} while (aux != NULL);
}

struct Aluno {
	Aluno* prx;
    Aluno* ant;
    String* nome;
    float notaFinal;
};

Aluno * insere_aluno(Aluno * alunos, String* nome, float notaFinal) {
    Aluno * aluno = new Aluno();
    aluno->prx = NULL;
    aluno->ant = NULL;
    aluno->nome = nome;
    aluno->notaFinal = notaFinal;

    if (alunos == NULL) {
        return aluno;
    }

    aluno->prx = alunos;
    alunos->ant = aluno;

    return aluno;
}

void print_alunos(Aluno * alunos, float notaMin) {
    if (alunos == NULL) {
		printf("[] <- lista vazia\n");
		return;
	}
	Aluno * aux = alunos;
    int count = 0;
	do {
        if (aux->notaFinal >= notaMin) {
            printf("Nome: ");
            printS(aux->nome);
            printf(", Nota Final: %.2f\n", aux->notaFinal);
            count++;
        }
		aux = aux->prx;
	} while (aux != NULL);
    if (count == 0) {
        printf("Nenhum aluno passou!\n");
    }
}

int main() {
    Aluno * alunos = NULL;

    alunos = insere_aluno(alunos, newString("Matheus Silva Moura"), 8.5f);
    alunos = insere_aluno(alunos, newString("Lucas"), 5.4f);
    alunos = insere_aluno(alunos, newString("Samuel"), 6.8f);
    alunos = insere_aluno(alunos, newString("Joao"), 9.5f);
    alunos = insere_aluno(alunos, newString("Pedro"), 10.0f);

    print_alunos(alunos, 7.0f);
    return 0;
}