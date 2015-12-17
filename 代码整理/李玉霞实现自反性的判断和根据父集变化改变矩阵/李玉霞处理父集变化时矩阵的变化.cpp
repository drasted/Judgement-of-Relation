#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
编写目标：处理矩阵A变化时关系矩阵matrix的变化
编写人：李玉霞
编写时间：2015.12.9
调用头文件： "BinaryRelation.h"

*/

 /*(李玉霞)处理矩阵A变化时关系矩阵matrix的变化，即根据变化增加或删减行列*/
template<typename T>
void  BinaryRelationAssmble<T>::whenFatherChange()
{
	int i;
    int fnum = getFatherLength();					 // 将集合A元素数，即矩阵的行数和列数赋给fnum;
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
