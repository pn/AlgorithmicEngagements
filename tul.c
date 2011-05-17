#include <stdio.h>
#define MAXTUL 15000
#define BITSINLONG (sizeof(long)*8)

unsigned long tul[MAXTUL / BITSINLONG + 1];
int main(int argc, char *argv[])
{
	unsigned long a, b, n, d, result = MAXTUL;
	fscanf(stdin, "%ld\n", &n);
	while (n--) {
		fscanf(stdin, "%ld", &d);
		a = d / BITSINLONG;
		b = d % BITSINLONG;
		if (!(tul[a] & 1ul << b)) {
			tul[a] |= 1ul << b;
			result--;
		}
	}
	printf("%ld\n", result);
	return 0;
}
