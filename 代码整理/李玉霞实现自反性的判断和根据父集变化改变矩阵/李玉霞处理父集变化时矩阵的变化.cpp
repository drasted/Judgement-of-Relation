#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
��дĿ�꣺�������A�仯ʱ��ϵ����matrix�ı仯
��д�ˣ�����ϼ
��дʱ�䣺2015.12.9
����ͷ�ļ��� "BinaryRelation.h"

*/

 /*(����ϼ)�������A�仯ʱ��ϵ����matrix�ı仯�������ݱ仯���ӻ�ɾ������*/
template<typename T>
void  BinaryRelationAssmble<T>::whenFatherChange()
{
	int i;
    int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	vector<vector<int> >matrix(fnum);
	for(int i=0;i<fnum;i++)
		matrix[i].resize(fnum);
	for(i=0;i<fnum;i++)
		for(int j=0;j<fnum;j++)
			matrix[i][j]=(i*j);
		for(i=0;i<fnum;i++)
		{
			for(int j=0;j<fnum;j++)
				cout<<matrix[i][j]<<" ";
			cout<<endl;
		}
}
