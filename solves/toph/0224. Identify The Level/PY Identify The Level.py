t=int(input())
for x in range(t):
    n=int(input())
    cnt = 0
    while n >= 1:
        cnt+=1
        n /=2

    print("Case {}: {}".format(x+1, cnt))