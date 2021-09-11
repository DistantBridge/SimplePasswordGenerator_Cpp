#include"Password_Group.h"

using namespace std;

Password_Group::Password_Group() 
{
	password_level = 0;
};
Password_Group::~Password_Group() {};

void Password_Group::Show_all_info()
{
	Show_values();
	Show_password_tags();
	Show_password_level();
};
void Password_Group::Show_values()
{
	if (password_values.empty())
	{
		cout << "no password_values" << endl;
	}
	else
	{
		for (auto iter = password_values.cbegin(); iter != password_values.cend(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
};
void Password_Group::Show_password_tags()
{
	if (password_tags.empty())
	{
		cout << "no password_tags" << endl;
	}
	else
	{
		for (auto iter = password_tags.cbegin(); iter != password_tags.cend(); iter++)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
};
void Password_Group::Show_password_level()
{
	switch (password_level)
	{
	case 1:
		cout << "low" << endl;
		break;
	case 2:
		cout << "medium" << endl;
		break;
	case 3:
		cout << "heigh" << endl;
		break;
	default:
		cout << "none" << endl;
		break;
	}
};

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
};
unsigned int Password_Group::Get_password_level()
{
	return password_level;
};

