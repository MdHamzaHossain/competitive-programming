N, A, B = map(int, input().split(" "))
arr = input().split(" ")
r = 0
for a in arr[A:B+1]:
   r = r + int(a)
print(r)
