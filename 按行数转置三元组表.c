#include<stdio.h>
#define MAXNUM 20
#define M 6
#define N 6
typedef struct {
	int i,j;
	int v;
}node;

typedef struct{
	int cols,rows;
	int length;
	node data[MAXNUM];
}spmatrix;

spmatrix change(spmatrix s,int a[M][N]){
	int i,j;
	int k = 0;
	s.cols = M;
	s.rows = N;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(a[i][j]!=0){
				s.data[k].i = i;
				s.data[k].j = j;
				s.data[k].v = a[i][j];
				k++;
			}
		}
	}
	s.length = k;
	return s;
}

spmatrix tranmatrix(spmatrix s){
	spmatrix t;
	int i,j;
	int k=0;
	t.length = s.length;
	t.cols = s.rows;
	t.rows = s.cols;
	for(j=0;j<s.rows;j++){
		for(i=0;i<s.length;i++){
			if(s.data[i].j == j){
				t.data[k].i = s.data[i].j;
				t.data[k].j = s.data[i].i;
				t.data[k].v = s.data[i].v;
				k++;
			}
		}
	}
	return t;
}

void print(spmatrix s){
	int i;
	printf("i j v\n");
	for(i=0;i<s.length;i++){
		printf("%d %d %d\n",s.data[i].i,s.data[i].j,s.data[i].v);
	}
}

int main(){
	int a[M][N]={{15,0,0,22,0,-15},{0,11,3,0,0,0},{0,0,0,-6,0,0},{0,0,0,0,0,0},{91,0,0,0,0,0},{0,0,28,0,0,0}};
	spmatrix s;
	spmatrix t;
	s = change(s,a); 
	t = tranmatrix(s);
	print(t);
 	return 0;
}
