#include <stdio.h>

int bitsUm (unsigned int n)
{
	int count = 0;
	while(n!=0){
		if(n&1 == 1)count++;
		n = n>>1;
	}
	return (count);
}
main () 
{
	unsigned int n;
	
	scanf("%d",&n);
	printf("%d",bitsUm (n));


}
