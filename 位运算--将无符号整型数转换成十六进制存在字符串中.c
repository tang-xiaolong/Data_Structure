/*
#include<stdio.h>
#include<string.h>
int main(void) 
{
	int a = 5,b = 6;
	//char info[6] = "Hello";
	//char info1[6] = "PPPPP";
	char info[6] = {'h','e','l','l','o'};
	char info1[6] = "PPPPP";
	char c = 'A';
	int *p = NULL;
	float i = 1,j;
	int c1 = 1,c2 = 2,c3;
	c3 = 1.0/c2*c1;
	printf("c3 = %d\n",c3);
	j = ++i*++i;
	printf("i = %d  j = %d\n",i,j);
	switch(a)
	{
		case 3:puts("3");
		case 5:puts("5");
		case 4:puts("4");
		default:puts("0");
		case 1:puts("1");
	}
	printf("%d\n",sizeof(int)*a);
	printf("%d %d\n",sizeof*p,sizeof a);
	a = 1,2;//a到底是几？
	printf("a=%d\n",a); 
	puts(info);
	gets(info1);
	printf("%s\n",info);
	printf("%d\n",info[20]);
	putchar(info[0]);
	printf("\n%x  %x  %x\n",info,info1,info-info1);
	puts(info);
	puts(info1);
	printf("%d  %d\n",strlen(info),strlen(info1));
	return 0;
}
*/


//#include<stdio.h>
//int main(void) 
//{
//	int a = 5,b = 6;
//	int *p = NULL;
//	printf("%d\n",sizeof(int)*a);
//	printf("%d %d\n",sizeof*p,sizeof a);
//	a = 1,2;//a到底是几？
//	printf("a=%d\n",a); 
//	return 0;
//}

/*
#include<stdio.h>
int main(void)
{
	int a[5] = {1,2,3,4,5};
	int *p = (int *)(&a+1);//a本身已经是数组首元素的地址了 a就代表这个数组的地址  再取址相当于再套一个笼子  就成了数组的地址  即数组指针 int (*p)[5];  故&a+1并非往后移一个sizeof(a[0])   而是移sizeof(a)/sizeof(a[0]),也就正好移到了数组的外面，然后强行把这个转成一个int类型的指针，即此时p是int类型的指针  且指向了数组最后一个元素的后面，所以后面对p进行操作  又是一次移动sizeof(int)的长度了  p-1正好就是指向了数组的最后一个元素
	printf("%d\n",*(p-1));//需要额外注意的是，指针做运算与指针的二进制表示再做运算是完全不同的，指针运算依赖于这个指针的类型
	return 0;
}

*/
  
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
	int a[5] = {1,2,3,4,5};
	int i = 1;
	char str1[] = "HelloWorld\n";//数组除了在被运算符sizeof操作的时候不是直接看作地址外，其余都是可以直接等同于这个数组首元素的地址的。即一个指向首元素的指针
	char *str2 = "HelloWorld\n";
	char *str6 = {"HelloWorld\n"};
	char str3[] = {"HelloWorld\n"};//事实上等同于第一种 
	char str4[] = {'H','e','l','l','o','W','o','r','l','d','\n','\0'};
	char str5[] = {'H','e','l','l','o','W','o','r','l','d','\n'};//末尾没有加 \0 结束符  最后可能会输出该数组外内存里的东西
	printf("%d  %d   %d\n",a[i],i[a],3[a]);//当执行a[i]时   事实上等同于*(a+i);   而a + i  ==  i + a;  所以，我们用i[a]也可以达到目的  同样的  3[a]也是
	//str1[2] = 'M';    // 1
	printf(str1);
	//str1[2] = 'M';	// 2
	//str2 = "This a Test";	// 3
	printf(str2);
	printf(str3);
	printf(str4);
	printf(str5);
	printf("strlrnResult:  %d %d %d %d %d\n",strlen(str1),strlen(str2),strlen(str3),strlen(str4),strlen(str5));
	printf("sizeofResult:  %d %d %d %d %d\n",sizeof(str1)/sizeof(str1[0]),sizeof(str2)/sizeof(str2[0]),sizeof(str3)/sizeof(str3[0]),sizeof(str4)/sizeof(str4[0]),sizeof(str5)/sizeof(str5[0]));
	//strlrnResult:  11 11 11 11 23
    //sizeofResult:  12 4 12 12 11
	//第一个和第三个输出的结果不一样 是因为我们在定义字符数组的时候，如果非第四、五种定义方式，会自动为你补上一个NUL结束符作为字符的结束符。而sizeof(str1)是计算这个数组总共花费的内存大小 也就是它计算了结束符  strlen是以'\0'(即NUL,注：并不存在这样的保留字)为结束条件的，所以strlen未计算'\0‘
	//第二个输出的结果不一样 是因为str2是采用了字符指针的方式定义的，指针的长度在同一台电脑上所占的长度是一致的。（在32位电脑中应该是4）。因为不管是什么指针，它事实上就是一个地址，使用4个字节可以存下。故sizeof(str2)得到的是这个指针本身的大小。而strlen是将这个指针作为字符数组来对待的，因此计算的是字符数组的长度
	//第五个输出的结果不一样，是因为上者未在自己本来地盘（也就是自己申请的那块内存中）的最后加上'\0'，因此使用strlen会一直往后找，判断后面的是不是'\0'，直到找到或者产生错误。（注：极可能发生严重的错误，尽管我自己电脑并没有，它找到了str4的结束符并停止了）  而sizeof计算时，当时系统是为其分配了11个sizeof(str5[0])长度 所以结果为11
}
*/

/*
#include<stdio.h>
int main(void)
{
	const int a = 5;
	int b = 3;
	char *cp;
	const char *ccp;
	char **p;
	const char **pp;
	//pp = p;
	p == pp;
	//ccp = cp;
	//cp = ccp;
	b = a;
	//a = b;
	printf("a = %d  b = %d\n",a,b);
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
typedef union 
{
	long i;
	int k[4];
	char c;
}DATE;
struct data
{
	int cat;
	DATE cow;
	double dog;
}too;
DATE max;
int main(void)
{
	char aa[10];
	//const char ch1[] = "AD";
	//const char ch2[] = "AD";
	//if(ch1 == ch2)
	//	putchar('1');


	//printf("%d\n",strlen(aa));


	unsigned int a = 6;
	int b = -20;
	(a+b)>6?puts(">6"):puts("<6");
	printf("%u\n",a+b);
	printf("%d  %d\n",sizeof(too),sizeof(struct data) + sizeof(max));
	return 0;
}
*/

/*
#include<stdio.h>
int main(void)
{
	int a[2];
	printf("%d\n",sizeof(a));
	printf("%d\n",sizeof(int [4]));
	printf("%d\n",sizeof(int *[4]));
	printf("%d\n",sizeof(int (*)[4]));
	printf("%d\n",sizeof(int (*)()));
	return 0;
}
*/
#include<stdio.h>
char *ui2hex(unsigned n,char *s);
int main(void)
{
	char s[12] = "\0";
	unsigned int num;
	scanf("%u",&num);
	ui2hex(num,s);
	puts(s);
	return 0;
}
char *ui2hex(unsigned n,char *s)
{
	unsigned int mask = 0xF<<28;//1111 0000 0000 0000
	unsigned temp;
	int flag = 0;
	char *p = s;
	char info[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(;mask;mask>>=4)//从左到右，每次读取四位，判断是否大于0
	{
		temp = mask&n;
		while(temp > 15)//去掉多余的0  如取到的是 1001 0000  则需要去掉后面这四个0
			temp>>=4;
		if(flag || temp)//如果已经是碰到一个非0了，那不管是什么都存进去
		{
			flag = 1;
			*p++ = info[temp];	
		}
	}
	*p = '\0';
	return s;
}
