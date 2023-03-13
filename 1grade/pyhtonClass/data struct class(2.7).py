import re # 정규표현식 regualr expression
pat = re.compile('[a-z]+')
m = pat.findall('life is too short')
print(m)

import re # 정규표현식 regualr expression
pat = re.compile('[a-z]+')
m = pat.findall('life is too short. I am 7 years old')
print(m)

text='''
신비한 소리와 함께 물 속으로...(김동균, 2019)
산신령1 : 어험, 나무꾼아! 이 금도끼가 네 도끼냐?(이순신, 2020)
돌쇠 : (고개를 가로 저으며) 아닙니다.
산실령1 : 음, 그래? 알았다.
산신령은 신비한 소리와 함께 물 속으로 들어간다.
(박병관, 1010)
'''

pat = re.compile(r'\([가-힣]+, \d+\)')
m=pat.findall(text)
print(m)


pat = re.compile('[a-z]+')
str = 'hello'
m=pat.match(str)
print(m)

str = '3 hello'
m=pat.search(str)
print(m)