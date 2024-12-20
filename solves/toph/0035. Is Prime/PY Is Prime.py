N = int(input())
isPrime = True
if N == 0 or N == 1:
    isPrime = False
else:
    for i in range(2, N):
        if N % i == 0:
            isPrime = False

print("Yes" if isPrime else "No")