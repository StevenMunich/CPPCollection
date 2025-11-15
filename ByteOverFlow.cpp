//Byte overflow - overflowing 1 bit at 255 and seeing if it affects the adjacent memory

#include "stdio.h"

int main(){
	
	unsigned char a  = 255;
	unsigned char b = 65; //sorry for confusion, A is 65 in assci so it may display "A" as a char. I took it out
	
	printf("Addreess locations in decimal:\n A %d \n B %d", &a, &b);
		printf("Addreess locations in hexidecimal: %p %p", &a, &b);
	
	printf("\nValue of A %c is %d\n", a , a );
	printf("Value of B as an ASCII char is %c and the integer value is %d\n", b , b );
	
	a++;
	
	printf("Value of A %c is now changed to %d\n", a , a );
	printf("Value of B in char is now %c and in integer is now changed to %d\n", b , b );
	
	printf("\n==============================================================\n");
	printf("Results of expiriment: A flips back to zero while B remains unaffected.\n Now to swap roles");
	printf("\n==============================================================\n");
	
	a = 65;
	b = 255;
		
	printf("Value of A is %d\n", a , a );
	printf("Value of B is %d\n", b , b );
	
	printf("b++ \n");
	b++;
	
	printf("Value of A is %d\n", a , a );
	printf("Value of B is %d\n", b , b );
	printf("\n==============================================================\n");
	printf("Results of expiriment: B flips back to zero while A remains unaffected.\n Conclusion: The byte overflow only affects the single variable and not memory adjacent to it.");
	printf("It is different from a buffer overflow using a string or pointer to a character. Then the adjacent memory is overwritten. In this case it is not and the bits contained in the variable are flipped to zero afer an increment of 1 at the value 255");
	printf("\n==============================================================\n");
	
	
	return 0;
}

