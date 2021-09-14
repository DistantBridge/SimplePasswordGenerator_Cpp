#include"Password_Group.h"
#include<cstdlib>
#include<algorithm>

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt文件 路径
#define SEPARATOR "," //txt文件 分隔符


vector<Password_Group> all_Groups;//从txt文件中读取所有组并保存
vector<string> all_tags;//所有密码标签
vector<string> selected_password_values_pool;//用户选择密码标签后，寻找符合的密码组并且存储

ifstream keywords_file(PASSWORD_KEYWORDS_PATH);//文件流

bool Import_from_file()//导入txt文件内容
{
	string line;

	if (keywords_file)
	{
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
		return true;
	}
	else
	{
		cout << "no such file" << endl;
		return false;
	}
}

void Show_all_groups()
{
	for (int i = 0; i < all_Groups.size(); i++)
	{
		cout << "     number:  " << i << endl;
		all_Groups[i].Show_all_info();
		cout << endl;
	}
}
void Show_all_tags()
{
	for (int i = 0; i < all_tags.size(); i++)
	{
		cout << "tag" << i << ":";
		cout << all_tags[i] << "  ";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void Collect_all_tags()//收集所有密码标签,排序后去重
{
	for (int i = 0; i < all_Groups.size(); i++)
	{
		for (int j = 0; j < all_Groups[i].Get_password_tags().size(); j++)
		{
			all_tags.push_back(all_Groups[i].Get_password_tags().at(j));
		}
	}

	//去重
	vector<string>::iterator all_tags_begin = all_tags.begin();
	vector<string>::iterator all_tags_end = all_tags.end();

	sort(all_tags_begin, all_tags_end);
	vector<string>::iterator all_tags_new_end = unique(all_tags_begin, all_tags_end);

	all_tags.erase(all_tags_new_end, all_tags_end);
}

int main()
{
	system("title SimplePasswordGeneration");
	system("chcp 65001 && cls");//控制台 UTF-8显示

	if (Import_from_file())
	{
		Show_all_groups();
		Collect_all_tags();
		Show_all_tags();
	}

	system("pause");

	return 0;
}