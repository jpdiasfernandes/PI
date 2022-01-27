#include <stdio.h>
void f (int n){

	for(int c = n; c > 0 ; c--)
	{	
		if (c%2 == 0)
		{
			for (int i = n; i > 0; i--)
			{
				if (i%2 == 0)putchar('#');else putchar('_');
			}
			putchar('\n');
		}
		else
		{
			for (int i = n; i > 0; i --)
			{
				if (i%2 == 0){putchar('_');} else {putchar('#');}
			}
			putchar('\n');
		}
	}




}
void tabuleiro (int n){
	int i,j;
	for(i = n; i > 0; i--){
		for(j=n; i>0; i--){
			if((i+j)%2 == 0) putchar('#');
			else putchar('_');
		}
		printf("\n");
	}
}



main(){ 
	int n;

	scanf("%d",&n);
	f(n);
}
