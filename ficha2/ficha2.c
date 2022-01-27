#include <stdio.h>
#include "ficha2.h"

//2
float mult(int n, float m){
	float res = 0;
	while (n != 1){
	
		if(n%2 == 1){
			res += m;
		}	
		m = m*2;
		n = n/2;
	}
	res += m;
}

//3
int mdc(int a, int b){
    int i;
    if (a > b) i = a; else i = b;

    while (b % i != 0 || a % i != 0){
        i--;
    }
    return i;
}

//4
int md4(int a, int b){
    if (a == b) return a;
    else{
        if (a > b) return md4 (a-b,b);
        else return md4(a,b-a);
    }
}
//5

//6a
int fib (int n){
    if(n < 2) return 1;
    else{
        return fib(n-1) +fib(n-2);
    }
}
//6b
int fib2(int n) {
    int i = 2, a = 1, b = 1;
    if (n < 2) {
        return 1;
    } else {
        while (i < n) {
            int x = a;
            a = b;
            b = (b + x);
            i++;
        }
        return b;
    }
}












