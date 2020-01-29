n = int(input())
ll = [[0]*n for i in range(n)]
direction = ((0,1),(1,0),(0,-1),(-1,0))
def main():
    cnt = 1
    cur_direction = 0
    cur_x = 0
    cur_y = 0
    check = float(n)
    while int(check)!=0:
        for i in range(int(check)):
            ll[cur_x][cur_y] = cnt
            if i == int(check)-1:
                cur_direction +=1
            cur_x += direction[cur_direction%4][0]
            cur_y += direction[cur_direction%4][1]
            cnt += 1
        check -= 0.5
    ## print square
    for i in range(n):
        for j in range(n):
            print(ll[i][j],end=" ")
        print()



if __name__ == "__main__":
    main()


