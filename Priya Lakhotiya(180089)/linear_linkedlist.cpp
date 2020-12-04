#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
};
struct node *head,*n;
void insert(){
	int x;
	struct node *ptr;
	ptr=head;
	printf("Enter the value of new node: ");
	scanf("%d",&x);
	n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	if(head==NULL){
		n->link=NULL;
		head=n;
	}else{
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		n->link=NULL;
		ptr->link=n;
	}
}
void traversal(){
	struct node *ptr;
	ptr=head;
	if(head==NULL){
		printf("List is empty");
		getch();
	}
	else{
		while(ptr!=NULL){
			printf("%d-> ",ptr->data);
			ptr=ptr->link;
		}
		getch();
	}
}
void srch(){
	struct node *ptr;
	ptr=head;
	int c=0,key,i=0;
	if(head==NULL){
		printf("List is empty");
		getch();
	}
	else{
		printf("Enter the value to search: ");
		scanf("%d",&key);
		while(ptr!=NULL||c==1){
			if(ptr->data==key){
				c=1;
				break;
			}
			else{
				ptr=ptr->link;
				i=i+1;
			}
		}
		if(c==1){
			printf("The value %d is found at position: %d",key,i+1);
			getch();
		}
		if(c==0){
			printf("Value not found");
			getch();
		}
	}
}
void main(){ clrscr();
	int c;
	L:system("cls");
	printf("1. Insertion\n");
	printf("2. Traversal\n");
	printf("3. Search\n");
	printf("4.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&c);
	switch(c){
		case 1:
			insert();
			goto L;
		case 2:
			traversal();
			goto L;
		case 3:
			srch();
			goto L;
		case 4:
			exit(0);
		default:
			printf("Invalid choice...Enter your choice again");
			getch();
			goto L;
	}
getch();
}