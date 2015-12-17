#include <iostream>
#include "BinaryRelation.h"
using namespace std;

/*
��дĿ�꣺ʵ�ֶ�Ԫ��ϵ���Գ��ԡ����Գ��ԡ������Ե��ж�
��д�ˣ�������
��дʱ�䣺2015.12.8
����ͷ�ļ��� "BinaryRelation.h"

*/

 /*(������)�ж϶����Ƿ�����Գ���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isSymmetric()
{
	int i, j;

	int fnum = getFatherLength();					 // ������AԪ���������������������������fnum;
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)					//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ��������  
			if (matrix[i][j] != matrix[j][i])
				return false;
	return true;
}

/*(������)�ж϶����Ƿ����㷴�Գ���,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isAntisymmetric()
{
	int i,j;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ��������  
			if ((matrix[i][j] == 1) && (matrix[j][i] == 1))
				if(i!=j)								// �ж϶Գ�λ����ȵ������Ƿ������Խ�����
				   return false;
	return true;
}


/* �������ĳ˻�����matrixp ��ʾ��˻�*/
static vector< vector<int> >  matrixp;          // ���徲̬�˻�����
void    matrixProduct()
{    int i, k,j;   // �������
	 int temp=0;	   //  ���ڴ�ų˻������ֵ
	 BinaryRelationAssmble<int>  br;				     // ���������
	
      int fnum = br.getFatherLength();                  // ��fnum ��ž�����к���  
	  /*  Ϊ�˻���������С������ʼ��Ϊ0*/
	  matrixp.resize(fnum);      
	  for ( i = 0; i < fnum; i++)
		  matrixp[i].resize(fnum, 0);
        /* ���г˻�����*/
	  for (i = 0; i < fnum; i++)
		  for (j = 0; j < fnum; j++)
		  {
			  for (k = 0; k < fnum; k++)                 // ��˻�������Ӧ���꣨i,j)��ֵ       
				  temp += br.getMatrixValue(i, k) + br.getMatrixValue(k, j);
			  if (temp != 0)                             //���temp��Ϊ0���򽫳˻�����������Ӧ��ֵ��Ϊ1
				  matrixp[i][j] = 1;
			  else                      
				  matrixp[i][j] = 0;
		  }

  }

/*(������)�ж϶����Ƿ����㴫����,���㷵��true,�����㷵��false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isTransitive( )
{
	int fnum = getFatherLength();							//  ��fnum ��ž�����к���
    matrixProduct();                                         // ֱ�ӵ��ã�����Ҫ���ݲ������˻�����Ϊȫ�ֱ���

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // �ҳ��˻������У�ֵΪ1 ��λ��
			{
				if (matrix[i][j] == 1)						// �ж�matrix�����ж�Ӧ��λ���Ƿ�Ϊ1,��Ϊ1 ���򴫵�
				   return true;
             }			 
		}
    return  false;                                           // ����β��裬˵�������Ǵ��ݵ�
}




