#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream> 
#include <cctype> 

using namespace std;

void Split(const string& src, const string& separator, vector<string>& dest);//�����ַ����ָ�

//����û����������Ƿ�Ϊһ���ض��ָ��������ּ���
bool Check_user_input_is_index(const string& src, const string& separator);