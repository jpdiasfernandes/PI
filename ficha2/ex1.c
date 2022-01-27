#include <stdio.h>

float multInt(int n, float m){
	int r = 0;
	while(n > 0){
		r = r + m;
		n--;
	}
	return r;
}

float multIntR(int n, float m){
	return (n == 1)? m : m + multIntR(n-1,m);
}

int main(){
	float e = multIntR(3,5);
	float i = multInt(3,5);
	printf("%f", e);
}
