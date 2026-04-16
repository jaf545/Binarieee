
printf("jaf545");



 * Pop Quiz 8 - Section 05
 * Topic: Linked Lists
 * 
 * TASK: Count Even Values
 * 
 * Given a linked list, count how many nodes have even values.
 * 
 * Input: First line n, then n integers to build list
 * Output: Count of even values
 * 
 * Example:
 *   Input:        Output:
 *   5             2
 *   1 2 3 4 5
 */

#include <stdio.h>
#include <stdlib.h>

/* PROVIDED - DO NOT MODIFY */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

Node* build_list(int arr[], int n) {
    if (n == 0) return NULL;
    Node *head = create_node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = create_node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void free_list(Node *head) {
    while (head) { Node *t = head; head = head->next; free(t); }
}
/* END PROVIDED */

// TODO: Implement this function
int count_even(Node *head) {
    int count = 0;
    Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
        count++;
    }
        curr = curr->next;
    }

    return count;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    Node *list = build_list(arr, n);
    printf("%d\n", count_even(list));
    free_list(list);
    return 0;
}
