# 11.1-------------------------------------------------------------------------------------

from random import * #from을 한다면 그냥 사용할 수 있고
import time #import를 하면 ~. 해서 사용해야 한다
for i in range(5):
    print(randint(1,6)) #1에서 6사이의 수를 만듬
    time.sleep(0.5) #0.5초 동안 전체를 멈춰줌

# -----------

# 숫자를 입력받아 정렬하여 출력
# 중복된 숫자는 하나만 나오도록
arr = list(map(int,input().split())) #list를 하면 list로 나눈 값을 하나하나 입력받게 된다
# print(arr)
# 중복 제거
arr = list(set(arr))
# 원래대로 list를 바꾸어 준다 (하지 않으면 {} 형태로 만들어짐)
print(arr)
    
# -----------

# 5명이 출입구에 모이면 키 큰순으로 들여보내야 한다
# 중복된 번호의 학생은 한 명만 안으로 보낸다
arr = list(map(int, input().split()))
arr = list(set(arr))
arr.sort()
arr.reverse()
print(arr)
# 박종현 답
# students = list(set(map(int, input().split())))
# students.sort(reverse=True)
# for i in students: print(i, end=' ')

# -----------

# # 숫자를 입력받아 총합을 구하는 프로그램 (5개)
num = 0
for _ in range(5):
    num += int(input())
print(num)
# 선생님 코드
n = []
for _ in range(5):
    n.append(int(input()))
print(sum(n))

# -----------

# tree란 
# 계층적 관계를 표현한다
# (스택 큐와 같은 선형 구조가 아닌 비선형 자료구조)

# 트리의 구성에는
# 노드 = 트리를 구성하는 각각의 요소
# 간선 = 각각의 노드를 연결하는 선
# 루트 노드 = 트리 구조에 최상에 있는 노드
# 단말 노드 = 하위에 다른 노드가 연결되어 있지 않은 최하위 노드
# 내부 노드, 비단말 노드 = 단말 노드를 제외한 모든 노드

# 선생님 정리
# 루트(root) | 부모가 없는 노드
# 서브 트리 | 루트의 다음 레벨에 있는 노드들은 서브트리의 루트가 된다
# 간선(edge) | 노드간의 연결 선
# 노드의 차수(degree) | 서브 트리의 개수
# 단말 노드 또는 잎노드(terminal / leaf) | 차수가 0 인 노드
# 비 단말노드(non terminal) | 단말 노드 이외의 노드들
# 자식 노드(child node) | 노드 x의 서브 트리의 루트들은 x의 자식
# 부모 노드(parent node) | x는 그 자식들의 부모
# 형제 노드(sibling node) | 부모가 같은 자식들
# 조상 노드(ancestor node) | 루트부토 노드에 이르는 경로상의 모든 노드들
# 트리의 차수(degree) | 트리에 속한 노드의 최대 차수

# -----------

#codeup 6046
a = int(input())
print(a << 1)

# codeup 6047
a,b = map(int,input().split())
print(a << b)

# codeup 6048
a,b = map(int,input().split())
print(a < b)

# codeup 6049
a,b = map(int, input().split())
print(a == b)

# codeup 6050
a,b = map(int, input().split())
print(a <= b)

# codeup 6051
a,b = map(int, input().split())
print(a != b)

# codeup 6052
a = int(input())
print(bool(a))

# codeup 6053
a = bool(int(input()))
print(not a)
# or
a = int(input())
print(not bool(a))

# codeup 6054
a,b = map(bool,(map(int,input().split())))
print(a and b)

# codeup 6055
a,b = map(bool,map(int,input().split()))
print(a or b)

# 11.4-------------------------------------------------------------------------------------

# dfs
# 방문한 노드는 1로 세팅하고 노드 번호출력
# 인접리스트에서 방문하지 않은 노드를 가지고 dfs 재귀 호출

visited = [0] * 9 #0을 먼저 넣어둔다

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

def dfs (v):
    visited[v] = 1
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(i)

# graph 는 인접 리스트로 노드를 표현한 것

dfs(1) #1번 노드부터 출발

# 기본적으로 0으로 세팅된 9칸의 배열
# 1번째 인덱스에서 시작
# for문으로 graph의 1번째 인덱스 = [2,3,8]
# 으로 for문을 돌리게 된다
# 
# 2번에 있는 곳이 0인지(안 간 곳인지) 비교
# 방문 안한 곳이면 1로 바꾸고 출력

# -----------

# codeup 6056
a,b = map(bool,map(int,input().split()))
print(a == (not b))

# codeup 6057
a,b = map(bool,map(int,input().split()))
print(a == b)

# codeup 6058
a,b = map(bool,(map(int,input().split())))
print((not a) and (not b))
