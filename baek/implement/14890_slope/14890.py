n,l = map(int,input().split())
data = [[int(x) for x in input().split()] for y in range(n)]

answer = 0
# 가로 판단
def check():
    global answer,data,n,l
    for i in range(n):
        impossible=0
        cur = data[i][0];
        j=1
        pos=-1
        # print(n)
        while j < n : # 1~n-1
            # print(data[i][j],end=" ")
            if cur == data[i][j]:
                pass
            elif cur + 1 == data[i][j]  : ##up
                if j-l<0:
                    impossible=1
                    break
                for k in range(j-l,j):
                    if cur!=data[i][k]:
                        impossible=1
                        break
                if impossible==1 or pos>=j-l:
                    impossible=1
                    break
                else:
                    pos = j-1
                    cur = data[i][j]
            elif  cur - 1 == data[i][j]: #down
                if j+l>n:
                    impossible=1
                    break
                for k in range(j,j+l):
                    if data[i][k] != cur-1:
                        impossible=1
                        break
                if impossible==1 or pos>=j:
                    impossible=1
                    break
                else:
                    pos = j+l-1
                    j+=l-1
                    cur=data[i][j]
            else:
                impossible=1
                break
            j+=1
        if impossible==0:
            # print(i)
            answer+=1

# 전치
check()
data = [list(x) for x in zip(*data)]
# print()
check()

print(answer)

