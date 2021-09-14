#include"Password_Group.h"
#include"base.h"

Password_Group::Password_Group()
{
	password_grade = None;
}
Password_Group::~Password_Group() {}

void Password_Group::Show_all_info()
{
	Show_password_composition();
	Show_password_tags();
	Show_password_grade();
}
void Password_Group::Show_password_composition()
{
	if (password_composition.empty())
	{
		cout << "no password_composition" << endl;
	}
	else
	{
		cout << "composition:  ";
		for (auto iter = password_composition.cbegin(); iter != password_composition.cend(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
}
void Password_Group::Show_password_tags()
{
	if (password_tags.empty())
	{
		cout << "no password tags" << endl;
	}
	else
	{
		cout << "       tags:  ";
		for (auto iter = password_tags.cbegin(); iter != password_tags.cend(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
}
void Password_Group::Show_password_grade()
{
	cout << "      grade:  ";
	switch (password_grade)
	{
	case None:
		cout << "none" << endl;
		break;
	case Low:
		cout << "low" << endl;
		break;
	case Medium:
		cout << "medium" << endl;
		break;
	case High:
		cout << "high" << endl;
		break;
	default:
		cout << "error" << endl;
		break;
	}
}

bool Password_Group::Search_in_tags(string need_tag)
{
	if (password_tags.empty())
	{
		return false;
	}
	else
	{
		for (auto iter = password_tags.cbegin(); iter != password_tags.cend(); iter++)
		{
			if (*iter == need_tag)
			{
				return true;
			}
		}
	}
	return false;
}
vector<string> Password_Group::Get_password_tags()
{
	return password_tags;
}
Password_Grade Password_Group::Get_password_grade()
{
	return password_grade;
}

void Password_Group::Write_password_composition(const string& line, const string& separator)
{
	Split(line, separator, password_composition);
}
void Password_Group::Write_password_tags(const string& line, const string& separator)
{
	Split(line, separator, password_tags);
}
void Password_Group::Write_password_grade(const string& line, const string& separator)
{
	//如果结尾不为, 直接跳过
	if (!(line.ends_with(separator + "\n") || line.ends_with(separator)))
	{
		password_grade = None;
	}
	else
	{
		//UTF-8中文字符判断
		char8_t level_chars[10] = u8"弱中强";

		for (int i = 0; i < 3; i++)
		{
			if (level_chars[i * 3] == (char8_t)line.at(0) &&
				level_chars[i * 3 + 1] == (char8_t)line.at(1) &&
				level_chars[i * 3 + 2] == (char8_t)line.at(2))
			{
				switch (i)
				{
				case 0:
					password_grade = Low;
					break;
				case 1:
					password_grade = Medium;
					break;
				case 2:
					password_grade = High;
					break;
				default:
					password_grade = None;
					break;
				}
			}
		}
	}
}
