#include"console_menu_for_test.h"
#include"BinaryRelation(��ܺ͹淶)1.1.h"

void fun1();
void fun2();
void fun3();
void fun4();

BinaryRelationAssmble<char> test;

int main()
{
	ConsoleMenu menu;
	menu.add_options("���븸����A");
	menu.add_functions(fun1);
	menu.add_options("�����ϵ����R(2��3��ѡһ���뼴�ɽ����ж�)");
	menu.add_functions(fun2);
	menu.add_options("�����ϵ����(2��3��ѡһ���뼴�ɽ����ж�)");
	menu.add_functions(fun3);
	menu.add_options("��ϵ���ۺ��ж�(�Է������Է����Գƣ����Գƣ����ݣ�");
	menu.add_functions(fun4);
	menu.run();
	return 0;
}

void fun1()
{
	cout << "������ʹ��char���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << "�����뼯��A�е�Ԫ�أ����ļ���β��־������windows��ΪCtrl+Z" << endl;
	cout << endl << "ʵ������" << endl;
	/*****ʵ��
	char c;
	while(cin >> c)
	{
		test.add_father(c);
	}
	*/
}

void fun2()
{
	cout << "������ʹ��char���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << "����A��";
	//test.print_father();
	cout << endl;
	cout << "�������ϵ����R�е�Ԫ�أ�����Ϊһ�飬���ļ���β��־������windows��ΪCtrl+Z" << endl;
	cout << endl << "ʵ������" << endl;
	/****ʵ��
	char c1, c2;
	while (cin>>c1>>c2)
	{
		test.add_relation(c1, c2);
	}
	*/
}

void fun3()
{
	cout << "������ʹ��char���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << "����A��";
	//test.print_father();
	cout << endl;
	cout << "�������ϵ���󣬽������뷽ʽ��inputMatrix(int i,int j)����" << endl;
	cout << endl << "ʵ������" << endl;
	/****ʵ��
	test.inputMatrix();
	*/
}

void fun4()
{
	cout << "������ʹ��char���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << "����A��";
	//test.print_father();
	cout << endl;
	cout << "��ϵ����R��";
	//test.print_relation();
	cout << endl;
	//(��ѡ)cout << "��ϵ����" << endl;
	//test.print_relation();
	//cout << endl;
	cout << "�Է���";
	//cout << test.isReflexive; 
	cout << endl;
	cout << "���Է���";
	//cout << test.isIrreflexive;
	cout << endl;
	cout << "�Գ���";
	//cout << test.isSymmetric();
	cout << endl;
	cout << "���Գ���";
	//cout << test.isAntisymmetric();
	cout << endl;
	cout << "������";
	//cout << test.isTransitive();
	cout << endl;
}