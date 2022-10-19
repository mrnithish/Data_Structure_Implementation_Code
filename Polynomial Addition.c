#include<stdio.h>
#include<math.h>

struct poly
{
  int coefficient;
  int exponent;
};


struct poly a[50],b[50],c[50];

void main(){
    int i;
    int deg1,deg2;
    int k=0,l=0,m=0;
    
    printf("Enter the highest degree of poly1:");
    scanf("%d",&deg1);
    
    for(i=0;i<=deg1;i++)
    {
    printf("\nEnter the coeff of x^%d :",i);
    scanf("%d",&a[i].coefficient);
    a[k++].exponent = i;
    }
    
     printf("\nEnter the highest degree of poly2:");
 scanf("%d",&deg2);
 
 for(i=0;i<=deg2;i++)
 { 
       printf("\nEnter the coeff of x^%d :",i);
       scanf("%d",&b[i].coefficient);
	   
	   b[l++].exponent = i;
 }
 
  if(deg1>deg2)
    {
		 for(i=0;i<=deg2;i++)
		  {
			c[m].coefficient = a[i].coefficient + b[i].coefficient;
			c[m].exponent = a[i].exponent;
			m++;
		  }
		  
		  for(i=deg2+1;i<=deg1;i++)
		  {
			c[m].coefficient = a[i].coefficient;
			c[m].exponent = a[i].exponent;
			m++;
		  }

    }
 else
  {
    for(i=0;i<=deg1;i++)
     {
       c[m].coefficient = a[i].coefficient + b[i].coefficient;
       c[m].exponent = a[i].exponent;
       m++;
     }
    
	for(i=deg1+1;i<=deg2;i++)
    {
      c[m].coefficient = b[i].coefficient;
      c[m].exponent = b[i].exponent;
      m++;
    }
  }
  
  
  

  printf("\nExpression after additon  = %d",c[0].coefficient);
  for(i=1;i<m;i++)
  {
     printf("+ %d x^%d",c[i].coefficient,c[i].exponent);
   }	 
 



}
