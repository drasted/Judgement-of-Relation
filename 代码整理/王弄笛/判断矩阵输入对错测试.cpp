/*����һ��i��j�еľ���  
����ɹ�����true������ʧ�ܷ���false*/
#include<iostream>
using namespace std;

int matrix[3][4];//ȫ�ֱ���

bool inputMatrix(int i,int j)
{
	int I,J;
	for (I=0;I<i;I++) 
		for (J=0;J<j;J++)
		{
			cin >> matrix[I][J];
			if (cin.fail()) //fail()������ĳ�Ա���������ս��еĲ���ʧ�ܣ��򷵻��棬���򷵻ؼ�
				return false;  //cin.fail()Ϊ�棬����false   
		 };
		return true;//cin.fail()Ϊ�٣�����ture
}


void main()
{
	cout<<"�����������еľ���"<<endl;
	if (inputMatrix(3,4)==false)
	{
		cout<<"����ʧ�ܣ�"<<endl;
	}
	else
	{
		cout<<"����ɹ���"<<endl;
	}
}