


#include <stdio.h>


int 			main()
{
	int n = 0xffaabb;
	int r;
	int g;
	int b;


	r = (unsigned int)n >> 16;
	g = (unsigned int)(n << 16) >> 24;
	b = (unsigned int)(n << 24) >> 24;
	printf("r = %x g = %x b = %x\n", r, g, b);





	return (0);
}
