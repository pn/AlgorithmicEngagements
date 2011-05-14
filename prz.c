#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
#define MAX 500000
#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
ull p[MAX+1], sums[MAX+2];
ull *m1, *m2, *n1, *n2;
int main(int argc, char* argv[])
{
	int cases, z;
	m1 = malloc(sizeof(int)*MAX);
	m2 = malloc(sizeof(int)*MAX);
	n1 = malloc(sizeof(int)*MAX);
	n2 = malloc(sizeof(int)*MAX);
	z = scanf("%d\n", &cases);
	while(cases--)
	{
		ull s, k, n, i, width;
		z = scanf("%lld %lld %lld\n", &s, &k, &n);
		z = scanf("%lld", &p[0]);
		sums[0] = p[0];
		for(i = 1; i < n; i++)
		{
			z = scanf("%lld", &p[i]);
			sums[i] = p[i]+sums[i-1];
		}
		width = sums[n-1];
		if(width % k > 0)
		{
			if(n % 2 == 0)
			{
				p[n-1] += k - (width % k);
				sums[n-1] += k - (width % k);
			}
			else
			{
				p[n] = (k - (width % k));
				sums[n+1] = (p[n] + sums[n-1]);
				n += 1;
			}
		}

		ull **m1tmp = &m1;
		ull **m2tmp = &m2;
		ull **n1tmp = &n1;
		ull **n2tmp = &n2;
		(*m1tmp)[0] = 0;
		(*m2tmp)[0] = k;
		ull mnum = 1, mtmpnum = 0, last, failed = 0;

		for(last = 0; last < sums[n-1]; last+=k)
		{
			ull save = 0, savei = 1, i;
			for(i = savei; i < n; i+=2)
			{
				if(p[i] >= s)
				{
					ull c[2] = {sums[i-1], sums[i-1]+p[i]};
					if(last + k <= c[0])
					{
						savei = i;
						break;
					}
					if((*m1tmp)[save] + last > c[1])
					{
						continue;
					}
					ull ipart;
					for(ipart = save; ipart < mnum; ipart++)
					{
						ull part[2] = {(*m1tmp)[ipart] + last, (*m2tmp)[ipart]};
						if(part[0] >= c[1])
						{
							save = ipart;
							break;
						}
						else if(part[0] + part[1] > c[0])
						{
							ull x = max(part[0], c[0]) - last;
							ull y = min(part[0]+part[1], c[1])-(x + last);
							if(y >= s)
							{
								(*n1tmp)[mtmpnum] = x;
								(*n2tmp)[mtmpnum++] = y;
							}
						}
					}
				}
			}
			ull **x1 = m1tmp;
			ull **x2 = m1tmp;
			m1tmp = n1tmp;
			m2tmp = n2tmp;
			n1tmp = x1;
			n2tmp = x2;
			mnum = mtmpnum;
			if(mtmpnum == 0)
			{
				failed = 1;
				break;
			}
			mtmpnum = 0;
		}
		if(failed == 1)
		{
			printf("NIE\n");
			continue;
		}

		printf("TAK\n");
	}
	return 0;
}
		
