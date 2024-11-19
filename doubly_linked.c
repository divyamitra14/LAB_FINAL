#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insertbeg(struct node **head, int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->prev = NULL;

    new->next=*head;
    if(*head != NULL) {
        (*head)->prev=new;
    }
    *head = new;
}

void insertend(struct node **head, int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if((*head)==NULL) {
        new->prev = NULL;
        (*head)=new;
        return;
    }
    struct node *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}

void insertafter(struct node **head, int data,int pos) {
    if(pos==1) {
        insertbeg(head,data);
        return;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    struct node *temp=*head;
    for(int i=1;i<pos-1;i++) {
        if(temp==NULL) {
            printf("pos out of range\n");
            free(new);
            return;
        }
        temp=temp->next;
    }
    new->next=temp->next;
    new->prev=temp;

    if(temp->next!=NULL) {
        temp->next->prev=new;
    }
    temp->next=new;

}

void delbeg(struct node **head) {
    struct node *temp=*head;
    if(*head==NULL) {
        printf("list is empty\n");
    }
    if((*head)->next==NULL) {
        free(*head);
        printf("list is empty\n");
        return;
    }
    *head=(*head)->next;
    if(*head!=NULL) {
        (*head)->prev=NULL;
    }
    free(temp);
}


void delend(struct node **head) {
    if(*head==NULL) {
        printf("list is empty\n");
    }
    if((*head)->next==NULL) {
        free(*head);
        printf("list is empty\n");
    }
    struct node *temp=*head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void delpos(struct node **head, int pos) {
    if(*head==NULL) {
        printf("list is empty\n");
    }
    if (pos==1) {
        delbeg(head);
        return;
    }
    struct node *temp=*head;
    for(int i=1;i<pos;i++) {
        if(temp==NULL) {
            printf("pos out of range\n");
            free(temp);
            return;
        }
        temp=temp->next;
    }
    if(temp->next!=NULL) {
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL) {
        temp->prev->next=temp->next;
    }
    free(temp);
}

void display(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    insertbeg(&head, 10);
    insertbeg(&head, 20);
    insertend(&head, 30);
    insertend(&head, 40);
    insertafter(&head, 50, 2);
    insertafter(&head,74,4);
    display(head);

    delbeg(&head);
    printf("deleted from begening\n");
    display(head);

    delend(&head);
    printf("deleted from end\n");
    display(head);

    delpos(&head,2);
    printf("deleted from %d position!\n",2);
    display(head);
}