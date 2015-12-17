/*Ϊ��Ԫ��ϵ�������ж���ӱ���*/

#include"console_menu_for_test.h"

void ConsoleMenu::clear_input() const
{
	cin.clear();
	while (cin.get() != '\n');
}

void ConsoleMenu::fun_tail() const
{
	cout << endl << "���س�������������" << endl;
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
	cout << "���˳�" << endl;
	exit(0);
}

ConsoleMenu::ConsoleMenu()
{
	op_num = 1;
	fun_num = 1;
	title = '\0';
	options.push_back("�˳�");
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
	cout << "                 *                 ��Ŀ                      *                  " << endl;
	cout << "                 *            ��ϵ���ʵ��ж�                 *                  " << endl;
	cout << "                 * ��������A�ϵĹ�ϵR�ļ��ϱ�ʾ��(��������A��*                  " << endl;
	cout << "                 *        ����ù�ϵ�����ʵ��жϽ����       *                  " << endl;
	cout << "                 *       ������ʾ����ϵĹ�ϵ�ľ���        *                  " << endl;
	cout << "                 *           �жϸù�ϵ�����ʡ�              *                  " << endl;
	cout << "                 *********************************************                  " << endl;
	cout << endl;
	for (i = 0; i < options.size(); i++)
	{
		cout << "  " << i << "." << options[i] << endl;
	}
	cout << endl;
	cout << "********************************************************************************" << endl;
	cout << "����������ѡ��";
	cin >> n;
	while (1)
	{
		if (n >= options.size())      //����c++�쳣����������򵥴���
		{
			cerr << "Error:There is no this option!" << endl;
			return;
		}
		system("cls");
		fun(n);
		system("cls");
		cout << "********************************************************************************" << endl;
		cout << "                 *********************************************                  " << endl;
		cout << "                 *                 ��Ŀ                      *                  " << endl;
		cout << "                 *            ��ϵ���ʵ��ж�                 *                  " << endl;
		cout << "                 * ��������A�ϵĹ�ϵR�ļ��ϱ�ʾ��(��������A��*                  " << endl;
		cout << "                 *        ����ù�ϵ�����ʵ��жϽ����       *                  " << endl;
		cout << "                 *       ������ʾ����ϵĹ�ϵ�ľ���        *                  " << endl;
		cout << "                 *           �жϸù�ϵ�����ʡ�              *                  " << endl;
		cout << "                 *********************************************                  " << endl;
		cout << endl;
		for (i = 0; i < options.size(); i++)
		{
			cout << "  " << i << "." << options[i] << endl;
		}
		cout << endl;
		cout << "********************************************************************************" << endl;
		cout << "����������ѡ��";
		cin >> n;
	}
	
}