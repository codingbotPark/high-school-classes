# 물 얼려먹기, 물 웅덩이 수 구하기

# 물 웅덩이를 0, 웅덩이가 아닌 곳을 1로 한다

n,m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input())))


def puddle(x,y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False
    if graph[x][y] == 0: # n과 m 반복하는 배열의 값이 0이면
        graph[x][y] = 1 # 1로 변경시킨다
        # 1로 변경시키는 이유는 아래의 재귀반복문에서
        # 동서남북으로 비교를 하는데 1로 바뀌지 않는다면
        # 지나온 다시를 다시 돌아와서 비교하게 된다

        # 4방을 확인해서 물 웅덩이가 이어진 것을 확인 한다
        # 이 동서남북을 확인하는 코드가 물 웅덩이가 아무리 크더라도
        # 하나로 인식할 수 있도록 한다
        puddle(x - 1, y) 
        puddle(x, y -1)
        puddle(x + 1, y)
        puddle(x, y + 1)
        return True
    return False # 비교한 배열의 인덱스가 길일 때 false를 반환

cnt = 0 #물 웅덩이 개수
# 가로 = n
# 세로 = m
for i in range(n):
    for j in range(m):
        if puddle(i,j) == True:
            cnt += 1
print(cnt)


#-----------

#codeup 6059
a = int(input())
print(~a)

#codeup 606
a, b = map(int,input().split())
print(a & b)

#codeup 6061
a, b = map(int,input().split())
print(a | b)

# #codeup 6062
a,b = map(int,input().split())
print(a ^ b)

#codeup 6063
a,b = map(int,input().split())
print(a if (a >= b) else b)

#codeup 6064
a,b,c = map(int,input().split())
print((a if a < b else b) if ((a if a < b else b) < c) else c)
