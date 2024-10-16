def f(phrase):
    return phrase.lower().replace(" ", "")
def solve():
    n = int(input())
    ans = set()
    for _ in range(n):
        phrase = input().strip()
        temp = f(phrase)
        ans.add(temp)
    
    print(len(ans))

solve()
