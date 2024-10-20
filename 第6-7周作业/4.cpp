#include<iostream>
#include<fstream> 
using namespace std;
const int STACKSIZE=1000;
typedef struct stack{
	char* top;
	char* base;
	int stacksize;
}stack;

void initStack(stack& s){//ע������������ 
	s.base=new char[STACKSIZE];
	if(!s.base){
		cout<<"��ʼ��ʧ��"<<endl; 
	}else{
		s.top=s.base;
		s.stacksize=STACKSIZE;
	}
}

//��ջ 
void push(stack &s,char x){
	if(s.top-s.base>=s.stacksize){
		cout<<"ջ��"<<endl; 
		s.base=new char[s.stacksize+STACKSIZE];
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKSIZE;
	}else{
		*(s.top)=x;
		s.top+=1;
	}
}

//��ջ 
char pop(stack &s){
	if(s.top==s.base){
		cout<<"ջΪ��"; 
	}else{
		char x=*(s.top-1);	//����д-- 
		*(s.top)='\0';//ɾ��ջ����Ԫ�� 
		s.top-=1;//���ﲻ��д-- 
		return x;
	}
}

char getTop(stack &s){
	if(s.top!=s.base){
		return *(s.top-1);	//����д--	 
	}else{
		return 0;
	}
}

int main(){
	fstream data;
	data.open("data.txt",ios::in);
	if(!data.is_open()){
		cout<<"�ļ���ʧ��";
		return 0; 
	}
	stack string;
	initStack(string);
	int number=0;
	char tmp;
	while(data>>tmp){	//���ﲻҪдdata.eof()!!
	/*����д��
		char tmp;
		data>>tmp;*/
	 
		if(tmp=='['||tmp=='('||tmp=='{'){
			push(string,tmp);
		}
		if(tmp==']'){
			if(getTop(string)=='['){	//ע�⣡string.top 
				number++;
				pop(string);
			}else{
				push(string,tmp);
			}
		}
		
		if(tmp==')'){
			if(getTop(string)=='('){
				number++;
				pop(string);
			}else{
				push(string,tmp);
			}
		}
		
		if(tmp=='}'){
			if(getTop(string)=='{'){
				number++;
				pop(string);
			}else{
				push(string,tmp);
			} 
		}
	}
	cout<<"��"<<number<<"��"<<endl; 
	cout<<string.base;
	data.close();
	
	delete[] string.base;
	string.top=NULL;
	string.stacksize=0;
}
