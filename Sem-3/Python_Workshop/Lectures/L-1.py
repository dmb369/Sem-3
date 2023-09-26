#String Keywords

a=' Hello, World'

print(a[1])
print(len(a))
print('world' in a)
print('no' in a)

if 'high' not in a:
    print('no, "high" is not present')

#Slicing
print(a[3:5])
print(a[:5])
print(a[2:])
print(a[:])

#Negative Indexing
print(a[-5:-2])      #-2 will not be included

#Modify
print(a.upper())
print(a.lower())

#Remove Whitespace
print(a.strip())    #Before and After "" only

#Replace
print(a.replace("H","J"))

#Split
b=a.split(",")
print(b)
print(b[1])

#Concatenate
c='hello'
d='world'
e=c+d
f=c+" "+d
print(e)
print(f)

  #Can't combine strings and numbers

#Format Strings
age=36
year=4
txt="My name is Punith, I am {}. I have worked for {} years."
print(txt.format(age, year))

#EScape Characters
#Use \ character
txt="We are so-called \"Vikings\" from the north."
print(txt)








