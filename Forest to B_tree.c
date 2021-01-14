#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex
{
    char label;
};

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

struct Vertex* lstVertices[MAX];

int adjMatrix[MAX][MAX],adjMatrix2[MAX][MAX];

int vertexCount = 0;

void addVertex(char label)
{
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start,int end)
{
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void binary()
{
    int i,j,f=0,p;

    for(i = 0; i<MAX; i++)
    {
        f=0;
        for(j = 0; j<MAX; j++)
        {
            if(adjMatrix[i][j] == 1)
            {
                adjMatrix[j][i] = 0;
                if(f==0)
                {
                    f+=1;
                    adjMatrix2[i][j] = 1;
                    adjMatrix2[j][i] = 1;
                    p=j;
                }
                else
                {
                    adjMatrix2[p][j] = 1;
                    adjMatrix2[j][p] = 1;
                    p=j;
                }
            }

        }
    }
    printf("Forest : \n\n");

    char X='A';
    for(i = 0; i<MAX; i++)
    {
        printf("\t%c",X++);
    }
    printf("\n\n");
    X='A';
    for(i = 0; i<MAX; i++)
    {
        printf("%c\t",X++);
        for(j = 0; j<MAX; j++)
        {
            printf("%d\t",adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    printf("Binary tree : \n\n");
    X='A';
    for(i = 0; i<MAX; i++)
    {
        printf("\t%c",X++);
    }
    printf("\n\n");
    X='A';
    for(i = 0; i<MAX; i++)
    {
        printf("%c\t",X++);
        for(j = 0; j<MAX; j++)
        {
            printf("%d\t",adjMatrix2[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i, j;

    for(i = 0; i<MAX; i++)
    {
        for(j = 0; j<MAX; j++)
            adjMatrix[i][j] = 0;
    }

    addVertex('A');
    addVertex('B');
    addVertex('C');
    addVertex('D');
    addVertex('E');

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    binary();
}
