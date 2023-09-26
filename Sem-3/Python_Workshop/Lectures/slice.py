#Slice the list

x=int(input())
for i in range (0,x):
    a=int(input())
    lst=list(map(int,input().split()))
    b=len(lst)
    
    rev=[]
    for j in range (0,b):
        ele=lst[-j-1]
        rev.append(ele)
        print(rev[j] ,end=' ')
    print()
    
    for k in range (0,b):
        if (k%3==0 and k>0):
            d=lst[k]+3
            print(d,end=' ')
    print()
    
    for l in range (0,b):
        if (l%5==0 and l>0):
            f=lst[l]-7
            print(f,end=' ')
    print()

    count=0
    for m in range (0,b):
        if (m>=3 and m<=7):
            count+=lst[m]
    print(count)

   

    

    
        

    

    
        
        
        
