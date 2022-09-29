//������-ѭ������
#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 5
typedef int elemtype;

typedef struct qnote{
    elemtype data[MAXNUM];
    int front,rear;
}SQqueue;  //�����ṹ�����

SQqueue *initqueue(SQqueue *q){ //��ʼ������
    q = (SQqueue *)malloc(sizeof(SQqueue));
    q -> front = q -> rear = 0;
    return q;
}

SQqueue *enqueue(SQqueue *q,elemtype x){  //�����
    if((q -> rear + 1) % MAXNUM == q -> front){return NULL;}  //����һ��ֱ�ն��к������У���Ϊ�������ж�
    q -> data[q -> rear] = x;
    q -> rear = (q -> rear + 1) % MAXNUM;
    return q;
}

elemtype outqueue(SQqueue *q){  //������
    elemtype x;
    x = q -> data[q -> front];
    q -> front = (q -> front + 1) % MAXNUM;
    return x;
}

void IFout(SQqueue *q){  //�����е�������
    if(q -> front != q -> rear){
        elemtype x;
        x = outqueue(q);
        printf("%d\n",x);
    }
    else {printf("�ն���");}
}
int main(void){
    SQqueue *q;
    q = initqueue(q);
    q = enqueue(q,1);
    q = enqueue(q,2);
    q = enqueue(q,3);
    q = enqueue(q,4);
    IFout(q);
    IFout(q);
    IFout(q);
    IFout(q);
    IFout(q);
    
    return 0;
}