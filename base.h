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
	Count //ö����Ԫ�ظ���
};

//���ز�������ʹPassword_Grade֧��<<���
ostream& operator<<(ostream& out, const Password_Grade& value);

void Split(const string& src, const string& separator, vector<string>& dest);//�����ַ����ָ�
void Split(const string& src, const string& separator, vector<int>& dest);

//����û����������Ƿ�Ϊһ���ض��ָ��������ּ���
bool Check_user_input_is_index(const string& src, const string& separator);