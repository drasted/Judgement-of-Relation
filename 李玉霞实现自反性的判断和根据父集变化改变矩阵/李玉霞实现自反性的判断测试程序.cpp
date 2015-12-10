#include <iostream>
#include <vector>
using  namespace std;
using std::vector;

bool isReflexive(vector< vector<int> >  matrix)
{
	int i;
	for (i = 0; i < 4; i++) 
		if (matrix[i][i] != 1)//判断主对角线上的元素是否为1
			return false;
	return true;
}

bool  isLrreflexive(vector< vector<int> >  matrix)
{
	int i;
	int fnum = 4;
	for (i = 0; i < fnum; i++)					  
			if (matrix[i][i]==1)//判断主对角线上的元素是否为1
				return false;
	return true;
}		

int main()
{
	int i, j;
	vector< vector<int> >  matrix;
	vector< vector<int> >  matrixp;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4,0);
	matrix[0][0] = 1;
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
	   if (isReflexive(matrix) == 1)
		   cout << "is Reflexive"<<endl;
	   else
		   cout << "is not Reflexive     "<<endl;
	   if (isLrreflexive(matrix)==1)
		   cout << "is Lrreflexive      "<<endl;
	   else
		   cout << "is not Lrreflexive "<<endl;
	   return 0;
}





