#include<stdio.h> 
int main() 
  { 
      int num,base,rem,digit,count=0,i; 
      char a[100];
      printf("\nNumber:"); 
      scanf("%d",&num); 
      printf("\nBase:"); 
      scanf("%d",&base); 
      while(num!=0) 
       { 
         rem=num%base; 
         digit='0'+ rem; 
         if(digit>'9')
         {
            digit=digit+7;   
         }
         a[count]=digit; 
         num=num/base; 
         count++;
       }
       printf("\n");
       for(i=count-1;i>=0;--i) 
       {
         printf("%c",a[i]); 
       }
    return 0;
  }
