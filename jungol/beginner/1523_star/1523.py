n, t = map(int,input().split())
def star_1(n):
    for i in range(n):
        for j in range(i+1):
            print("*",end="")
        print()
def star_2(n):
    for i in range(n):
        for j in range(n-i):
            print("*",end="")
        print()
def star_3(n):
    for i in range(n):
        for j in range(n-i-1):
            print(" ",end="")
        for j in range(i*2+1):
            print("*",end="")
        print()
def main():
    #global n,t
    if t==1:
        star_1(n)
    elif t==2:
        star_2(n)
    else:
        star_3(n)

if __name__ == "__main__":
    if n>100 or n<1 or t>3 or t<1:
        print("INPUT ERROR!")
    else:
        main()
