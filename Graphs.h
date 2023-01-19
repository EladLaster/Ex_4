#ifndef GRAPH_
#define GRAPH_



typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_{
    int weight;
    pnode endpoint;
    struct edge_ *next; //nextedge
} edge, *pedge;


typedef struct GRAPH_NODE_{
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next; //nextnode
} node, *pnode;

typedef struct Dijkstra {
    pnode node;
    int weight;
    int tag;
    struct Dijkstra *next;
} dijkstra, *pdijkstra;


void build_graph_cmd(pnode head); //v
void insert_node_cmd(pnode *head); //v
void delete_node_cmd(pnode *head); // v
void printGraph_cmd(pnode head); //v
void deleteGraph_cmd(pnode* head); //v
int shortsPath_cmd(pnode head, int src, int dest); // v
int TSP_cmd(pnode head); // v
void free_node(pnode node); //v
void free_edge(pedge edge); //v
void delete_outgoing_edges(pnode node); // v
void delete_incoming_edges(pnode *head,int n); //v
pnode connect_all_nodes(); //v
pnode find_node(pnode head, int key); //v


#endif