#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
��дĿ�꣺ʵ�ֶ�Ԫ��ϵ���Է��ԡ����Է���
��д�ˣ�����ϼ
��дʱ�䣺2015.12.9
����ͷ�ļ��� "BinaryRelation.h"

*/

 /*(����ϼ)�ж϶����Ƿ������Է���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isReflexive()
{
	int i;
	int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	for (i = 0; i < fnum; i++)
		if (matrix[i][i] != 1)   //�ж����Խ�����Ԫ���Ƿ�Ϊ1
				return false;
	return true;
}

/*(����ϼ)�ж϶����Ƿ����㷴�Է���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isLrreflexive()
{
	int i;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		  if (matrix[i][i] == 1) //�ж����Խ�����Ԫ���Ƿ�Ϊ1
			  return false;
	return true;
}
