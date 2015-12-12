#include"console_menu_for_test.h"
#include"BinaryRelation(框架和规范)1.1.h"

void fun1();
void fun2();
void fun3();
void fun4();

BinaryRelationAssmble<char> test;

int main()
{
	ConsoleMenu menu;
	menu.add_options("输入父集合A");
	menu.add_functions(fun1);
	menu.add_options("输入关系集合R(2与3任选一输入即可进行判断)");
	menu.add_functions(fun2);
	menu.add_options("输入关系矩阵(2与3任选一输入即可进行判断)");
	menu.add_functions(fun3);
	menu.add_options("关系的综合判断(自反，反自反，对称，反对称，传递）");
	menu.add_functions(fun4);
	menu.run();
	return 0;
}

void fun1()
{
	cout << "本测试使用char类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << "请输入集合A中的元素，以文件结尾标志结束，windows中为Ctrl+Z" << endl;
	cout << endl << "实现暂无" << endl;
	/*****实现
	char c;
	while(cin >> c)
	{
		test.add_father(c);
	}
	*/
}

void fun2()
{
	cout << "本测试使用char类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << "父集A：";
	//test.print_father();
	cout << endl;
	cout << "请输入关系集合R中的元素，两个为一组，以文件结尾标志结束，windows中为Ctrl+Z" << endl;
	cout << endl << "实现暂无" << endl;
	/****实现
	char c1, c2;
	while (cin>>c1>>c2)
	{
		test.add_relation(c1, c2);
	}
	*/
}

void fun3()
{
	cout << "本测试使用char类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << "父集A：";
	//test.print_father();
	cout << endl;
	cout << "请输入关系矩阵，结束输入方式由inputMatrix(int i,int j)决定" << endl;
	cout << endl << "实现暂无" << endl;
	/****实现
	test.inputMatrix();
	*/
}

void fun4()
{
	cout << "本测试使用char类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << "父集A：";
	//test.print_father();
	cout << endl;
	cout << "关系集合R：";
	//test.print_relation();
	cout << endl;
	//(可选)cout << "关系矩阵：" << endl;
	//test.print_relation();
	//cout << endl;
	cout << "自反性";
	//cout << test.isReflexive; 
	cout << endl;
	cout << "反自反性";
	//cout << test.isIrreflexive;
	cout << endl;
	cout << "对称性";
	//cout << test.isSymmetric();
	cout << endl;
	cout << "反对称性";
	//cout << test.isAntisymmetric();
	cout << endl;
	cout << "传递性";
	//cout << test.isTransitive();
	cout << endl;
}