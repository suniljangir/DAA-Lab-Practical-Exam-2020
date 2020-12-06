#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
void swapNodes(struct Node** head_ref, struct Node* currX,
               struct Node* currY, struct Node* prevY)
{
    *head_ref = currY;
    prevY->next = currX;
    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}
struct Node* recurSelectionSort(struct Node* head)
{
    if (head->next == NULL)
        return head;
    struct Node* min = head;
    struct Node* beforeMin = NULL;
    struct Node* ptr;
    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
        if (ptr->next->data < min->data) {
            min = ptr->next;
            beforeMin = ptr;
        }
    }
    if (min != head)
        swapNodes(&head, head, min, beforeMin);
    head->next = recurSelectionSort(head->next);
    return head;
}
void sort(struct Node** head_ref)
{
    if ((*head_ref) == NULL)
        return;
    *head_ref = recurSelectionSort(*head_ref);
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
         (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(struct Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    struct Node* head = NULL;
    push(&head, 6);
    push(&head, 4);
    push(&head, 8);
    push(&head, 12);
    push(&head, 10);
    cout << "Linked list before sorting:n";
    printList(head);
    sort(&head);
    cout << "\nLinked list after sorting:n";
    printList(head);
    return 0;
}
