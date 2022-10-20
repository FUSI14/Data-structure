#include <stdio.h>
#include <string.h>
#define MAXNUM 20

typedef struct{
	char data[MAXNUM];
	int length;
}SQstring;  //���ṹ��  

SQstring enstr(SQstring s){  //�����������ݵĺ���
	int l;
	s.length = 0;
	printf("please input a string:");
	fgets(s.data,MAXNUM,stdin);
	l = strlen(s.data);
	s.length = s.length + l - 1;  //������ʹ�øú�������
	return s;
}

SQstring selstr(SQstring s,int m,int n){  //�����Ӵ��ĺ�����mΪλ�ã�nΪ����
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
		str.length = 0;  //���Ӵ���length�Ƿ�Ϊ0�ж�m,n�����Ƿ���ȷ
		return str;}
}

int main(void){
	SQstring s,str;
	int m,n,i;
	s = enstr(s);
	printf("please input m:");  //����m��n
	scanf("%d",&m);
	printf("please input n:");
	scanf("%d",&n);
	str = selstr(s,m,n);
	if(str.length != 0){  //����Ӵ�
		for(i=0;i<str.length;i++){
			printf("%c",str.data[i]);
		}
	}
	return 0;
}