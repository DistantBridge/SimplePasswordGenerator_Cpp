#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Password_Group
{
public:
	Password_Group() {};
	~Password_Group() {};

	void Show_values()//��ʾ�������ֵ
	{};

	bool Search_in_tags(string need_tag)//Ѱ�������ǩ
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

	unsigned int Show_password_level()//��ʾ�������
	{
		return password_level;
	};

private:
	vector<string> password_values;//�������ֵ
	vector<string> password_tags;//�����ǩ
	unsigned int password_level;//�������
};

int main()
{
	vector<Password_Group> all_Groups;//��txt�ļ��ж�ȡ�����鲢����
	vector<string> selected_password_values_pool;//�û�ѡ�������ǩ��Ѱ�ҷ��ϵ������鲢�Ҵ洢

	return 0;
}