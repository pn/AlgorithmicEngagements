#!/usr/bin/env python
import sys
L = 10**9
n = int(raw_input())
a = []
for i in xrange(n):
	a.append(map(int, raw_input().split()))
left = a[0][1]
right = a[0][0]
result = 0
for i in xrange(1, len(a)):
	left_level = a[i-1][1]
	s = a[i][0] + a[i][1]
	if left_level < s:
		a[i][0] = left_level
		a[i][1] = s - a[i][0]
		left, right = right, left
		left = min(left, a[i][1])
		result+=1
		sys.stderr.write('right %d\n' % result)
	else:
		diff = left_level - s
		if left >= diff:
			a[i][0] = s
			a[i][1] = 0
			left -= diff
			right += diff
			left, right = right, left
			left = 0
			result+=1
			sys.stderr.write('left %d\n' % result)

print(result)
