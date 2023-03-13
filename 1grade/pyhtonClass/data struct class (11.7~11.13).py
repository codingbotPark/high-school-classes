#11.8-------------------------------------------------------------------------------------

# BFS = Breath First Search
# 너비 우선 탐색

from collections import deque # double ended queue
def bfs(start):
    queue = deque([start]) # deque는 끝이 두 개 인 큐이다 = 속도가 빠르다
    # deque를 사용하려면 collections라는 것을 들고 와야 한다
    # deque는 안에 값을 넣으려면 대괄호를 해야한다
    visited[start] = True # 시작점을 true로 바꿈
    while queue: 
        v = queue.popleft() # 큐 왼쪽 값을 뺌
        print(v,end='') # 큐에서 뺀 값을 출력
        for i in range[v]: # 뺀 큐(현재 위치) 와 연결된 노드들을 반복
            if not visited[i]: # 반복하는 노드 중 방문하지 않았다면
                queue.append(i) # 큐에 넣기
                visited[i] = True # 큐에 넣은 수를 true로 변경
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]
visited = [False] * 9
bfs(1)

#-----------

#codeup 6065
a,b,c = map(int,input().split())
if a % 2 == 0:
    print(a)
if b % 2 == 0:
    print(b)
if c % 2 == 0:
    print(c)

#codeup 6066
a,b,c = map(int,input().split())
if a % 2 == 0:
    print("even")
else:
    print("odd")
if b % 2 == 0:
    print("even")
else:
    print("odd")
if c % 2 == 0:
    print("even")
else:
    print("odd")

#codeup 6067
a = int(input())
if a % 2 == 0:
    if a > 0:
        print('C')
    else:
        print('A')
else:
    if a > 0:
        print('D')
    else:
        print('B')

#codeup 6068
a = int(input())
if a >= 90:
    print('A')
elif a >= 70:
    print('B')
elif a >= 40:
    print('C')
else:
    print('D')

#codeup 6069
a = input()
if a == 'A':
    print('best!!!')
elif a == 'B':
    print('good!!')
elif a == 'C':
    print('run!')
elif a == 'D':
    print('slowly~')
else:
    print('what?')

#codeup 6070
a = int(input())
if a // 3 == 1:
    print('spring')
elif a // 3 == 2:
    print('summer')
elif a // 3 == 3:
    print('fall')
else:
    print('winter')

#codeup 6071
n = 1
while n != 0:
    n = int(input())
    if n != 0:
        print(n)

#codeup 6072
a = int(input())
while a > 0:
    print(a)
    a = a-1

#codeup 6073
a = int(input())
while a > 0:
    a = a-1
    print(a)

#codeup 6074
e = ord(input())
s = ord('a')
while s <= e:
    print(chr(s))
    s = s+1

#codeup 6075, 6076
a = int(input())
i = 0
while i <= a:
    print(i,end='\n')
    i += 1

#codeup 6077
a = int(input())
i = 2
j = 0
while i <= a:
    j += i
    i += 2
print(j)