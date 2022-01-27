char *mystrcpy(char dest[], const char source[]) {
        char *r = dest;
        while(*source)
            *dest++ = *source++;
        *dest = 0;

        return r;
}









