n = int(input())
k = int(input()) - 1
a = [0 for _ in range(1900)]
a[0] = 1
a[1] = k
i = 2
while i<=n :
	a[i] = k*(a[i-1]+a[i-2])
	i += 1
print(a[n])