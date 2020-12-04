                                                 PROGRAM  4
Objectives :- Write an algorithm and program to sort n numbers using Selection sort technique 
i) Using arrays                  
       #include<iostream>
        using namespace std;
         int main()
        {
        int i,j,n,loc,temp,min,a[30];
        cout<<"Enter the number of elements:";
        cin>>n;
        cout<<"\nEnter the elements\n";
        for(i=0;i<n;i++)
       {
        cin>>a[i];
        }
       for(i=0;i<n-1;i++)
    {
     min=a[i];
     loc=i;
        for(j=i+1;j<n;j++)
        {
         if(min>a[j])
         {
         min=a[j];
         loc=j;
            }
        }
       temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
  cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 return 0;
}


(iii) recursion and linked list:

#include <iostream>
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
