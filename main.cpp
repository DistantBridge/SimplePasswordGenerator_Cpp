#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Password_Group
{
public:
	Password_Group() {};
	~Password_Group() {};

	void Show_values()//显示密码组成值
	{};

	bool Search_in_tags(string need_tag)//寻找密码标签
	{
		for (auto iter = password_tags.cbegin(); iter != password_tags.cend(); iter++)
		{
			if (*iter == need_tag)
			{
				return true;
			}
		}
		return false;
	};

	unsigned int Show_password_level()//显示密码分类
	{
		return password_level;
	};

private:
	vector<string> password_values;//密码组成值
	vector<string> password_tags;//密码标签
	unsigned int password_level;//密码分类
};

int main()
{
	vector<Password_Group> all_Groups;//从txt文件中读取所有组并保存
	vector<string> selected_password_values_pool;//用户选择密码标签后，寻找符合的密码组并且存储

	return 0;
}