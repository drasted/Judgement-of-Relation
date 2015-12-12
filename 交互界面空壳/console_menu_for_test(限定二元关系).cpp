/*为二元关系的性质判断添加标题*/

#include"console_menu_for_test.h"

void ConsoleMenu::clear_input() const
{
	cin.clear();
	while (cin.get() != '\n');
}

void ConsoleMenu::fun_tail() const
{
	cout << endl << "按回车键返回主界面" << endl;
	clear_input();
	cin.get();
}

void ConsoleMenu::fun(const int i) const
{
	cout << i << "." << options[i] << endl << endl;
	(*(functions[i]))();
	fun_tail();
}

void ConsoleMenu::quit_menu()
{
	cout << "已退出" << endl;
	exit(0);
}

ConsoleMenu::ConsoleMenu()
{
	op_num = 1;
	fun_num = 1;
	title = '\0';
	options.push_back("退出");
	functions.push_back(&ConsoleMenu::quit_menu);
}

void ConsoleMenu::add_options(string s,int i)
{
	if (i < 0) i = op_num;
	options.resize(i + 1);
	options[i] = s;
	op_num++;
}

void ConsoleMenu::add_functions(void (*p)(void),int i)
{
	if (i < 0) i = fun_num;
	functions.resize(i + 1);
	functions[i] = p;
	fun_num++;
}

void ConsoleMenu::run() const
{
	unsigned int i, n;
	cout << "********************************************************************************" << endl;
	cout << "                 *********************************************                  " << endl;
	cout << "                 *                 题目                      *                  " << endl;
	cout << "                 *            关系性质的判断                 *                  " << endl;
	cout << "                 * 键盘输入A上的关系R的集合表示法(包括集合A）*                  " << endl;
	cout << "                 *        输出该关系的性质的判断结果。       *                  " << endl;
	cout << "                 *       给定表示有穷集上的关系的矩阵        *                  " << endl;
	cout << "                 *           判断该关系的性质。              *                  " << endl;
	cout << "                 *********************************************                  " << endl;
	cout << endl;
	for (i = 0; i < options.size(); i++)
	{
		cout << "  " << i << "." << options[i] << endl;
	}
	cout << endl;
	cout << "********************************************************************************" << endl;
	cout << "请输入您的选择：";
	cin >> n;
	while (1)
	{
		if (n >= options.size())      //不会c++异常处理，因此做简单处理
		{
			cerr << "Error:There is no this option!" << endl;
			return;
		}
		system("cls");
		fun(n);
		system("cls");
		cout << "********************************************************************************" << endl;
		cout << "                 *********************************************                  " << endl;
		cout << "                 *                 题目                      *                  " << endl;
		cout << "                 *            关系性质的判断                 *                  " << endl;
		cout << "                 * 键盘输入A上的关系R的集合表示法(包括集合A）*                  " << endl;
		cout << "                 *        输出该关系的性质的判断结果。       *                  " << endl;
		cout << "                 *       给定表示有穷集上的关系的矩阵        *                  " << endl;
		cout << "                 *           判断该关系的性质。              *                  " << endl;
		cout << "                 *********************************************                  " << endl;
		cout << endl;
		for (i = 0; i < options.size(); i++)
		{
			cout << "  " << i << "." << options[i] << endl;
		}
		cout << endl;
		cout << "********************************************************************************" << endl;
		cout << "请输入您的选择：";
		cin >> n;
	}
	
}