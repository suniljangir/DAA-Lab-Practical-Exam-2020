#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 
main()
{int n,i,temp,j,k;
 printf("\nEnter the Number of elements to be sorted");
  scanf("%d",&n);
 int a[n];
 printf("\nenter the elements");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 printf("\nelements before sorting are:\n");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]); 
 for(i=0;i<n-1;i++)
 {for(j=0;j<n-i;j++)
  {if(a[j]>a[j+1])
   {temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("\nelements after sorting are:\n");
 for(k=0;k<n;k++)
 printf("%d\t",a[k]);
} 
