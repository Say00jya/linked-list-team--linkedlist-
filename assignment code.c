#include <stdio.h>
#include <stdlib.h>


struct Node {
    int rollNo;
    struct Node* next;
};


struct Node* createNode(int rollNo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int rollNo) {
    struct Node* newNode = createNode(rollNo);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Roll Numbers in Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->rollNo);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int rollNo, n, i;

   
    printf("Enter your roll number: ");
    scanf("%d", &rollNo);
    head = createNode(rollNo);

  
    printf("Enter number of teammates: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter teammate %d roll number: ", i + 1);
        scanf("%d", &rollNo);
        insertEnd(&head, rollNo);
    }

    displayList(head);

    return 0;
}

