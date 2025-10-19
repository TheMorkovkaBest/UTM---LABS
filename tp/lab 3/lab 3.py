import math
import random
import datetime

#1.1
def func1():
    print('Hello World')

func1()
func1()
func1()
#1.2

def summadvuh(a,b):
    return 'summa : '+ str(a+b)

print(summadvuh( int(input('enter a : ')) , int(input('enter b : ')) ) )

#2.1
def maximalnoe(a,b,c):
    return 'maximal : '+str(max(a,b,c))

print(maximalnoe(int(input('enter a : ')),int(input('enter b : ')),int(input('enter c : '))))

#2.2
n = int(input('enter n : '))

x = n
def func2():
    x = n*2
    print('localnaia peremenaia : x = ',x)
func2()
print('globalnaia peremenaia : x = ',x)

#3.1

def factorialfunc(cislo):
    if cislo == 1:
        return 1
    elif cislo < 1:
        return 'incorect factorial'
    else:
        return cislo*factorialfunc(cislo-1)
print(factorialfunc(int(input('enter n : '))))

#3.2
def summapervih(cislo):
    if cislo == 1:
        return 1
    elif cislo < 1:
        return 'incorect summa'
    else:
        return cislo+summapervih(cislo-1)
print(summapervih(int(input('enter a : '))))

#4.1
a=int(input('enter a : '))
x=int(input('enter x : '))
y=int(input('enter y : '))

print(math.sqrt(a))
print(math.pi)
print(math.pow(x,y))

#4.2
def brosok():
    for i in range(1,int(input('enter kol-vo broskov kubica '))):
        print('brosok : ',i,'vipalo : ', random.randint(1,6))

brosok()
#4.3
print(datetime.datetime.now())

#5
while 1:
    i = int(input('vividenie factoriala - 1, maximum iz 3 - 2,'
                  ' simuliatia broska - 3 , data ceichas -4 , exit - 5'))
    if i == 1:
        print(factorialfunc(int(input('enter n : '))))
    if i == 2:
        print(maximalnoe(int(input('enter a : ')), int(input('enter b : ')), int(input('enter c : '))))
    if i == 3:
        brosok()
    if i == 4:
        print(datetime.datetime.now())
    if i == 5:
        break
