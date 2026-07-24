#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };

struct complex_struct {
	enum coordinate_type t;
	double a, b;    // a为直角坐标下的x/极坐标下的r；b为直角坐标下的y/极坐标下的A
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

/* real_part、img_part、magnitude、angle */
double real_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return z.a;
    }
    else if (z.t == POLAR)
    {
        return z.a * cos(z.b);
    }
}

double img_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return z.b;
    }
    else if (z.t == POLAR)
    {
        return z.a * sin(z.b);
    }
}

double magnitude(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return sqrt(z.a * z.a + z.b * z.b);
    }
    else if (z.t == POLAR)
    {
        return z.a;
    }
}

double angle(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
    {
        return atan2(z.b, z.a);
    }
    else if (z.t == POLAR)
    {
        return z.b;
    }
}

int main(void)
{
    struct complex_struct z1, z2;
    z1 = make_from_real_img(3.0, 4.0);
    z2 = make_from_mag_ang(5.0, atan2(4.0, 3.0));
    printf("real part of z1 is %f\n", real_part(z1));
    printf("image part of z1 is %f\n", img_part(z1));
    printf("magnitude of z1 is %f\n", magnitude(z1));
    printf("angel of z1 is %f\n", angle(z1));
    printf("real part of z2 is %f\n", real_part(z2));
    printf("real part of z2 is %f\n", img_part(z2));
    printf("magnitude of z2 is %f\n", magnitude(z2));
    printf("angel of z2 is %f\n", angle(z2));

    return 0;
}