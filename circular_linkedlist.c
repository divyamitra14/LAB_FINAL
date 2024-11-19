#include <stdio.h>
#include <stdlib.h>

// Define a node
struct node {
    int data;
    struct node *next;
};

// Insert at the beginning
void insertbeg(struct node **head, int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    if (*head == NULL) { // Empty list
        new->next = new;
        *head = new;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    new->next = *head;
    temp->next = new;
    *head = new;
}

// Insert at the end
void insertend(struct node **head, int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    if (*head == NULL) { // Empty list
        new->next = new;
        *head = new;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = new;
    new->next = *head;
}

// Insert at a specific position
void insertatpos(struct node **head, int data, int pos) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;

    if (pos == 1) { // Insert at the beginning
        insertbeg(head, data);
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == *head) { // Position out of bounds
            printf("Position out of bounds\n");
            free(new);
            return;
        }
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
}

// Delete from the beginning
void delbeg(struct node **head) {
    if (*head == NULL) { // Empty list
        printf("List is empty\n");
        return;
    }

    struct node *temp = *head;

    if ((*head)->next == *head) { // Single node case
        free(*head);
        *head = NULL;
        return;
    }

    struct node *last = *head;
    while (last->next != *head)
        last = last->next;

    *head = (*head)->next;
    last->next = *head;

    free(temp);
}

// Delete from the end
void delend(struct node **head) {
    if (*head == NULL) { // Empty list
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == *head) { // Single node case
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Delete at a specific position
void delatpos(struct node **head, int pos) {
    if (*head == NULL) { // Empty list
        printf("List is empty\n");
        return;
    }

    if (pos == 1) { // Delete the first node
        delbeg(head);
        return;
    }

    struct node *temp = *head;
    struct node *prev = NULL;

    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == *head) { // Position out of bounds
            printf("Position out of bounds\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}

// Display the circular linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

// Main function to test the circular linked list
int main() {
    struct node *head = NULL;

    insertbeg(&head, 10);
    insertbeg(&head, 5);
    insertend(&head, 20);
    insertend(&head, 30);
    insertatpos(&head, 15, 3); // Insert 15 at position 3

    printf("Circular Linked List: ");
    display(head);

    delbeg(&head);
    printf("After deleting the first node: ");
    display(head);

    delend(&head);
    printf("After deleting the last node: ");
    display(head);

    delatpos(&head, 2); // Delete the node at position 2
    printf("After deleting node at position 2: ");
    display(head);

    return 0;
}
