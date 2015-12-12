#include <iostream>
#include "BinaryRelation.h"

using namespace std;

//关系集合转换为关系矩阵的判断
template <typename T>
void BinaryRelationAssmble<T>::relationTOmatrix()
{
	int fnum = getFatherLength();//将矩阵的行数和列数赋给fnum
	int a,i, j, k; 
	matrix.resize(fnum);
	for (a = 0;a<frum; a++)
	matrix[a].resize(fnum);
	for (i = 0; i < fnum ; i++)
	{
		for (j = 0; j < fnum; j++)
		{
			for (k = 0; k < getRelationLength(); k++)//将关系集合的数目用k来表示
			{
				if (father[i] == relation[k].getR1() && father[j] == relation[k].getR2())
					matrix[i][j]=1;
				else
					matrix[i][j] = 0;
			}
		}
	}

}

//关系矩阵转换为关系集合的判断
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
					cout << "关系不存在。" << endl;
			}
		}
	}


}
