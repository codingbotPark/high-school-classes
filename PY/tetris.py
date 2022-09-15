import time
import os
import ctypes
from xml.dom.expatbuilder import makeBuilder
import numpy as np
import msvcrt

def cls():
    os.system('cls')

def gotoxy(x,y):
    ctypes.windll.kernel32.SetConsoleCursorPosition(ctypes.windll.kernel32.GetStdHandle(-11),(((y&0xFFFF)<<0x10)|(x&0xFFFF)))

def draw_background():
    for j in range(0,22):
        for i in range(0,12):
            if background[j,i] == 1:
                print("*", end="")
            else:
                print("-", end="")
        print("")

def print_background_value():
    for j in range(0,22):
        for i in range(0,12):
            if background[j,i] == 1:
                gotoxy(i + 15,j)
                print("1")
            else:
                gotoxy(i+15,j)
                print("0")

def make_block(color):
    for j in range(0, 4):
        for i in range(0,4):
            if block_L[j,i] == 1:
                gotoxy(i+x, j+y)
                print("\033[%dm" % color + "*" + '\033[0m');
        print("")
        
def delete_block():
    for j in range(0, 4):
        for i in range(0,4):
            if block_L[j,i] == 1:
                gotoxy(i+x, j+y)
                print("-")
        print("")
        
        
# def overlap_check(tmp_x, tmp_y):
    
#     temp_background = background[y+tmp_y:y+tmp_y+4, x+tmp_x:x+tmp_x+4]
    
#     if temp_background.shape != block_L.shape:
#         return False
#     if np.sum(block_L[rotate,:,:] & temp_background) > 0:
#         return False
#     return True

def overlap_check(xx, yy):
    overlap_count = 1
    if ((x + xx) >= 0) and ((x + xx) <= 8) and ((y + yy) <= 18): 
        tmp_back = background[0 + y + yy: 4 + y + yy, 0 + x + xx:4 + x + xx]
        overlap_block = (tmp_back & block_L)
        overlap_count = overlap_block.sum()

    return overlap_count


    # 이중 반복을 활용
    # for i in range(4):
    #     for j in range(4):
    #         if block_L[i][j] == 1 and background[j + y + tmp_y,i + x + tmp_x] == 1:
    #             return False
    # return True

def overlap_check2(tmp_x,tmp_y):
    overlap_counter = 0

    for i in range(4):
        for j in range(4):
            if block_L[j][i] == 1 and background[j + y + tmp_y,i + x + tmp_x] == 1:
                # overlap_counter+=1
                return False
    # return overlap_counter
    return True
    

def overlap_check_rotate():
    overlap_count = 1

    if (x >= 0) and (x <= 8) and (y <= 18):
        tmp_back = background[0 + y:4 + y, 0 + x : 4 + x]
        tmp_block_L = np.dot(block_L.T, reverse_col) * (-1)
        overlap_block  = (tmp_back & tmp_block_L)
        overlap_count = overlap_block.sum()

    return overlap_count

def insert_block():
    for j in range(0, 4):
        for i in range(0,4):
            if block_L[j,i] == 1:
                background[j+y, i + x] = 1

background = np.array([[1,1,1,1,1,1,1,1,1,1,1,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,0,0,0,0,0,0,0,0,0,0,1],
                       [1,1,1,1,1,1,1,1,1,1,1,1]])

reverse_col = np.array([[0,0,0,-1],
                        [0,0,-1,0],
                        [0,-1,0,0],
                        [-1,0,0,0]])

block_L = np.array([[0,0,0,0],
                     [0,1,0,0],
                     [0,1,1,1],
                     [0,0,0,0]]) 


text_color = np.array([30,31,32,33,34,35,36,37])

rotate = 0
x = 3
y = 3
           
count = 0             
#print(background.shape)

time.sleep(1)    

cls()
draw_background()
make_block(text_color[1])
print_background_value()
                                       
while True:
    
    if msvcrt.kbhit():
        key = msvcrt.getch()
        
        if key == b'a':
            if overlap_check(-1, 0)==0:
                delete_block()
                x -= 1
                make_block(text_color[1])
                #print(block_L.shape)
            
        elif key == b'd':
            if overlap_check(1, 0)==0:
                delete_block()
                x += 1
                make_block(text_color[1])
            
        elif key == b's':
            if overlap_check(0, 1)==0:
                delete_block()
                y += 1
                make_block(text_color[1])

        elif key == b'r':
            # if  overlap_check_rotate() == 0:
            #     delete_block()
            #     rotate += 1
            #     if (rotate == 4):
            #         rotate = 0
            #     make_block(text_color[1])
            delete_block()
            block_L = np.dot(block_L.T, reverse_col) * (-1)
            make_block(text_color[1])
    
    # --------------------------------------------------------
    if count == 100:
        count = 0
        if overlap_check(0, 1)==0:
            delete_block()
            y += 1
            make_block(text_color[1])
        else:
            # 블록 넣어주기
            insert_block()
            print_background_value()
            x = 3
            y = 3

        
    # --------------------------------------------------------
    count += 1
    time.sleep(0.01)
       
    
    
