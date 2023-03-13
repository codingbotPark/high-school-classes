import pyperclip
import pyautogui
from time import process_time, sleep

# cla = input("반 : ")
# num = input("학번 : ")
# name = input("이름 : ")
# address

# valueArray = [[0] * 15 for i in range(15)]

arr = []
stringArr = []

classNum = int(input("반 입력"))

for i in range(1,20):
    string = input().split()
    arr.append(string)

sleep(5)

for i in arr:
    # string = f"insert into class2{classNum} values({i[0],i[1],i[2],i[3]}"{i[4]}'')\n"
    string = f'insert into class2{classNum} values({i[0]},{i[1]},{i[2]},{i[3]},"{i[4]}","{i[5]}");\n'
    pyperclip.copy(string)
    pyautogui.hotkey('ctrl','v')

# name = "insert into class21 values("
# pyperclip.copy(name)
# pyautogui.hotkey('ctrl','v')``\
