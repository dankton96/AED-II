#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>
 int i,j;

void lemapa(MAPA* m) {
	FILE* f;
	f = fopen("mapa.txt", "r");
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
	alocamapa(m);

	for(i = 0; i < m->linhas; i++) {
		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);
}

void alocamapa(MAPA* m) {
	m->matriz =(char*)malloc(sizeof(char)* m->linhas);

	for(i = 0; i < m->linhas; i++) {
		m->matriz[i] = (char*)malloc(sizeof(char) * m->colunas + 1);
	}
}

void copiamapa(MAPA* destino, MAPA* origem) {
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;
	alocamapa(destino);
	for(i = 0; i < origem->linhas; i++) {
		strcpy(destino->matriz[i], origem->matriz[i]);
	}
}


void liberamapa(MAPA* m) {
	for(i = 0; i < m->linhas; i++) {
		free(m->matriz[i]);
	}

	free(m->matriz);
}


int encontramapa(MAPA* m, POSICAO* p, char c) {

	for(i = 0; i < m->linhas; i++) {
		for(j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}

	return 0;
}

int podeandar(MAPA* m, char personagem, int x, int y) {
	return
		ehvalida(m, x, y) &&
		!ehparede(m, x, y) &&
		!ehpersonagem(m, personagem, x, y);
}

int ehvalida(MAPA* m, int x, int y) {
	if(x >= m->linhas)
		return 0;
	if(y >= m->colunas)
		return 0;

	return 1;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y) {
	return
		m->matriz[x][y] == personagem;
}

int ehparede(MAPA* m, int x, int y) {
	return
		m->matriz[x][y] == PAREDE_VERTICAL ||
		m->matriz[x][y] == PAREDE_HORIZONTAL;
}


void andanomapa(MAPA* m, int xorigem, int yorigem,
	int xdestino, int ydestino) {

	char personagem = m->matriz[xorigem][yorigem];
	m->matriz[xdestino][ydestino] = personagem;
	m->matriz[xorigem][yorigem] = VAZIO;

}
