#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    int vertex;
};

typedef struct node *GNODE;

/* DEFINE graph here */
GNODE graph[20];

void print(int *N) {
    GNODE p;
    int i;
    for(i = 1; i <= *N; i++) {
        if(graph[i] != NULL) {
            printf("%d=>", i);
            p = graph[i];
            while(p != NULL) {
                printf("%d\t", p->vertex);
                p = p->next;
            }
            printf("\n");
        }
    }
}

void insertVertex(int *N) {
    int i, m, v;
    GNODE p, q;

    (*N)++;

    printf("Enter the number of edges from existing vertices to the new vertex : ");
    scanf("%d", &m);

    for(i = 1; i <= m; i++) {
        scanf("%d", &v);
        if(v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            continue;
        }

        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = *N;
        q->next = NULL;

        if(graph[v] == NULL)
            graph[v] = q;
        else {
            p = graph[v];
            while(p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("Enter the number of edges from new vertex to existing vertices : ");
    scanf("%d", &m);

    for(i = 1; i <= m; i++) {
        scanf("%d", &v);
        if(v < 1 || v >= *N) {
            printf("Invalid vertex.\n");
            continue;
        }

        q = (GNODE)malloc(sizeof(struct node));
        q->vertex = v;
        q->next = NULL;

        if(graph[*N] == NULL)
            graph[*N] = q;
        else {
            p = graph[*N];
            while(p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}

void insertEdge(int *N) {
    int s, d;
    GNODE p, q;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &s);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &d);

    if(s < 1 || s > *N || d < 1 || d > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    q = (GNODE)malloc(sizeof(struct node));
    q->vertex = d;
    q->next = NULL;

    if(graph[s] == NULL)
        graph[s] = q;
    else {
        p = graph[s];
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}

void deleteVertex(int *N) {
    int v, i;
    GNODE p, temp, prev;

    if(*N == 0) {
        printf("Graph is empty.\n");
        return;
    }

    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);

    if(v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    for(i = 1; i <= *N; i++) {
        p = graph[i];
        prev = NULL;
        while(p != NULL) {
            if(p->vertex == v) {
                if(prev == NULL)
                    graph[i] = p->next;
                else
                    prev->next = p->next;
                temp = p;
                p = p->next;
                free(temp);
            } else {
                prev = p;
                p = p->next;
            }
        }
    }

    p = graph[v];
    while(p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }

    for(i = v; i < *N; i++)
        graph[i] = graph[i+1];

    graph[*N] = NULL;
    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}

void deleteEdge(int *N) {
    int s, d;
    GNODE p, prev;

    printf("Enter the source vertex of the edge : ");
    scanf("%d", &s);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &d);

    if(s < 1 || s > *N || d < 1 || d > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    p = graph[s];
    prev = NULL;

    while(p != NULL) {
        if(p->vertex == d) {
            if(prev == NULL)
                graph[s] = p->next;
            else
                prev->next = p->next;
            free(p);
            break;
        }
        prev = p;
        p = p->next;
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}
