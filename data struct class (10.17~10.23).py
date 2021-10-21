# # 10.18
# name = input('이름을 입력하세요') #문자열 입력받기, printf(), scanf()
# print('My name is',name) # 숫자는 연결한다 
# print('My name is'+ name) 
# # print('My name is'+ 3) #+로 숫자는 연결이 되지 않는다
# print('My name is', 3) #,로 숫자는 연결 된다

# a = input('a=') 
# b = input('b=')
# a = int(a)
# b = int(b)
# #int(input('a=')) #이 형태로 보통 사용
# print('-' * 10) #10회 반복이 된다
# print(a + b) # 두 숫자 더하여 출력하기
# print('-' * 10) #10회 반복이 된다

# # 두 숫자를 입력받아 사칙연산
# a = int(input('a='))
# b = int(input('b='))
# print(a + b)
# print(a - b)
# print(a * b)
# print(a / b)

# # F string
# a = input('a=')
# b = input('b=')
# print(f'a + b={a +b}')

# # 함수 만들어보기
# # 파이썬
# def Hello():
#     print('Hello')
#     print('PARK')
# # 파이썬에서는 들여쓰기 (4칸 뛰우기 or  tab)
# Hello()

# # PARK라는 매개변수 값을 넘겨줄 때
# # PARK가 출력되도록
# name = input('name = ')
# def Hello(name):
#     print('Hi',name)
# Hello(name)

# # 이름과 주소를 출력하는 함수 (f string 사용)
# def info(name, address, phone):
#     print(f'제 이름은 {name}입니다!\n'\
#         f'주소는 {address}이고 휴대폰 번호는 {phone}입니다')
# info('박병관','천을로70','010 9413 2856')

# # 자신이 좋아하는 가수 이름을 3개 입력받고, 출력하는 함수
# def singer(a,b,c):
#     print(f'{a} 와 {b} 와 {c} 를 좋아합니다')
# a = input('좋아하는 가수 = ')
# b = input('좋아하는 가수 = ')
# c = input('좋아하는 가수 = ')
# singer(a,b,c)

# # 두 수를 입력받아 덧셈을 출력하도록 하시오
# # 한 줄에 여러개의 수를 입력받으려면
# a,b = map(int , input().split)
# # 입력받은 값을 split 으로 쪼갬
# # int 로 정수로 변환
# # map은 행동하도록 하는 역할을 한다
# print(a + b)
# # map 을 사용해야지 int가 둘 다 적용이 된다

# # 스왑
# a,b = 3, 4
# print(a,b)
# a,b = b,a # swap
# print(a,b)

# # 제어문 if 사용
# a = 5
# if a > 3:
#     print('3보다 큼')
# elif a > 1:
#     print('3보다 작고 1보다 큼')
# else:
#     print('1보다 작음')

# # 두 숫자를 한 줄에 입력받아 더 큰수를 출력하는 프로그램
# a,b = map(int, input().split())
# if a > b:
#     print(a)
# else:
#     print(b)

# # 수를 입력받아 70이상 최우수,
# # 50 이상 우수
# # 20 이상 보통
# # 그 외에는 노력 필요
# score = int(input())
# if score>= 70:
#     print('최우수')
# elif score >= 50:
#     print('우수')
# elif score >= 20:
#     print('보통')
# else:
#     print('노력필요')

# # 리스트에 주어지 알파벳을 정렬하라
# arr = ['a', 'b', 'c', 'f', 'z' , 'a']
# arr.sort()
# print(arr)

# 리스트에서 아스키 코드 값이 가장 작은,큰 알파벳을 출력하시오
# arr = ['z', 'b', 'i','q']
# arr.sort()
# print(arr[0])#맨 앞 요소
# print(arr[-1])#맨 뒤 요소
# # 역순사용
# arr.sort(reverse=True)
# print(arr)

# #주어진 점수 중 최고점과 최저점을 출력
# score = [55,78,99,34,87]
# score.sort()
# print('최저점 =',score[0])
# print('최고점 =',score[-1])
# print(max(score)) # 최고점
# print(min(score)) # 최저점

# # 반복문 for, while
# for i in range(10): #0에서 9까지 , (0,10)에서 0을 표현하지 않는 것이다
# # range (0, 10, 2) 는 0 에서 10까지 2 씩 증가시키는 것이다
#     print(i, end = '')
# # end는 기본값이 \n 이다
# # 즉 end를 넣지 않는다면 줄바꿈이 발생한다
# # end값을 바꿔서 마지막 값을 바꿀 수 있다

# # # 1에서 100이하까지 홀수를 출력
# # for i in range(1,100,2):
# #     print(i,end = ' ')

# # 1에서 100이하까지 4의 배수를 한 줄로 출력
# for i in range(0,101,4):
#     print(i,end = ' ')

#-------------------------------------------------------------------------------------

# # 10.21

# 달력 가져오기
# import calendar #캘린더 모듈 사용
# import datetime # date / time 에 대한 모듈
# d = datetime.datetime.now()
# print(calendar.month(d.year,d.month))

# 랜덤 모듈 사용
# import random # 랜덤 모듈
# arr = list() # arr을 리스트 생성자로 비어 있는 리스트 선언
# # 로또 번호 생성기
# for i in range(6): # 6회 반복
#     #for _ int range(6) 라면 단순 반복을 위한 코드이다
#     arr.append(random.randint(1,46))
# # append는 추가하는 것이다
# # 즉 1에서 46까지의 수를 생성해서 arr에 추가하는 것이다
# print(arr)
# #arr에 있는 데이터 중 가장 큰 값 출력
# # arr.sort()
# # print(arr[-1])
# print(max(arr))
# #max를 사용해 배열 중 가장 큰 값을 구할 수 있다
# # 리스트에서 두번째 큰 값을 출력
# arr.sort()
# print(arr[-2])

# 리스트 활용
# li = []
# li.append('BTS')
# li.append('Black Pink')
# print(li) # BTS
# print(li[1]) # Black Pink
# 가수 세 명을 입력 받기
# li = []
# for _ in range(0,3,1):
#     li.append(input('가수 이름을 쓰세요 : '))
# print('-' * 20)
# print(li)
# print(f'리스트 개수 {len(li)} 개 입니다')

# 팩토리얼 구연
# num = int(input("자연수 입력 : "))
# fac = 1 #초기값 설정
# for i in range(1, num + 1):
#     fac = fac * i
# print(f'{num}  팩토리얼은 {fac}입니다.')

# 랜덤 활용
# import random
# a1 = "오늘도 행복하세요"
# a2 = "폭염 주의하세요"
# a3 = "오늘 로또를 사세요"
# a4 = "당신은 천재에요"
# a5 = "영화 무료 쿠폰을 보내드립닌다"
# print(":::오늘의 운세:::")
# input("엔터를 누르면 시작됩니다")
# c = random.randint(1,5)
# if c == 1:
#     d = a1
# elif c == 2:
#     d = a2
# elif c == 3:
#     d = a3
# elif c == 4:
#     d = a4
# elif c == 5:
#     d = a5
# print(d)

# 딕셔너리 자료구조
#  key - value 형태의 값을 저장할 수 있는 자료구조를 말한다. 
# JavaScript에서는 이를 Object(객체)라 부른다. 
# 이름은 박보검 등 실제 데이터 값과 데이터를 설명하는 key의 대응 관계를 표현할 때 유용하다.2020. 5. 22.
# + 수업
# [키, 값] 쌍을 담아두는 자료구조이다
# 키는 원소를 찾기 위한 식별자이다
# 딕셔너리와 해시는 유일한 값(반복되지 않는 값)만 저장한다
# nation = {'한국':'서울','중국':'북경','일본':'동경'}
# n = input('나라 이름 입력 : ')
# print(f'수도는 {nation[n]}입니다')

# 딕셔너리
# KPop = {'BTS' : '세계적인 한국의 보이밴드이다. 총 7명으로 구성되어 있다',
#     '블랙핑크' : '세계적인 한국의 여성 아이돌 밴드이다. 총 4명으로 구성되어 있다.'}]
# name = input('좋아하는 K Pop 가수 이름을 적으시오')
# print(KPop[name])
