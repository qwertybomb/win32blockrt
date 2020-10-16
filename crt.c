void *memset(void *s, int c, size_t n) 
{
	char *s2 = (char *) s;
	while (n--) *s2++ = c;
	return s;
}

void *memcpy(void *d, const void *s, size_t n) 
{
	char *s2 = (char *) s, *d2 = (char *) d;
	while (n--) *d2++ = *s2++;
	return d;
}

size_t strlen(const char *s) 
{
	size_t c = 0;
	for (; *s; s++) c++;
	return c;
}

void *memmove(void *d, const void *s, size_t n) 
{
	char *s2 = (char *) s, *d2 = (char *) d;
	if (d2 < s2) { while (n--) *d2++ = *s2++; return d; }
	s2 += n, d2 += n;
	while (n--) *(--d2) = *(--s2);
	return d;
}

void *malloc(size_t size) 
{
	return HeapAlloc(GetProcessHeap(), 0, size);
}

void free(void *pointer) 
{
	HeapFree(GetProcessHeap(), 0, pointer);
}

/* from https://www.codeproject.com/articles/15156/tiny-c-runtime-library */
int vprintf(const char *fmt, va_list args)
{
    char bfr[2048];                // ugly... but this whole idea of replacing
                                   // the CRT could be called ugly too!
    int ret = wvsprintf(bfr, fmt, args);

    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), bfr, ret, NULL, NULL);   // fwrite takes care of CRLF translation
    return ret;
}


/* from https://www.codeproject.com/articles/15156/tiny-c-runtime-library */
int sprintf(char *bfr, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int ret = wvsprintf(bfr, fmt, args);
    va_end(args);
    return ret;
}

int printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}

int puts(const char *str)
{
	int ret = lstrlenA(str);
    WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), str, ret, NULL, NULL);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, NULL, NULL);
	return ret + 1;
}
