/*
Ŀ�꣺���ϴ����дһ�����������ɿ���̨�˵���ͨ���࣬�����α�д����̨�˵�
		����console_menu_for_test.cppһ�����
��д�ˣ�wei
��дʱ�䣺2015.10.31
*/

#ifndef CONSOLE_MENU_FOR_TEST
#define CONSOLE_MENU_FOR_TEST

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::cerr;

class ConsoleMenu
{
private:
	string title;
	vector<string>  options;
	vector<void(*)(void)> functions;
	int op_num, fun_num;

	void clear_input() const;        //������뻺����
	void fun_tail() const ;           //ѡ������ĺ���
	void fun(const int i) const;           //ѡ���
	static void quit_menu();
public:
	ConsoleMenu();   //��ʼ������̨�˵�
	void add_options(string s,int i = -1);  //����ѡ��
	void add_functions(void (*p)(void), int i = -1);  //����ѡ�����
	void run() const;                //���п���̨�˵�
	
};


#endif