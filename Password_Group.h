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
	vector<string> password_composition;//�������ֵ
	vector<string> password_tags;//�����ǩ
	Password_Grade password_grade;//�������
public:
	Password_Group();
	~Password_Group();

	/*------��ʾ����------*/
	//��ʾ������Ϣ��������
	void Show_all_info();
	//��ʾ�������ֵ
	void Show_password_composition();
	//��ʾ�����ǩ
	void Show_password_tags();
	//��ʾ�������
	void Show_password_grade();

	/*------���ܺ���------*/
	/*------Get-----*/
	//��ȡ�������ֵ
	vector<string> Get_password_composition();
	//��ȡ�������
	Password_Grade Get_password_grade();
	//��ȡ�����ǩ
	vector<string> Get_password_tags();

	/*-----Search-----*/
	//Ѱ���ض������ǩ�Ƿ����
	bool Search_in_tags(string need_tag);

	/*------Write-----*/
	//д���������ֵ
	void Write_password_composition(const string& line, const string& separator);
	//д�������ǩ
	void Write_password_tags(const string& line, const string& separator);
	//д���������
	void Write_password_grade(const string& line, const string& separator);
};