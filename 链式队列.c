#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct qnode{
	elemtype data;
	struct qnode *next;
}linkqueue;

linkqueue * initque(){  //��ʼ����ʽ����
	linkqueue *q = (linkqueue*)malloc(sizeof(linkqueue));
	q -> next = NULL;
	return q;
}

linkqueue * enque(linkqueue *rear,elemtype x){  //������
	linkqueue *p = (linkqueue*)malloc(sizeof(linkqueue));
	p -> data = x;
	p -> next = NULL;
	rear -> next = p;  //�����߼���ϵ
	rear = p;  //ָ�����
	printf("in:%d\n",x); 
	return rear;
}

elemtype outque(linkqueue *front,linkqueue *rear){  //�����У�frontʼ��Ϊͷָ��
	elemtype x;
	linkqueue *s;
	s = front -> next;
	x = s -> data;
	front -> next = s -> next;
	free(s);
	return x;
}

void ifout(linkqueue *front,linkqueue *rear){  //�����ĳ�����
	if(front -> next == NULL){printf("EMPTY\n");}  //��ջ��
	else{
		elemtype x;
		x = outque(front,rear);
		printf("out:%d\n",x);
	}
}

int main(void){
	linkqueue *front,*rear;  //front���ڿ�ͷ
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