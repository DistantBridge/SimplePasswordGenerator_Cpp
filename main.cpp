#include"Password_Group.h"
#include<cstdlib>
#include <map>
#include <set>

using namespace std;

#define PASSWORD_KEYWORDS_PATH "Password_Keywords.txt" //txt�ļ� ·��
#define SEPARATOR "," //txt�ļ� �ָ���

#define RANDOM_TIME_LEAST 3 //���������ȡ���������ֵ��������
#define RANDOM_TIME_MOST  8 //��������ȡ���������ֵ��������

ifstream keywords_file(PASSWORD_KEYWORDS_PATH);//�ļ���
vector<Password_Group> all_Groups;//��txt�ļ��ж�ȡ�����鲢����

vector<Password_Grade> selected_grade;//�û�ѡ�������ȼ�
multimap<string, int> all_tags_in_user_grade;//�����û�����ȼ������������ǩ��all_Groups������һ�Զ�ģ��
int in_user_grade_tags_number = 0; // �����û�����ȼ������������ǩ�ĸ���
vector<string> selected_tag;//�û�ѡ��������ǩ
vector<string> selected_password_values_pool;//�û�ѡ�������ǩ��Ѱ�ҷ��ϵ������鲢�Ҵ洢


bool Import_from_file()//����txt�ļ�����
{
	string line;

	if (keywords_file)
	{
		while (!keywords_file.eof() && keywords_file.peek() != EOF)
		{
			Password_Group this_group;
			for (int i = 0; i < 4; i++)
			{
				getline(keywords_file, line);

				if (line.empty())
				{
					continue;
				}
				else
				{
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
			}

			if (!this_group.Get_password_composition().empty() && !this_group.Get_password_tags().empty())
			{
				all_Groups.push_back(this_group);
			}
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
void Show_all_tags_in_user_grade()
{

	for (auto it = all_tags_in_user_grade.begin(); it != all_tags_in_user_grade.end(); it = all_tags_in_user_grade.upper_bound(it->first))
	{
		in_user_grade_tags_number++;
		cout << "tag" << in_user_grade_tags_number << ":";
		cout << it->first << "  ";
		if ((in_user_grade_tags_number + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}
void Show_selected_tags()
{
	for (int i = 0; i < selected_tag.size(); i++)
	{
		cout << selected_tag[i] << "  ";
	}
	cout << endl;
}
void Show_all_grades()
{
	cout << Password_Grade::None << "---" << "None" << endl;
	cout << Password_Grade::Low << "---" << "Low" << endl;
	cout << Password_Grade::Medium << "---" << "Medium" << endl;
	cout << Password_Grade::High << "---" << "High" << endl;
}

void Collect_all_tags_in_user_grade()//�ռ����з����û�����ȼ��������ǩ
{
	for (int i = 0; i < all_Groups.size(); i++)
	{
		auto it_of_none = find(selected_grade.begin(), selected_grade.end(), Password_Grade::None);
		//һ���û�ѡ����none����ȼ����������û���ѡ�����������ȼ����Զ��Ѽ����������ǩ

		if (it_of_none == selected_grade.end() &&
			!(all_Groups[i].Get_password_grade() == Password_Grade::None))//�û�ûѡ��none����ȼ����ҵ�ǰ�ж������鶥������ȼ���Ϊnone
		{
			//����û�ûѡ��none����ȼ������жϵ�ǰ�����������ȼ��Ƿ�Ϊ�û���ѡ�������ȼ��������Ѽ���������������ǩ
			auto it_of_grade = find(selected_grade.begin(), selected_grade.end(), all_Groups[i].Get_password_grade());
			if (it_of_grade == selected_grade.end())
			{
				continue;
			}
		}

		for (int j = 0; j < all_Groups[i].Get_password_tags().size(); j++)
		{
			all_tags_in_user_grade.insert(make_pair(all_Groups[i].Get_password_tags().at(j), i));
		}
	}
}
void User_select_grades()
{
	bool select_end = false;

	while (!select_end)
	{
		cout << "Please select grades with correct speartor ( " << SEPARATOR << " )" << endl;

		cin.clear();
		cin.sync();

		string user_input;
		getline(cin, user_input);

		if (Check_user_input_is_index(user_input, SEPARATOR))
		{
			vector<int> selected_grade_number;
			Split(user_input, SEPARATOR, selected_grade_number);

			if (selected_grade_number.size() > static_cast<underlying_type<Password_Grade>::type>(Password_Grade::Count))
			{
				cout << "Enter error index , please enter again" << endl;
				continue;
			}

			//Ѱ���Ƿ���Խ���enum class Password_Grade��ֵ
			auto it = find_if(selected_grade_number.begin(), selected_grade_number.end(),
				[&selected_grade_number](int n) { return (n >= static_cast<underlying_type<Password_Grade>::type>(Password_Grade::Count)) || (n < 0); }
			);//lamda���ʽ

			if (it != selected_grade_number.end())//�ҵ�Խ���ֵ
			{
				cout << "Enter error index , please enter again" << endl;
				continue;
			}

			for (int i = 0; i < selected_grade_number.size(); i++)
			{
				switch (selected_grade_number[i])
				{
				case static_cast<underlying_type<Password_Grade>::type>(Password_Grade::Low):
					selected_grade.push_back(Password_Grade::Low);
					break;
				case static_cast<underlying_type<Password_Grade>::type>(Password_Grade::Medium):
					selected_grade.push_back(Password_Grade::Medium);
					break;
				case static_cast<underlying_type<Password_Grade>::type>(Password_Grade::High):
					selected_grade.push_back(Password_Grade::High);
					break;
				case static_cast<underlying_type<Password_Grade>::type>(Password_Grade::None):
					selected_grade.push_back(Password_Grade::None);
					break;
				default:
					break;
				}
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
void User_select_tags()//�û�ѡ�������ǩ����������
{
	bool select_end = false;

	while (!select_end)
	{
		cout << "Please enter index of password tags with correct speartor ( " << SEPARATOR << " )" << endl;

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
				//sscanfת�����ͷ���Խ����
				if (!is_error || index_number <= 0 || index_number > in_user_grade_tags_number)
				{
					cout << "Enter error index , please enter again" << endl;
					continue;
				}

				//����multimapֱ���ҵ��û�ѡ���tag
				int now_number = 1;
				for (auto iter = all_tags_in_user_grade.begin(); iter != all_tags_in_user_grade.end(); iter = all_tags_in_user_grade.upper_bound(iter->first))
				{
					if (now_number == index_number)
					{
						selected_tag.push_back(iter->first);
						break;
					}
					else
					{
						now_number++;
					}
				}

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
void Select_groups_by_user_tags()//ͨ���û�ѡ��������ǩ�ҵ���Ӧ�������飬�������е�����Ԫ�ط���selected_password_values_pool��
{
	for (int i = 0; i < selected_tag.size(); i++)
	{
		auto pos = all_tags_in_user_grade.equal_range(selected_tag[i]);

		for (auto it_range = pos.first; it_range != pos.second; ++it_range)
		{
			//��������Ԫ��
			selected_password_values_pool.insert(
				selected_password_values_pool.end(),
				all_Groups[it_range->second].Get_password_composition().begin(),
				all_Groups[it_range->second].Get_password_composition().end()
			);
		}
	}
}
void Create_password()
{
	bool create_end = false;

	srand(time(NULL));

	string output("");

	while (!create_end)
	{
		for (int i = 0; i < rand() % (RANDOM_TIME_MOST - RANDOM_TIME_LEAST) + RANDOM_TIME_LEAST; i++)
		{
			output += selected_password_values_pool[rand() % selected_password_values_pool.size()];
		}

		cout << "password is: " << output << endl;

	label:
		cin.clear();
		cin.sync();
		cout << "Do you want to recreate another password ? [1---yes / 0---no]" << endl;

		int input = cin.get();
		getchar();

		switch (input)
		{
		case 48:
			create_end = true;
			break;
		case 49:
			output.clear();
			continue;
			break;
		default:
			cout << "Please enter again" << endl;
			goto label;
			break;
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

		Show_all_grades();
		User_select_grades();

		Collect_all_tags_in_user_grade();
		Show_all_tags_in_user_grade();

		User_select_tags();
		Show_selected_tags();

		Select_groups_by_user_tags();

		Create_password();
	}

	system("pause");

	return 0;
}