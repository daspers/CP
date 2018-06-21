def multiply(a, b, m) :
	res = [ [0 for _ in range(2)] for _ in range(2)]
	for i in range(2) :
		for j in range(2) :
			for k in range(2) :
				res[i][j] += a[i][k]*b[k][j]
				res[i][j] %= m
	return res 

def new(a) :
	res = [ [0 for _ in range(2)] for _ in range(2)]
	for i in range(2) :
		for j in range(2) :
			res[i][j] = a[i][j]
	return res
	
n = int(input())
k = int(input()) - 1
m = int(input())
	
mat = []
a = [[0 for _ in range(2)] for _ in range(2)]
a[0][0] = a[0][1] = k
a[1][0] = 1
a[1][1] = 0
mat.append(a);
for i in range(63) :
	a = multiply(a, a, m)
	mat.append(new(a))

ans = [[0 for _ in range(2)] for _ in range(2)]
ans[0][0] = ans[1][1] = 1
i = 0
while n>0 :
	if n%2==1 :
		ans = multiply(ans, mat[i], m)
	n >>= 1
	i += 1
print(ans[0][0])