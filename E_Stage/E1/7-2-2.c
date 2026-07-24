#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
        return a;
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

struct rational {
    int numerator;      // 分子
    int denominator;    // 分母
};

struct rational make_rational(int x, int y) // r = x / y
{
    struct rational r;
    r.denominator = y / gcd(x, y);   // 对分母约分
    r.numerator   = x / gcd(x, y);   // 对分子约分
    return r;
}

struct rational add_rational(struct rational r1, struct rational r2)
{
    /* x1/y1 + x2/y2 = (x1y2+x2y1)/y1y2 */
    int x1 = r1.numerator;
    int y1 = r1.denominator;
    int x2 = r2.numerator;
    int y2 = r2.denominator;
    int addy = y1 * y2;
    int addx = x1 * y2 + x2 * y1;
    struct rational addresult = make_rational(addx, addy);
    return addresult;
}

struct rational sub_rational(struct rational r1, struct rational r2)
{
    /* x1/y1 - x2/y2 = (x1y2-x2y1)/y1y2 */
    int x1 = r1.numerator;
    int y1 = r1.denominator;
    int x2 = r2.numerator;
    int y2 = r2.denominator;
    int suby = y1 * y2;
    int subx = x1 * y2 - x2 * y1;
    struct rational subresult = make_rational(subx, suby);
    return subresult;
}

struct rational mul_rational(struct rational r1, struct rational r2)
{
    /* x1/y1 * x2/y2 = x1x2/y1y2 */
    int x1 = r1.numerator;
    int y1 = r1.denominator;
    int x2 = r2.numerator;
    int y2 = r2.denominator;
    int muly = y1 * y2;
    int mulx = x1 * x2;
    struct rational mulresult = make_rational(mulx, muly);
    return mulresult;
}

struct rational div_rational(struct rational r1, struct rational r2)
{
    /* x1/y1 ÷ x2/y2 = x1y2/y1x2 */
    int x1 = r1.numerator;
    int y1 = r1.denominator;
    int x2 = r2.numerator;
    int y2 = r2.denominator;
    int divy = y1 * x2;
    int divx = x1 * y2;
    struct rational divresult = make_rational(divx, divy);
    return divresult;
}

void print_rational(struct rational r)
{
    if (r.numerator == 0)
        printf("0\n");
    else if (r.numerator == r.denominator)
        printf("1\n");
    else if (r.numerator == -r.denominator)
        printf("-1\n");
    else if (r.denominator < 0)   // 打印结果的符号统一放在前面
        printf("-%d/%d\n", r.numerator, abs(r.denominator));
    else
        printf("%d/%d\n", r.numerator, r.denominator);
}

int main(void)
{
	struct rational a = make_rational(1, 8);    /* a=1/8 */
	struct rational b = make_rational(-1, 8);   /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}
