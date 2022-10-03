#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 5  //最大可存储的数据个数
typedef int elemtype;

typedef struct Deque{
	elemtype data[MAXNUM];
	int front,rear;
}deque;  //定义队列结构体

deque *initqueue(deque *q){  //初始化队列
	q = (deque*)malloc(sizeof(deque));
	q -> front = q -> rear = 0;
	return q;
}

void enque_head(deque *q,elemtype x){  //从head端输入数据
	if(q -> rear == q -> front - 1){printf("full\n");}  //当数据存储到倒数第二格时算为满队列
	else{
		q -> data[q -> rear] = x;
		q -> rear = (q -> rear + 1) % MAXNUM;  //循环队列是这样的
		printf("head:%d\n",x);
	} 
}

void enque_tail(deque *q,elemtype x){  //从tail端输入数据
	if(q -> rear == q -> front - 1){printf("full\n");}
	else{
		if(q -> front - 1 < 0){q -> front = MAXNUM - (q -> front) -1;}
		else{q -> front = q -> front - 1;}
		q -> data[q -> front] = x;
		printf("tail:%d\n",x);
	}
}

elemtype outqueue(deque *q){  //出队列
	elemtype x;
	x = q -> data[q -> front];
	q -> front = (q -> front + 1) % MAXNUM;
	return x;
}

void ifoutqueue(deque *q){  //判队列空||输出
	if(q -> front == q -> rear){printf("empty\n");}
	else{
		elemtype x;
		x = outqueue(q);
		printf("out:%d\n",x);
	}
}

int main(void){
	deque *q;
	q = initqueue(q);
	enque_head(q,1);
	enque_head(q,2);
	enque_head(q,3);
	enque_tail(q,4);
	enque_tail(q,5);
	ifoutqueue(q);
	ifoutqueue(q);
	ifoutqueue(q);
	ifoutqueue(q);
	ifoutqueue(q);
	ifoutqueue(q);
	return 0;
}