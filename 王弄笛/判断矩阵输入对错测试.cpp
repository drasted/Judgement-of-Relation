/*输入一个i行j列的矩阵  
输入成功返回true，输入失败返回false*/
#include<iostream>
using namespace std;

int matrix[3][4];//全局变量

bool inputMatrix(int i,int j)
{
	int I,J;
	for (I=0;I<i;I++) 
		for (J=0;J<j;J++)
		{
			cin >> matrix[I][J];
			if (cin.fail()) //fail()流对象的成员函数，若刚进行的操作失败，则返回真，否则返回假
				return false;  //cin.fail()为真，返回false   
		 };
		return true;//cin.fail()为假，返回ture
}


void main()
{
	cout<<"输入三行四列的矩阵："<<endl;
	if (inputMatrix(3,4)==false)
	{
		cout<<"输入失败！"<<endl;
	}
	else
	{
		cout<<"输入成功！"<<endl;
	}
}