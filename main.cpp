#include"Password_Group.h"
#include<cstdlib>

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt文件 路径
#define SEPARATOR "," //txt文件 分隔符

ifstream keywords_file(PASSWORD_KEYWORDS_PATH);//文件流

vector<Password_Group> all_Groups;//从txt文件中读取所有组并保存
vector<string> all_tags;//所有密码标签

vector<string> selected_tag;//用户选择的密码标签
vector<string> selected_password_values_pool;//用户选择密码标签后，寻找符合的密码组并且存储


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

void User_select_tags()//用户选择密码标签并做输入检查
{
	bool select_end = false;

	while (!select_end)
	{
		cout << "Please enter index of password tags with correct speartor (" << SEPARATOR << ")" << endl;

		//清除输入流缓存
		cin.clear();
		cin.sync();

		string user_input;
		getline(cin, user_input);

		if (Check_user_input_is_index(user_input, SEPARATOR))
		{
			vector<string> selected_tag_index;
			Split(user_input, SEPARATOR, selected_tag_index);

			//存储用户选择的密码标签
			for (int i = 0; i < selected_tag_index.size(); i++)
			{
				int index_number;

				int is_error = sscanf_s(selected_tag_index[i].c_str(), "%d", &index_number);
				//sscanf转换检查和下标访问越界检查
				if (!is_error || index_number <0 || index_number+1>all_tags.size())
				{
					cout << "Enter error index , please enter again" << endl;
					continue;
				}

				selected_tag.push_back(all_tags.at(index_number));
			}

			select_end = true;
		}
		else
		{
			cout << "Please enter again" << endl;
			continue;
		}
	}
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

		User_select_tags();

	}

	system("pause");

	return 0;
}