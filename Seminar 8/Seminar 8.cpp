#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>

std::string read (std::ifstream& input)
{
	std::string result;
	while (!input.eof ())
	{
		std::string temp;
		input >> temp;
		result += temp + " ";
	}
	return result;
}
size_t findSeparator (const std::string& str, const char* sep)
{
	for (int i = 0; i < strlen (sep); i++)
	{
		size_t index = str.find (sep[i]);
		if (index != -1)
			return index;
	}
	return -1;
}
std::vector<std::string> split (std::string str)
{
	std::vector<std::string> result;
	const char* sep = ".,?!";
	size_t pos = findSeparator (str, sep);

	while (pos != -1)
	{
		str.erase (pos, 1);
		pos = findSeparator (str, sep);
	}

	std::string temp;
	for (auto ch : str)
		if (ch == ' ')
		{
			result.push_back (temp);
			temp.clear ();
		}
		else
			temp += ch;

	return result;
}
std::map<std::string, int> count (const std::vector<std::string>& vec)
{
	std::map<std::string, int> map;

	for (auto& str : vec)
		map[str]++;

	return map;
}

int main ()
{
	std::ifstream in ("file.txt");
	std::string all = read (in);
	std::vector<std::string> afterSplit = split (all);

	auto comp1 = [](const std::string& left, const std::string& right)
	{
		auto toLower = [](std::string str)
		{
			for (auto& ch : str)
				if (ch >= 'A' && ch <= 'Z')
					ch += 32;
			return str;
		};
		return toLower (left) < toLower (right);
	};
	std::map<std::string, int, decltype(comp1)> map (comp1);
	for (const auto& str : afterSplit)
		map[str]++;

	using pair = std::pair<std::string, int>;
	auto comp2 = [](const pair& left, const pair& right) { return left.first.size () < right.first.size (); };
	std::priority_queue<pair, std::vector<pair>, decltype(comp2)> queue (comp2);

	for (const auto& item : map)
		queue.push (item);

	while (!queue.empty ())
	{
		std::cout << "\"" << queue.top ().first << "\" => " << queue.top ().second << '\n';
		queue.pop ();
	}

	return 0;
}
