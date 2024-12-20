N = int(input())
A = map(int, input().split())
biggest = 0
for a in A:
    if a > biggest:
        biggest = a
print(biggest)