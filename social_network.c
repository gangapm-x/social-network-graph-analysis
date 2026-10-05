#include <stdio.h>
#include <stdlib.h>

#define V 6

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

/* Adjacency Matrix */
int matrix[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

/* Structure for Adjacency List */
struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[V];

/* Create a new node */
struct Node* createNode(int vertex) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = vertex;
    newNode->next = NULL;

    return newNode;
}

/* Add an undirected edge */
void addEdge(int u, int v) {

    struct Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

/* Display Adjacency Matrix */
void displayMatrix() {

    printf("\n===== ADJACENCY MATRIX =====\n\n");

    printf("   ");
    for (int i = 0; i < V; i++)
        printf("%c ", vertices[i]);

    printf("\n");

    for (int i = 0; i < V; i++) {

        printf("%c  ", vertices[i]);

        for (int j = 0; j < V; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

/* Display Adjacency List */
void displayList() {

    printf("\n===== ADJACENCY LIST =====\n\n");

    for (int i = 0; i < V; i++) {

        printf("%c -> ", vertices[i]);

        struct Node *temp = adjList[i];

        while (temp != NULL) {
            printf("%c -> ", vertices[temp->vertex]);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

/* BFS */
void BFS(int start) {

    int visited[V] = {0};
    int queue[V];

    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\n===== BFS TRAVERSAL =====\n");
    printf("Starting from A: ");

    while (front < rear) {

        int current = queue[front++];

        printf("%c ", vertices[current]);

        for (int i = 0; i < V; i++) {

            if (matrix[current][i] == 1 &&
                visited[i] == 0) {

                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

/* DFS */
void DFSUtil(int vertex, int visited[]) {

    visited[vertex] = 1;

    printf("%c ", vertices[vertex]);

    for (int i = 0; i < V; i++) {

        if (matrix[vertex][i] == 1 &&
            visited[i] == 0) {

            DFSUtil(i, visited);
        }
    }
}

void DFS(int start) {

    int visited[V] = {0};

    printf("\n===== DFS TRAVERSAL =====\n");
    printf("Starting from A: ");

    DFSUtil(start, visited);

    printf("\n");
}

/* Search vertex using Matrix */
void searchMatrix(char target) {

    int operations = 0;

    printf("\n===== MATRIX SEARCH =====\n");

    for (int i = 0; i < V; i++) {

        operations++;

        if (vertices[i] == target) {

            printf("Vertex %c found.\n", target);
            printf("Operations required: %d\n",
                   operations);

            return;
        }
    }

    printf("Vertex not found.\n");
}

/* Search vertex using List */
void searchList(char target) {

    int operations = 0;

    printf("\n===== LIST SEARCH =====\n");

    for (int i = 0; i < V; i++) {

        operations++;

        if (vertices[i] == target) {

            printf("Vertex %c found.\n", target);
            printf("Operations required: %d\n",
                   operations);

            return;
        }
    }

    printf("Vertex not found.\n");
}

/* Main function */
int main() {

    /* Initialize adjacency list */
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;

    /* Given connections */
    addEdge(0, 1);   // A-B
    addEdge(0, 2);   // A-C
    addEdge(1, 3);   // B-D
    addEdge(1, 4);   // B-E
    addEdge(2, 5);   // C-F
    addEdge(4, 5);   // E-F

    /* Display graph representations */
    displayMatrix();
    displayList();

    /* BFS and DFS */
    BFS(0);
    DFS(0);

    /* Search vertex F */
    searchMatrix('F');
    searchList('F');

    return 0;
}
