#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream> 
#include <cctype> 

using namespace std;

void Split(const string& src, const string& separator, vector<string>& dest);//单行字符串分割

//检查用户单行输入是否为一个特定分隔符的数字集合
bool Check_user_input_is_index(const string& src, const string& separator);