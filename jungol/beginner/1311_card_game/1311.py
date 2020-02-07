deck = []
for i in range(5):
    a,b = (map(str,input().split()))
    deck.append([a,int(b)])
deck.sort(key=lambda x:x[1])

def all_same_color():
    temp = deck[0][0]
    for i in range(1,5):
        if temp != deck[i][0]:
            return False
    return True
def straight():
    temp = deck[0][1]
    for i in range(1,5):
        if deck[i][1] != temp+1:
            return False
        temp += 1
    return True
def four_card():
    temp_list =[0]*5
    for i in range(5):
        for j in range(5):
            if deck[i][1] == deck[j][1]:
                temp_list[i] +=1
    if max(temp_list) == 4:
        return True
    else: 
        return False
def full_house():
    temp_list =[0]*5
    three_card = 0
    two_card = 0
    for i in range(5):
        for j in range(5):
            if deck[i][1] == deck[j][1]:
                temp_list[i] +=1
    for i in range(5):
        if temp_list[i] == 3:
            three_card = deck[i][1]
        elif temp_list[i] ==2:
            two_card = deck[i][1]
    temp_list.sort()
    if temp_list == [2,2,3,3,3]:
        return 700 + three_card*10 + two_card
    else:
        return False
def triple():
    temp_list =[0]*5
    three_card = 0
    for i in range(5):
        for j in range(5):
            if deck[i][1] == deck[j][1]:
                temp_list[i] +=1
    for i in range(5):
        if temp_list[i] == 3:
            three_card = deck[i][1]
    if three_card != 0:
        return 400 + three_card
    else:
        return False
def two_twopair():
    temp_list =[0]*5
    two_card = [0,0]
    for i in range(5):
        for j in range(5):
            if deck[i][1] == deck[j][1]:
                temp_list[i] +=1
    temp_list.sort()
    if temp_list == [1,2,2,2,2]:
        temp = [0]*5
        for i in range(5):
            for j in range(5):
                if deck[i][1] == deck[j][1]:
                    temp[i] += 1
        for i in range(5):
            for j in range(5):
                if i!=j and temp[i]==2 and temp[j]==2 and deck[i][1] != deck[j][1]:
                    two_card = [deck[i][1],deck[j][1]]
                    break
            if two_card !=[0,0] :
                break
        two_card.sort()
        return 300 + two_card[1]*10 + two_card[0]
    return False
def two_pair():
    temp_list =[0]*5
    two_card = [0,0]
    for i in range(5):
        for j in range(5):
            if deck[i][1] == deck[j][1]:
                temp_list[i] +=1
    temp_list.sort()
    if temp_list ==[1,1,1,2,2]:
        for i in range(5):
            for j in range(5):
                if i!=j and deck[i][1] == deck[j][1]:
                    return 200 + deck[i][1]
    return False
def main():
    if all_same_color():
        if straight():
            return 900 + deck[4][1]
        else:
            return 600 + deck[4][1]
    if four_card():
        for i in range(5):
            for j in range(5):
                if i!=j and deck[i][1] == deck[j][1]:
                    return 800 + deck[i][1]
    if full_house():
        return full_house()
    if straight():
        return 500 + deck[4][1]
    if triple():
        return triple()
    if two_twopair():
        return two_twopair()
    if two_pair():
        return two_pair()
    return 100 + deck[4][1]
if __name__ =="__main__":
    print(main())
