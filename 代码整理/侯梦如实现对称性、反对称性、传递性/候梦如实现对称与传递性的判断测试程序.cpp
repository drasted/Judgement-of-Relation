#include <iostream>
#include <vector>
using  namespace std;
using std::vector;


bool isSymmetric(vector< vector<int> >  matrix)
{
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = i; j < 4; j++)					//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ���������  
			if (matrix[i][j] != matrix[j][i])			
				return false;
	return true;
}

bool  isAntisymmetric(vector< vector<int> >  matrix)
{
	int i, j;
	int fnum = 4;
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//�Ծ����ϰ벿�ֽ��б����жϣ�matrix[i][j]�Գ�λ���Ƿ���������  
			
			if ((matrix[i][j]==1)&& (matrix[j][i]==1))
				if (i != j)								// �ж϶Գ�λ�����ȵ������Ƿ������Խ�����
				{
					//cout <<"i"<< i << "j"<<j<<endl;
					return false;
				}
	return true;
}
static vector< vector<int> >  matrixp;		
void    matrixProduct( vector< vector<int> >  matrix)
{		
	int i, k, j;   // ��������
	int temp = 0;	   //  ���ڴ��ų˻�������ֵ
				        // ����������													 //static vector< vector<int> >  matrixp;          // ���徲̬�˻�����
	int fnum = 4;                  // ��fnum ���ž������к���  
							  /*  Ϊ�˻�����������С������ʼ��Ϊ0*/
	matrixp.resize(fnum);
	for (i = 0; i < fnum; i++)
		matrixp[i].resize(fnum, 0);

	
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			for (k = 0; k < fnum; k++)                 // ���˻�������Ӧ���꣨i,j)��ֵ       
				temp += matrix[i][k] * matrix[k][j];

			if (temp != 0)                             //����temp��Ϊ0���򽫳˻�����������Ӧ��ֵ��Ϊ1
				matrixp[i][j] = 1;
			else
				matrixp[i][j] = 0;

		}

}
bool isTransitive(vector< vector<int> >  matrix)
{
	//vector< vector<int> >  matrixp;							// �����˻�����
	int fnum = 4;							//  ��fnum ���ž������к���
	matrixProduct(matrix);

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // �ҳ��˻������У�ֵΪ1 ��λ��
			{
				if (matrix[i][j] == 0)						// �ж�matrix�����ж�Ӧ��λ���Ƿ�Ϊ1����Ϊ1 ���򲻴���
					return false;
					
			}
		}
	return  true;                                           // �����β��裬˵�������Ǵ��ݵ�
}



int main()
{
	int i, j;
	vector< vector<int> >  matrix;
	//vector< vector<int> >  matrixp;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4,0);
	   matrix[2][1] = 0;
	   matrix[1][2] = 0;
	   matrix[1][1] = 0;
	   matrix[2][2] = 0;
	   matrix[1][3] = 0;
	   matrix[1][1] = 0;
	   matrix[3][3] = 0;
	   matrix[3][1] = 0;
	   cout << "���Ծ���:"<<endl;
	   for (i = 0; i < 4; i++)
		   for (j = 0; j < 4; j++)
		   {
			   cout << matrix[i][j];
			   if (j == 3)
				   cout << endl;

		   }
	   cout << "��Ԫ��ϵ�ж�:" << endl;
	   if (isSymmetric(matrix) == 1)
	   {
		   cout << "is Symmetric    " << endl;
	   }
	   else
	     cout << "is not Symmetric     "<<endl;
	   if (isAntisymmetric(matrix) == 1)
		   cout << "is  Antisymmetric      "<<endl;
	   else
		   cout << "is not Antisymmetric "<<endl;

			   matrixProduct(matrix);
			   if (isTransitive(matrix) == 1)
			   {
				   for (i = 0; i < 4; i++)
					   for (j = 0; j < 4; j++)
					   {
						   cout << matrixp[i][j];
						   if (j == 3)
							   cout << endl;

					   }
				
				   cout << "is  Transitive     " << endl;
			   }
	   else
		   cout << "is   not Transitive       "<<endl;
	   return 0;
}





