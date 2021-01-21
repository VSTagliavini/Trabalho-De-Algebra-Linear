#include <iostream>

#define tam 26

void Dijkstra(int grafo[tam][tam], int origem, int destino) {
	/*distancias armazena a menor distancia da origem ao vértice i
     *caminho armazena o vértice anterior ao vértice i
     *vertices armazena os vértice que ainda não foram checados pelo programa
     *aux dita se vertices está "vazio", se todos os vértices já foram checados*/
    
    int distancias[tam], caminho[tam], vertices[tam];
    bool aux = false;
	
    /*Isto inicializa os vetores de acordo com suas necessidades
     *distancias é inicializado com INT_MAX, o maior valor que um int armazena
     *caminho é inicializado com -1, o que significa que ainda não foi definido um vértice anterior
     *vertices é inicializado com a numeração de cada vetor, poderia ser qualquer diferente de -1*/
    for (int i = 0; i < tam; i++) {
		distancias[i] = INT_MAX;
        caminho[i] = -1;
        vertices[i] = i;
	}
    //Troca-se a distância do vértice de origem por 0 porque qualquer outro valor não faria sentido
	distancias[origem] = 0;
    
    /*Este trecho assume aux como falso, se qualquer valor de vertices for diferente de -1 aux se tornará true
     *Eu preferi fazer assim ao invés de só colocar um monte de || no while porque assim
     *ele checará cada vértice sem a necessidade de mudar o código toda vez*/

    aux = false;
    for (int i = 0; i < tam; i++) {
        if (vertices[i] != -1) aux = true;
        if (aux) break;
    }

    while (aux) {
        //posicao é o índice do vértice inexplorado de menor distância da origem
        int posicao;
        //Esta função encontra o valor de posicao
        for (int i = 0, min = INT_MAX; i < tam; i++) {
            if (vertices[i] == i && distancias[i] < min) {
                min = distancias[i];
                posicao = i;
            }
        }
        //Define-se vertices[posicao] como -1 para evitar que o trecho acima o escolha uma segunda vez
        vertices[posicao] = -1;

        /*Este trecho checa todos os vértices adjacentes ao vértice posicao
         *e checa se chegar a este vértice é mais "barato" pelo vértice
         *posicao se for, atualiza-se com o peso por posicao e define-se
         *o caminho desse vértice como posicao*/
        for (int i = 0; i < tam; i++) {
            if (grafo[posicao][i]) {
                int dist = distancias[posicao] + grafo[posicao][i];
                if (dist < distancias[i]) {
                    distancias[i] = dist;
                    caminho[i] = posicao;
                }
            }
        }

        //Este trecho é idêntico ao da linha 27, checa se vertices tem todos os seus valores como -1
        aux = false;
        for (int i = 0; i < tam; i++) {
            if (vertices[i] != -1) aux = true;
            if (aux) break;
        }
        }
    /*Isto é só para printar a distância de cada vértice em relação à origem
     *e o caminho deste vértice à origem
     *Tá, há n formas de armazenar o caminho para chegar a um vértice mas achei que esta seria a mais fácil*/
    for (int i = 0; i < tam; i++) {
        std::cout << "Distancia: " << distancias[i] << "   " << i << "->" << caminho[i]  <<"\n";
    }
    printf("\n\nCaminho para %d:\n%d", destino, destino);
    while (caminho[destino] != -1) {
        printf(" <- %d", caminho[destino]);
        destino = caminho[destino];
    }
}

int main() {
    int grafo[tam][tam] = { {0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {2,  0,  3,  0,  0,  0,  0,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  8,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  5,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 11},
                            {0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  8,  0,  0,  1,  0,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  4,  4,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  9,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0, 11,  0,  0,  9,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 11,  0,  2,  5,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  5,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  0},
                            {0,  0,  0,  0,  0,  0,  0, 11,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}};
	Dijkstra(grafo, 0, 23);
}