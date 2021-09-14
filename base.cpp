#include"base.h"

void Split(const string& src, const string& separator, vector<string>& dest)
{
	//src Ҫ�ָ���ַ���
	//separator ��Ϊ�ָ������ַ�
	//dest ��ŷָ����ַ�����vector
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
	//src �������ַ���
	//separator ��Ϊ�ָ������ַ�

	bool only_single_number = true;//�Ƿ�ֻ������һ��ֵ
	for (int i = 0; i < src.size(); i++)
	{
		if (!isdigit(src[i]))
		{
			only_single_number = false;
		}
	}

	//��������˶������ȴû��ʹ�ù涨�ķָ���
	if (src.find(separator) == string::npos && !only_single_number)
	{
		return false;
	}

	//dest ��ŷָ����ַ�����vector
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

