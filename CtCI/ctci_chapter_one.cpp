#include "ctci_chapter_one.h"

#include <algorithm>
#include <sstream>

bool allUnique(const std::string& str)
{
	std::set<char> charset(std::begin(str), std::end(str));
	return charset.size() == str.size();
}

void reverseString(char* str)
{
	size_t len = 0;
	char* tmp = str;
	while (0 != *tmp++) len++;

	for (size_t i = 0; i < len / 2; i++)
	{
		std::swap(*(str+i), *(str+len-i - 1));
	}
}

void replaceSpace(char* str, size_t len)
{
	size_t space_count = std::count(str, str + len, ' ');
	
	//for (size_t i = 0; i < len; i++)
	//	if (' ' == str[i])
	//		space_count++;

	size_t extended_length = len + space_count * 2;
	for (size_t i = len; i > 0; i--)
	{
		if (' ' != str[i])
		{
			str[extended_length--] = str[i];
		}
		else
		{
			str[extended_length--] = '0';
			str[extended_length--] = '2';
			str[extended_length--] = '%';
		}
	}
}

bool isPermutation(const std::string& a, const std::string& b)
{
	if (a.size() != b.size())
		return false;
	
	// Here is copy because const 
	std::string sorted_a = a;
	std::string sorted_b = b;

	std::sort(std::begin(sorted_a), std::end(sorted_a));
	std::sort(std::begin(sorted_b), std::end(sorted_b));

	return sorted_a.compare(sorted_b) == 0;
}

std::string compressString(const std::string& str)
{
	std::stringstream ss;

	for (auto i = std::begin(str); i != std::end(str); /**/)
	{ 
		// Get lower and upper bounds of sequentially repeating characters
		auto range = std::equal_range(std::begin(str), std::end(str), *i);

		// Get distance of repeating characters
		auto distance = std::distance(range.first, range.second);
		
		// Form new string
		ss << *i << distance;

		// Advance iterator to new character
		std::advance(i, distance);
	}

	// Get copy of string from stream
	std::string res = ss.str();

	// Return input string if compress does not compress
	return res.length() < str.length() ? res : str;
}