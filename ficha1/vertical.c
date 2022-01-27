#include <stdio.h>
void f(int);
void trih (int n){
	for(int i = 1; i <= n; i++){f(i);printf("\n");}	
	for(int i = n-1; i > 0; i--){f(i);printf("\n");}
	
}
void f(int n){
	for (int i = 0; i < n; i++) putchar('#');
}

int main (){
	trih(5);
}

