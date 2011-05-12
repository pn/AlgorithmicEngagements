#!/usr/bin/env python
import sys
t = int(raw_input())
for case in xrange(t):
	sys.stderr.write('case: %d\n' % case)
	result = 'NIE'
	(s, k, n) = map(int, raw_input().split())
	p = map(int, raw_input().split())
	sums = [p[0]] # end point
	for i in xrange(1, len(p)):
		sums.append(p[i]+sums[i-1])
	sys.stderr.write(str(p) + str(sums) + "\n")

	m = [[0,k]]
	mtmp = []
	for last in range(0, sums[-1], k):
		#i = 1 # start on black
		save = 0
		for i in range(1, len(p), 2): # loop through black
			if p[i] >= s: # foot fits
				c = [sums[i-1], sums[i-1]+p[i]]
				sys.stderr.write('c [%s] \n' % ','.join(map(str, c)))
				if m[save][0] + last > c[1]:
					sys.stderr.write('continuing\n')
					i+=2
					continue
				for ipart in xrange(save, len(m)):
					part = [m[ipart][0] + last, m[ipart][1]]
					sys.stderr.write('part %s last %d\n' % (str(part), int(last)))
					if part[0] + part[1] > c[0] and part[0] < c[1]:
						tmp = [max(part[0], c[0]) - last, min(part[0]+part[1], c[1])-max(part[0], c[0])-last]
						if tmp[1] - tmp[0] >= s: # foot fits
							mtmp.append(tmp)
					if part[0] > c[1]:
						save = ipart
						break
		sys.stderr.write('m %s mtmp %s last %d\n' % (str(m), str(mtmp), last))
		m = mtmp
		if not mtmp:
			break
		if m:
			sys.stderr.write("%d\n" % (last + m[-1][0] + m[-1][1]))
		mtmp = []
		
	current_start = -10**9
	current_end = 0
	print("%s" % result)
