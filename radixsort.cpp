#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to find the maximum number in the linked list
int findMax(struct Node* head) {
    int max = -1;
    while (head != NULL) {
        if (head->data > max) {
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

// Function to perform counting sort based on a particular digit
struct Node* countSort(struct Node* head, int exp) {
    struct Node* output = (struct Node*)malloc(sizeof(struct Node));
    output->next = NULL;
    int count[10] = {0};

    // Count the occurrences of each digit at the specified place
    struct Node* current = head;
    while (current != NULL) {
        count[(current->data / exp) % 10]++;
        current = current->next;
    }

    // Calculate the positions of each element in the output list
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output list
    current = head;
    while (current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;
        int index = (current->data / exp) % 10;
        if (count[index] > 0) {
            output->data = current->data;
            output->next = newNode;
            count[index]--;
        } else {
            struct Node* temp = output;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        current = current->next;
    }

    return output->next;
}

// Radix Sort function for linked list
struct Node* radixSort(struct Node* head) {
    int max = findMax(head);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        head = countSort(head, exp);
    }
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insert(head, data);
    }

    printf("Original list: ");
    printList(head);

    head = radixSort(head);

    printf("Sorted list: ");
    printList(head);

    // Free memory allocated for the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

