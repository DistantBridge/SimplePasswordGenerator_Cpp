#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Password_Group
{
private:
	vector<string> password_values;//�������ֵ
	vector<string> password_tags;//�����ǩ
	unsigned int password_level;//�������
public:
	Password_Group() {};
	~Password_Group() {};

	/*------��ʾ����------*/
	void Show_all_info();//��ʾ������Ϣ��������
	void Show_values();//��ʾ�������ֵ
	void Show_password_tags();//��ʾ�����ǩ
	void Show_password_level();//��ʾ�������

	/*------���ܺ���------*/
	unsigned int Get_password_level();//��ȡ�������
	bool Search_in_tags(string need_tag);//Ѱ�������ǩ
};