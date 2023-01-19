#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

int main(){
    char c;
    pnode head=NULL;
    while (scanf(" %c", &c) != EOF)
    {
        switch (c){

        case 'n':
            build_graph_cmd(head);
            // printGraph_cmd(head);
            break;

        case 'A':
            int num_of_nodes;
            deleteGraph_cmd(&head);
            scanf(" %d",&num_of_nodes);
            head = connect_all_nodes(num_of_nodes);
            // printGraph_cmd(head);
            break;

        case 'B':
            insert_node_cmd(&head);
            // printGraph_cmd(head);
            break;

        case 'D':
            delete_node_cmd(&head);
            // printGraph_cmd(head);
            break;

        case 'S':
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = shortsPath_cmd(head, src, dest);
            printf("Dijsktra shortest path: %d \n", dis);
            break;
            
        case 'T':
            TSP_cmd(head);
            break;
        }
    }
    return 0;
}
