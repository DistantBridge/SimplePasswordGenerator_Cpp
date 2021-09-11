#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Password_Group
{
private:
	vector<string> password_values;//密码组成值
	vector<string> password_tags;//密码标签
	unsigned int password_level;//密码分类
public:
	Password_Group() {};
	~Password_Group() {};

	/*------显示函数------*/
	void Show_all_info();//显示该组信息所有内容
	void Show_values();//显示密码组成值
	void Show_password_tags();//显示密码标签
	void Show_password_level();//显示密码分类

	/*------功能函数------*/
	unsigned int Get_password_level();//获取密码分类
	bool Search_in_tags(string need_tag);//寻找密码标签
};