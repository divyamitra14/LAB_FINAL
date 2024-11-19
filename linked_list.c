#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertbeg(struct node **head,int data) {
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=*head;
    *head=new;
}
void insertend(struct node **head, int data) {
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(*head==NULL) {
        new->next=*head;
        *head=new;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=new;
}

void insertafternode(struct node **head,int data,int pos) {
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;

    if(pos==1) {
        new->next=*head;
        *head=new;
        return;
    }
    struct node *temp=*head;
    for(int i=1;i<pos-1;i++) {
        if(temp==NULL) {
            printf("pos out of range!");
            return;
        }
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
}
void delbeg(struct node **head) {

    if(*head==NULL) {
        printf("list is empty");
    }
    struct node *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void delend(struct node **head) {
    if(*head==NULL) {
        printf("list is empty");
    }
    if((*head)->next==NULL) {
        free(*head);
        *head=NULL;
        return;
    }
    struct node *temp=*head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleatpos(struct node **head,int pos) {
    if(*head==NULL) {
        printf("list is empty");
    }
    struct node *temp=*head;
    if(pos==1) {
        *head=(*head)->next;
        free(temp);
        return;
    }
    for(int i=1;i<pos-1;i++) {
        temp=temp->next;
    }
    struct node *delenode=temp->next;
    temp->next=delenode->next;
    free(delenode);
}

void display(struct node *head) {
    struct node *temp=head;
    while(temp!=NULL) {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct node *head=NULL;
    insertbeg(&head,12);
    insertend(&head,85);
    insertend(&head,70);
    insertafternode(&head,14,2);
    display(head);

    delbeg(&head);
    printf("deleted from begening\n");
    display(head);

    delend(&head);
    printf("deleted from end\n");
    display(head);


    deleatpos(&head,1);
    printf("dleted from node!\n");
    display(head);

}