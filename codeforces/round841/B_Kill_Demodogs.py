
t = 0
t = input()
t = int(t)
modc = 1000000007
while t != 0 :
    n = 0
    n = input()
    n = int(n)
    sol = n * (n + 1) * (4 * n - 1) * 2022 // 6 % modc
    sol = int(sol)
    print(sol)
    t -= 1