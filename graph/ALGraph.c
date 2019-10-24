#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10

/*
Filename: ALGraph (Adjacency List Graph)
Author: erqitao
Date: 2019-10-24
*/

typedef struct edgeNode {
	int adjvex;
	struct edgeNode *nextarc;
}edgeNode;

typedef struct vertexNode {
	char vertex;
	edgeNode *firstarc;
}vertexNode;

typedef struct ALGraph {
	vertexNode vertexList[MAX_SIZE];
	int numOfVertex, numOfEdge;
}ALGraph;

typedef struct seqQueue {
	int data[MAX_SIZE];
	int front, rear;
}seqQueue;

ALGraph *initGraph() {
	ALGraph * g = malloc(sizeof(ALGraph)); 
	g->numOfVertex = g->numOfEdge = 0;
	return g;
}

seqQueue *initQueue() {
	seqQueue *q = malloc(sizeof(seqQueue));
	q->front = q->rear = 0;
	return q;
}

int getIndex(ALGraph *g, int vertex) {
	int i;
	for(i = 0; i < g->numOfVertex; i++) {
		if(g->vertexList[i].vertex == vertex) {
			return i;
		}
	}
	return -1;
}

char getValue(ALGraph *g, int i) {
	return g->vertexList[i].vertex;
}

void createGraph(ALGraph *g, char vertices[], int numOfVertex, char edges[][2], int numOfEdge) {
	g->numOfVertex = numOfVertex;
	g->numOfEdge = numOfEdge;

	int i, j, k;
	for (i = 0; i < numOfVertex; i++) {
		g->vertexList[i].vertex = vertices[i];
		g->vertexList[i].firstarc = NULL;
	}

	for (k = 0; k < numOfEdge; k++) {
		i = getIndex(g, edges[k][0]);
		j = getIndex(g, edges[k][1]);

		edgeNode *newNode = malloc(sizeof(edgeNode));
		newNode->adjvex = j;
		newNode->nextarc = NULL;


		/*
		// head insertion
		newNode->nextarc = g->vertexList[i].firstarc;
		g->vertexList[i].firstarc = newNode;
		*/

		// tail insertion

		if (g->vertexList[i].firstarc == NULL) {
			g->vertexList[i].firstarc = newNode;
		} else {
			edgeNode *p = g->vertexList[i].firstarc;
			while(p->nextarc != NULL) {
				p = p->nextarc;
			}
			p->nextarc = newNode;
		}
	}
}

int firstNeighbor(ALGraph *g, int v) {
	if (g == NULL)
		return -1;
	edgeNode *p = g->vertexList[v].firstarc;
	if (p != NULL)
		return p->adjvex;
	return -1;
}

int nextNeighbor(ALGraph *g, int v, int w) {
	if (g == NULL)
		return -1;
	edgeNode *p = g->vertexList[v].firstarc;

	while (p != NULL && p->adjvex != w)
		p = p->nextarc;
	if (p != NULL && p->nextarc != NULL)
		return p->nextarc->adjvex;
	return -1;
}

void printGraph(ALGraph *g) {
	int i, j;
	printf("Number of Vertex = %d\n", g->numOfVertex);
	printf("Number of Edge = %d\n", g->numOfEdge);
	printf("Vertices:\n");
	for(i = 0; i < g->numOfVertex; i++) {
		printf("%c\t", g->vertexList[i].vertex);
	}
	putchar('\n');

	printf("Edges:\n");
	for(i = 0; i < g->numOfVertex; i++) {
		printf("%c:\t", g->vertexList[i].vertex);

		edgeNode *p = g->vertexList[i].firstarc;
		while(p) {
			printf("(%c, %c)\t", g->vertexList[i].vertex, getValue(g, p->adjvex));
			p = p->nextarc;
		}
		putchar('\n');
	}
}

void DFS(ALGraph *g, int v, bool visited[]) {
	visited[v] = true;
	printf("%c\t", getValue(g, v));

	int w;
	for(w = firstNeighbor(g, v); w >= 0; w = nextNeighbor(g, v, w)) {
		if (!visited[w]) {
			DFS(g, w, visited);
		}
	}
}

void BFS(ALGraph *g, int v, bool visited[]) {
	visited[v] = true;
	printf("%c\t", getValue(g, v));

	seqQueue *q = initQueue();
	int top, w;

	q->data[q->rear++] = v;
	while(q->front != q->rear) { // while the queue is not empty
		top = q->data[q->front++]; // deQueue
		for (w = firstNeighbor(g, top); w >= 0; w = nextNeighbor(g, top, w)) {
			if (!visited[w]) {
				visited[w] = true;
				printf("%c\t", getValue(g, w));
				q->data[q->rear++] = w; // enQueue
			}
		}
	}
	putchar('\n');
}

void resetFlagArray(bool visited[], int n) {
	int i;
	for (i = 0; i < n; i++)
		visited[i] = false;
}

int main() {
	/* test data 1 */
	char vertexes[] = {'A', 'B', 'C', 'D', 'E'};
	int numOfVertex = 5;
	char edges[][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'E'}, {'C', 'B'}, {'D', 'C'}, {'E', 'A'}, {'E', 'D'}};
	int numOfEdge = 7;
	
	/* test data 2
	char vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int numOfVertex = 7;
	char edges[][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'C', 'G'}};
	int numOfEdge = 6;
	*/

	ALGraph *g = initGraph();
	createGraph(g, vertexes, numOfVertex, edges, numOfEdge);
	printGraph(g);

	bool visited[MAX_SIZE];
	resetFlagArray(visited, MAX_SIZE);

	printf("DFS...\n");
	DFS(g, 0, visited);
	putchar('\n');

	resetFlagArray(visited, MAX_SIZE);
	printf("BFS...\n");
	BFS(g, 0, visited);

	return 0;
}
