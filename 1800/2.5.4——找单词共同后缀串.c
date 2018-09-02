#include<stdio.h>
#include<malloc.h>
#define maxSize 20
typedef struct word
{
	char data;
	struct word *next;
}Word;
void Init(Word *List,char *info);
Word * FindSameLast(Word *str1,Word *str2); 
int main(void)
{
	char info1[maxSize],info2[maxSize];
	Word str1,str2;
	Word *p = NULL;
	scanf("%s%s",info1,info2);
	Init(&str1,info1);
	Init(&str2,info2);//初始化
	p = FindSameLast(&str1,&str2);
	if(p == NULL)
		printf("没有相同后缀串！\n");
	else
		printf("相同后缀串从%c开始\n",p->data);
	return 0;
}
Word * FindSameLast(Word *str1,Word *str2)
{
	int l1 = 0,l2 = 0,flag = 0;
	int i,j,k;
	
	Word *p = NULL,*q = NULL,*r = NULL;
	i = j = k = 0;
	//分别计算两个单词的长度，决定从什么位置开始比较
  //只要碰到不一样的，直接置空，否则，若不为空，则更新为当前位置
	p = str1->next;
	while(p)
	{
		++l1;
		p = p->next;
	}

	q = str2->next;
	while(q)
	{
		++l2;
		q = q->next;
	}
	k = l1-l2;
	if(k > 0)
		flag = 1;
	else
		flag = 2,k = -1*k;
	//根据flag决定哪个下标往后走
	p = str1->next;
	q = str2->next;
	if(flag == 1)
		while(i < k)
			p = p->next,++i;
	else
		while(j < k)
			q = q->next,++j;
	//移到指定位置后，就直接遍历到末尾即可
	while(p != NULL)
	{
		if(p->data != q->data)
			r = NULL;
		else if(r == NULL)
			r = p;
		p = p->next;
		q = q->next;
	}
	return r;
}
void Init(Word *List,char *info)
{
	char c;
	int i = 0;
	Word *p = List;
	while((c = info[i++]) != '\0')
	{
		p->next = (Word*)malloc(sizeof(Word));
		p = p->next;
		p->data = c;
	}
	p->next = NULL;
}
