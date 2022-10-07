#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
typedef int elemtype;

typedef struct stack{  //定义结构体
    elemtype data[MAXNUM];
    int top;    
}stack;

stack *initstack(stack *s){  //初始化栈
    s = (stack*)malloc(sizeof(stack));  //开辟空间
    s -> top = 0;
    return s;
}

void enqueue(stack *s,elemtype x){  //进第一个栈（进队列）
    if(s -> top < MAXNUM){  //判栈满
        s -> data[s -> top] = x;
        s -> top ++;
        printf("in:%d\n",x);
    }
    else{printf("full\n");}
}

elemtype outqueue(stack *s1,stack *s2){  //出栈（出队列）
    int i;
    elemtype x;
    if(s2 -> top == 0){  //如果第二个栈是空的，就把第一个栈内的元素全部弹出压入第二个栈
        for(i=s1->top;i>0;i--){
            s1 -> top--;
            s2 -> data[s2 -> top] = s1 -> data[s1 -> top];
            s2 -> top++;
        }
    }
    s2 -> top --;  //弹出第二个栈中的元素
    x = s2 -> data[s2 -> top];
    return x;
}

void ifout(stack *s1,stack *s2){  //判栈空的函数
    elemtype x;
    if(s2 -> top == 0 && s1 -> top == 0){  //两个栈都空的时候即为空栈
        printf("empty\n");
    }
    else{
        x = outqueue(s1,s2);  //不空时运行出栈函数
        printf("out:%d\n",x);
    }
}
int main(void){
    stack *s1,*s2;  //声明两个栈
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