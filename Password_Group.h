#pragma once
#include"base.h"
#include<iostream>
#include<vector>
#include<string>
#include <fstream> 
#include <algorithm>

using namespace std;

enum Password_Grade
{
	None = 0,
	Low,
	Medium,
	High
};


class Password_Group
{
private:
	vector<string> password_composition;//密码组成值
	vector<string> password_tags;//密码标签
	Password_Grade password_grade;//密码分类
public:
	Password_Group();
	~Password_Group();

	/*------显示函数------*/
	//显示该组信息所有内容
	void Show_all_info();
	//显示密码组成值
	void Show_password_composition();
	//显示密码标签
	void Show_password_tags();
	//显示密码分类
	void Show_password_grade();

	/*------功能函数------*/
	/*------Get-----*/
	//获取密码组成值
	vector<string> Get_password_composition();
	//获取密码分类
	Password_Grade Get_password_grade();
	//获取密码标签
	vector<string> Get_password_tags();

	/*-----Search-----*/
	//寻找特定密码标签是否存在
	bool Search_in_tags(string need_tag);

	/*------Write-----*/
	//写入密码组成值
	void Write_password_composition(const string& line, const string& separator);
	//写入密码标签
	void Write_password_tags(const string& line, const string& separator);
	//写入密码分类
	void Write_password_grade(const string& line, const string& separator);
};