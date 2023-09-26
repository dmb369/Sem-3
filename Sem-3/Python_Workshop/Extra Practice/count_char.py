#Count the characters in WORDS

x=int(input())

for i in range (0,x):
    a=str(input())
    b=a[1:]
    c=b.split()
    d=[str(len(j)) for j in c]
    ans=",".join(d)
    print(ans)
    
    
  
