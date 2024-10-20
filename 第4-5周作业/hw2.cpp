#include<iostream>
#include<fstream>
using namespace std;
bool is_repeat(int num,int arr[],int arrlen,int tmp){
	for(int i=tmp;i<arrlen;i++){
		if(num==arr[i]){
			return 1;
		}
	}
	return 0;
}

int main(){
	fstream data2;
	fstream data3;
	fstream data;
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
	int number[30];
	int num=0;
	
	//1
	while(!data2.eof()){
		data2>>number[num];
		num++;
	}
	//2
	for(int i=num;i>=2;i--){
		number[i]=number[i-1];
		if(i==2){
			number[i]=3456;
		}
	}
	num++;
	
	//3
	int number1[30];
	int num1=0;
	while(!data3.eof()){
		data3>>number1[num1];
		num1++;
	}
	int numtmp=0;
	int number2[50];
	for(int i=0;i<num;i++){
		number2[numtmp]=number[i];
		numtmp++;
		for(int j=i+1;j<num;j++){
			if(number[i]==number[j]){
				numtmp--;
				break;
			}
		}
		
	}

	for(int i=0;i<num1;i++){
		if(!is_repeat(number1[i],number,num,0)){
			number2[numtmp]=number1[i];
			numtmp++;
		}
	}
	cout<<numtmp;
	for(int i=0;i<numtmp;i++){
		data<<number2[i]<<endl;
	}
	data2.close();
	data3.close();
	data.close();
}
