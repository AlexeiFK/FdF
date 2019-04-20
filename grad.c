








typedef struct			s_spec
{
	float	r;
	float	g;
	float	b;
}				t_spec;






int 		main()
{

	int	color1 = 0xff12aa;
	int	color2 = 0x000000;
	t_spec	spec1;
	t_spec	spec2;

	spec1.r = (color1 & 0xff0000);
	spec1.g = (color1 & 0x00ff00);
	spec1.b = (color1 & 0x0000ff);

	spec2.r = color2 / (16*16*16*16);
	spec2.g = (color2 / (16*16)) % (16*16);
	spec2.b = color2 % (16 * 16);


	printf("%x, %x, %x", (int)spec1.r, (int)spec1.g, (int)spec1.b);



	return (0);
}
