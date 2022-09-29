//刘紫潆-循环队列
#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 5
typedef int elemtype;

typedef struct qnote{
    elemtype data[MAXNUM];
    int front,rear;
}SQqueue;  //创建结构体变量

SQqueue *initqueue(SQqueue *q){ //初始化队列
    q = (SQqueue *)malloc(sizeof(SQqueue));
    q -> front = q -> rear = 0;
    return q;
}

SQqueue *enqueue(SQqueue *q,elemtype x){  //入队列
    if((q -> rear + 1) % MAXNUM == q -> front){return NULL;}  //留出一格分辨空队列和满队列，此为满队列判断
    q -> data[q -> rear] = x;
    q -> rear = (q -> rear + 1) % MAXNUM;
    return q;
}

elemtype outqueue(SQqueue *q){  //出队列
    elemtype x;
    x = q -> data[q -> front];
    q -> front = (q -> front + 1) % MAXNUM;
    return x;
}

void IFout(SQqueue *q){  //出队列的完整版
    if(q -> front != q -> rear){
        elemtype x;
        x = outqueue(q);
        printf("%d\n",x);
    }
    else {printf("空队列");}
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