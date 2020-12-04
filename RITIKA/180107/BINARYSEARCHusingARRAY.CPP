#include<stdio.h>
#include<conio.h>
void main()
{
int m, beg, end, middle, n, search;
int a[10];
printf("\n Enter the number of elements in the array:");
scanf("%d", &n);
printf("\nEnter the %d integers:",n);
for(m=0; m<n; m++)
scanf("%d", &a[m]);
printf("\n Enter the number to search:");
scanf("%d", &search);
beg = 0;
end = n - 1;
middle = (beg + end)/2;
while(beg<=end)
{
if(a[middle]<search)
beg= middle+1;
else if (a[middle] == search)
{
printf("Element %d is found at location:%d",search, middle+1);
break;
}
else
end = middle - 1;
middle = (beg + end)/2;
}
if(beg>end)
printf("Element %d is not present in the array.", search);
getch();
}