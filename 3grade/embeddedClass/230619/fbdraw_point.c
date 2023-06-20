#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <math.h>

#define FBDEVICE "/dev/fb0"

typedef unsigned char ubyte;

unsigned short makepixel(unsigned char r, unsigned char g, unsigned char b) {
    return (unsigned short)(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
}

static int DrawPoint(int fd, int x, int y, unsigned short color)
{
    struct fb_var_screeninfo vinfo;

    /* 현재 프레임버퍼에 대한 고정된 화면 정보를 얻어온다. */
    if(ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("Error reading fixed information");
        return -1;
    }

    /* 색상 출력을 위한 위치를 구한다. */
    /* offset  = (X의_위치 + Y의_위치 x 해상도의_넓이) x 2  */
    int offset = (x + y*vinfo.xres)*2;
    lseek(fd, offset, SEEK_SET);
    write(fd, &color, 2);

    return 0;
}

// 가로
static int DrawColumnLine(int fd, int start_x, int end_x, int y, unsigned short color) 
{
    int x, offset;
    struct fb_var_screeninfo vinfo;

    /* 현재 프레임버퍼에 대한 고정된 화면 정보를 얻어온다. */
    if(ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("Error reading fixed information");
        return -1;
    }

    for(x = start_x; x < end_x; x++) {
        offset = (x+y*vinfo.xres)*2;
        lseek(fd, offset, SEEK_SET);
        write(fd, &color, 2);
    };

    return 0;
}

// 세로선
static int DrawRowLine(int fd, int start_y, int end_y, int x, unsigned short color){
    int y, offset;
    struct fb_var_screeninfo vinfo;

    /* 현재 프레임버퍼에 대한 고정된 화면 정보를 얻어온다. */
    if(ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) < 0) {
        perror("Error reading fixed information");
        return -1;
    }

    for(y = start_y; y < end_y; y++) {
        offset = (x+y*vinfo.xres)*2;
        lseek(fd, offset, SEEK_SET);
        write(fd, &color, 2);
    };

    return 0;
}

int drawCircle(int fbfd){
    
    int topTemp = 100;
    int leftTemp = 100;
    int r = 50; // 반지름
    
    int centerPointerX = leftTemp + r;
    int centerPointerY = topTemp + r;
    
    // 세로(y)
    for (int i = topTemp;i<=topTemp+(r*2);i++){
            for (int j = leftTemp; j <= leftTemp + (r*2) ;j++){
                    int tempR = sqrt(pow(centerPointerY - i,2) + pow(centerPointerX - j,2));
                    if (tempR == r){
                        DrawPoint(fbfd, j, i, makepixel(0, 255, 0));
                    }
            }
    }
} 

int drawRectangle(int fbfd){
    int topTemp = 300;
    int leftTemp = 300;
    int row = 150; // 세로
    int column = 100; // 가로
    
    DrawColumnLine(fbfd, leftTemp, leftTemp + column, topTemp, makepixel(0, 255, 0)) ;
    DrawColumnLine(fbfd, leftTemp, leftTemp + column, topTemp+row, makepixel(0, 255, 0)) ;
    DrawRowLine(fbfd, topTemp, topTemp + row, leftTemp,makepixel(0, 255, 0));
    DrawRowLine(fbfd, topTemp, topTemp + row, leftTemp+column,makepixel(0, 255, 0));
}



int main(int argc, char** argv)
{
    int fbfd, status, offset;
    /* 프레임버퍼 정보 처리를 위한 구조체 */
    unsigned short pixel;

    fbfd = open(FBDEVICE, O_RDWR);    /* 사용할 프레임버퍼 장치를 오픈한다. */
    if(fbfd < 0) {
        perror("Error: cannot open framebuffer device");
        return -1;
    }
    

    
    drawCircle(fbfd);
    drawRectangle(fbfd);

    close(fbfd);                                           /* 사용이 끝난 프레임버
퍼 장치를 닫는다. */

    return 0;
}

