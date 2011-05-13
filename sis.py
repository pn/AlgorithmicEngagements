#!/usr/bin/env python
import sys
k = int(raw_input())
#for i in xrange(k):
#	print([int(j) for j in range(1, i+2)])
s = 0
p = 5
while p <= k:
	d = k // p
	r = k % p
	s += (r+1)*d + p*(d*(d-1))/2
	p *= 5
sys.stdout.write(str(s))
#print s
