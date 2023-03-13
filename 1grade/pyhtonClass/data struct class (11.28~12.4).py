# 11.29-------------------------------------------------------------------------------------
# 최대공약수(Greatest Common Divisor)
def gcd(x,y):
    while y:
        x,y = y,x % y # 나누어떨어진다면 y = 0 이 된다
    return x # y 가 0이 되었을 때 x를 리턴한다
a,b = map(int,input().split())
print(gcd(a,b))

# math 모듈 기능
from math import gcd
a,b = map(int,input().split())
print(gcd(a,b))

# 최소공배수(Least Common Multiple)
from math import gcd

def lcm(x,y):
    return x * y // gcd(x,y) # 최대공약수로 나눈다
a,b = map(int,input().split())
print(lcm(a,b))



# c언어 일 때
# include <stdio.h>
# int main() {
#     int n1, n2, i, gcd, lcm;
#     printf("두 정수를 입력: ");
#     scanf("%d %d", &n1, &n2);
    
#     for (i = 1; i <= n1 && i <= n2; ++i) {
        
#         if (n1 % i == 0 && n2 % i == 0)
#             gcd = i;
#     }
    
#     lcm = (n1 * n2) / gcd;
    
#     printf("%d 와 %d의 최소 공배수: %d\n", n1, n2, lcm);
#     return 0;
# }


# 선생님 코드
# Using Recursion : 재귀적 용법으로 구하기
def 최대공약수(a,b): #GCD
    if b == 0:
        return a
    else:
        return 최대공약수(b,a%b)
a,b = map(int,input().split())
print(최대공약수(a,b))

# 메르센 소수
# 메르센 소수란 2의 n승 빼기 1 로 표현되는 소수를 말한다


#-----------

#codeup 6087
a = int(input())
i =1
while a >= i:
    if i % 3 != 0:
        print(i,end=' ')
    i+=1


#-----------

# dgsw.goorim.io  11 번 문제
a = list(input())
j=a[0] # 배열 전의 수를 비교
counter =0 # 같은 문자가 몇번 왔는지 카운트
for i in a:
    if (ord(j) != ord(i)): # 다를 때 입력
        # 출력
        print(f'{j}{counter}',end='')
        j = i
        counter = 1
    else: # 같을 때 더하기
        counter += 1
print(f'{j}{counter}',end='')

# dgsw.goorim.io 12 번 문제
a = list(map(int,input().split()))
j = 0
for i in range(a.__len__()):
    if a[i] < 0: # 0보다 작고 
        if j == i: # 앞에 양수가 없었을 때
            j = i
        else: #앞에 양수가 있을 때
            # 스왑한다
            a[j+1],a[i] = a[i],a[j+1]
print(*(a))
# 잘못된 코드

a = list(map(int,input().split()))
for i in a:
    if i < 0:
        print(i,end=' ')
for i in a:
    if i > 0:
        print(i,end=' ')


# 선생님코드
arr = list(map(int,input().split()))
test1 = [i for i in arr if i < 0] # if 조건에 맞는 것만 i로 넘긴다
test2 = [i for i in arr if i > 0] 
print(*(test1+test2))
# * 을 넣으면 for문의 대괄호를 없애준다