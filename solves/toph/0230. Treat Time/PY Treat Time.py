a, b, c = map(int, input().split(" "))
res = False
if b <= a:
    res = 0
elif b > a and c > a: 
    res = 0
elif min(b,c) == c:
    res = 1
print("Ice-cream" if res else "Chocolate")