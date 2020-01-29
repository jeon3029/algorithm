possible = range(111,1000)

n = int(input())
num = []
s = []
b = []
answer = 0
while n:
    n -=1
    x,y,z = map(int,input().split())
    num.append(x)
    s.append(y)
    b.append(z)

for i in possible:
    check = 0
    temp = i
    third = temp % 10
    temp //=10
    second = temp % 10
    temp //=10
    first = temp %10
    
    if first==0 or second==0 or third ==0:
        continue
    if first== second or first == third or second == third:
        continue
    for index in range(len(num)):
        ball = 0
        strike = 0
        
        temp = num[index]
        num_third = temp % 10
        temp //=10
        num_second = temp % 10
        temp //=10
        num_first = temp % 10

        if third == num_third:
            strike+=1
        elif third == num_second:
            ball +=1
        elif third == num_first:
            ball +=1

        if second == num_second:
            strike+=1
        elif second == num_first:
            ball +=1
        elif second == num_third:
            ball +=1

        if first == num_first:
            strike+=1
        elif first == num_second:
            ball +=1
        elif first == num_third:
            ball +=1

        if s[index] == strike and b[index] == ball:
            check += 1
        else:
            check = 0
            break

    if check == len(num):
        answer +=1
print(answer)
    
