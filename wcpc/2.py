MOD = 10**9 + 7
INF = float('inf')
NINF = float('-inf')

def solve(a, b, c, x):
    prefix_sum = [0] + [0] * a
    for i in range(1, a + 1):
        prefix_sum[i] = prefix_sum[i - 1] + x[i - 1]

    ans = NINF
    for i in range(b, c + 1):
        max_sum = prefix_sum[i]
        for j in range(1, a - i + 1):
            max_sum = max(max_sum, prefix_sum[i + j] - prefix_sum[j])
        ans = max(ans, max_sum)

    return ans % MOD

if __name__ == "__main__":
    a, b, c = map(int, input().split())
    x = list(map(int, input().split()))
    result = solve(a, b, c, x)
    print(result)
