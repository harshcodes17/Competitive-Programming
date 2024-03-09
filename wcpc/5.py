MOD = 10**9 + 7
INF = float('inf')
NINF = float('-inf')

def inp():
    return int(input())

def linp():
    return list(map(int, input().split()))

def solve():
    a, b, c = linp()
    x = linp()
    prefix_sum = [0] * (a + 1)
    for i in range(1, a + 1):
        prefix_sum[i] = prefix_sum[i - 1] + x[i - 1]

    ans = NINF
    for i in range(b, min(c, a) + 1):
        for j in range(a - i + 1):
            ans = max(ans, prefix_sum[j + i] - prefix_sum[j])

    print(ans)

solve()