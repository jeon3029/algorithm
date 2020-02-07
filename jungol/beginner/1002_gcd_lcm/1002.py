n = int(input())
ll = []
ll = list(map(int,input().split()))

def gcd(a,b):
    small = int(min(a,b))
    for i in range(small,0,-1):
        if a%i==0 and b%i ==0:
            return i
def lcm(a,b):
    return a*b / gcd(a,b)


def main():
    global n,ll
    GCD = ll[0]
    LCM = ll[0]
    for i in range(1,len(ll)):
        GCD = gcd(GCD,ll[i])
        LCM = lcm(LCM,ll[i])
    print("{0} {1}".format(GCD,int(LCM)))

if __name__ == "__main__":
    main()

