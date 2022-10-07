#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
typedef int elemtype;

typedef struct stack{  //����ṹ��
    elemtype data[MAXNUM];
    int top;    
}stack;

stack *initstack(stack *s){  //��ʼ��ջ
    s = (stack*)malloc(sizeof(stack));  //���ٿռ�
    s -> top = 0;
    return s;
}

void enqueue(stack *s,elemtype x){  //����һ��ջ�������У�
    if(s -> top < MAXNUM){  //��ջ��
        s -> data[s -> top] = x;
        s -> top ++;
        printf("in:%d\n",x);
    }
    else{printf("full\n");}
}

elemtype outqueue(stack *s1,stack *s2){  //��ջ�������У�
    int i;
    elemtype x;
    if(s2 -> top == 0){  //����ڶ���ջ�ǿյģ��Ͱѵ�һ��ջ�ڵ�Ԫ��ȫ������ѹ��ڶ���ջ
        for(i=s1->top;i>0;i--){
            s1 -> top--;
            s2 -> data[s2 -> top] = s1 -> data[s1 -> top];
            s2 -> top++;
        }
    }
    s2 -> top --;  //�����ڶ���ջ�е�Ԫ��
    x = s2 -> data[s2 -> top];
    return x;
}

void ifout(stack *s1,stack *s2){  //��ջ�յĺ���
    elemtype x;
    if(s2 -> top == 0 && s1 -> top == 0){  //����ջ���յ�ʱ��Ϊ��ջ
        printf("empty\n");
    }
    else{
        x = outqueue(s1,s2);  //����ʱ���г�ջ����
        printf("out:%d\n",x);
    }
}
int main(void){
    stack *s1,*s2;  //��������ջ
    s1 = initstack(s1);
    s2 = initstack(s2);
    enqueue(s1,1);
    enqueue(s1,2);
    enqueue(s1,3);
    ifout(s1,s2);
    ifout(s1,s2);
	enqueue(s1,4);
    ifout(s1,s2);
    ifout(s1,s2);
    return 0;
}