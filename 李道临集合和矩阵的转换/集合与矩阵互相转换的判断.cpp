#include <iostream>
#include "BinaryRelation.h"

using namespace std;

//��ϵ����ת��Ϊ��ϵ������ж�
template <typename T>
void BinaryRelationAssmble<T>::relationTOmatrix()
{
	int fnum = getFatherLength();//���������������������fnum
	int a,i, j, k; 
	matrix.resize(fnum);
	for (a = 0;a<frum; a++)
	matrix[a].resize(fnum);
	for (i = 0; i < fnum ; i++)
	{
		for (j = 0; j < fnum; j++)
		{
			for (k = 0; k < getRelationLength(); k++)//����ϵ���ϵ���Ŀ��k����ʾ
			{
				if (father[i] == relation[k].getR1() && father[j] == relation[k].getR2())
					matrix[i][j]=1;
				else
					matrix[i][j] = 0;
			}
		}
	}

}

//��ϵ����ת��Ϊ��ϵ���ϵ��ж�
template <typename T>
void BinaryRelationAssmble<T>::matrixTOrelation()
{
	int fnum = getFatherLength();
	int i, j, k,a;
	matrix.resize(fnum);
	for (a = 0; a<frum; a++)
		matrix[a].resize(fnum);
	for (i = 0; i < fnum; i++)
	{
		for (j = 0; j < fnum; j++)
		{
			for (k = 0; k < getRelationLength(); k++)
			{
				if (matrix[i][j] == 1)
					relation[k].getR1() = father[i];
				    relation[k].getR2() = father[j];
				else
					cout << "��ϵ�����ڡ�" << endl;
			}
		}
	}


}
