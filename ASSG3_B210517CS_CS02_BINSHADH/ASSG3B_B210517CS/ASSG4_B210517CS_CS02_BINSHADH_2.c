#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
int num_vertices;
typedef struct Graph_t
{
	int V;
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

Graph *Graph_create(int V)
{
	Graph *g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			g->adj[i][j] = false;
		}
	}

	return g;
}
void Graph_destroy(Graph *g) { free(g); }

void Graph_addEdge(Graph *g, int v, int w)
{
	g->adj[v][w] = true;
}
void Graph_BFS(Graph *g, int s)
{
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->V; i++)
	{
		visited[i] = false;
	}
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear)
	{
		s = queue[front++];
		printf("%d ", s);
		for (int adjacent = 0; adjacent < g->V; adjacent++)
		{
			if (g->adj[s][adjacent] && !visited[adjacent])
			{
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d\n", &n);
	Graph *g = Graph_create(n);
	num_vertices=n;
	for (int i = 0; i < n; i++)
	{
		char *s = (char *)malloc(100 * sizeof(char));
		fgets(s, 100, stdin);
		int j = 0, key, mul = 1;
		for (j = 2; s[j] != '\0'; j++)
		{
			if (s[j] <= '9' && s[j] >= '0')
			{
				key = key + (s[j] - '0');
				mul = mul * 10;
			}
			if (s[j] == ' ')
			{
				Graph_addEdge(g, i, key);
				key = 0;
			}
		}
	}
	Graph_BFS(g, 0);
	Graph_destroy(g);

	return 0;
}