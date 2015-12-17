#include<iostream>
#include<vector>
using namespace std;
void whenFatherChange(){
	vector<vector<int> >matrix(4);
	for(int i=0;i<4;i++)
		matrix[i].resize(4);
	for(i=0;i<4;i++)
		for(int j=0;j<4;j++)
			matrix[i][j]=(i*j);
		for(i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}
}
void main(){
	whenFatherChange();
}
