#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char elemtype;

typedef struct LinkStack{  //定义链栈的结构体
  	elemtype data;
  	struct LinkStack *next;
}link;

link *initStack(link * s){  //初始化栈
  	s = (link *)malloc(sizeof(link));
  	s -> next = NULL;
  	return s;
}

link *PushStack(link * s,elemtype e){  //压栈
  	link *p =  (link *)malloc(sizeof(link)); 
  	p -> data = e;
  	p -> next = s -> next;  
  	s -> next = p;  //p结点成为新的首元节点
  	return s;
}

elemtype PopStack(link * s){  //出栈
  	elemtype e;
	link *p;
  	p = s -> next;
  	e = p -> data;
  	s -> next = p -> next;
  	free(p);
	return e;
}

int main() {
  	char a[20];
  	int i,l;
  	link *s;
  	elemtype e;
  	s = initStack(s);
  	fgets(a,100,stdin);
  	l = strlen(a);
  	for(i=0;i<l;i++){  //遍历字符数组a
    	
		
			if(a[i]=='('||a[i]=='['){  //如果遍历字符为左括号，则入栈
      		s = PushStack(s,a[i]);
      		} 
      
    	else if(a[i]==')'){  //如果遍历字符为右括号，则弹栈，看两括号是否同为小括号或中括号
    		if(s -> next != NULL){  //如果遍历到右括号时，栈内无左括号，直接结束循环
      			if(s -> next != NULL){
        			e = PopStack(s);
        			if(e == '('){continue;}
        			else{break;}
      			}
      			else{break;}
			}
			else{break;}
    	}
    		
    	else if(a[i]==']'){
    		if(s -> next != NULL){
      			if(s -> next != NULL){
        		e = PopStack(s);
        		if(e == '['){continue;}
        		else{break;}
     			}
      			else{break;}
      		}
      		else{break;}
    	}
    		else{continue;}  //如果遍历到其它字符，则继续遍历
	}
 	if(s -> next == NULL && i == l){
 		printf("括号匹配\n"); 
	}
	else{
		printf("括号不匹配\n");
	}
  	return 0;
}
