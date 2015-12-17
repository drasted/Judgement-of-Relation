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
					//cout << matrix[i][j];
				}
				else
				{
					matrix[i][j] = 0;
					//cout << matrix[i][j];
				}
			}
			cout << matrix[i][j];//
		}
		cout << endl;//
	}
}

void matrixTOrelation()//��ϵ����ת��Ϊ��ϵ����
{
	int fnum = 4;
	relation.clear();
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (matrix[i][j] == 1)
			{
				BRelation<int>  a(father[i], father[j]);
				relation.push_back(a);
			}
			else
				cout << "��ϵ������" << endl;
		}
	}

}

int main()
{
	int i, j;
	father.resize(4);
	for (i = 0; i < 4; i++)
		father[i] = i;
	//for (j = 0; j < 4; j++)
		//father[j] = j;
	cout << father[1] << '\n' << father[1] << endl;
	relation.push_back(BRelation<int>(1, 2)); //
	relation.push_back(BRelation<int>(2, 3)); //
	relation.push_back(BRelation<int>(0, 1)); //

	relationTOmatrix();
	cout << "���������,�����е�Ԫ��Ϊ1��0" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			cin >> matrix[i][j];
		//cout << endl;
	}
	matrixTOrelation();
	return 0;
}