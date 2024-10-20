#include<iostream>
#include<fstream>
using namespace std;
typedef struct node{
	node *last;
	int number;
	node *next;
}node;

class list{
	public:
		node *head;
		node *tail;
		int size;
};

list *init_list(){
	list *num_list=new list;
	node *new_node=new node;
	num_list->head=new_node;
	num_list->tail=new_node;
	num_list->size=0;
	
	new_node->last=NULL;
	new_node->next=NULL;
	return num_list;
}

void printList(list *num_list){
	list *list=num_list;
	node *headtemp=num_list->head;
	for(int i=0;i<list->size;i++){
		cout<<list->head->number<<endl;
		list->head=list->head->next;
	}
	list->head=headtemp;
}

void printReverseList(list *num_list){
	list *list=num_list;
	node *tailtemp=num_list->head;
	for(int i=0;i<list->size;i++){
		cout<<list->tail->number<<endl;
		list->tail=list->tail->last;
	}
	list->tail=tailtemp;
}
void insertNode(list *num_list,int pos,int number){
	node *new_node=new node;
	node *head=num_list->head;
	new_node->number=number;
	for(int i=2;i<pos;i++){
		head=head->next;
	}
	new_node->last=head;
	new_node->next=head->next;
	head->next->last=new_node;
	head->next=new_node; 
	num_list->size++;
	
}

void removeNode(list *num_list,int pos){
	node *pos_node=num_list->head;
	for(int i=0;i<pos;i++){
		pos_node=pos_node->next;
	}
	pos_node->next=pos_node->next->next;
	pos_node->next->last=pos_node;
	num_list->size--;
}

int main(){
	fstream data2;
	fstream data3;
	fstream data;
	list *num_list=init_list();
	list *num_list_data3=init_list();
	data2.open("data2.txt",ios::in);
	data3.open("data3.txt",ios::in);
	data.open("data.txt",ios::out);
	if(!data2.is_open()){
		cout<<"文件读取失败"<<endl; 
		return 0;
	}
	if(!data3.is_open()){
		cout<<"文件读取失败"<<endl; 
		return 0;
	}
	if(!data.is_open()){
		cout<<"文件读取失败"<<endl; 
		return 0;
	}
	while(!data2.eof()){
		if(num_list->size==0){
			data2>>num_list->head->number;
			num_list->size++;
		}else{
			node *new_node=new node;
			data2>>new_node->number;
			num_list->tail->next=new_node;
			new_node->last=num_list->tail;
			num_list->tail=new_node;
			num_list->size++;
		}
	}
	num_list->tail->next=NULL;

	cout<<"第一小问"<<endl; 
	insertNode(num_list,3,3456);
	printList(num_list);
	cout<<endl;
	cout<<"第二小问"<<endl; 
	
	
	while(!data3.eof()){
		if(num_list_data3->size==0){
			data3>>num_list_data3->head->number;
			num_list_data3->size++;
		}else{
			node *new_node=new node;
			data3>>new_node->number;
			num_list_data3->tail->next=new_node;
			new_node->last=num_list->tail;
			num_list_data3->tail=new_node;
			num_list_data3->size++;
		}
	}
	
	node *nodetmp1;
	nodetmp1 = num_list_data3->head;
	while (nodetmp1->next != NULL) {
	    nodetmp1 = nodetmp1->next;
	    node *nodetmp2 = num_list->head;
	    num_list->tail->next = nodetmp1;
	    nodetmp1->last = num_list->tail;
	    num_list->tail = nodetmp1;
	    num_list->size++;
	
	    bool duplicateFound = false;
	    while (nodetmp2 != num_list->tail) {
	        if (nodetmp1->number == nodetmp2->number) {
	            duplicateFound = true;
	            break;
	        }
	        nodetmp2 = nodetmp2->next;
	    }
	
	    if (duplicateFound) {
	        num_list->tail = num_list->tail->last;
	        num_list->tail->next = NULL;
	        nodetmp1 = nodetmp1->last;
	        num_list->size--;
	    }
	}

	node *tmp=num_list->head;
	for(int i=0;i<num_list->size;i++){
		data<<tmp->number<<endl;
		tmp=tmp->next;
	}
	cout<<endl;
	data.close();
	cout<<"第三小问"<<endl;
	printReverseList(num_list);
	
	cout<<"第四小问"<<endl;
	node *tmp1 = num_list->head;
	node *tmp2;
	while (tmp1 != NULL) {
	    tmp2 = tmp1->next;
	    while (tmp2 != NULL) {
	        if (tmp2->number == tmp1->number) {
	            tmp2->last->next = tmp2->next;
	            if (tmp2->next != NULL) {
	                tmp2->next->last = tmp2->last;
	            } else {
	                num_list->tail = tmp2->last;
	            }
	            node *toDelete = tmp2;
	            tmp2 = tmp2->next;
	            delete toDelete;
	        } else {
	            tmp2 = tmp2->next;
	        }
	    }
	    tmp1 = tmp1->next;
	}
	
	int array[num_list->size];
	node *tmp3=num_list->head;
	for(int i=0;i<num_list->size;i++){
		array[i]=tmp3->number;
		tmp3=tmp3->next;
	}

}
