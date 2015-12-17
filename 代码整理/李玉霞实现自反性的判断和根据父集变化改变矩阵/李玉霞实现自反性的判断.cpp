#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
编写目标：实现二元关系：自反性、反自反性
编写人：李玉霞
编写时间：2015.12.9
调用头文件： "BinaryRelation.h"

*/

 /*(李玉霞)判断对象是否满足自反性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isReflexive()
{
	int i;
	int fnum = getFatherLength();					 // 将集合A元素数，即矩阵的行数和列数赋给fnum;
	for (i = 0; i < fnum; i++)
		if (matrix[i][i] != 1)   //判断主对角线上元素是否为1
				return false;
	return true;
}

/*(李玉霞)判断对象是否满足反自反性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isLrreflexive()
{
	int i;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		  if (matrix[i][i] == 1) //判断主对角线上元素是否为1
			  return false;
	return true;
}
