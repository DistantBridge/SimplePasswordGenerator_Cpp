#include"Password_Group.h"
#include<cstdlib>
#include<algorithm>

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt�ļ� ·��
#define SEPARATOR "," //txt�ļ� �ָ���


vector<Password_Group> all_Groups;//��txt�ļ��ж�ȡ�����鲢����
vector<string> all_tags;//���������ǩ
vector<string> selected_password_values_pool;//�û�ѡ�������ǩ��Ѱ�ҷ��ϵ������鲢�Ҵ洢

ifstream keywords_file(PASSWORD_KEYWORDS_PATH);//�ļ���

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

int main()
{
	system("title SimplePasswordGeneration");
	system("chcp 65001 && cls");//����̨ UTF-8��ʾ

	if (Import_from_file())
	{
		Show_all_groups();
		Collect_all_tags();
		Show_all_tags();
	}

	system("pause");

	return 0;
}