#include"console_menu_for_test.h"
#include"BinaryRelationAssmble.h"

void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
string getbool(bool b);

BinaryRelationAssmble<int> test;

int main()
{
	ConsoleMenu menu;
	menu.add_options("添加输入父集合A");
	menu.add_functions(fun1);
	menu.add_options("添加输入关系集合R(2与3任选一输入即可进行判断)");
	menu.add_functions(fun2);
	menu.add_options("添加输入关系矩阵(2与3任选一输入即可进行判断)");
	menu.add_functions(fun3);
	menu.add_options("关系的综合判断(自反，反自反，对称，反对称，传递）");
	menu.add_functions(fun4);
	menu.add_options("清空父集A，二元关系集合R和矩阵，重新输入");
	menu.add_functions(fun5);
	menu.run();
	return 0;
}

void fun1()
{
	cout << "本测试使用int类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl << endl;
	cout << "请输入集合A中的元素，以文件结尾标志结束，windows中为Ctrl+Z" << endl;
	cout << "提示：为避免元素输入错误，建议在输入文件结尾标志前，先输入回车符！" << endl;
	int c;
	while(cin >> c)
	{
		test.add_father(c);
	}
	cout << "您输入的是：" << endl;
	test.print_father();
}

void fun2()
{
	cout << "本测试使用int类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << endl << "父集A：" ;
	test.print_father();
	cout << endl << endl;
	cout << "请输入关系集合R中的元素，两个为一组，以文件结尾标志结束，windows中为Ctrl+Z" << endl;
	cout << "提示：为避免元素输入错误，建议在输入文件结尾标志前，先输入回车符！" << endl;
	int c1, c2;
	while (cin>>c1>>c2)
	{
		test.add_relation(c1, c2);
	}
	test.relationTOmatrix();
	cout << "您输入的是：" << endl;
	test.print_relation();
}

void fun3()
{
	cout << "本测试使用int类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	cout << endl << "父集A：" ;
	test.print_father();
	cout << endl << endl;
	cout << "请输入关系矩阵，若父集A个数为n,则矩阵为n*n矩阵" << endl;
    test.inputMatrix();
	test.matrixTOrelation();
	cout << "您输入的为：" << endl;
	cout << "关系矩阵：" << endl;
	test.print_matrix();
}

void fun4()
{
	cout << "本测试使用int类型集合，但源代码支持各种类型，可简单修改类型参数后重新编译" << endl;
	if (test.has_empty())
	{
		cout << endl << "输入未完成，条件不足，无法判断！" << endl;
		return;
	}
	cout << "父集A：";
	test.print_father();
	cout << endl;
	cout << "关系集合R：";
	test.print_relation();
	cout << endl;
	cout << "关系矩阵：" << endl;
	test.print_matrix();
	cout << endl;
	cout << "自反性";
	cout <<"  "<< getbool(test.isReflexive()); 
	cout << endl;
	cout << "反自反性";
	cout << "  " << getbool(test.isIrreflexive());
	cout << endl;
	cout << "对称性";
	cout << "  " << getbool(test.isSymmetric());
	cout << endl;
	cout << "反对称性";
	cout << "  " << getbool(test.isAntisymmetric());
	cout << endl;
	cout << "传递性";
	cout << "  " << getbool(test.isTransitive());
	cout << endl;
}

string getbool(bool b)
{
	if (b)
		return "true";
	else
		return "false";
}

void fun5()
{
	cout << endl << "正在清空......" << endl;
	test.clear();
	cout << "清空完成！可重新输入！" << endl;
}