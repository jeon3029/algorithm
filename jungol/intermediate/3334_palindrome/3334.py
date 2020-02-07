import math
n = int(input())

ll = []
for i in range(n):
    temp = input()[0:-1]
    ll.append(temp)


def isPalindrome(string):
    first = math.ceil(len(string)/2)
    second = math.floor(len(string)/2)
    if string[0:first] == string[-1:second-1:-1]:
        return True
    else:
        return False


def main():
    global n, ll
    for i in range(n):
        if isPalindrome(ll[i]):
            print("0")
        else:
            check = 0
            a = 0
            b = len(ll[i])-1
            c = 0
            d = 0
            while a <= b:
                if ll[i][a] == ll[i][b]:
                    a += 1
                    b -= 1
                    if a > b:
                        print("1")
                        break
                    continue
                else:
                    if check == 2:
                        print("2")
                        break
                    elif check == 0:
                        c = a
                        d = b
                        a += 1
                        check = 1
                    elif check == 1:
                        a = c
                        b = d-1
                        check = 2


if __name__ == "__main__":
    main()
