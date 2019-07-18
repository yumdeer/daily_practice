#include <iostream>  

int main() 
{ 
　　　int a[10]; 
　　　int i,k; 
　　　long n; 
　　　//scanf("%d",&n); 
　　　k=0; 
　　　while (n>0) 
　　　{ 
　　　　 a[k]=n-(n/10)*10; 
　　　　 n=n/10; 
　　　　 k++; 
　　　} 
　　　//printf("%d\n",k); 
　　　for (i=0;i<k;i++) 
　　　//　 printf("%d",a[i]); 
　　　//system("pause");

　　　return 0; 
}
