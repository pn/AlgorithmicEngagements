#!/usr/bin/env python
t = int(raw_input())
for case in xrange(t):
	result = 'NIE'
	(s, k, n) = map(int, raw_input().split())
	p = map(int, raw_input().split())
	sums = [p[0]] # end point
	for i in xrange(1, len(p)):
		sums.append(p[i]+sums[i-1])
	width = sums[n-1]
	if width % k > 0:
		if n % 2 == 0:
			p[n-1] += k - (width % k)
			sums[n-1] += k - (width % k)
		else:
			p.append(k - (width % k))
			sums.append(p[n] + sums[n-1])
			n+=1

	m = [[0,k]]
	mtmp = []
	for last in xrange(0, sums[n-1], k): # loop through steps
		#i = 1 # start on black
		save = 0
		savei = 1
		for i in range(savei, n, 2): # loop through black
			if p[i] >= s: # foot fits
				c = [sums[i-1], sums[i-1]+p[i]]
				if last + k <= c[0]:
					savei = i
					break
				if m[save][0] + last > c[1]:
					continue
				for ipart in xrange(save, len(m)):
					part = [m[ipart][0] + last, m[ipart][1]]
					if part[0] >= c[1]:
						save = ipart
						break
					elif part[0] + part[1] > c[0]:
						x = max(part[0], c[0]) - last
						tmp = [x, min(part[0]+part[1], c[1])-(x + last)]
						if tmp[1] >= s: # foot fits
							mtmp.append(tmp)
		m = mtmp
		if not mtmp:
			break
		mtmp = []
	else:
		result = 'TAK'
		
	print("%s" % result)
