#include <stdio.h>
#include <math.h>

struct complex_struct {     // 以直角坐标存储, z=x+iy
	double x, y;
};

double real_part(struct complex_struct z)
{
	return z.x;
}

double img_part(struct complex_struct z)
{
	return z.y;
}

double magnitude(struct complex_struct z)   // 返回幅值
{
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)       // 返回幅角
{
	return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)    // 根据传入的直角坐标返回复数变量
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)     // 根据传入的极坐标返回复数变量
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

void complex_print(struct complex_struct z)
{
    if (real_part(z) == 0 && img_part(z) == 0)
    {
        printf("The number is 0.\n");
    }
    else if (real_part(z) == 0)
    {
        printf("%fi\n", z.y);
    }
    else if (img_part(z) == 0)
    {
        printf("%f\n", z.x);
    }
    else
    {
        if (img_part(z) > 0)
        {
            printf("%f+%fi\n", z.x, z.y);
        }
        else
        {
            printf("%f%fi\n", z.x, z.y);
        }
    }
}

int main()
{
    struct complex_struct z1, z2;
    z1.x = 3.0;
    z1.y = -4.0;
    z2.x = -1.0;
    z2.y = 1.0;
    printf("z1 = ");   complex_print(z1);
    printf("real part of z1 is %f\t", real_part(z1));
    printf("imagine part of z1 is %f\n", img_part(z1));
    printf("magitude of z1 is %f\t", magnitude(z1));
    printf("angle of z1 is %f\n", angle(z1));
    printf("z2 = ");    complex_print(z2);
    printf("real part of z2 is %f\t", real_part(z2));
    printf("imagine part of z2 is %f\n", img_part(z2));
    printf("magitude of z2 is %f\t", magnitude(z2));
    printf("angle of z2 is %f\n\n", angle(z2));

    double x3 = 3.0;
    double y3 = -4.0;
    double r4 = 1.414214;
    double A4 = 2.356194;
    struct complex_struct z3 = make_from_real_img(x3, y3);
    struct complex_struct z4 = make_from_mag_ang(r4, A4);
    printf("z3 = ");    complex_print(z3);
    printf("real part of z3 is %f\t", real_part(z3));
    printf("imagine part of z3 is %f\n", img_part(z3));
    printf("magitude of z3 is %f\t", magnitude(z3));
    printf("angle of z3 is %f\n", angle(z3));
    printf("z4 = ");    complex_print(z4);
    printf("real part of z4 is %f\t", real_part(z4));
    printf("imagine part of z4 is %f\n", img_part(z4));
    printf("magitude of z4 is %f\t", magnitude(z4));
    printf("angle of z4 is %f\n\n", angle(z4));

    struct complex_struct z1addz2 = add_complex(z1, z2);
    struct complex_struct z1subz2 = sub_complex(z1, z2);
    struct complex_struct z1mulz2 = mul_complex(z1, z2);
    struct complex_struct z1divz2 = div_complex(z1, z2);
    printf("z1addz2 = ");   complex_print(z1addz2);
    printf("z1subz2 = ");   complex_print(z1subz2);
    printf("z1mulz2 = ");   complex_print(z1mulz2);
    printf("z1divz2 = ");   complex_print(z1divz2);

    return 0;
}