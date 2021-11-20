# 11.20-------------------------------------------------------------------------------------
# dgsw 구름 1번문제 (1~n까지의 합을 출력)
a = int(input())
v =0
for i in range(1,a + 1):
    v = v + i
print(v)

# dgsw 구름 2번문제 (숫자를 입력받아 정렬하여 출력하기, 
# 중복된 수는 하나만 나오게 하기)
a = []
a = set(list(map(int,input().split(' '))))
for i in a:
    print(i,end=' ')

# dgsw 구름 4번문제 (시간을 입력받아 3이 포함된 숫자의 개수를 출력)
a = int(input())
cnt = 0 
for i in range(a + 1): # 시
    for j in range(60): # 분
        for k in range(60): # 초
            # !!!!
            ss = str(i) + str(j)  +str(k)
            cnt += ss.count('3')
print(cnt)            

# dgsw 구름 6번문제 (번호가 적힌 n개의 공을 바구니에 넣고,
# k개 만큼 빼기를 반복)
# list와 degue를 사욛하여 품
from collections import deque
from os import scandir
#deque를 사용하기 위해 사용
stack = deque()
stack.append

# 리스트는 시간 복잡도 O(n),
# deque는 시간 복잡도가 O(1) 이다

a = int(input()) # 몇 번의 input, pop을 할지

for i in range(a):
    b = list(input().split(' '))
    for j in b: #추가하는 과정
        stack.append(j)
    c = int(input())
    for j in range(c):
        stack.pop()

# 값들 사이에 스페이스 바를 넣고 출력한다 (join)
print(' '.join(stack))

# dgsw 구름 7번문제 (두 정수 n과 k를 입력받고
# 어떤 수 n이 1이 될 때까지 n이 k보다 큰 경우
# 1-1, 1-2 두 과정 중 하나를 선택하여 반복)
# 1-1 = nㅔ서 1을 뺀다 (정수 n을 k로 정확히 나눌 수 없을 때)
# 1-2 = n을 k로 나누어지면 n은 k로 나눈 몫이 저장된다
# 2 = n >= k인 경우동안 1,2 중 하나를 반복한다

# n이 k보다 작은 경우 1-1 을 반복한다
# n이 1이 되면 종료한다

# 반복 할 때마다 1씩 카운트

# 위의 과정을 반복한 횟수를 출력

n,k = map(int,input().split())
cnt =1
while (not n == 1):
    if n >= k:
        if n % k == 0:
            n /= k
        else:
            n -= 1
    else:
        n -= 1
    cnt+=1
print(cnt)
    