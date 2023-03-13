# 10.25-------------------------------------------------------------------------------------


# ord 는 유니코드 정수
# chr 는 유니코드 문자

print(ord('a')) #97
print(ord('A')) #65

print(chr(99)) #c
print(chr(66)) #B

# 소문자를 출력
for i in range(97,123):
    print(chr(i),end = '')
print()
for i in range(0,26):
    print(chr(ord('a')+i),end = '')

# -----------

# zfill 은 0으로 채운다

# 지정된 수만큼의 수를 차지하고
# 자리수만큼 체워지지않는 것을 0으로 채움

n = 20
print(hex(n))#0x14

n1 = str(hex(n))
print(n1.zfill(10))
#0000000x14

n2 = 'hello'
print(n2.zfill(10))
#00000hello

# -----------

Group = {}
print("### K-Pop 그룹 관리 프로그램 ###")

while True:
    menu = int(input("[1:등록 / 2:삭제 / 3:조회 / 4:종료]"))
    if menu == 4:
        break
    elif menu == 1:
        name = input("그룹 이름이 무엇인가?")
        member = input("그룹 인원이 몇명인가?")
        Group[name] = member
    elif menu == 2:
        delete = input("삭제할 그룹 이름이 무엇인가?")
        del(Group[delete])
    elif menu == 3:
        print(Group)

print("### K-Pop 관리 프로그램 종료 ###")
# class로 관리

# -----------

sum = 0
for i in range(1010):
    sum += i
print("sum:{}".format(sum))
print("%d" % sum)

# 출력하는 포멧 중 하나

# -----------

# 스택, 큐 구현
# 큐 = FIFO = First In First Out

from collections import deque
queue = deque()
queue.append(1)
queue.append(2)
queue.append(3)
print(queue)
print(queue.popleft())
#큐는 First In First Out이기 때문에
#popleft해서 먼저들어온 값이 나가도록 한다
print(queue.popleft())
print(queue.popleft())
print(queue)

from collections import deque
queue=deque()
queue.append(1)
queue.append(2)
queue.append(3)
print(queue)
print(queue.popleft())
print(queue.popleft())
print(queue)
queue.append(11)
queue.append(22)
queue.append(33)
print(queue)
#print(queue.reverse())#이렇게 하면 안됨, None
queue.reverse()
print(queue)

# -----------

# 스택 = FILO = First In First Out

stack = []
stack.append(5)
stack.append(3)
stack.append(8)
stack.append(6)
stack.append(4)
stack.pop()
stack.append(1)
stack.pop()
print(stack)
print(stack[0])
print(stack[::-1])
# arr[A:B:C] 의 의미는
# index A부터 index B까지 C의 간격으로 배열을 만들라는 의미이다
#
# 만약 A가 None이면, 처음부터 라는 의미,
# 만약 B가 None이면 할 수 있는데 까지 라는 의미아다
# 만약 C가 None이면 한 칸 간격으로 라는 뜻이다
#
# C가 양수면 마지막 index까지, 음수면 첫 index까지가 된다 
# 
# 출처 : https://blog.wonkyunglee.io/3
print('stack pop', stack.pop())
print('stack pop', stack.pop())
print('stack pop', stack.pop())
print('stack pop', stack.pop())

# -----------

# 배열 인덱스 연습
a = []*6
print(a)
a = [0,2,3,4,5,1]
print(a)
for i in range(1,6):    
    a[i] = a[a[i]]
print(a)
for i in range(1,6):
    a[i] = a[a[i]]
print(a)
#인덱스 간접 참조
#해당 값 위치로 가라는 의미

# -----------

#팩토리얼
def fac(n):
    r = 1
    for i in range(1,n+1):
        r*=i
    return r

def rec(n):
    if n<=1:
        return 1
    else:
        return n*rec(n-1)

print(fac(5))
print(rec(5))

# -----------

# 딕셔너리 생성 없데이트 등

# 딕셔너리 생성(여러 빈칸이 있는 경우 처리 법)
# 입력할 때
# BTS 7인조 남자 아이돌
# 이라 입력할 때
# BTS따로, 7인조 남자 아이돌 을 따로 입력받아
# 딕셔너리에 넣음
d1 = {}
k = input()
v = input()
d1[k] =v
k = input()
v = input()
d1[k] = v
print(d1)

# 빈칸이 한 번 있는 경우 딕셔너리 생성법
# 입력할 때
# BTS 남자
# 이라 입력할 때
# BTS따로, 남자 를 따로 입력받아
# 딕셔너리에 넣음
dct1 = {}
for _ in range(2):
    k,v = input().split()
    dct1[k] = v
print(dct1)

hash = {}
for _ in range(3):
    key,value = input().split()
    hash[int(key)] = value
print(hash)

# -----------

# 필터와 맵 예제

# 1 - 2 map 함수를 사용하는 것과 아닌 것의 차이
# 똑같은 작업을 map을 이용했을 때와 그렇지 않을 때를 비교

# 리스트에 값을 하나씩 더해서 새로운 리스트를 만드는 작업
myList = [1,2,3,4,5]

# for 반복문 이용
result1 = []
for val in myList:
    result1.append(val + 1)

print(f'result : {result1}')

# map 함수 이용
def add_one(n):
    return n + 1

result2 = list(map(add_one, myList))
# map 반환을 list로 변환
print(f'result : {result2}')


# 2 - 1 리스트와 map 함수

import math #math.ceil 함수 사용

#예제1 리스트의 값을 정수 타입으로 변환
result1 = list(map(int, [1.1,2.2,3.3,4.4,5.5]))
print(f'map(int, 리스트) : {result1}')

#예제2 리스트 값 제곱
def func_pow(x):
    return pow(x,5)
# x의 5제곱을 반환
result = list(map(func_pow,[1,2,3,4,5]))
print(f'map(func_pow, 리스트) : {result}')

#예제3 리스트 값 소수점 올림
result3 = list(map(math.ceil,[1.1,2.2,3.3,4.4,5.5,6.6]))
print(f'map(func_ceil, 리스트) : {result3}')


# 2 - 2 람다와 map 함수

# map의 첫번째 인자로 함수가 들어간다면
# 이름 없는 함수 즉, 람다 함수도 가능하다는 말이다
# 만약 map의 인자로 사용할 함수가 일회성이거나 매우 짧은 경우에는 람다 함수를 사용해서 넘기는게 조금 더 효율적일 것이다

# map과 lambda

# 일반 함수 이용
def func_mul(x):
    return x * 2

result1 = list(map(func_mul, [5,4,3,2,1]))
print(f'map(일반함수, 리스트) : {result1}')

# 람다 함수 이용
result2 = list(map(lambda x : x * 2, [5,4,3,2,1]))
print(f'map(람다함수, 리스트) : {result2}')


# 2 - 2 filter 함수와 람다 함수

arr = [1,10.2,100.3,2.3,20.2,200.3,3,30,300]

result1 = list(filter(lambda n : n < 10, arr))
result2 = list(filter(lambda n : isinstance(n,int), arr))
# isinstance 함수는 값과 비교할 형식을 인자로 받고
# 맞으면 True, 아니면 False를 리턴한다
# 출처 : https://devpouch.tistory.com/87
result3 = list(filter(lambda n : isinstance(n, float),arr))

print(f'원래 리스트 : {arr}')
print(f'10보다 작은 수 : {result1}')
print(f'정수만 출력{result2}')
print(f'정수만 출력{result3}')

# -----------

# 위의 문법을 사용한 문제 풀이
# 문제 - 암호해독
# 문자와 숫자를 입력받아 문자일 때는 스택에 저장, 숫자일 때 스택에서 그 숫자만큼 문자의 개수를 빼서 해독
# 단 띄어쓰기는 없다, 숫자는 한 자리수씩 해석한다(두자리 수는 없다), 오타는 없다
# 예) ym2n1a1em2 = myname
# 예) H1lle3o1 = Hello
# 예) evol13 = love

result = []
value = input('해독 전 : ')
value =list(value)
# 입력받은 값을 배열로 변경
print('해독 후 : ',end = '')

for i in range(0,len(value)): # 0 부터 배열의 길이만큼반복
    if ord(value[i]) < 58:#숫자일 때
        for _ in range(0, int(value[i])):
            print(result[-1],end = '')
            result.pop()
    else:#문자일 때
        result.append(value[i])

# 10.28-------------------------------------------------------------------------------------

# codeup 6001
print("Hello")

# codeup 6002
print("Hello","World")

# codeup 6003
print("Hello World")

# codeup 6004
print("'Hello'")

# codeup 6005
print("\"Hello World\"")

# codeup 6006
print("\"!@#$%^&*()'")

#codeup 6007
print("\"C:\\Download\\'hello'.py\"")

# codeup 6008
print("print(\"Hello\\nWorld\")")

# codeup 6009
a = input()
print(a)

# codeup 6010
a = int(input(''))
print(a)

# codeup 6011
a = float(input(''))
print(a)

# codeup 6012
a = int(input(''))
b = int(input(''))
print(a)
print(b)

# codeup 6013
a = input('')
b = input('')
print(b)
print(a)

# codeup 6014
a = float(input(''))
print(a)
print(a)
print(a)

# codeup 6015
a,b = input().split()
print(a)
print(b)

# codeup 6016
a,b = input().split()
print(b)
print(a)

# codeup 6017
a = input('')
print(a,a,a)

# codeup 6018
a,b = input().split(':')
print(a,b,sep=':')

# codeup 6019
a,b,c = input().split('.')
print(c,b,a,sep = '-')

# codeup 6020
a,b = input().split('-')
print(a,b,sep='')

# codeup 6021
s = input()
print(s[0])
print(s[1])
print(s[2])
print(s[3])
print(s[4])

# codeup 6022
a = input()
print(a[0:2])
print(a[2:4])
print(a[4:6])

# codeup 6023
a,b,c = input().split(':')
print(b)

# + 문자를 치는 과정(codeup a번 문제)를 자동화
from pyautogui import *
for i in range(50):
    write('#codeup')
    press('space')
    write(str(i + 6024))
    press('enter')
    press('enter')


# codeup 6024
a,b = input().split()
print(a,b,sep="")

# codeup 6025
a,b = input().split()
print(int(a) + int(b))

# codeup 6026
a = input()
b = input()
print(float(a) + float(b))

# codeup 6027
a = int(input())
print('%x'%a)

# codeup 6028
a = int(input())
print('%X'%a)

# codeup 6029
a = int(input(),16)
print('%o'%a)

# codeup 6030
a = ord(input())
print(a)

# codeup 6031
a = int(input())
print(chr(a))

# codeup 6032
a = int(input())
print(-a)

# codeup 6033
a = ord(input())
print(chr(a + 1))

# codeup 6034
a,b = input().split()
print(int(a) - int(b))

# codeup 6035
a,b = map(float,input().split())
print(a * b)

# codeup 6036
a,b = input().split()
print(a * int(b))

# codeup 6037
a= input()
b = input()
print(b * int(a))

# codeup 6038
a,b = map(int,input().split())
print(a**b)

# codeup 6039
a,b = map(float,input().split())
print(a**b)

# codeup 6040
a,b = map(int,input().split())
print(a//b)

# codeup 6041
a,b = map(int,input().split())
print(a%b)

# codeup 6042
a = float(input())
print(format(a,".2f"))

# codeup 6043
a,b = map(float,input().split())
print(format(a/b,".3f"))

# codeup 6044
a,b = map(int,input().split())
print(a + b)
print(a - b)
print(a * b)
print(a // b)
print(a % b)
print(format(a / b,'.2f'))

# codeup 6045
a,b,c = map(int,input().split())
print(a+b+c,format((a+b+c)/3,'.2f'))