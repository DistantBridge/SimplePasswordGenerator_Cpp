#include"Password_Group.h"

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt�ļ� ·��
#define SEPARATOR "," //txt�ļ� �ָ���


int main()
{
	system("chcp 65001 && cls");//����̨ UTF-8��ʾ

	vector<Password_Group> all_Groups;//��txt�ļ��ж�ȡ�����鲢����
	vector<string> selected_password_values_pool;//�û�ѡ�������ǩ��Ѱ�ҷ��ϵ������鲢�Ҵ洢

	ifstream keywords_file(PASSWORD_KEYWORDS_PATH);
	string line;

	if (keywords_file)
	{
		//�ļ�����
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

		//��ʾ
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