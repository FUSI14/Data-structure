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

spmatrix fasttranmatrix(spmatrix s){
	spmatrix t;
	int a[N]={},b[N]={};
	int i;
	int k=0;
	t.length = s.length;
	t.cols = s.rows;
	t.rows = s.cols;
	for(i=0;i<s.length;i++){
		a[s.data[i].j]++;
	}
	for(i=1;i<s.rows;i++){
		b[i]=b[i-1]+a[i-1];
	}
	for(i=0;i<s.length;i++){
		t.data[b[s.data[i].j]].i = s.data[i].j;
		t.data[b[s.data[i].j]].j = s.data[i].i;
		t.data[b[s.data[i].j]].v = s.data[i].v;
		b[s.data[i].j]++;
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
	t = fasttranmatrix(s);
	print(t);
 	return 0;
}
