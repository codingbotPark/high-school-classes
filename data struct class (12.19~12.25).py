# 12.19~12.25-------------------------------------------------------------------------------------

#codeup 6088
a,b,c = map(int,input().split())
print(a + (b * (c-1)))

#codeup 6089
a, b, c = map(int, input().split())
print(a * (b ** (c-1)))

#codeup 6090
a, b, c, d = map(int, input().split())
for i in range(d-1):
    a *= b
    a += c
print(a)

#codeup 6091
a = list(map(int, input().split()))
a.sort()
for i in range(a[2],a[0] * a[1] * a[2] + 1,1):
    if (i % a[0] == 0) and (i % a[1] == 0) and (i % a[2] == 0):
        print(i)
        break

#codeup 6092
arr1 = [0] * 23
a = int(input())
arr2 = list(map(int,input().split()))
for i in range(a):
    arr1[arr2[i]-1]+=1
print(*arr1)

#codeup 6093
a = int(input())
b = list(map(int,input().split()))
b.reverse()
print(*b)

#codeup 6094
input()
a = list(map(int,input().split()))
a.sort()
print(a[0])

#codeup 6095
arr = [[0] * 19 for _ in range(19)]
a = int(input())
for i in range(a):
    b = list(map(int,input().split()))
    arr[b[0]-1][b[1]-1] = 1

for i in arr:
    for j in i:
        print(j,end=" ")
    print()

#codeup 6096
# 선언하기
# arr의 앞부분이 세로의 인덱스, 뒷부분이 가로의 인덱스이다
arr1 = [[0] * 19 for _ in range(19)]
arr2 = []
#입력받기
for i in range(19):
    arr2 = list(map(int,input().split()))
    for j in range(19):
        arr1[i][j] = arr2[j]

a = int(input())
for i in range(a):
    b = list(map(int,input().split()))
    for j in range(19):
        if arr1[b[0]-1][j] == 1:
            arr1[b[0]-1][j] = 0
        else:
            arr1[b[0]-1][j] = 1
    for j in range(19):
        if arr1[j][b[1]-1] == 1:
            arr1[j][b[1]-1] = 0
        else:
            arr1[j][b[1]-1] = 1
for i in arr1:
    for j in i:
        print(j,end=' ')
    print()

#codeup 6097
a = list(map(int,input().split()))
arr = [[0] * a[1] for _ in range(a[0])]
a = int(input())
for i in range(a):
    b = list(map(int,input().split()))
    for j in range(b[0]):
        # 방향이 세로일 때
        if b[1] == 0:
            arr[b[2]-1][b[3]-1+j] = 1
        else:
            arr[b[2]-1+j][b[3]-1] = 1
for i in  arr:
    for j in i:
        print(j,end=" ")
    print()