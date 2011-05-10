#include <stdio.h>
unsigned long a[500000][2];
int main(int argc, char *argv[])
{
	unsigned long s, i, x, n, left_level, diff;
	unsigned long left = 0, right = 0, failed_join = 1, result = 0;
	x = scanf("%ld\n", &n);
	x = scanf("%ld %ld\n", &a[0][0], &a[0][1]);
	for(i = 1; i < n; i++)
	{
		x = scanf("%ld %ld\n", &a[i][0], &a[i][1]);
		if(failed_join)
		{
			left = a[i-1][1];
			right = a[i-1][0];
			failed_join = 0;
		}
		left_level = a[i-1][1];
		s = a[i][0] + a[i][1];
		if(left_level < s)
		{
			a[i][0] = left_level;
			a[i][1] = s - a[i][0];
			left ^= right;
			right ^= left;
			left ^= right;
			if(left > a[i][1])
				left = a[i][1];
			result+=1;
		}
		else
		{
			diff = left_level - s;
			if(left >= diff)
			{
				a[i][0] = s;
				a[i][1] = 0;
				left -= diff;
				right += diff;
				left ^= right;
				right ^= left;
				left ^= right;
				left = 0;
				result+=1;
			}
			else
				failed_join = 1;
		}
	}
	printf("%ld\n", result);
	return 0;
}
