#!/usr/bin/env python
n = int(raw_input())
a = []
for i in xrange(n):
	a.append(map(int, raw_input().split()))
result = 0
failed_join = True
for i in xrange(1, len(a)):
	if failed_join:
		left = a[i-1][1]
		right = a[i-1][0]
		failed_join = False

	left_level = a[i-1][1]
	s = a[i][0] + a[i][1]
	if left_level < s:
		a[i][0] = left_level
		a[i][1] = s - a[i][0]
		left, right = right, left
		left = min(left, a[i][1])
		result+=1
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
		else:
			failed_join = True

print(result)
