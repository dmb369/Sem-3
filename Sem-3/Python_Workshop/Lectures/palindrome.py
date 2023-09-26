#Palindrome Or Not

def reverse(s):
    s_reversed =""
    for ch in s:
        s_reversed = ch + s_reversed
    return s_reversed


def is_palindrome_v1(s):
    reverse_s = reverse(s)
    b=len(s)
    g=1
    for j in range (0,b):
        c=ord(s[j])
        d=ord(reverse_s[j])
        e=min(c,d)
        f=max(c,d)
        if ((f-e)==32 or (f-e)==0):
            continue
        else:
            g=0
            break
    return g

x=int(input())
for i in range (0,x):
    a=str(input())
    k=is_palindrome_v1(a)
    if (k==1):
        print("It is a palindrome")
    else:
        print("It is not a palindrome")
        
    
