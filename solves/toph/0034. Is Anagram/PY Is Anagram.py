a = str(input())
b = str(input())
print("Yes" if "".join(sorted(a)) == "".join(sorted(b)) else "No")
