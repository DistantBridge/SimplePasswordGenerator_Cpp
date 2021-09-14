#include"base.h"

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

bool Check_user_input_is_index(const string& src, const string& separator)
{
	//src 待检查的字符串
	//separator 作为分隔符的字符

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

