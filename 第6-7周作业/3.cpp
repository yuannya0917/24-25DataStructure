#include<iostream>
#include<fstream>
using namespace std;
typedef struct node{
	int num;
	node* next;
}node; 

typedef struct list{
	node* head;
	int total;
}list;

void init_list(list* list){
	list->head=new node;
	node* tmp=list->head;
	for(int i=1;i<list->total;i++){	//!!!!i要从1开始 
		node *newnode=new node;
		tmp->next=newnode;
		tmp=tmp->next;
	}
	tmp->next=NULL;
}


void printList(list* list){
	node* tmp;
	tmp=list->head;
	while(tmp!=NULL){
		cout<<tmp->num<<endl;
		tmp=tmp->next;
	}
}

void sortList(list* list){
	node* tmp=list->head;
	
	node* p;		//存储临时量 
	node* p1;
	
	for(int i=0;i<list->total;i++){			//冒泡排序 
		tmp=list->head;
		for(int j=0;j<list->total;j++){
			p=tmp;
			p1=tmp->next;
			if(p1==NULL){
				break;
			}
			if(p->num>=p1->num){
				int temp=p->num;
				p->num=p1->num;
				p1->num=temp;
			}
			tmp=tmp->next;
		}
	}
}

void check(list* list){
	node* cur=list->head;
	node* cnext=NULL;	//后一个	 
	node* prev=NULL;	//前一个 
	
	while(cur!=NULL){
		prev=cur;
		cnext=cur->next;
		while(cnext!=NULL){
			if(cur->num==cnext->num){
				prev->next=cnext->next;
				delete cnext;
				cnext=prev->next;
				list->total--;
			}else{
				prev=cnext;
				cnext=cnext->next;
			}
		}
		cur=cur->next;
	}
	
	/*错误写法
		void check(list* list){
			node* cur;
			node* cnext;
			cur=list->head;
			cnext=cur->next;
				while(cur!=NULL){
					while(cur->num!=cnext->num){
						node* tmp;
						tmp=cnext;
						cur->next=cur->next->next;
						cnext=cur->next;
						delete tmp;
						list->total-=1;
					}
					cur=cur->next;
					cnext=cnext->next;
				} */
}

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
	fstream Testdata1;
	fstream Testdata2;
	Testdata1.open("Testdata1.txt",ios::in);
	Testdata2.open("Testdata2.txt",ios::in);
	if(!Testdata1.is_open()){
		cout<<"data1文件读取失败"; 
	}
	if(!Testdata2.is_open()){
		cout<<"data2文件读取失败"; 
	}
	list* list1=new list;	//这里要分配动态内存
	list* list2=new list;
	 
	Testdata1>>list1->total;
	Testdata2>>list2->total;
	init_list(list1);
	init_list(list2);
	
	//1
	node* tmp=list1->head;
	while(!Testdata1.eof()){
		Testdata1>>tmp->num;
		tmp=tmp->next;
	}
	cout<<"第一个链表"<<endl; 
	printList(list1);
	cout<<endl;
	
	tmp=list2->head;
	while(!Testdata2.eof()){
		Testdata2>>tmp->num;
		tmp=tmp->next;
	}
	cout<<"第二个链表"<<endl; 
	printList(list2);
	cout<<endl;
	
	//2
	cout<<"第二问"<<endl; 
	sortList(list1);
	printList(list1);
	cout<<endl; 
	
	sortList(list2);
	printList(list2);
	cout<<endl;
	
	//3
	cout<<"第三问"<<endl; 
	list* list3=new list;
	list3->total=list1->total+list2->total;
	init_list(list3);
	node* tail3=list3->head;
	node* tail1=list1->head;
	node* tail2=list2->head;
	for(int i=0;i<list1->total;i++){
		tail3->num=tail1->num;
		tail3=tail3->next;
		tail1=tail1->next;
	}
	for(int i=0;i<list2->total;i++){
		tail3->num=tail2->num;
		tail3=tail3->next;
		tail2=tail2->next;
	}
	sortList(list3);
	check(list3);
	printList(list3);
	
	freeList(list1);
	freeList(list2);
	freeList(list3);
	delete list1;
	delete list2;
	delete list3;
}
