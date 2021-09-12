#include"Password_Group.h"

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt文件 路径
#define SEPARATOR "," //txt文件 分隔符


int main()
{
	system("chcp 65001 && cls");//控制台 UTF-8显示

	vector<Password_Group> all_Groups;//从txt文件中读取所有组并保存
	vector<string> selected_password_values_pool;//用户选择密码标签后，寻找符合的密码组并且存储

	ifstream keywords_file(PASSWORD_KEYWORDS_PATH);
	string line;

	if (keywords_file)
	{
		//文件导入
		while (!keywords_file.eof())
		{
			Password_Group this_group;
			for (int i = 0; i < 4; i++)
			{
				getline(keywords_file, line);
				switch (i)
				{
				case 0:
					continue;
					break;
				case 1:
					this_group.Write_password_composition(line, SEPARATOR);
					break;
				case 2:
					this_group.Write_password_tags(line, SEPARATOR);
					break;
				case 3:
					this_group.Write_password_grade(line, SEPARATOR);
					break;
				default:
					break;
				}
			}
			all_Groups.push_back(this_group);
		}
		keywords_file.close();

		//显示
		for (int i = 0; i < all_Groups.size(); i++)
		{
			cout << i << endl;
			all_Groups[i].Show_all_info();
			cout << endl;
		}

		system("pause");
	}
	else
	{
		cout << "no such file" << endl;
		return 0;
	}

	return 0;
}