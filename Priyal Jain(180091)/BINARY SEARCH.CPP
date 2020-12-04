#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
 int mid,item,i,a[20],size,f=0,upper,lower=1;
 clrscr();

 cout<<"Enter size of array";
 cin>>size;
 upper=size;
 cout<<"Enter elements of an array in ascending order:";
 for(i=1;i<=size;i++)
 {
  cin>>a[i];
 }
 cout<<"enter the element to search:";
 cin>>item;
 while((f==0)&&(lower<upper))
 {
   mid=(lower+upper)/2;
   if(item==a[mid])
   {
    cout<<"element is found at "<<mid;
    f=1;
    break;
   }
   else
   {
    if(item<a[mid])
    {
     upper=mid-1;
    }
    else
    {
     lower=mid+1;
    }
     }
 if (f==0)
 {
  cout<<"Element not found!";
 }
 }
 getch();
 }


