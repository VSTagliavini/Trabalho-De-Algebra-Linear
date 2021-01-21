#include <iostream>

#define tam 26

void Dijkstra(int grafo[tam][tam], int origem, int destino) {
	/*distancias armazena a menor distancia da origem ao v�rtice i
     *caminho armazena o v�rtice anterior ao v�rtice i
     *vertices armazena os v�rtice que ainda n�o foram checados pelo programa
     *aux dita se vertices est� "vazio", se todos os v�rtices j� foram checados*/
    
    int distancias[tam], caminho[tam], vertices[tam];
    bool aux = false;
	
    /*Isto inicializa os vetores de acordo com suas necessidades
     *distancias � inicializado com INT_MAX, o maior valor que um int armazena
     *caminho � inicializado com -1, o que significa que ainda n�o foi definido um v�rtice anterior
     *vertices � inicializado com a numera��o de cada vetor, poderia ser qualquer diferente de -1*/
    for (int i = 0; i < tam; i++) {
		distancias[i] = INT_MAX;
        caminho[i] = -1;
        vertices[i] = i;
	}
    //Troca-se a dist�ncia do v�rtice de origem por 0 porque qualquer outro valor n�o faria sentido
	distancias[origem] = 0;
    
    /*Este trecho assume aux como falso, se qualquer valor de vertices for diferente de -1 aux se tornar� true
     *Eu preferi fazer assim ao inv�s de s� colocar um monte de || no while porque assim
     *ele checar� cada v�rtice sem a necessidade de mudar o c�digo toda vez*/

    aux = false;
    for (int i = 0; i < tam; i++) {
        if (vertices[i] != -1) aux = true;
        if (aux) break;
    }

    while (aux) {
        //posicao � o �ndice do v�rtice inexplorado de menor dist�ncia da origem
        int posicao;
        //Esta fun��o encontra o valor de posicao
        for (int i = 0, min = INT_MAX; i < tam; i++) {
            if (vertices[i] == i && distancias[i] < min) {
                min = distancias[i];
                posicao = i;
            }
        }
        //Define-se vertices[posicao] como -1 para evitar que o trecho acima o escolha uma segunda vez
        vertices[posicao] = -1;

        /*Este trecho checa todos os v�rtices adjacentes ao v�rtice posicao
         *e checa se chegar a este v�rtice � mais "barato" pelo v�rtice
         *posicao se for, atualiza-se com o peso por posicao e define-se
         *o caminho desse v�rtice como posicao*/
        for (int i = 0; i < tam; i++) {
            if (grafo[posicao][i]) {
                int dist = distancias[posicao] + grafo[posicao][i];
                if (dist < distancias[i]) {
                    distancias[i] = dist;
                    caminho[i] = posicao;
                }
            }
        }

        //Este trecho � id�ntico ao da linha 27, checa se vertices tem todos os seus valores como -1
        aux = false;
        for (int i = 0; i < tam; i++) {
            if (vertices[i] != -1) aux = true;
            if (aux) break;
        }
        }
    /*Isto � s� para printar a dist�ncia de cada v�rtice em rela��o � origem
     *e o caminho deste v�rtice � origem
     *T�, h� n formas de armazenar o caminho para chegar a um v�rtice mas achei que esta seria a mais f�cil*/
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