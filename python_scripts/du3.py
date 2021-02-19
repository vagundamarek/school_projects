### Math/Triangle Quest ###

for i in range(1,int(input())): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print (i*(10**i - 1) // 9)

### Math/Triangle Quest 2 ###

for i in range(1,int(input())+1): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print (((10**i-1)//9)**2)

### Strings/sWAP cASE ###

print((input().swapcase()))

### Strings/String Split and Join ###

print(input().replace(" ", "-"))

### Strings/What's Your Name? ###

firstName = input()
lastName = input()
print ("Hello", firstName, lastName, end = "! You just delved into python.")

### Strings/Mutations ###

s = input().strip()
position, char = input().split()

print (s[:int(position)]+char+s[(int(position)+1):])
    
### Strings/Find a string ###

s = input()
sub = input()
count = 0
while sub in s:
    count +=1
    s = s[s.find(sub)+1:]
print (count)

### Strings/String Validators ###
s = input()
print (any(k.isalnum() for k in s))
print (any(k.isalpha() for k in s))
print (any(k.isdigit() for k in s))
print (any(k.islower() for k in s))
print (any(k.isupper() for k in s))
    
### Strings/Text Alignment ###

thickness = int(input()) #This must be an odd number
c = 'H'

#Top Cone
for i in range(thickness):
    print((c*i).rjust(thickness-1)+c+(c*i).ljust(thickness-1))

#Top Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))

#Middle Belt
for i in range((thickness+1)//2):
    print((c*thickness*5).center(thickness*6))    

#Bottom Pillars
for i in range(thickness+1):
    print((c*thickness).center(thickness*2)+(c*thickness).center(thickness*6))    

#Bottom Cone
for i in range(thickness):
    print(((c*(thickness-i-1)).rjust(thickness)+c+(c*(thickness-i-1)).ljust(thickness)).rjust(thickness*6))  
    
### Strings/Text Wrap ###

import textwrap
print (textwrap.fill(input(),int(input())))
    
### Strings/Capitalize! ###

import string
print(string.capwords(input(), ' '))

### Numpy/Arrays ###

import numpy
print (numpy.array([float(x) for x in input().strip().split(' ')[::-1]]))

### Numpy/Shape and Reshape ###

import numpy
print (numpy.reshape((numpy.array([int(x) for x in input().strip().split(' ')[:]])),(3,3)))

### Sets/Introduction to Sets ###

n = int(input())
numbers =set(float(x) for x in (list(input().split())))
print (sum(numbers)/len(numbers))

### Sets/Symmetric Difference ###

input()
first=set(map(int,input().split()))
input()
second = set(map(int,input().split()))
for x in sorted(list(first.symmetric_difference(second))):
    print (x)
