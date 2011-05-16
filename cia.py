#!/usr/bin/env python
def wariancja(n, k):
	result = 1
	r = n
	p = 1
	while r > max(k, n-k):
		result *= r
		result /= p
		r -= 1
		p += 1
	return result
def ciag(a, b, p, q):
	c = range(p)
	c.append(len(a)-1)
	i = p-1
	while c[i] + 1 == c[i+1]:
		i -= 1
	#i = 1
	#while i <= p:
	#	j = i
	#	while j > 0 and (c[j] < c[j+1] or j == p - 1):
	#		j -= 1
	#	while c[i] < len[a] - 1:
	#		c[i] += 1

(n, p, q) = map(int, raw_input().split())
a = map(int, raw_input().split())
for start in xrange(len(a)-1):
	b = [start]
	for i in xrange(1, len(a)):
		if a[i] < a[b[-1]]:
			b.append(i)
	print a, b
	if len(b) >= p:
		break
for case in xrange(q):
	result = 0
	question = int(raw_input())
	if len(b) < p:
		result = -1
	print result
	
