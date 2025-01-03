n=int(input())
print(( "I can participate in LCPC" if (n < 1582 and n % 4 == 0) or (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)) else "I have to travel back to the past"))