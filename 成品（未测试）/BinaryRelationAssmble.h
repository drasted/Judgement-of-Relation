/*
题目:（关系性质的判断）
键盘输入A上的关系R的集合表示法（包括集合A），输出该关系的性质的判断结果。
给定表示有穷集上的关系的矩阵，判断该关系的性质。
团队：14计科二班离散二组
成员：卫孝贤、姜文彪、石俊、 陈劲宇，王泽宇
侯梦如、李玉霞、李道临、王弄笛、孙文倩
*/

/*
编写目标：设计程序框架和代码编写规范，代码编写工作分工
编写人：卫孝贤
编写时间：2015.12.3
引用文件：暂无
后续修改：暂无
*/

/*代码规范********1.代码文件头规范
编写目标：（文件内容，代码实现目标）
编写人：（姓名）
编写时间：(年.月.日)
引用文件：(需要一起编译的文件名或是无法由编译器自动导入的头文件名)
后续修改：(修改时间+修改内容)   //每一项修改换一行，格式上每项的时间和内容列对齐
*/

#ifndef BINARY_RELATION_ASSMBLE
#define BINARY_RELATION_ASSMBLE

#include<vector>
#include<string>

using std::vector;
using std::string;

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
	const T & getR1() const { return r1; }     //获取二元关系前一个元素的值
	const T & getR2() const { return r2; }     //获取二元关系后一个元素的值
	void setR1(const T & v1) { r1 = v1; }    //用v1设置第一个元素的值
	void setR2(const T & v2) { r2 = v2; }    //用v2设置第二个元素的值
};

/*代码规范********2.类方法规范
a.获取类私有变量值使用get___命名方法,修改类私有变量值使用set____命名方法，get或set后面的部分开头大写以示区别；
b.方法(函数)声明或者定义头后面加上//注释，注释包含函数功能，参数说明，返回值说明；
c.函数或方法中不修改的参数加上const前缀修饰，不修改调用其的对象的方法加上const后缀；
d.使用了模板类，使用方法很简单，定义模板类对象时 BRelation<T> a; T为希望将类声明中的T替换的类型
类外定义模板类方法的格式，以setR1()为例：
template<typename T>
void BRelation<T>::setR1(const T & v1){  }  即前一行加上template<typename T>，方法名称前加类名和作用域解析符::
e.命名使用英文单词,变量名和方法开头字母小写，可使用中间隔开的大写字母分开单词，类名首字母大写；
f.命名尽可能即使缺少注释也可一眼看出功能；
*/

template<typename T>
class BinaryRelationAssmble
{
private:
	vector<T> father;   //父集，即题目中的集合A
	vector< BRelation<T> > relation;  //二元关系的集合
	vector< vector<int> >  matrix;  //关系矩阵
	/*考虑到指针使用易引起的不明故障，以及代码整合后的复杂故障，这里使用STL中的最简单的向量vector来实现动态数组，
	  其原理类似于数据结构中的线性表可变数组，支持使用[]访问内部元素，vector<T>中的T表示动态数组中的元素类型，
	  这也是一种模板类，除了自动扩展长度外，vector还有很多便于操作的方法，例如将元素加至数组尾，插入删除元素等等。
	  vector的诸多方法可以自行查阅C++帮助文档，或是上文搜寻相关资料，使用还是较简单的
	*/


	/*代码规范********3.实现规范
	  a.字符串类型统一使用string类型而不是字符数组；
	  b.动态数组使用vector,其他用倒指针的地方另行讨论；
	  c.空指针统一使用NULL；
	*/

	/*（李玉霞）辅助函数，处理父集A变化时关系矩阵matrix的变化，即根据变化增加或删减行列*/
	void whenFatherChange();  //可使用vector类的erase()方法删除，resize()方法增加行，注意这是二维数组，行列都要修改

	/*(陈劲宇)辅助函数，将Matrix中所有元素置0*/
	void setMatrixZero();

	/*(王弄笛)设置二维数组matrix[i][j]的值,设置为值value*/
	void setMatrixValue(int i, int j, int value = 0);

	/* (侯梦茹)求出矩阵的乘积，用matrixp 表示其乘积*/
	void matrixProduct(vector< vector<int> > &  matrixp);

public:
	/*(陈劲宇)添加元素el到父集A*/
	void add_father(const T & el);
	/*（陈劲宇）变元素e1,e2为<el,e2>添加到二元关系集合relation*/
	void add_relation(const T & e1, const T & e2);

	/*(李道临)关系集合转换为关系矩阵（relation转为用matrix表示）
	以father集合对应元素的下标作为关系矩阵作为矩阵行列标志
	即  a b c
	a 0 1 0
	b 0 0 1
	c 1 1 0
	abc存储在father集合中，故可以用father[0]、father[1]father[2]分别表示
	即矩阵第一行表示为matrix[0][0]、matri[0][1]、matrix[0][2],值为0、1、0;
	以上为matrix二维动态数组存储关系矩阵的方式
	*/
	void relationTOmatrix();  //ps：中间的是to的大写,不是T和零
							  /*(李道临)关系矩阵转换为关系集合(matrix转换为relation)*/
	void matrixTOrelation();


	/*(王弄笛)获取matrix[i][j]值*/
	int getMatrixValue(int i, int j);
	/*(王弄笛)获取父集A，即father的元素数目*/
	int getFatherLength();
	/*(王弄笛)获取二元关系集合relation的元素数目*/
	int getRelationLength();
	/*(王弄笛)输入一个i行j列的矩阵*/
	bool inputMatrix();   //输入成功返回true，输入失败返回false（可以查一下cin的输入失败的一些情况做考虑）

	//关系判断一律以矩阵为基础，所以判断函数第一行先调用relationTOmatrix()将二元关系转换为矩阵
	/*(李玉霞)判断对象是否满足自反性,满足返回true,不满足返回false*/
	bool isReflexive();
	/*(李玉霞)判断对象是否满足反自反性,满足返回true,不满足返回false*/
	bool isIrreflexive();
	/*(侯梦茹)判断对象是否满足对称性,满足返回true,不满足返回false*/
	bool isSymmetric();
	/*(侯梦茹)判断对象是否满足反对称性,满足返回true,不满足返回false*/
	bool isAntisymmetric();
	/*(侯梦茹)判断对象是否满足传递性,满足返回true,不满足返回false*/
	bool isTransitive();

	/*(卫孝贤)main函数和控制台交互菜单*/

	/*清空父集和二元关系集合、矩阵*/
	void clear();
	
	/*判断父集或二元关系集合中是否有空*/
	bool has_empty();

	/*(石俊)输出父集元素*/
	void print_father();
	/*(石俊)输出关系集合*/
	void print_relation();
	/*(石俊)输出关系矩阵(可选)*/
	void print_matrix();
};


/*代码规范********4.编写规范
a.避免代码重复，重复的行尽量用循环代替，重复的块尽量用函数代替，为排除故障提供方便
b.main函数编写过程中使用各位编写的公有方法，各位在编写方法过程中也可以多调用已设计出的功能方法来实现
c.基本思路为支持矩阵输入和关系输入，转换为关系矩阵后判断是否满足相应性质;
*/

/*辅助函数，将Matrix中所有元素置0*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixZero() {//辅助函数，将Matrix中所有元素置0
	int m = getFatherLength();
	for (int i = 0; i<m; i++)//第一层循环; i为行，m为A现在所有的元素数目（使用_getFatherLength()获得）
		for (int j = 0; j<m; j++)//第二层循环；j为列
		{
			matrix[i][j] = 0;
		}
}

/*添加元素el到父集A*/
template<typename T>
void BinaryRelationAssmble<T>::add_father(const	T & e1) {//添加元素el到父集A

	father.push_back(e1);//添加元素e1

}

/*变元素e1,e2为<el,e2>添加到二元关系集合relation*/
template<typename T>
void BinaryRelationAssmble<T>::add_relation(const T & e1, const T & e2)//变元素e1,e2为<el,e2>添加到二元关系集合relation
{
	BRelation<T>  r(e1, e2);
	relation.push_back(r);
}

/*设置二维数组matrix[i][j]的值,设置为值value*/
template<typename T>
void BinaryRelationAssmble<T>::setMatrixValue(int i, int j, int value = 0)
{
	matrix[i][j] = value;
}


/*获取matrix[i][j]值*/
template<typename T>
int BinaryRelationAssmble<T>::getMatrixValue(int i, int j)
{
	return matrix[i][j];
}

/*获取父集A，即father的元素数目*/
template<typename T>
int BinaryRelationAssmble<T>::getFatherLength()
{
	return father.size();
}

/*获取二元关系集合relation的元素数目*/
template<typename T>
int BinaryRelationAssmble<T>::getRelationLength()
{
	return relation.size();
}


/*输入一个关系矩阵*/
template<typename T>
bool BinaryRelationAssmble<T>::inputMatrix()  //输入成功返回true，输入失败返回false（可以查一下cin的输入失败的一些情况做考虑）
{
	int  i, j;
	i = j = father.size();
	matrix.resize(i);
	int I, J;
	for (I = 0; I<i; I++)
		for (J = 0; J<j; J++)
		{
			int temp;
			cin >> temp;
			matrix[I].push_back(temp);
			if (cin.fail())
				return false;
		};
	return true;
}

//关系集合转换为关系矩阵的判断
template <typename T>
void BinaryRelationAssmble<T>::relationTOmatrix()
{
	/*int fnum = getFatherLength();//将矩阵的行数和列数赋给fnum
	int a, i, j, k;
	matrix.resize(fnum);
	for (a = 0; a<frum; a++)
		matrix[a].resize(fnum);
	*/
	int fnum = getFatherLength();
	int  i, j, k;
	whenFatherChange();
	setMatrixZero();
	for (k = 0; k < getRelationLength(); k++)//将关系集合的数目用k来表示
	{
		for (j = 0; j < fnum; j++)
		{
			for (i = 0; i < fnum; i++)
			{
				if (father[i] == relation[k].getR1() && father[j] == relation[k].getR2())
					matrix[i][j] = 1;
			}
		}
	}

}

//关系矩阵转换为关系集合的判断
template <typename T>
void BinaryRelationAssmble<T>::matrixTOrelation()
{
	int fnum = getFatherLength();
	relation.clear();//集合清空
	int i, j;
	for (i = 0; i < fnum; i++)
	{
		for (j = 0; j < fnum; j++)
		{
			if (matrix[i][j] == 1)
			{
				BRelation <T> a(father[i], father[j]);
				relation.push_back(a);
			}
			//else
				//cout << "关系不存在" << endl;
		}
	}
}

template<typename T>
void BinaryRelationAssmble<T>::print_father()
{
	int i;
	cout << "{";
	for (i = 0; i < father.size() - 1; i++)
		cout << father[i] << ",";
	cout << father[i] << "}";
}

template<typename T>
void BinaryRelationAssmble<T>::print_matrix()
{
	int i, j;
	for (i = 0; i < getFatherLength(); i++)
	{
		for (j = 0; j < getFatherLength(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

template<typename T>
void BinaryRelationAssmble<T>::print_relation()
{
	int i;
	cout << "{" ;
	for (i = 0; i<relation.size() - 1; i++)
		cout << "<" << relation[i].getR1() << "," << relation[i].getR2() << ">" << ",";
	cout << "<" << relation[i].getR1() << "," << relation[i].getR2() << ">";
	cout << "}" << endl;
}

/*(李玉霞)处理矩阵A变化时关系矩阵matrix的变化，即根据变化增加或删减行列*/
template<typename T>
void  BinaryRelationAssmble<T>::whenFatherChange()
{
	int i;
	int fnum = getFatherLength();					 // 将集合A元素数，即矩阵的行数和列数赋给fnum;
	matrix.resize(fnum);
	for (i = 0; i<fnum; i++)
		matrix[i].resize(fnum);
}

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
bool  BinaryRelationAssmble<T>::isIrreflexive()
{
	int i;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		if (matrix[i][i] == 1) //判断主对角线上元素是否为1
			return false;
	return true;
}

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
	int i, j;
	int fnum = getFatherLength();
	for (i = 0; i < fnum; i++)
		for (j = i; j < fnum; j++)						//对矩阵上半部分进行遍历判断，matrix[i][j]对称位置是否与其相等  
			if ((matrix[i][j] == 1) && (matrix[j][i] == 1))
				if (i != j)								// 判断对称位置相等的坐标是否在主对角线上
					return false;
	return true;
}


/* 求出矩阵的乘积，用matrixp 表示其乘积*/
template<typename T>
void  BinaryRelationAssmble<T>::matrixProduct(vector< vector<int> > &  matrixp)
{
	int i, k, j;   // 定义变量
	int temp = 0;	   //  用于存放乘积矩阵的值

	int fnum = getFatherLength();                  // 用fnum 存放矩阵的列和行  
													  /*  为乘积矩阵分配大小，并初始化为0*/
	matrixp.resize(fnum);
	for (i = 0; i < fnum; i++)
		matrixp[i].resize(fnum, 0);
	/* 进行乘积运算*/
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			temp = 0;
			for (k = 0; k < fnum; k++)                 // 求乘积矩阵相应坐标（i,j)的值       
				temp += getMatrixValue(i, k) * getMatrixValue(k, j);
			matrixp[i][j] = temp;
			/*if (temp != 0)                             //如果temp不为0，则将乘积矩阵坐标相应的值赋为1
				matrixp[i][j] = 1;
			else
				matrixp[i][j] = 0;*/
		}

}

/*(侯梦如)判断对象是否满足传递性,满足返回true,不满足返回false*/
template<typename T>
bool  BinaryRelationAssmble<T>::isTransitive()
{
	int fnum = getFatherLength();           //  用fnum 存放矩阵的列和行
	vector< vector<int> >  matrixp;
	matrixProduct(matrixp);                                   // 直接调用，不需要传递参数，乘积矩阵为全局变量

	int j, i;
	for (i = 0; i < fnum; i++)
		for (j = 0; j < fnum; j++)
		{
			if (matrixp[i][j] == 1)						   // 找出乘积矩阵中，值为1 的位置
			{
				if (matrix[i][j] != 1)						// 判断matrix矩阵中对应的位置是否为1,都为1 ，则传递
					return false;
			}
		}
	return  true;                                           // 到达次步骤，说明矩阵是传递的
}

/*清空父集和二元关系集合、矩阵*/
template<typename T>
void BinaryRelationAssmble<T>::clear()
{
	father.clear();
	relation.clear();
	setMatrixZero();
}

/*判断父集或二元关系集合中是否有空*/
template<typename T>
bool BinaryRelationAssmble<T>::has_empty()
{
	return father.empty() || relation.empty();
}

#endif


