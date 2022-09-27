#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char elemtype;

typedef struct LinkStack{  //������ջ�Ľṹ��
  	elemtype data;
  	struct LinkStack *next;
}link;

link *initStack(link * s){  //��ʼ��ջ
  	s = (link *)malloc(sizeof(link));
  	s -> next = NULL;
  	return s;
}

link *PushStack(link * s,elemtype e){  //ѹջ
  	link *p =  (link *)malloc(sizeof(link)); 
  	p -> data = e;
  	p -> next = s -> next;  
  	s -> next = p;  //p����Ϊ�µ���Ԫ�ڵ�
  	return s;
}

elemtype PopStack(link * s){  //��ջ
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
  	for(i=0;i<l;i++){  //�����ַ�����a
    	
		
			if(a[i]=='('||a[i]=='['){  //��������ַ�Ϊ�����ţ�����ջ
      		s = PushStack(s,a[i]);
      		} 
      
    	else if(a[i]==')'){  //��������ַ�Ϊ�����ţ���ջ�����������Ƿ�ͬΪС���Ż�������
    		if(s -> next != NULL){  //���������������ʱ��ջ���������ţ�ֱ�ӽ���ѭ��
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
    		else{continue;}  //��������������ַ������������
	}
 	if(s -> next == NULL && i == l){
 		printf("����ƥ��"); 
	}
	else{
		printf("���Ų�ƥ��");
	}
  	return 0;
}