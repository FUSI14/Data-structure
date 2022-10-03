#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 5  //���ɴ洢�����ݸ���
typedef int elemtype;

typedef struct Deque{
	elemtype data[MAXNUM];
	int front,rear;
}deque;  //������нṹ��

deque *initqueue(deque *q){  //��ʼ������
	q = (deque*)malloc(sizeof(deque));
	q -> front = q -> rear = 0;
	return q;
}

void enque_head(deque *q,elemtype x){  //��head����������
	if(q -> rear == q -> front - 1){printf("full\n");}  //�����ݴ洢�������ڶ���ʱ��Ϊ������
	else{
		q -> data[q -> rear] = x;
		q -> rear = (q -> rear + 1) % MAXNUM;  //ѭ��������������
		printf("head:%d\n",x);
	} 
}

void enque_tail(deque *q,elemtype x){  //��tail����������
	if(q -> rear == q -> front - 1){printf("full\n");}
	else{
		if(q -> front - 1 < 0){q -> front = MAXNUM - (q -> front) -1;}
		else{q -> front = q -> front - 1;}
		q -> data[q -> front] = x;
		printf("tail:%d\n",x);
	}
}

elemtype outqueue(deque *q){  //������
	elemtype x;
	x = q -> data[q -> front];
	q -> front = (q -> front + 1) % MAXNUM;
	return x;
}

void ifoutqueue(deque *q){  //�ж��п�||���
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