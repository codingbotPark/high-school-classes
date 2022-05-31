#include <stdio.h>
#include <stdlib.h>

void atexit_handler(){
    printf("atexit_handler1 함수 호출합니다\n");
}
void atexit_handler2(){
    printf("atexit_handler2 함수 호출합니다\n");
}

int main(){
    atexit(atexit_handler);
    atexit(atexit_handler2);
    exit(0);
}

// 프로그램 실행을 위해서는
// 프로그램의 코드, 데이터, 스택, 힙, U영역이 필요하다

// 힙 영역에는 doA함수가 종료되도 안 날아간다
// 스택 영역에는 지역변수가 들어가게 된다, 종료되면 날아감