#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int rollNo;
    struct Node* next;
};

// Function to create a node
struct Node* createNode(int rollNo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
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

// Display linked list
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

    // First node: your roll number
    printf("Enter your roll number: ");
    scanf("%d", &rollNo);
    head = createNode(rollNo);

    // Insert teammates' roll numbers
    printf("Enter number of teammates: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter teammate %d roll number: ", i + 1);
        scanf("%d", &rollNo);
        insertEnd(&head, rollNo);
    }

    // Display the list
    displayList(head);

    return 0;
}

