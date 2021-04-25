N = 0
answer = 0


def back(queens):
    global N
    global answer

    if len(queens) == N:
        answer += 1
        return

    for i in range(N):  # 해당 행의 모든 위치 체크
        # 같은 열 체크
        check = 0
        for j in queens:
            if j == i:
                check = 1
                break
        if check == 1:
            continue

        # 왼쪽 대각선 위 체크
        v = 1
        for j in reversed(queens):
            if i - v >= 0:
                if i - v == j:
                    check = 1
                    break
            else:
                break
            v += 1
        if check == 1:
            continue
        # 오른쪽 대각선 위 체크
        v = 1
        for j in reversed(queens):
            if i + v < N:
                if i + v == j:
                    check = 1
                    break
            else:
                break
            v += 1

        if check == 1:
            continue
        queens.append(i)
        back(queens)
        queens.pop()


def solution(n):
    ll = []  # 각 행별로 놓여진 말들의 위치
    global answer
    global N
    N = n
    back(ll)
    return answer


inp = int(input())
ans = solution(inp)
print(ans)

