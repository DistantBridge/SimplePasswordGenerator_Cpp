#include"base.h"

ostream& operator<<(ostream& out, const Password_Grade& value)
{
	out << static_cast<underlying_type<Password_Grade>::type>(value);
	return out;
}

void Split(const string& src, const string& separator, vector<string>& dest)
{
	//src 要分割的字符串
	//separator 作为分隔符的字符
	//dest 存放分割后的字符串的vector
	string str = src;
	string substring;
	string::size_type start = 0, index;

	dest.clear();

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = index + separator.size();
			index = str.find(separator, start);
			if (start == string::npos)
			{
				return;
			}
		}
	} while (index != string::npos);

	substring = str.substr(start);
	dest.push_back(substring);
}

void Split(const string& src, const string& separator, vector<int>& dest)
{
	//src 要分割的字符串
	//separator 作为分隔符的字符
	//dest 存放分割后的字符串的vector
	string str = src;
	string substring;
	string::size_type start = 0, index;
	int index_number;
	int is_error;

	dest.clear();

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);

			is_error = sscanf_s(substring.c_str(), "%d", &index_number);
			assert(is_error > 0);

			dest.push_back(index_number);
			start = index + separator.size();
			index = str.find(separator, start);
			if (start == string::npos)
			{
				return;
			}
		}
	} while (index != string::npos);

	substring = str.substr(start);
	is_error = sscanf_s(substring.c_str(), "%d", &index_number);
	assert(is_error > 0);
	dest.push_back(index_number);
}

bool Check_user_input_is_index(const string& src, const string& separator)
{
	//src 待检查的字符串
	//separator 作为分隔符的字符

	//如果输入为空
	if (src.empty())
	{
		return false;
	}

	bool only_single_number = true;//是否只输入了一个值
	for (int i = 0; i < src.size(); i++)
	{
		if (!isdigit(src[i]))
		{
			only_single_number = false;
		}
	}

	//如果输入了多个数字却没有使用规定的分隔符
	if (src.find(separator) == string::npos && !only_single_number)
	{
		return false;
	}

	//dest 存放分割后的字符串的vector
	vector<string> dest;
	Split(src, separator, dest);

	for (int i = 0; i < dest.size(); i++)
	{
		for (int j = 0; j < dest[i].size(); j++)
		{
			if (!isdigit(dest[i].at(j)))
			{
				return false;
			}
		}
	}

	return true;
}

