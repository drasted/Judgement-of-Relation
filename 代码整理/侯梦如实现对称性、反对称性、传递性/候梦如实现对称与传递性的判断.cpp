#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
编写目标：实现二元关系：对称性、反对称性、传递性的判断
编写人：候梦如
编写时间：2015.12.8
调用头文件： "BinaryRelation.h"

*/

 /*(侯梦如)判断对象是否满足对称性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isSymmetric()
{
	int i, j;

	int fnum = getFatherLength();					 // 将集合A元素数，即矩阵的行数和列数赋给fnum;
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)					//对矩阵上半部分进行遍历判断，matrix[i][j]对称位置是否与其相等  
			if (matrix[i][j] != matrix[j][i])
				return false;
	return true;
}

/*(侯梦如)判断对象是否满足反对称性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isAntisymmetric()
{
	int i,j;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//对矩阵上半部分进行遍历判断，matrix[i][j]对称位置是否与其相等  
			if ((matrix[i][j] == 1) && (matrix[j][i] == 1))
				if(i!=j)								// 判断对称位置相等的坐标是否在主对角线上
				   return false;
	return true;
}


/* 求出矩阵的乘积，用matrixp 表示其乘积*/
static vector< vector<int> >  matrixp;          // 定义静态乘积矩阵
void    matrixProduct()
{    int i, k,j;   // 定义变量
	 int temp=0;	   //  用于存放乘积矩阵的值
	 BinaryRelationAssmble<int>  br;				     // 定义类变量
	
      int fnum = br.getFatherLength();                  // 用fnum 存放矩阵的列和行  
	  /*  为乘积矩阵分配大小，并初始化为0*/
	  matrixp.resize(fnum);      
	  for ( i = 0; i < fnum; i++)
		  matrixp[i].resize(fnum, 0);
        /* 进行乘积运算*/
	  for (i = 0; i < fnum; i++)
		  for (j = 0; j < fnum; j++)
		  {
			  for (k = 0; k < fnum; k++)                 // 求乘积矩阵相应坐标（i,j)的值       
				  temp += br.getMatrixValue(i, k) + br.getMatrixValue(k, j);
			  if (temp != 0)                             //如果temp不为0，则将乘积矩阵坐标相应的值赋为1
				  matrixp[i][j] = 1;
			  else                      
				  matrixp[i][j] = 0;
		  }

  }

/*(侯梦如)判断对象是否满足传递性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isTransitive( )
{
	int fnum = getFatherLength();							//  用fnum 存放矩阵的列和行
    matrixProduct();                                         // 直接调用，不需要传递参数，乘积矩阵为全局变量

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // 找出乘积矩阵中，值为1 的位置
			{
				if (matrix[i][j] == 1)						// 判断matrix矩阵中对应的位置是否为1,都为1 ，则传递
				   return true;
             }			 
		}
    return  false;                                           // 到达次步骤，说明矩阵是传递的
}




