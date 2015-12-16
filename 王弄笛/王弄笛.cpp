#include<iostream>
#include "BinaryRelation(��ܺ͹淶)1.1.h"

/*���ö�ά����matrix[i][j]��ֵ,����Ϊֵvalue*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixValue(int i, int j, int value = 0)
{
	matrix[i][j] = value;
}


/*��ȡmatrix[i][j]ֵ*/
template<typename T>
int BinaryRelationAssmble<T>::getMatrixValue(int i, int j)
{
	return matrix[i][j];
}

/*��ȡ����A����father��Ԫ����Ŀ*/
template<typename T>
int BinaryRelationAssmble<T>::getFatherLength()
{
	return (int)father.size();
}

/*��ȡ��Ԫ��ϵ����relation��Ԫ����Ŀ*/
template<typename T>
int BinaryRelationAssmble<T>::getRelationLength()
{
	return relation.size();
}


/*����һ��i��j�еľ���*/
template<typename T>
bool BinaryRelationAssmble<T>::inputMatrix(int i, int j)  //����ɹ�����true������ʧ�ܷ���false�����Բ�һ��cin������ʧ�ܵ�һЩ��������ǣ�
{
	matrix.resize(i);
	int I, J;
	for (I = 0; I<i; I++)
	for (J = 0; J<j; J++)
	{
		T temp;
		cin >> temp;
		matrix[I].push_back��temp��;
		if (cin.fail())
			return false;
	};
	return true;
}

