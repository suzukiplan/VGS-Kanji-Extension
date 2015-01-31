/* VGS Kanji Extension - sample code */
/* (C)2015, SUZUKI PLAN */
/* Author: Y.Suzuki Apr-2013 */
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "vgeapi.h"

static unsigned char* _kanji;
static unsigned short getcode(unsigned char sjis[2]);
static void putkanji(int x,int y,int col,const char* msg,...);

/*
 *----------------------------------------------------------------------------
 * Initialization
 * - Load KANJI.ROM from DSLOT255.
 *----------------------------------------------------------------------------
 */
int vge_init()
{
	size_t sz;
	_kanji=(unsigned char*)vge_getdata(255,&sz);
	return 0;
}

/*
 *----------------------------------------------------------------------------
 * Termination
 *----------------------------------------------------------------------------
 */
int vge_term()
{
	return 0;
}

/*
 *----------------------------------------------------------------------------
 * Main
 *----------------------------------------------------------------------------
 */
int vge_loop()
{
	size_t sz;
	/* read "こんにちは、世界!!\0"(SJIS) from DSLOT000.DAT, and print it. */
	putkanji(0,0,111,"%s",(char*)vge_getdata(0,&sz);
	return 0;
}

/*
 *----------------------------------------------------------------------------
 * PAUSE procedure (do not use)
 *----------------------------------------------------------------------------
 */
int vge_pause()
{
	return 1;
}

/*
 *----------------------------------------------------------------------------
 * get sequencial JIS X 0208 code that started from 0, from SJIS
 *----------------------------------------------------------------------------
 */
static unsigned short getcode(unsigned char sjis[2])
{
	unsigned char jis[2];
	unsigned short ret;
	jis[0]=sjis[0];
	jis[1]=sjis[1];
	if(jis[0]<=0x9f) {
		jis[0]-=0x71;
	} else {
		jis[0]-=0xb1;
	}
	jis[0]*=2;
	jis[0]++;
	if(jis[1]>=0x7F) {
		jis[1]-=0x01;
	}
	if(jis[1]>=0x9e){
		jis[1]-=0x7d;
		jis[0]++;
	} else {
		jis[1]-=0x1f;
	}
	ret=(jis[0]-0x21)*94;
	ret+=jis[1]-0x21;
	return ret;
}

/*
 *----------------------------------------------------------------------------
 * putkanji
 *----------------------------------------------------------------------------
 */
static void putkanji(int x,int y,int col,const char* msg,...)
{
	char buf[256];
	int i,j,k;
	unsigned char c[2];
	int jis;
	unsigned char bin;
	va_list args;

	va_start(args,msg);
	vsprintf(buf,msg,args);
	va_end(args);

	for(i=0;'\0'!=(c[0]=(unsigned char)buf[i]);i++) {
		if(c[0]&0x80) {
			c[1]=(unsigned char)buf[i+1];
			jis=(int)getcode(c);
			jis*=12;
			for(j=0;j<12;j++) {
				bin=_kanji[jis+j];
				for(k=0;k<8;k++,bin<<=1) {
					if(bin&0x80) {
						vge_pixelSP(x+k,y+j,col);
					}
				}
			}
			x+=8;
			i++;
		} else {
			c[0]-=0x20;
			vge_putSPM(255,c[0]%16*4,c[0]/16*12,4,12,x,y,col);
			x+=4;
		}
	}
}
