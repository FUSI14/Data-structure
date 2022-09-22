#include <stdio.h>
#include <stdlib.h>

typedef struct Link{
	Elemtype data;
	struct	Link *next;
}link;
link *initlink(){
	int i;
	link *p=NULL;  
	link *temp=(link*)malloc(sizeof(link));
	temp->data=1;
	temp->next=NULL;
	p=temp;
	for(i=2;i<5;i++){
		link *a=(link*)malloc(sizeof(link));
		a->data=i;
		a->next=NULL;
		temp->next=a;
		temp=temp->next;
	}
	return p;
}
void display(link *p){
	link *temp=p;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(void){
	link *p=NULL;
	p=initlink();
	display(p);
	return 0;
}
