#Star Pattern

x=int(input())
for i in range (0,x):
    a=int(input())
    for j in range (1,a+1):
        count=0
        for k in range(j,a+1):
            count+=1
            if (count%5==0):
                print("#",end="")
            else:
                print("*",end="")

        print()
