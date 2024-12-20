N = int(input())
S = str(input())
abc = "abcdefghijklmnopqrstuvwxyz"

s = ""
for c in S:
    if c not in abc:
        s += c
        continue

    s += abc[abc.index(c)-N]
print(s)
# print(N[0].upper() + N[1:].replace("s", "$").replace("o", "()").replace("i", "!") + ".")