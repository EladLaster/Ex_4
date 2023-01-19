#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"


pnode connect_all_nodes(int num_of_nodes){

    pnode temp=NULL,head=NULL,current=NULL;
    for (int i = 0; i < num_of_nodes; i++) {
        temp = (pnode)malloc(sizeof(node));
        temp->node_num = i;
        temp->edges = NULL;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = temp;
        } 
        else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

void printGraph_cmd(pnode head){

    pnode tempNode = head;
    printf("%s","||");
    while (tempNode != NULL){
        printf(" %d --> (", tempNode->node_num);
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL){
            printf(" destination: %d weight: %d ", tempEdge->endpoint->node_num,tempEdge->weight);
            tempEdge = tempEdge->next;
        
        }
        printf(") -->");
        tempNode = tempNode->next;
    }
    printf("%s","||");
}

void deleteGraph_cmd(pnode* head){

    pnode tempNode = (*head);
    while (tempNode != NULL){
        pedge tempEdge = tempNode->edges;
        while (tempEdge != NULL){
            pedge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
}

void delete_node_cmd(pnode *head){
   
    int delete_node_num= 0;
    scanf("%d",&delete_node_num);
    delete_incoming_edges(head,delete_node_num);
    pnode tempNode = *head;
    node *current = NULL;
    if(tempNode->node_num != delete_node_num){
        while (tempNode->next->node_num!=delete_node_num){
        tempNode = tempNode->next;
        }
        current = tempNode->next;
        tempNode->next=tempNode->next->next;
        delete_outgoing_edges(current);
        free(current);    
    }
    else{
    current = *head;
    *head = current->next;
    delete_outgoing_edges(current);
    free(current);
    }
}

void delete_outgoing_edges(pnode node){

    if(node->edges!=NULL){
        pedge temp = node->edges;
        while(temp!=NULL){
            pedge edge = temp;
            temp = temp->next;
            free(edge);
        }
    }
    else{
        free(node->edges);
    }
}
    
void delete_incoming_edges(pnode *head,int delete_node_num){

    pnode tempNode = (*head);
    while (tempNode!= NULL){
        if(tempNode->node_num!= delete_node_num && tempNode->edges!=NULL){
            if(tempNode->edges->endpoint->node_num!=delete_node_num){
                pedge tempEdge = tempNode->edges;
                while (tempEdge->next!= NULL){   
                    if(tempEdge->next->endpoint->node_num== delete_node_num){
                        pedge edge = tempEdge->next;
                        tempEdge->next=tempEdge->next->next;
                        free(edge);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }           
            }
            else{ 
                if(tempNode->edges->next ==NULL){
                    pedge edge = tempNode->edges;
                    tempNode->edges = NULL;
                    free(edge);
                    }
                else{
                    pedge edge = tempNode->edges;
                    tempNode->edges = edge->next;
                    free(edge);
                    }
            }
        }
        tempNode = tempNode->next; 
    }
}

pnode find_node(pnode head,int key){

    pnode node = head;
    while (node != NULL){
        if(node->node_num == key){
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head){

    int new_node_num;
    int connectNode, weight;
    pnode temp=(*head);
    pedge edgeCurrent = NULL;
    scanf(" %d",&new_node_num);
    
    pnode check = find_node(temp,new_node_num);
    if(check!=NULL){
        delete_outgoing_edges(check);
        check->edges=NULL;
    }
    if(check==NULL){
        pnode newnode=(pnode)malloc(sizeof(node));
        newnode->node_num = new_node_num;
        newnode->edges = NULL;
        newnode->next = NULL;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        check=newnode;
    }
    while (scanf(" %d %d", &connectNode, &weight)==2){
        temp = (*head);
        while (temp->node_num != connectNode){
            temp = temp->next;
        }
        edgeCurrent = (pedge)malloc(sizeof(edge));
        edgeCurrent->weight = weight;
        edgeCurrent->endpoint = temp;
        edgeCurrent->next = check->edges;
        check->edges = edgeCurrent;
    }
}

void build_graph_cmd(pnode head) {

    int mainNode, connectNode, weight;
    pnode current = NULL,temp=NULL;
    pedge edgeCurrent = NULL;
    scanf(" %d", &mainNode);
    current=head;
    while (current->node_num != mainNode) {
        current = current->next;
    }
    while (scanf(" %d %d", &connectNode, &weight)==2) {
        temp=head;
        while (temp->node_num != connectNode) {
            temp = temp->next;
        }
        edgeCurrent = (pedge)malloc(sizeof(edge));
        edgeCurrent->weight = weight;
        edgeCurrent->endpoint = temp;
        edgeCurrent->next = current->edges;
        current->edges = edgeCurrent;
    }
}