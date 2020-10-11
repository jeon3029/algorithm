N,M,H = map(int,input().split())
ladder = [[0 for x in range(N)] for y in range(H)]

for _ in range(M):
    a,b = map(int,input().split())
    ladder[a-1][b-1] = 1

def print_ladder():
    for i in range(H):
        for j in range(N-1):
            print(ladder[i][j],end=" ")
        print()

def check(): 
    for j in range(N): 
        pos = j 
        for i in range(H): 
            if ladder[i][pos] == 1: 
                pos += 1 
            elif pos > 0 and ladder[i][pos-1]: 
                pos -= 1 
        if j != pos: 
            return False 
    return True
answer = 4
def brute(cnt,y,x):
    global answer
    if answer<=cnt:
        return
    elif check():
        if answer > cnt:
            answer = cnt
        return
    elif cnt == 3:
        return

    for i in range(y,H):
        if i==y:
            pos = x
        else:
            pos = 0
        for j in range(pos,N-1):
            if ladder[i][j]==0 and ladder[i][j+1]==0:
                ladder[i][j] = 1
                brute(cnt+1,i,j+2)
                ladder[i][j] = 0

brute(0,0,0)
if answer == 4:
    print(-1)
else:
    print(answer)


