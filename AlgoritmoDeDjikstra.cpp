#include <iostream>

#define tam 26

void Dijkstra(int grafo[tam][tam], int origem, int destino) {
    int distancias[tam], caminho[tam], vertices[tam];
    bool aux = false;
    for (int i = 0; i < tam; i++) {
		distancias[i] = INT_MAX;
        caminho[i] = -1;
        vertices[i] = i;
	}
	distancias[origem] = 0;
    aux = false;
    for (int i = 0; i < tam; i++) {
        if (vertices[i] != -1) aux = true;
        if (aux) break;
    }
    while (aux) {
        int posicao;
        for (int i = 0, min = INT_MAX; i < tam; i++) {
            if (vertices[i] == i && distancias[i] < min) {
                min = distancias[i];
                posicao = i;
            }
        }
        vertices[posicao] = -1;
        for (int i = 0; i < tam; i++) {
            if (grafo[posicao][i]) {
                int dist = distancias[posicao] + grafo[posicao][i];
                if (dist < distancias[i]) {
                    distancias[i] = dist;
                    caminho[i] = posicao;
                }
            }
        }
        aux = false;
        for (int i = 0; i < tam; i++) {
            if (vertices[i] != -1) aux = true;
            if (aux) break;
        }
    }
    printf("\n\nCaminho para %d:\n%d", destino, destino);
    while (caminho[destino] != -1) {
        printf(" <- %d", caminho[destino]+1);
        destino = caminho[destino];
    }
}

int main() {
    int origem, destino;
    int grafo[tam][tam];
	std::cin >> origem >> destino;
	Dijkstra(grafo, origem, destino);
}
