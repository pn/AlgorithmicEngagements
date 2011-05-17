#include <stdlib.h>
#include <stdio.h>
#define MAX 1000000000000000000
#define MAX2 1000000000
typedef unsigned long long ull;
typedef struct bigint
{
	ull a;
	ull b;
} BigInt;
void bigprint(BigInt s)
{
	if(s.a > 0)
		printf("%lld%018lld\n", s.a, s.b);
	else
		printf("%lld\n", s.b);
}
BigInt bigassign(ull x, ull y)
{
	BigInt result;
	result.a = x;
	result.b = y;
	return result;
}
BigInt tobigint(ull x)
{
	BigInt result;
	result.a = 0;
	result.b = x;
	return result;
}
BigInt bigmult(BigInt x, BigInt y)
{
	BigInt result;
	ull xb1 = x.b / (MAX2);
	ull yb1 = y.b / (MAX2);
	ull xb2 = x.b % (MAX2);
	ull yb2 = y.b % (MAX2);
	result.a = x.a * y.a + xb1 * yb1 + x.a * y.b + x.b * y.a;
	ull r = xb1 * yb2 + yb1 * xb2;
	result.a += r / MAX2;
	result.b = xb2 * yb2;
	result.b += (r % MAX2) * MAX2;
	result.a += result.b / MAX;
	result.b %= MAX;
	return result;
}
BigInt bigaddull(BigInt x, ull y)
{
	if(y < 0 && (-y > x.b))
	{
		x.a--;
		x.b += MAX;
	}
	x.b += y;
	x.a += x.b / MAX;
	x.b %= MAX;
	return x;
}
BigInt bigadd(BigInt x, BigInt y)
{
	BigInt result;
	result.a = x.a + y.a;
	result.b = x.b + y.b;
	if(result.b >= MAX)
	{
		result.b %= MAX;
		result.a += 1;
	}
	return result;
}
BigInt bigdiv2(BigInt x)
{
	if(x.a % 2)
	{
		x.b += MAX/2;
	}
	x.a /= 2;
	if(x.b >= MAX)
	{
		x.b %= MAX;
		x.a += 1;
	}
	return x;
}
int main(int argc, char* argv[])
{
	ull k;
	scanf("%lld", &k);
	BigInt s = bigassign(0, 0);
	ull p = 5, d, r;
	while(p <= k)
	{
		d = k / p;
		r = k % p;
		ull d1 = d;
		ull d2 = d-1;
		if(d1 % 2 == 0)
			d1 /= 2;
		else
			d2 /= 2;
		s = bigadd(s, bigaddull((bigmult(tobigint(p), bigmult(tobigint(d1), tobigint(d2)))), (r+1)*d));
		p *= 5;
	}
	bigprint(s);
	return 0;
}
