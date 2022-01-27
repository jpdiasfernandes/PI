int strcmp(char s1[], char s2[]){
	int r1 = 0; r2 = 0;
	
	while(*s1){r1++;s1++;}
	while(*s2){r2++;s2++;}
	
	if(r1 == r2) return 0;
	else if (r1>r2) return 1;
	else return (-1);
}
