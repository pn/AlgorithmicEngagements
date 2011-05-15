#!/usr/bin/env python
k = int(raw_input())
s = 0
p = 5
while p <= k:
	d = k // p
	r = k % p
	s += (r+1)*d + p*(d*(d-1))/2
	p *= 5
print s
