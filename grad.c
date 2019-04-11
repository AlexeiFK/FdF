








typedef struct			s_spec
{
	int	r;
	int	g;
	int	b;
}				t_spec;






int 		main()
{

	int	color1 = 0xff12aa;
	int	color2 = 0x000000;
	t_spec	spec1;
	t_spec	spec2;

	spec1.r = color1 / (16*16*16*16);
	spec1.g = (color1 / (16*16)) % (16*16);
	spec1.b = color1 % (16 * 16);

	spec2.r = color2 / (16*16*16*16);
	spec2.g = (color2 / (16*16)) % (16*16);
	spec2.b = color2 % (16 * 16);

	if (abs(spec1.r - spec2.r) > abs(spec1.g - spec2.g))
		if (abs(spec1.r - spec2.r) > abs(spec1.b - spec2.b))
			printf("r");
		else
			printf("b");
	else
		if (abs(spec1.g - spec2.g) > abs(spec1.b - spec2.b))
			printf("g");
		else
			printf("b");

	printf("%x, %x, %x", spec1.r, spec1.g, spec1.b);



	return (0);
}
