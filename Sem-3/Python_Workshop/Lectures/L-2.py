#Taking input

x=input("Enter your name:")  #input(prompt)
print("Hello " + x)

#OR
#print("Hello" + input("Enter your name:"))

#Variables do not need to be declared of a particular type
x=5
y="Marry"
print(x)
print(y)

x=y
print(x)

#Specification of data type
x=str(3)
y=float(3)

print(x,y)

#Get type of the variable
print(type(x))

#Variables are case sensitive -> a or A

#Assign Multiple Values
x,y,z = "Dev", "Shreyas", "???"
print(x)
print(y)
print(z)

print(z,y,x)

#One value to multiple variables -> a=b=c='Man'

#Unpack a collection
fruits=['at','bat','cat']
x,y,z=fruits
print(x)
print(y)
print(z)


x=5
y="john"
 #print(x+y) Will give any error, diff. data type variables
print(x, y)

#Global / Local Variable
x="awesome"
def myfunc():
    global x      #need to explicitly define 
    x="fantastic"
    print("Python is " +x)

myfunc()
print("Python is " + x)

#Task-1
print("Day 1-Python Print Function")
print("The function is declared like this:")
print('print("What to print")')

#Task-2
print("Day 1 - string manipulation")
print("String concantenation is done with the /'+'/ sign.")
print("e.g. print('hello' + 'world')")
print('("new lines can be created with a backlash on")')

""" this is comment
   written in
   more than just one line """

#if-else
if (5>2):
    print("five is greater than 2!")




