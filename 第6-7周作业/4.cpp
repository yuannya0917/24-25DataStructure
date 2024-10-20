#include<iostream>
#include<fstream> 
using namespace std;
const int STACKSIZE=1000;
typedef struct stack{
	char* top;
	char* base;
	int stacksize;
}stack;

void initStack(stack& s){//注意这里是引用 
	s.base=new char[STACKSIZE];
	if(!s.base){
		cout<<"初始化失败"<<endl; 
	}else{
		s.top=s.base;
		s.stacksize=STACKSIZE;
	}
}

//入栈 
void push(stack &s,char x){
	if(s.top-s.base>=s.stacksize){
		cout<<"栈满"<<endl; 
		s.base=new char[s.stacksize+STACKSIZE];
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKSIZE;
	}else{
		*(s.top)=x;
		s.top+=1;
	}
}

//出栈 
char pop(stack &s){
	if(s.top==s.base){
		cout<<"栈为空"; 
	}else{
		char x=*(s.top-1);	//不能写-- 
		*(s.top)='\0';//删除栈顶的元素 
		s.top-=1;//这里不能写-- 
		return x;
	}
}

char getTop(stack &s){
	if(s.top!=s.base){
		return *(s.top-1);	//不能写--	 
	}else{
		return 0;
	}
}

int main(){
	fstream data;
	data.open("data.txt",ios::in);
	if(!data.is_open()){
		cout<<"文件打开失败";
		return 0; 
	}
	stack string;
	initStack(string);
	int number=0;
	char tmp;
	while(data>>tmp){	//这里不要写data.eof()!!
	/*错误写法
		char tmp;
		data>>tmp;*/
	 
		if(tmp=='['||tmp=='('||tmp=='{'){
			push(string,tmp);
		}
		if(tmp==']'){
			if(getTop(string)=='['){	//注意！string.top 
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
	cout<<"有"<<number<<"对"<<endl; 
	cout<<string.base;
	data.close();
	
	delete[] string.base;
	string.top=NULL;
	string.stacksize=0;
}
