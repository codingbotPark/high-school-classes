#11.15-------------------------------------------------------------------------------------
# 4 5
# 00110
# 00011
# 11111
# 00000
# 출력
# 3
# 
# 첫 번째 줄에 땅 크기 N, M  1<=N,M<=1000
# 두 번째 줄에 N+1번째 줄까지 땅에 대한 표시이다
# 0은 물 구덩이, 1은 밟아도 무너지지 않는 땅이다
# 전체 땅 속에서 물 구덩이 개수를 출력한다


n,m = map(int,input().split())
graph = [] #빈 리스트 생성
for i in range(n): #n줄만큼 입력받기
    graph.append(list(map(int,input()))) #split을 사용할 필요가 없다

def puddle(x,y): #물 웅덩이의 개수를 체크하는 함수
    if x<=-1 or x>=n or y <= -1 or y >= m:
        return False

    if graph[x][y] == 0:
        graph[x][y] = 1
        puddle(x - 1, y)
        puddle(x, y - 1)
        puddle(x + 1, y)
        puddle(x, y+1)
        return True
    else:
        return False

cnt = 0 #물 웅덩이 개수
for i in range(n):
    for j in range(m):
        if puddle(i,j) == True:
            cnt += 1

print(cnt)
#-----------

#codeup 6078
n = []
n = list(input().split('\n'))
i = 0
while (n[i] != 'q'):
    print(n[i])
    i = i + 1
print('q')
print(n)

while True:
    i = input()
    if (i == 'q'):
       break
    print(i)
print('q')
   
#11.18-------------------------------------------------------------------------------------
# 최소비용 신장트리
# 최소 비용으로 모든 노드 방문하기

# 신장트리 (spanning tree)
# 그래프의 모든 정점(vertex)들이 연결되어 있으며
# 사이클(cycle)이 없는 단순 연결 그래프

# => 모든 노드들은 다 연결되어있지만 사이클이 없는 것이다


# Kruska Algorithm (MST Minimum cost Spanning Tree)
# MST방식에는 Kruskal방식과 Prim 방식이 있다

# => n개의 노드가 있다면 n-1개의 엣지가 생긴다

# 가중치에 따라 선택한다

# a --- c
# ㅣ  / ㅣ
# ㅣ /  ㅣ
# ㅣ/   ㅣ
# b --- d

# ab = 1
# ac = 2
# bc = 3
# bd = 4
# cd = 5
# 라면

# a --- c
# ㅣ    
# ㅣ    
# ㅣ     
# b --- d
# 이런 최소비용 신장트리가 된다

# Kruskal 방식은 시작 위치가 필요 없다

# Prim 방식은 시작 정점이 있다
# 시작 정점에서부터 출발하여 신장트리 집합을 단계적으로 확장해나가는 방법

# 동작
# 시작 단계에서는 시작 정점만이 MST(최소 비용 신장 트리) 집합에 포함된다.
# 앞 단계에서 만들어진 MST 집합에 인접한 정점들 중에서 최소 간선으로 연결된 정점을 선택하여 트리를 확장한다.
# 위의 과정을 트리가 (N-1)개의 간선을 가질 때까지 반복한다.
# https://gmlwjd9405.github.io/2018/08/30/algorithm-prim-mst.html

# kruskal 알고리즘은 전체 그래프에서 최소비용의 길부터 선택
# prim 알고리즘은 시작정점부터 최소비용의 길부터 선택

# prim은 시작지점이 있고, 
# 지나온 길에서 이어져있고, 사이클이 만들어 지지 않는 길 중 
# 가장 가중치가 낮은 길을 선택한다 

# kruskal은 시작점이 없고 길 중 가장 가중치가 낮은 길부터 시작하기 때문에
# prim 과 지나오는 길의 순서가 다르다


# 그리디 (욕심쟁이, greedy, 탐욕법)
# 그리디 알고리즘은 매순간 최적이라 생각하는 해를 선택해서
# 최종적으로 최적해에 도달하는 알고리즘이다

# 구한 해가 항상 최적이 보장되지 않아서 근삿값을 구하는 용도로 사용된다

# 탐욕법이 충족되기 전 조건
# 1 앞의 선택이 이후의 선택에 영향을 주지 않을 때
# 2 문제에 대한 최적해가 부분문제에 대해서도 역시 최적해일 때

# https://suyeoniii.tistory.com/21

#-----------

# 구름(한 줄로 입력되는 수들 중 가장 큰 수를 찾아내기)
a = input()
for i in reversed(range(10)):
	if str(i) in a:
		print(i)
		break
# 종현이 코드
print(sorted(list(map(int, input())))[-1])

#-----------

#codeup 6079
a = int(input())
i = 1
j = 0
while(1):
    j+=i
    if (a <= j):
        break
    i+=1
print(i)


#codeup 6080
a,b = map(int,input().split())
for i in range(1,a+1):
    for j in range(1,b+1):
        print(i,j)

#codeup 6081
n = int(input(),16)
for i in range(1,16):
    print('%X'%n, '*%X'%i, '=%X'%(n*i), sep='')

#codeup 6082
a = int(input())
for i in range(1,a+1):
    line = str(i)
    if '3' in line or '6' in line or '9' in line:
        print('X',end=' ')
    else:
        print(i,end=' ')

#codeup 6083
a,b,c = map(int,input().split())
cnt=0
for i in range(a):
    for j in range(b):
        for k in range(c):
            print(i,j,k)
            cnt+=1
print(cnt)
