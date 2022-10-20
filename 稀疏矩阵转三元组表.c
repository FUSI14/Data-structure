#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20

typedef struct {
	int i,j;
	int v;
}node;  //三元组表结构体

typedef struct{
	node data[MAXNUM];
}matrix;  //用来计数的结构体

void change(matrix n,int a[6][6]){  //将稀疏矩阵转为三元组表并输出的函数
	int i,j,k=0;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(a[i][j]!=0){
				n.data[k].i = i;
				n.data[k].j = j;
				n.data[k].v = a[i][j];
				k++;
			}
		}
	}
	for(i=0;i<k;i++){
		printf("%d %d %d\n",n.data[i].i,n.data[i].j,n.data[i].v);
	}
}

int main(void){
	int a[6][6]={{15,0,0,22,0,-15},{0,11,3,0,0,0},{0,0,0,-6,0,0},{0,0,0,0,0,0},{91,0,0,0,0,0},{0,0,28,0,0,0}};  //导入一个稀疏矩阵
	matrix n={};
	printf("after:\n");
	change(n,a);
	return 0;
}
