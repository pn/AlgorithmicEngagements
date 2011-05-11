#!/usr/bin/env python
import sys
(s, w, k) = map(float, raw_input().split())
sys.stderr.write("%f %f %f\n" % (s, w, k))
n = w//k
result = 0
while n > 0 and s > 0:
	if n == 1:
		result = w - s
		break
	x = k / (2*n - 1)
	sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))
	if x > s:
		x = s
	k2 = k
	if w % k >= 2*x:
		sys.stderr.write("%f\n" % (w % k))
		n+=1
		k2 = w/n
	w = n*k2 - x*(2*n-1)
	sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))
	s -= x
	if not w:
		break
	result = w
	n = w//k
	sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))

print("%.3f" % result)
