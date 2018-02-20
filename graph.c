#include <stdio.h>
#include <stdlib.h>


struct edge {
    int from;
    int to;
    int wt;
    struct edge *next;
};

struct adj_list {
    struct edge *head;
};

struct graph {
    int V;
    int E;
    struct adj_list *array;
};

struct graph *create_graph(int vertex)
{
    struct graph *g = NULL;
    int i = 0;

    g = (struct graph *)malloc(sizeof(struct graph));

    if (!g) {
        return NULL;
    }

    g->V = vertex;
    g->E = 0;

    g->array = (struct adj_list *)malloc(sizeof(struct edge)*vertex);
    if (!g->array) {
        free(g);
        return NULL;
    }

    for (i=0; i<g->V; i++) {
        g->array[i].head = NULL;
    }

    return g;
}

void add_edge(struct graph *g, int to, int from, int wt)
{
    struct edge *e = NULL;
    e = (struct edge *)malloc(sizeof(struct edge));

    if (!e) {
        printf("\nMemory allocation failed\n");
        return;
    }

    e->to = to;
    e->from = from;
    e->wt = wt;
    e->next = g->array[from].head;
    g->array[from].head = e;
}

void destroy_graph(struct graph *g)
{
    int i = 0;
    struct edge *x = NULL, *tmp = NULL;
    
    for (i=0; i<g->V; i++) {
        x = g->array[i].head;
        if (x == NULL) {
            continue;
        }
        while(x->next != NULL) {
            tmp = x;
            x = tmp->next;
            free(tmp);
        }
    }
    
    if (g->array) {
        free(g->array);
    }

    free(g);
}

void print_graph(struct graph *g)
{
    int i = 0;
    struct edge *x = NULL;
    for (i=0; i<g->V; i++) {
        x = g->array[i].head;
        printf("\n edgs for vertex %d :", i);
        if (x == NULL) {
            printf("none");
            continue;
        }
        while(x != NULL) {
            printf("%d ", x->to);
            x = x->next;
        }
    } /* end of for loop */
}

static int done[8];
static int dist_to[8];
static int edge_to[8];
static int path[8];

#define INFINITY  9999

int is_all_done()
{
    int i = 0;
    for(i=0; i<8; i++) {
        if (!done[i]) {
            return 0;
        }
    }

    return 1;
}

int get_min_vertex()
{
    int i = 0;
    int min = INFINITY;
    int min_idx = -1;

    for (i=0; i<8; i++) {
        if ((!done[i]) && (dist_to[i] < min))
        {
            min_idx = i;
            min = dist_to[i];
        }
    }

    return min_idx;
}

void find_sp(struct graph *g) 
{
    int v = 0, i = 0, to = 0;
    struct edge *head = NULL;

    while(!is_all_done()) {
        v = get_min_vertex();
        head = g->array[v].head;
        while(head != NULL) {
            to = head->to;
            if (dist_to[to] > (dist_to[v] + head->wt)) {
                edge_to[to] = v;
                dist_to[to] = dist_to[v] + head->wt;
            }

            head = head->next;
        } /* end of inner while - traverse the adj list for this vertex*/

        done[v] = 1;
        printf("\nMarking %d as done", v);
        //break;
    } /* end of outer while */
}

void sp_to(int v)
{
    int i = 0;
    int tmp = v;
    int sp = 0;

    path[i] = v;
    i++;

    while(edge_to[tmp] != 0) {
        path[i] = edge_to[tmp];
        tmp = edge_to[tmp];
        i++;
    }

    path[i] = 0;
    sp = i;

    printf("\n Shortest Path from 0 to %d: ", v);
    for (i=sp;i>=0;i--) {
        printf(" %d", path[i]);
    }
}

main()
{
    struct graph *G = NULL;
    int i = 0;

    printf("Enter graph processing");
    G = create_graph(8);

    for (i=0; i<8; i++) {
        done[i] = 0;
    }
    
    for (i=0; i<8; i++) {
        edge_to[i] = -1;
    }

    edge_to[0] = 0;

    for (i=0; i<8; i++) {
        dist_to[i] = INFINITY;
    }

    dist_to[0] = 0;
   
    /* add_edge(G, to, from, wt); */
    add_edge(G, 5, 4, 35);
    add_edge(G, 4, 5, 35);
    add_edge(G, 7, 4, 37);
    add_edge(G, 7, 5, 28);
    add_edge(G, 5, 7, 28);
    add_edge(G, 1, 5, 32);
    add_edge(G, 4, 0, 38);
    add_edge(G, 2, 0, 26);
    add_edge(G, 3, 7, 39);
    add_edge(G, 3, 1, 29);
    add_edge(G, 7, 2, 34);
    add_edge(G, 2, 6, 40);
    add_edge(G, 6, 3, 52);
    add_edge(G, 0, 6, 58);
    add_edge(G, 4, 6, 93);

    print_graph(G);
    
    printf("\nRun shortest path\n");
    find_sp(G);

    for (i=0; i<8; i++) {
        printf("\n edge_to %d distance %d", edge_to[i], dist_to[i]);
    }

    sp_to(6);

    destroy_graph(G);
    printf("\nExit graph processing\n");
}
