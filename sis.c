#include <stdlib.h>
#include <stdio.h>
#define ull unsigned long long
int main(int argc, char* argv[])
{
	ull k;
	scanf("%lld", &k);
	ull s = 0, p = 5, d, r;
	while(p <= k)
	{
		d = k / p;
		r = k % p;
		s += (r+1)*d + p*(d*(d-1))/2;
		p *= 5;
	}
	printf("%lld\n", s);
	return 0;
}
