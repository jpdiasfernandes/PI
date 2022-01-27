#include <stdio.h>
main(){
	int maior,x;
	x = 1;
	for(int i = 0; x != 0; i++)
	{
		if(i == 0)
		{
			scanf("%d", &x);
			maior = x;
		}
		else
		{
			scanf("%d",&x);
			if(x > maior) maior = x;
		}
	}
	printf("%d\n",maior);
}
