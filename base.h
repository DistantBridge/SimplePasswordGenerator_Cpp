#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream> 
#include<cctype>
#include<sstream>
#include<cassert>

using namespace std;

//C++ 11 enum class 
enum class Password_Grade
{
	None = 0,
	Low,
	Medium,
	High,
	Count //枚举类元素个数
};

//重载操作符，使Password_Grade支持<<输出
ostream& operator<<(ostream& out, const Password_Grade& value);

void Split(const string& src, const string& separator, vector<string>& dest);//单行字符串分割
void Split(const string& src, const string& separator, vector<int>& dest);

//检查用户单行输入是否为一个特定分隔符的数字集合
bool Check_user_input_is_index(const string& src, const string& separator);