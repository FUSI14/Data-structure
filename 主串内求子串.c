#include <stdio.h>
#include <string.h>
#define MAXNUM 20

typedef struct{
	char data[MAXNUM];
	int length;
}SQstring;  //串结构体  

SQstring enstr(SQstring s){  //输入主串内容的函数
	int l;
	s.length = 0;
	printf("please input a string:");
	fgets(s.data,MAXNUM,stdin);
	l = strlen(s.data);
	s.length = s.length + l - 1;  //可连续使用该函数输入
	return s;
}

SQstring selstr(SQstring s,int m,int n){  //查找子串的函数，m为位置，n为长度
	SQstring str;
	int i;
	if(m + n <= s.length && m >= 0 && n >= 0){
		for(i=m;i<m+n;i++){
			str.data[i-m] = s.data[i];
		}
		str.length = n;
		return str;
	}
	else{printf("error");
		str.length = 0;  //以子串的length是否为0判定m,n输入是否正确
		return str;}
}

int main(void){
	SQstring s,str;
	int m,n,i;
	s = enstr(s);
	printf("please input m:");  //输入m，n
	scanf("%d",&m);
	printf("please input n:");
	scanf("%d",&n);
	str = selstr(s,m,n);
	if(str.length != 0){  //输出子串
		for(i=0;i<str.length;i++){
			printf("%c",str.data[i]);
		}
	}
	return 0;
}