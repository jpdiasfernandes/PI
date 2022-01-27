#include <stdio.h>
void f(int);
void g(int);
void triangulo_vert(int);
void triangulo_hor(int);

void triangulo_vert (int n)
{
	for(int i = 1; i <= n; i++)
	{
                f(i); 
		putchar('\n');
	}
	for(int i = n-1; i > 0; i--)
	{
		f(i);
		putchar('\n');
	}
          
}
void f (int n)
{
	for (int i = n; i > 0; i--)
	{
		putchar('#');
	}

}
void triangulo_hor (int n)
{
	for(int i = 1; i <= n; i++)
	{
        	g(n-i);
		f((2*i)-1);
		g(n-i);
		putchar('\n');
	}
}
void g (int n)
{
	for(int i = n; i > 0; i--)
	{
		putchar(' ');
	}
}
main()
{
	int n;
	scanf("%d", &n);
	triangulo_vert(n);
	triangulo_hor(n);
	return 0;
}
