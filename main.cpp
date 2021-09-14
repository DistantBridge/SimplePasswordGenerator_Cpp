#include"Password_Group.h"
#include<cstdlib>

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt�ļ� ·��
#define SEPARATOR "," //txt�ļ� �ָ���

ifstream keywords_file(PASSWORD_KEYWORDS_PATH);//�ļ���

vector<Password_Group> all_Groups;//��txt�ļ��ж�ȡ�����鲢����
vector<string> all_tags;//���������ǩ

vector<string> selected_tag;//�û�ѡ��������ǩ
vector<string> selected_password_values_pool;//�û�ѡ�������ǩ��Ѱ�ҷ��ϵ������鲢�Ҵ洢


bool Import_from_file()//����txt�ļ�����
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

void Collect_all_tags()//�ռ����������ǩ,�����ȥ��
{
	for (int i = 0; i < all_Groups.size(); i++)
	{
		for (int j = 0; j < all_Groups[i].Get_password_tags().size(); j++)
		{
			all_tags.push_back(all_Groups[i].Get_password_tags().at(j));
		}
	}

	//ȥ��
	vector<string>::iterator all_tags_begin = all_tags.begin();
	vector<string>::iterator all_tags_end = all_tags.end();

	sort(all_tags_begin, all_tags_end);
	vector<string>::iterator all_tags_new_end = unique(all_tags_begin, all_tags_end);

	all_tags.erase(all_tags_new_end, all_tags_end);
}

void User_select_tags()//�û�ѡ�������ǩ����������
{
	bool select_end = false;

	while (!select_end)
	{
		cout << "Please enter index of password tags with correct speartor (" << SEPARATOR << ")" << endl;

		//�������������
		cin.clear();
		cin.sync();

		string user_input;
		getline(cin, user_input);

		if (Check_user_input_is_index(user_input, SEPARATOR))
		{
			vector<string> selected_tag_index;
			Split(user_input, SEPARATOR, selected_tag_index);

			//�洢�û�ѡ��������ǩ
			for (int i = 0; i < selected_tag_index.size(); i++)
			{
				int index_number;

				int is_error = sscanf_s(selected_tag_index[i].c_str(), "%d", &index_number);
				//sscanfת�������±����Խ����
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
	system("chcp 65001 && cls");//����̨ UTF-8��ʾ

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