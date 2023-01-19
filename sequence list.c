#include <stdio.h>
#define MAXNUM 20

typedef int elemtype;
typedef struct list{
	elemtype elem[MAXNUM];
	int length;
}sqlist;

void print(sqlist L){
	int i;
	printf("List:");
	for(i=0;i<L.length;i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

sqlist createlist(sqlist L){
	int i;
	printf("please input the length:");
	scanf("%d",&L.length);
	printf("please input the numbers:");
	for(i=0;i<L.length;i++){
		scanf("%d",&L.elem[i]);
	}
	return L;
}

sqlist add(sqlist L){
	int i;
	int p;
	int n;
	printf("please input the place:");
	scanf("%d",&p);
	printf("please input the number:");
	scanf("%d",&n);
	for(i=L.length;i>p;i--){
		L.elem[i]=L.elem[i-1];
	}
	L.elem[p]=n;
	L.length++;
	return L;
}

sqlist delete(sqlist L){
	int i;
	int p;
	printf("please input the place:");
	scanf("%d",&p);
	for(i=p+1;i<=L.length;i++){
		L.elem[i-1]=L.elem[i];
	}
	L.length--;
	return L;
}

void print(sqlist L){
	int i;
	for(i=0;i<L.length;i++){
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

int main(void){
	sqlist L;
	L = createlist(L);
	print(L);
	L = add(L);
	print(L);
	L = delete(L);
	print(L);
	return 0;
}