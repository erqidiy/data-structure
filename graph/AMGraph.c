#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 16 // max number of vertex

/*
Filename: AMGraph.c (Adjacency Matrix Graph)
Author: erqitao
Date: 2019-09-20
*/

typedef struct adjGraph {
	int edges[N][N];
	char vertexes[N];
	int numOfVertex, numOfEdge;
}adjGraph, *graph;

typedef struct seqQueue {
	int data[N];
	int front, rear;
}seqQueue, *queue;

queue initQueue() {
	queue q = malloc(sizeof(seqQueue));
	q->front = q->rear = 0;
	return q;
}

graph initGraph() {
	graph g = (adjGraph *)malloc(sizeof(adjGraph));
	g->numOfVertex = g->numOfEdge = 0;
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			g->edges[i][j] = 0;
	return g;
}

int getIndex(graph g, char c) {
	int i;
	for(i = 0; i < g->numOfVertex; i++)
		if(g->vertexes[i] == c)
			return i;
	return -1;
}

char getValue(graph g, int i) {
	return g->vertexes[i];	
}

void create(graph g, char vertexes[], int numOfVertex, char edges[][2], int numOfEdge) {
	g->numOfVertex = numOfVertex;
	g->numOfEdge = numOfEdge;
	int i, j, k;

	for(i = 0; i < numOfVertex; i++)
		g->vertexes[i] = vertexes[i];
	
	for(k = 0; k < numOfEdge; k++) {
		i = getIndex(g, edges[k][0]);
		j = getIndex(g, edges[k][1]);
		g->edges[i][j] = 1;
	}
}

int firstNeighbor(graph g, int vertex) {
	int i;
	for(i = 0; i < g->numOfVertex; i++)
		if(g->edges[vertex][i] == 1)
			return i;
	return -1;
}

int nextNeighbor(graph g, int vertex, int v) {
	int i;
	for(i = v + 1; i < g->numOfVertex; i++)
		if(g->edges[vertex][i] == 1)
			return i;
	return -1;
}

void DFS(graph g, int vertex, bool visited[]) {
	visited[vertex] = true;
	printf("%c\t", getValue(g, vertex));

	int i;
	for(i = firstNeighbor(g, vertex); i >= 0; i = nextNeighbor(g, vertex, i)) {
		if(!visited[i])
			DFS(g, i, visited);
	}
}

void BFS(graph g, int vertex, bool visited[]) {
	queue q = initQueue();
	int i, top;
	visited[vertex] = true;
	printf("%c\t", getValue(g, vertex));
	
	q->data[q->rear++] = vertex;
	while(q->front != q->rear) {
		top = q->data[q->front++];
		for(i = firstNeighbor(g, top); i >= 0; i = nextNeighbor(g, top, i)) {
			if(!visited[i]) {
				printf("%c\t", getValue(g, i));
				visited[i] = true;
				q->data[q->rear++] = i;
			}
		}
	}
}

void initAry(bool visited[], int n) {
	int i;
	for(i = 0; i < n; i++)
		visited[i] = false;
}

void display(graph g) {
	int i, j;
	printf("Vertexes: \n");
	for(i = 0; i < g->numOfVertex; i++)
		printf("%c\t", g->vertexes[i]);

	printf("\nEdges: \n");
	for(i = 0; i < g->numOfVertex; i++) {
		for(j = 0; j < g->numOfVertex; j++)
			printf("%d\t", g->edges[i][j]);
		putchar('\n');
	}
}

int main() {
	graph g = initGraph();
	/*
	char vertexes[] = {'A', 'B', 'C', 'D', 'E'};
	int numOfVertex = 5;
	char edges[][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'E'}, {'C', 'B'}, {'D', 'C'}, {'E', 'A'}, {'E', 'D'}};
	int numOfEdge = 7;
	*/

	char vertexes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	int numOfVertex = 7;
	char edges[][2] = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'C', 'G'}};
	int numOfEdge = 6;

	create(g, vertexes, numOfVertex, edges,numOfEdge);
	display(g);

	bool visited[N];
	initAry(visited, N);
	int i, j;

	printf("\nDFS...\n");
	DFS(g, 0, visited);

	initAry(visited, N);

	printf("\nBFS...\n");
	BFS(g, 0, visited);

	return 0;
}
