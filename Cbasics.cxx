#include <stdio.h>
#include <stdbool.h> 
// allows booleans

int main(int argc, char *argv[])
{
    int age = 27;            //4 bytes
    float pie = 3.1476;   //4bytes
    float div2;
    double double1 = 3.14; // 8 bytes
    char grade = 'C';        //1byte -128 to 127
    unsigned char ascii; // 1byte 0 to 255
    char name[ ] = "ste";
    int x, x2;
   
   
    //FOR ACSII
    grade=0;
  for(x=0; x < 256; x++)
      { 
      ascii = x;
      printf("number %d is %c \n", ascii, ascii);   
      }
     for(x=33; x<127; x++){
     ascii = x;
     scanf("%d", &x);
     printf("you typed %c \n", ascii);
     break;
     
     }
     
 
    
    
    bool t = true;
    bool f = false;
    printf("%d and %d", t, f);
    
    
  //  printf("gello %s \n", name);
 //   printf("grade is %c \n", grade);
//  printf("your age is %d \n", age);
 //   printf("pie is %f", pie);
 printf("double val %lf \n", double1);
 
   //printf("enter a number: ");
   // scanf("%d %f %s \n", &x, &pie, &name);
    //printf("%d  \n %f \n %s", x, pie, name); 
    // x2 = x *2;
  //  div2= pie/2;
  //  printf(" %d times two is %d \n", x, x2);
  //  printf("%f divided by 2 is %f", pie, div2);
 
 
 
/*       printf("\n enter a number even or odd \n");
       scanf("%d", &x);
       if (x%2==0)
       {
           printf("even");
       }
       else
       {
           printf("odd");
       }
       
       int i;
       for (i=0; i < 10; i++)
       printf("\n num %d \n", i);
       */
       
       
   //    int sum =0;
     //  while(i!=0)
  //     {
        //   sum += i;
//           i--;
       //    printf("value of i %d \n", i);
    //       printf("value of sum %d \n", sum);
 //      }
 /*
       int i;
       int a[10];
       for(i=0; i < 10; i++)
       scanf("%d", &a[i]);
       for(i=0; i < 10; i++)
       printf("%d and memory %d \n", a[i], &a[i]);
       */
       
       struct cat{
           int age;
           char name[];
       };
       cat seagull;
      printf("enter name: ");
      scanf("%s \n", seagull.name);
      printf("%s is a cat \n", seagull.name);
      cat *pc = &seagull;
      pc->age = 5;
      printf("%d is the age \n", seagull.age);
      
    
// printf("hal");
}
