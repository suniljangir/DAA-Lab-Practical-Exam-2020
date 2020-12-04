#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 15

int a[11], b[10];
void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
	 b[i] = a[l1++];
      else
	 b[i] = a[l2++];
   }

   while(l1 <= mid)
      b[i++] = a[l1++];

   while(l2 <= high)
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   } else {
      return;
   }
}

void main() {

   int i,s;
   clrscr();
   printf("\n Enter size of array:");
   scanf("%d", &s);
   printf("Enter the elements:");
   for(i=0;i<s;i++)
   {
    scanf("%d",&a[i]);
   }
   printf("Before sorting\n");

   for(i = 0; i < s; i++)
      printf("%d ", a[i]);

   sort(0, s-1);

   printf("\nAfter sorting\n");

   for(i = 0; i < s; i++)
      printf("%d ", a[i]);
      getch();
}
