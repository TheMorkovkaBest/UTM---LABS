
#N1
numbers = [0,0]
numbers[0] = input('enter number a:')
numbers[1] = input('enter number b:')
print('a+b=',numbers[0] + numbers[1] , ' a*b=',float(numbers[0]) * float(numbers[1]))
print('max =',max(numbers[0],numbers[1]))
#-------------------
number = input('enter number a:')
if int(number)%2:
    print('necetnoe cislo')
else:
    print('cetnoe cislo')
#-------------------
n = input('enter number n:')
for n in range(1,int(n)+1):
    print(n)
#----------------------
n = input('enter number n:')
i = 1
sum = 0
while i<=int(n):
    sum+=int(i)
    i+=1
print(sum)
#---------------------
#2
def yray1():
    print('ax+b=0')
    a = float(input('enter number a:'))
    b = float(input('enter number b:'))
    if a:
        print('x= '+str(-b/a))
    else:
        print('x='+str(b))
#------------------------------
def yray2():
    print('ax²+bx+c=0')
    a = int(input('enter number a:'))
    b = int(input('enter number b:'))
    c = int(input('enter number c:'))
    det = 0

    if not a:
        print('x= '+str(-c/b))
    else:
        det = float((b*b - 4*a*c))
        print('D =',det)
        if det>0:
            det=det**(1/2)
            print('x1 =',b-det/2*a,'  x2 =',b+det/2*a)
        elif det == 0:
            print('x1 =',b/2*a)
        elif det < 0:
            det = -det
            det = det ** (1 / 2)
            print('x1 =', (b-det/2*a),'i','  x2 =',(b+det/2*a),'i')
#------------------
yray1()
yray2()
#------------------
#3
while 1:
    choice = input('enter exit or 1 for yrovnenie pervoi stepeni or 2 for yrovnenie vtoroi stepeni :')
    if choice == 'exit':
        break
    elif choice == '1':
        yray1()
    elif choice == '2':
        yray2()
    else:
        continue

