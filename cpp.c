#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int x) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = x;
    new->next = *head;
    *head = new;
}

void traverse(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node **head, int x) {
    struct Node *temp = *head, *prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void update(struct Node *head, int old, int new) {
    while (head != NULL) {
        if (head->data == old) {
            head->data = new;
            return;
        }
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);

    traverse(head);

    update(head, 20, 25);
    traverse(head);

    deleteNode(&head, 10);
    traverse(head);

    return 0;
}

