tc = int(input())

for i in range(tc):
	s = input().strip()
	a = s.replace('x', '1').replace('X', '0');
	b = s.replace('x', '0').replace('X', '1');
	if(eval(a) == eval(b)):
		print('Case #'+str(i+1)+': 0')
	else:
		print('Case #'+str(i+1)+': 1')
