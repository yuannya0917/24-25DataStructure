#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream data1;
	data1.open("data1.txt",ios::in);
	if(!data1.is_open()){
		cout<<"¶ÁÈ¡ÎÄ¼şÊ§°Ü"<<endl;
		return 0; 
	}
	int number[30];
	int num=0;
	while(!data1.eof()){
		data1>>number[num];
		num++;
	}
	data1.close();
	cout<<"Ë³Ğò"<<endl;
	for(int i=0;i<num;i++){
		cout<<number[i]<<endl;
	} 
	cout<<endl<<"ÄæĞò"<<endl; 
	for(int i=num-1;i>=0;i--){
		cout<<number[i]<<endl;
	}
}
