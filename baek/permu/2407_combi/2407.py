
a, b = map(int, input().split())

answer = 1;
num = a;
for _ in range(b):
    answer *= num
    num -= 1
num = 1;
for _ in range(b):
    answer //= num
    num+=1
print((int)(round(answer)))
