#include <stdio.h>

int length(char *s){
	int r = 0;
	while(*(s+r) != '\0'){
		r++;
	}
	return (r+1);
}

char *strcat(char s1[], char s2[])
{
        	
	int n1 = length (s1);
	int n2 = length (s2);
	int i = 0, j = 0;
	while (i < n2) {
		*(s1+n1+i) = s2[i];
		i++;
	}
	return s1;

}


int main(){
	char s2[4] = "Ola";
	char s1 = " Gente";
	char *s = strcat(s1,s2);
	int i = 0;
	while(i < length (s1)){
		printf("%c", *(s+i));
		i++;
	}
}
