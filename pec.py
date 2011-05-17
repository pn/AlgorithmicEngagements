#!/usr/bin/env python
import sys
(s, w, k) = map(float, raw_input().split())
sys.stderr.write("%f %f %f\n" % (s, w, k))
n = w//k
result = 0
while s > 0:
	#sys.stderr.write('n: %f s: %f\n' % (n, s))
	if n <= 1:
		result = w - s
		break
	x = k / (2*n - 1)
	#sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))
	if x > s:
		x = s
	k2 = k
	if w % k >= 2*x:
		#sys.stderr.write("%f\n" % (w % k))
		n+=1
		k2 = w/n
	w = n*k2 - x*(2*n-1)
	#sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))
	s -= x
	if not w:
		break
	result = w
	#sys.stderr.write('w: %f x: %f s: %f n: %f\n' % (w, x, s, n))
	n -= 1
if result < 0:
	print("NIE")
else:
	print("%.3f\n" % result)
