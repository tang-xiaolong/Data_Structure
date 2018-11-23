/*
函数i2ba将int类型的整数n在内存中表示的每个字节按顺序转换成字节数组s中的每个元素值，返回指向数组首元素的指针
函数原型 unsigned char* i2ba(int n,unsigned char *s);
例如在Intel 32位CPU的机器上运行n=-2时，s的前4个元素为254,255,255,255
*/
#include<stdio.h>
#include<stdlib.h>
unsigned char* i2ba(int n,unsigned char *s);
int main(void)
{
	unsigned char *r = (unsigned char *)malloc(sizeof(char) * 4);
	r = i2ba(-2,r);
	printf("%d\t%d\t%d\t%d\t\n",r[0],r[1],r[2],r[3]);
	free(r);
	return 0;
}
unsigned char* i2ba(int n,unsigned char *s)
{
    s[0]=n&0xFF;//分别取出对应位上的值存进去即可
    s[1]=(n>>8)&0xFF;
    s[2]=(n>>16)&0xFF;
    s[3]=(n>>24)&0xFF;
    return s;
}
