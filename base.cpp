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
	index = str.find_first_of(separator, start);
	while (index != string::npos)
	{
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = index + separator.size();
			index = str.find(separator, start);
			if (start == string::npos)
			{
				break;
			}
		}
	}
}
