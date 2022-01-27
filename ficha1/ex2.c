#include <stdio.h>

void quad (int n){
	int i=n;
	while (i>0){
		int j = n;
		while (j>0){
			putchar('#');
			j--;
		}
		printf("\n");
		i--;
	}
}
int main (){
        int n;
	scanf("%d",&n);
	quad(n);	
	return 0;
}









