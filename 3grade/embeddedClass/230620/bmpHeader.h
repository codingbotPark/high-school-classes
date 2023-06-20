#ifndef __BMP_FILE_H__
#define __BMP_FILE_H__

typedef struct __attribute__((__packed__)){
		unsigned short bfType; 
		unsigned int bfSize;
		unsigned short bfReserved1;
		unsigned short bfReserved2;
		unsigned int bf0ffBits;
} BITMAPFILEHEADER;

typeof struct{
	unsigned int biSize;
	unsigned int biWidth;
	unsigned int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned 
}


