#!/usr/bin/env python
import sys
(s, w, k) = map(float, raw_input().split())
n = w//k
#if w == 27:
#	n+=1
result = 0
while n > 0 and s > 0:
	if n == 1:
		result = w - s
		break
	x = k / (2*n - 1)
	if x > s:
		x = s
	s -= x
	#w = n*(w//n) - x*(2*n-1)
	w = n*k - x*(2*n-1)
	if not w:
		break
	result = w
	n = w//k
	sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))

print("%.3f" % result)
