from timeit import Timer

t = Timer('part1.run()', 'import part1')
reps = 10
print "Pure python: %0.1f" %(sum(t.repeat(repeat=reps, number=1)) / reps)

t = Timer('part2.run()', 'import part2')
reps = 10
print "Pure python: %0.1f" %(sum(t.repeat(repeat=reps, number=1)) / reps)
