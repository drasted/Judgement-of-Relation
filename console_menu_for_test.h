/*
目标：整合代码编写一个可用于生成控制台菜单的通用类，避免多次编写控制台菜单
		请与console_menu_for_test.cpp一起编译
编写人：wei
编写时间：2015.10.31
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

	void clear_input() const;        //清空输入缓冲区
	void fun_tail() const ;           //选项处理函数的后续
	void fun(const int i) const;           //选项处理
	static void quit_menu();
public:
	ConsoleMenu();   //初始化控制台菜单
	void add_options(string s,int i = -1);  //增加选项
	void add_functions(void (*p)(void), int i = -1);  //增加选项处理函数
	void run() const;                //运行控制台菜单
	
};


#endif