#include<iostream>
#include<cmath>
using namespace std;
typedef struct Node{
	int light;
	int sec;
	Node* next;
}Node;
typedef struct List{
	Node* head;
	int total=0;
}List;

void init_list(List* backHome,int num){
	backHome->head=new Node;
	backHome->head->next=NULL;
	Node* p=backHome->head;
	for(int i=1;i<num;i++){
		Node* newnode=new Node;
		p->next=newnode;
		p=p->next;
	}
	p->next=NULL;
}

void updatelist(List* list,Node* node,int r,int y,int g){
	Node* p=node;
	int tmp;
	if(p->light!=0){
		if(p->light==1){
			tmp=list->total+(r-p->sec);
		}else if(p->light==2){
			tmp=list->total+r+g+y-p->sec;
		}else if(p->light==3){
			tmp=list->total+r+g-p->sec;
		}
		tmp%=r+g+y;		//取余后判断在红绿黄哪个时间段 
		if(tmp>=r+g){
			p->sec=r+g+y+r-tmp;
		}else if(tmp<=r){
			p->sec=r-tmp;
		}else{
			p->sec=0;
		}
		
	}
	list->total+=p->sec;
	
}

void freeList(List* list){
	Node* p=list->head;
	while(p!=NULL){
		Node* tmp=p->next;
		delete p;
		p=tmp;
	}
	list->head=NULL;
} 
int main(){
	int r;
	int y;
	int g;
	int num;
	int ans=0;
	int tmp;
	cin>>r;
	cin>>y;
	cin>>g;
	cin>>num;
	List* backHome=new List;
	init_list(backHome,num);
	Node* p=backHome->head;
	for(int i=0;i<num;i++){
		cin>>p->light;
		cin>>p->sec;
		p=p->next;                 
	}
	
	p=backHome->head;
	for(int i=0;i<num;i++){
		updatelist(backHome,p,r,y,g);
		p=p->next;
	}
	
	cout<<backHome->total;
	freeList(backHome);
	delete backHome;
}
