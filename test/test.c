#include <stdio.h>

int main(void)
{
	__block int i = 0;
	void(^hello_world)(void) = ^(void) 
	{ 
		printf("Hello, World!\n");
		printf("i = %d", i);
	};

	i += 2;
	hello_world();
}
