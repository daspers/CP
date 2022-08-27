import math

t = int(input())
for cc in range(t):
    ans = 0
    n = int(input())
    strs = input()
    arr = strs.split()
    a = [int(x) for x in arr]
    for i in range(len(a)):
        if i == 0:
            continue
        l1 = int(math.log10(a[i-1]) + 1)
        l2 = int(math.log10(a[i]) + 1)
        if l2 > l1:
            continue
        if l1 > l2:
            a[i] = a[i]* 10 ** (l1-l2)
        if a[i] > a[i-1]:
            ans += l1-l2
            continue
        diff = a[i-1] - a[i]
        tmp = a[i] + diff + 1
        # print(diff, tmp, a[i], tmp / (10 ** (l1-l2)), a[i] / (10 ** (l1-l2)))
        if tmp // (10 ** (l1-l2)) != a[i] // (10 ** (l1-l2)):
            a[i] *= 10
        else:
            a[i] = tmp
        ans += int(math.log10(a[i]) + 1) - l2
    # for x in a:
    #     print(x)
    print('Case #{0}: {1}'.format(cc+1, ans))
