#include<iostream>
using namespace std;
typedef struct node{
	int loca;	//存储跳到的位置 
	int score;	//存储该位置的分数 
	node* next;
}node;
typedef struct list{
	node* head;
	int score;	//存储总分数 
}list;

void freeList(list* list){
	node* p=list->head;
	while(p!=NULL){
		node* tmp=p->next;
		delete p;
		p=tmp;
	}
	list->head=NULL;
} 
int main(){
	list* jump=new list;
	node* head=new node;
	jump->head=head;
	int tmp;
	cin>>tmp;
	jump->head->loca=tmp;
	jump->head->score=tmp;
	jump->score=0;
	jump->score+=tmp; 
	node* p=jump->head;
	
	while(1){
		cin>>tmp;
		if(tmp==0)break;
		node* newnode=new node;
		if(tmp==1){
			newnode->score=1;
			newnode->loca=tmp;
		}else if(tmp==2){
			newnode->loca=tmp;
			if(p->loca==2){
				newnode->score=p->score+2;
			}else{
				newnode->score=2;
			}
		}
		p->next=newnode;
		p=p->next;
		jump->score+=p->score;	
	}
	cout<<jump->score;
	freeList(jump);
	delete jump;
}
