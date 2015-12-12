#include <iostream>
#include <vector>
using namespace std;
using std::vector;


template<typename T>
class BRelation             //��ʾ��Ԫ��ϵ��������<1,2>
{
private:
	T r1;      //��Ԫ��ϵ�е�ǰһ��Ԫ��
	T r2;      //��Ԫ��ϵ�еĺ�һ��Ԫ��

public:
	BRelation(const T & v1, const T & v2)      //���캯��:��V1,V2��ֵ��r1,r2;
	{
		r1 = v1;
		r2 = v2;
	}
	T & getR1() { return r1; }   const   //��ȡ��Ԫ��ϵǰһ��Ԫ�ص�ֵ
		T & getR2() { return r2; }   const   //��ȡ��Ԫ��ϵ��һ��Ԫ�ص�ֵ
		void setR1(const T & v1) { r1 = v1; }    //��v1���õ�һ��Ԫ�ص�ֵ
	void setR2(const T & v2) { r2 = v2; }    //��v2���õڶ���Ԫ�ص�ֵ
};

static vector< int >  father;
static vector< BRelation<int> > relation;
vector< vector<int> >   matrix;

void relationTOmatrix()//��ϵ����ת���ɹ�ϵ����
{
	int i, j, k;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4);//matrix����Ϊ4��4�е�����
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 3; k++)
			{//��������е�Ԫ������ɵĹ�ϵ�������еĹ�ϵ���ϣ�������е�Ԫ�ص�ֵΪ1�������ֵΪ1��������Ϊ0
				if (father[i] == relation[k].getR1() && father[j] == relation[k].getR2())
				{
					matrix[i][j] = 1;
					cout << matrix[i][j];
				}
				else
				{
					matrix[i][j] = 0;
					cout << matrix[i][j];
				}
			}
		}
	}
}

void matrixTOrelation()//��ϵ����ת��Ϊ��ϵ����
{
	int i, j, k;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4);//����һ���������е�����
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (matrix[i][j] == 1)//��������е�Ԫ�ص�ֵΪ1����֤���ö�Ԫ��ϵ����
				{
					relation[k].setR1(father[i]);//��Ԫ��ϵ��һ��Ԫ�ص�ֵ
					relation[k].setR2(father[j]);//��Ԫ��ϵ�ڶ���Ԫ�ص�ֵ
				}
				else
					cout << "��ϵ�����ڡ�" << endl;
			}
		}
	}

}

int main()
{
	int i,j,menu,k;
	for (k = 0; k < 4; k++)
	{
		for (i = 0; i < 3; i++)
		{
			relation[i].setR1(k);
			relation[i].setR2(k);
		}
		i = k;
		j = k;
		father[k] = k;
		
	}
	
	do{
		cout << "1.��ϵ����ת��Ϊ��ϵ����" << endl;
		cout << "2.��ϵ����ת��Ϊ��ϵ����" << endl;
		cout << "0.�˳�" << endl;
		cout << "���������ѡ��(0--2): ";
		cin >> menu;
		switch (menu)
		{
		  case 1:relationTOmatrix();
			  break;
		  case 2:matrixTOrelation();
			  break;
		  case 0:exit(0);
		}
	} while (menu);
	
}