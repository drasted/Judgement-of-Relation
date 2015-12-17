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
	menu.add_options("������븸����A");
	menu.add_functions(fun1);
	menu.add_options("��������ϵ����R(2��3��ѡһ���뼴�ɽ����ж�)");
	menu.add_functions(fun2);
	menu.add_options("��������ϵ����(2��3��ѡһ���뼴�ɽ����ж�)");
	menu.add_functions(fun3);
	menu.add_options("��ϵ���ۺ��ж�(�Է������Է����Գƣ����Գƣ����ݣ�");
	menu.add_functions(fun4);
	menu.add_options("��ո���A����Ԫ��ϵ����R�;�����������");
	menu.add_functions(fun5);
	menu.run();
	return 0;
}

void fun1()
{
	cout << "������ʹ��int���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl << endl;
	cout << "�����뼯��A�е�Ԫ�أ����ļ���β��־������windows��ΪCtrl+Z" << endl;
	cout << "��ʾ��Ϊ����Ԫ��������󣬽����������ļ���β��־ǰ��������س�����" << endl;
	int c;
	while(cin >> c)
	{
		test.add_father(c);
	}
	cout << "��������ǣ�" << endl;
	test.print_father();
}

void fun2()
{
	cout << "������ʹ��int���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << endl << "����A��" ;
	test.print_father();
	cout << endl << endl;
	cout << "�������ϵ����R�е�Ԫ�أ�����Ϊһ�飬���ļ���β��־������windows��ΪCtrl+Z" << endl;
	cout << "��ʾ��Ϊ����Ԫ��������󣬽����������ļ���β��־ǰ��������س�����" << endl;
	int c1, c2;
	while (cin>>c1>>c2)
	{
		test.add_relation(c1, c2);
	}
	test.relationTOmatrix();
	cout << "��������ǣ�" << endl;
	test.print_relation();
}

void fun3()
{
	cout << "������ʹ��int���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	cout << endl << "����A��" ;
	test.print_father();
	cout << endl << endl;
	cout << "�������ϵ����������A����Ϊn,�����Ϊn*n����" << endl;
    test.inputMatrix();
	test.matrixTOrelation();
	cout << "�������Ϊ��" << endl;
	cout << "��ϵ����" << endl;
	test.print_matrix();
}

void fun4()
{
	cout << "������ʹ��int���ͼ��ϣ���Դ����֧�ָ������ͣ��ɼ��޸����Ͳ��������±���" << endl;
	if (test.has_empty())
	{
		cout << endl << "����δ��ɣ��������㣬�޷��жϣ�" << endl;
		return;
	}
	cout << "����A��";
	test.print_father();
	cout << endl;
	cout << "��ϵ����R��";
	test.print_relation();
	cout << endl;
	cout << "��ϵ����" << endl;
	test.print_matrix();
	cout << endl;
	cout << "�Է���";
	cout <<"  "<< getbool(test.isReflexive()); 
	cout << endl;
	cout << "���Է���";
	cout << "  " << getbool(test.isIrreflexive());
	cout << endl;
	cout << "�Գ���";
	cout << "  " << getbool(test.isSymmetric());
	cout << endl;
	cout << "���Գ���";
	cout << "  " << getbool(test.isAntisymmetric());
	cout << endl;
	cout << "������";
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
	cout << endl << "�������......" << endl;
	test.clear();
	cout << "�����ɣ����������룡" << endl;
}