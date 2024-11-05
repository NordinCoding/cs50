from cs50 import get_string

credit = get_string("Number: ")
creditLen = len(credit)
sum1 = []
sum2 = []

if (creditLen % 2) == 0:
    for  i in range(creditLen):
        if (i % 2) == 0:
            tmp = int(credit[i]) * 2
            sum1.append(tmp)
        else:
            sum2.append(int(credit[i]))
else:
    for  i in range(creditLen):
        if (i % 2) == 0:
            sum2.append(int(credit[i]))
        else:
            tmp = int(credit[i]) * 2
            sum1.append(tmp)

for i in range(len(sum1)):
    tmp = str(sum1[i])
    if len(tmp) > 1:
        splitList = [int(a) for a in tmp]
        del sum1[i]
        sum1 = sum1 + splitList

print(sum1)
print(sum2)

sumTotal = sum(sum1) + sum(sum2)
print(sumTotal)


checkList = [int(a) for a in str(sumTotal)]
for i in range(len(checkList)):
    if checkList[i] == 0:
        print("AMEX")


