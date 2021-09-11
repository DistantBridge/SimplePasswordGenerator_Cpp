#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Password_Group
{
public:
	Password_Group();
	~Password_Group();

	void Show_values();
	bool Search_in_tags(string need_tag)
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
	unsigned int Show_password_level()
	{
		return password_level;
	};

private:
	vector<string> password_values;
	vector<string> password_tags;
	unsigned int password_level;
};

int main()
{
	vector<Password_Group> all_Groups;
	vector<string> selected_password_values_pool;

	return 0;
}