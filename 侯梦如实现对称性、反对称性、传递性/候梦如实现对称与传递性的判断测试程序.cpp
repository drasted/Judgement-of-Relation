#include <iostream>
#include <vector>
using  namespace std;
using std::vector;


bool isSymmetric(vector< vector<int> >  matrix)
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = i; j < 4; j++)					//对矩阵上半部分进行遍历判断，matrix[i][j]对称位置是否与其相等  
			if (matrix[i][j] != matrix[j][i])			
				return false;
	return true;
}

bool  isAntisymmetric(vector< vector<int> >  matrix)
{
	int i, j;
	int fnum = 4;
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//对矩阵上半部分进行遍历判断，matrix[i][j]对称位置是否与其相等  
			
			if ((matrix[i][j]==1)&& (matrix[i][j]==1))
				if (i != j)								// 判断对称位置相等的坐标是否在主对角线上
				{
					//cout <<"i"<< i << "j"<<j<<endl;
					return false;
				}
	return true;
}
static vector< vector<int> >  matrixp;		
void    matrixProduct( vector< vector<int> >  matrix)
{		
	int i, k, j;   // 定义变量
	int temp = 0;	   //  用于存放乘积矩阵的值
				        // 定义类变量													 //static vector< vector<int> >  matrixp;          // 定义静态乘积矩阵
	int fnum = 4;                  // 用fnum 存放矩阵的列和行  
							  /*  为乘积矩阵分配大小，并初始化为0*/
	matrixp.resize(fnum);
	for (i = 0; i < fnum; i++)
		matrixp[i].resize(fnum, 0);

	
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			for (k = 0; k < fnum; k++)                 // 求乘积矩阵相应坐标（i,j)的值       
				temp += matrix[i][k] + matrix[k][j];

			if (temp != 0)                             //如果temp不为0，则将乘积矩阵坐标相应的值赋为1
				matrixp[i][j] = 1;
			else
				matrixp[i][j] = 0;

		}

}
bool isTransitive(vector< vector<int> >  matrix)
{
	//vector< vector<int> >  matrixp;							// 定义乘积矩阵
	int fnum = 4;							//  用fnum 存放矩阵的列和行
	matrixProduct(matrix);

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // 找出乘积矩阵中，值为1 的位置
			{
				if (matrix[i][j] == 1)						// 判断matrix矩阵中对应的位置是否为1，不为1 ，则不传递
					return true;
			}
		}
	return  false;                                           // 到达次步骤，说明矩阵是传递的
}



int main()
{
	int i, j;
	vector< vector<int> >  matrix;
	vector< vector<int> >  matrixp;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4,0);
	   matrix[2][1] = 1;
	   matrix[1][2] = 1;
	   matrix[1][1] = 1;
	   matrix[2][2] = 1;
	   matrix[1][3] = 1;
	   matrix[1][1] = 1;
	   matrix[3][3] = 1;
	   matrix[3][1] = 1;
	   cout << "测试矩阵:"<<endl;
	   for (i = 0; i < 4; i++)
		   for (j = 0; j < 4; j++)
		   {
			   cout << matrix[i][j];
			   if (j == 3)
				   cout << endl;

		   }
	   cout << "二元关系判断:" << endl;
	   if (isSymmetric(matrix) == 1)
		   cout << "is Symmetric    "<<endl;
	   else
		   cout << "is not Symmetric     "<<endl;
	   if (isAntisymmetric(matrix) == 1)
		   cout << "is  Antisymmetric      "<<endl;
	   else
		   cout << "is not Antisymmetric "<<endl;

			   matrixProduct(matrix);
	   if (isTransitive(matrix) == 1)
		   cout << "is  Transitive     "<<endl;
	   else
		   cout << "is   not Transitive       "<<endl;
	   return 0;
}





