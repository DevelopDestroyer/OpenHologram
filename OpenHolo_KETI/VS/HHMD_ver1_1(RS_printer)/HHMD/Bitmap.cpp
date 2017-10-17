#include "stdafx.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include "Define.h"

#define _bitsperpixel 8 //24 // 3����Ʈ=24 
#define _planes 1
#define _compression 0
#define _xpixelpermeter 0x130B //2835 , 72 DPI
#define _ypixelpermeter 0x130B //2835 , 72 DPI
#define pixel 0xFF
#pragma pack(push,1)
typedef struct{
    uint8_t signature[2];
    uint32_t filesize;
    uint32_t reserved;
    uint32_t fileoffset_to_pixelarray;
} fileheader;
typedef struct{
    uint32_t dibheadersize;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bitsperpixel;
    uint32_t compression;
    uint32_t imagesize;
    uint32_t ypixelpermeter;
    uint32_t xpixelpermeter;
    uint32_t numcolorspallette;
    uint32_t mostimpcolor;
} bitmapinfoheader;
// 24��Ʈ �̸� Į��� �ȷ�Ʈ�� �ʿ���
typedef struct{
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved;
} rgbquad;
typedef struct {
    fileheader fileheader;
    bitmapinfoheader bitmapinfoheader;
	rgbquad rgbquad[256]; // 8��Ʈ 256Į��(���)
} bitmap;
#pragma pack(pop)

int creatBitmapFile(unsigned char* pixelbuffer, int pic_width, int pic_height, char* file_name) {

	int _height = pic_height;
	int _width = pic_width;
	int _pixelbytesize = _height*_width*_bitsperpixel/8;
	int _filesize = _pixelbytesize+sizeof(bitmap);

	char bmpFile[256];
	sprintf(bmpFile,"%s.bmp",file_name);
    FILE *fp = fopen(bmpFile,"wb");
    bitmap *pbitmap  = (bitmap*)calloc(1,sizeof(bitmap));
	memset(pbitmap,0x00,sizeof(bitmap));

	// �������
    pbitmap->fileheader.signature[0] = 'B';
	pbitmap->fileheader.signature[1] = 'M';
    pbitmap->fileheader.filesize = _filesize;
    pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(bitmap);

	// �ȷ�Ʈ �ʱ�ȭ: ������� ����� �ݴϴ�.
	for(int i= 0; i < 256; i++) {
		pbitmap->rgbquad[i].rgbBlue = i;
		pbitmap->rgbquad[i].rgbGreen = i;
		pbitmap->rgbquad[i].rgbRed = i;
	}
	// �̹��� ���
    pbitmap->bitmapinfoheader.dibheadersize =sizeof(bitmapinfoheader);
    pbitmap->bitmapinfoheader.width = _width;
    pbitmap->bitmapinfoheader.height = _height;
    pbitmap->bitmapinfoheader.planes = _planes;
    pbitmap->bitmapinfoheader.bitsperpixel = _bitsperpixel;
    pbitmap->bitmapinfoheader.compression = _compression;
    pbitmap->bitmapinfoheader.imagesize = _pixelbytesize;
    pbitmap->bitmapinfoheader.ypixelpermeter = _ypixelpermeter ;
    pbitmap->bitmapinfoheader.xpixelpermeter = _xpixelpermeter ;
    pbitmap->bitmapinfoheader.numcolorspallette = 256;
    fwrite (pbitmap, 1, sizeof(bitmap),fp);
    fwrite(pixelbuffer,1,_pixelbytesize,fp);
    fclose(fp);
    free(pbitmap);
	return 1;
}
