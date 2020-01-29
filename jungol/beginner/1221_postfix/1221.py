n = int(input())
ll = list(map(str,input().split()))
stack = []
def main():
    for i in ll:
        if i.isdigit():
            stack.append(i)
        else:
            a = int(stack.pop())
            b = int(stack.pop())
            if i == "*":
                stack.append(a*b)
            elif i == "/":
                stack.append(b//a)
            elif i == "+":
                stack.append(a+b)
            elif i == "-":
                stack.append(b-a)
    return stack.pop()
if __name__ == "__main__":
    print(main())
