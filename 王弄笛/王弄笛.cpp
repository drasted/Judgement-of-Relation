#include<iostream>
#include "BinaryRelation(框架和规范)1.1.h"

/*设置二维数组matrix[i][j]的值,设置为值value*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixValue(int i, int j, int value = 0)
{
	matrix[i][j] = value;
}


/*获取matrix[i][j]值*/
template<typename T>
int BinaryRelationAssmble<T>::getMatrixValue(int i, int j)
{
	return matrix[i][j];
}

/*获取父集A，即father的元素数目*/
template<typename T>
int BinaryRelationAssmble<T>::getFatherLength()
{
	return (int)father.size();
}

/*获取二元关系集合relation的元素数目*/
template<typename T>
int BinaryRelationAssmble<T>::getRelationLength()
{
	return relation.size();
}


/*输入一个i行j列的矩阵*/
template<typename T>
bool BinaryRelationAssmble<T>::inputMatrix(int i, int j)  //输入成功返回true，输入失败返回false（可以查一下cin的输入失败的一些情况做考虑）
{
	matrix.resize(i);
	int I, J;
	for (I = 0; I<i; I++)
	for (J = 0; J<j; J++)
	{
		T temp;
		cin >> temp;
		matrix[I].push_back（temp）;
		if (cin.fail())
			return false;
	};
	return true;
}

