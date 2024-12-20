S = str(input())
result = ""
for c in S.split(" "):
    if c.upper() != c:
        result += c + " "

print(result.strip())