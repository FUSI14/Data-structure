#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct qnode{
	elemtype data;
	struct qnode *next;
}linkqueue;

linkqueue * initque(){  //初始化链式队列
	linkqueue *q = (linkqueue*)malloc(sizeof(linkqueue));
	q -> next = NULL;
	return q;
}

linkqueue * enque(linkqueue *rear,elemtype x){  //进队列
	linkqueue *p = (linkqueue*)malloc(sizeof(linkqueue));
	p -> data = x;
	p -> next = NULL;
	rear -> next = p;  //建立逻辑联系
	rear = p;  //指针后移
	printf("in:%d\n",x); 
	return rear;
}

elemtype outque(linkqueue *front,linkqueue *rear){  //出队列，front始终为头指针
	elemtype x;
	linkqueue *s;
	s = front -> next;
	x = s -> data;
	front -> next = s -> next;
	free(s);
	return x;
}

void ifout(linkqueue *front,linkqueue *rear){  //完整的出队列
	if(front -> next == NULL){printf("EMPTY\n");}  //判栈空
	else{
		elemtype x;
		x = outque(front,rear);
		printf("out:%d\n",x);
	}
}

int main(void){
	linkqueue *front,*rear;  //front留在开头
	rear = front = initque();
	rear = enque(rear,1);
	rear = enque(rear,2);
	rear = enque(rear,3);
	ifout(front,rear);
	ifout(front,rear);
	ifout(front,rear);
	ifout(front,rear);
	return 0;
}