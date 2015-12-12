#include <iostream>
#include <vector>
using namespace std;
using std::vector;


template<typename T>
class BRelation             //表示二元关系，即形如<1,2>
{
private:
	T r1;      //二元关系中的前一个元素
	T r2;      //二元关系中的后一个元素

public:
	BRelation(const T & v1, const T & v2)      //构造函数:将V1,V2赋值给r1,r2;
	{
		r1 = v1;
		r2 = v2;
	}
	T & getR1() { return r1; }   const   //获取二元关系前一个元素的值
		T & getR2() { return r2; }   const   //获取二元关系后一个元素的值
		void setR1(const T & v1) { r1 = v1; }    //用v1设置第一个元素的值
	void setR2(const T & v2) { r2 = v2; }    //用v2设置第二个元素的值
};

static vector< int >  father;
static vector< BRelation<int> > relation;
vector< vector<int> >   matrix;

void relationTOmatrix()//关系集合转换成关系矩阵
{
	int i, j, k;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4);//matrix定义为4行4列的数组
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 3; k++)
			{//如果父集中的元素所组成的关系属于已有的关系集合，则矩阵中的元素的值为1（数组的值为1），否则为0
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

void matrixTOrelation()//关系矩阵转换为关系集合
{
	int i, j, k;
	matrix.resize(4);
	for (i = 0; i < 4; i++)
		matrix[i].resize(4);//定义一个四行四列的数组
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (matrix[i][j] == 1)//如果矩阵中的元素的值为1，则证明该二元关系存在
				{
					relation[k].setR1(father[i]);//二元关系第一个元素的值
					relation[k].setR2(father[j]);//二元关系第二个元素的值
				}
				else
					cout << "关系不存在。" << endl;
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
		cout << "1.关系集合转换为关系矩阵" << endl;
		cout << "2.关系矩阵转换为关系集合" << endl;
		cout << "0.退出" << endl;
		cout << "请输入你的选择(0--2): ";
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