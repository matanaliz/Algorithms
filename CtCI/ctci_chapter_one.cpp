#include "ctci_chapter_one.h"

#include <algorithm>
#include <sstream>
#include <utility>
#include <vector>

bool allUnique(const std::string& str)
{
	// Get all chars into set. Compare sizes of containers.
	std::set<char> charset(std::begin(str), std::end(str));
	return charset.size() == str.size();
}

void reverseString(char* str)
{
	if (!str)
		return;

	size_t len = 0;
	char* tmp = str;
	while (*tmp++) len++;

	for (size_t i = 0; i < len / 2; i++)
		std::swap(str[i], str[len - i - 1]);
}

void replaceSpace(char* str, size_t len)
{
	// Invalid args
	if (!str || len <= 0)
		return;

	size_t space_count = std::count(str, str + len, ' ');
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
	
	// Here is copy because of const 
	std::string sorted_a = a;
	std::string sorted_b = b;

	std::sort(std::begin(sorted_a), std::end(sorted_a));
	std::sort(std::begin(sorted_b), std::end(sorted_b));

	return sorted_a.compare(sorted_b) == 0;

}

std::string compressString(const std::string& str)
{
	std::stringstream ss;

	for (auto i = std::begin(str); i != std::end(str); /*will advance in body*/)
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
	return res.size() < str.size() ? res : str;
}

void rotateMatrix(int* matrix, size_t n)
{
	// Transpose and reverse rows
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
		{
			std::swap(matrix[i + n * j], matrix[j + n * i]);
		}

	
	for (size_t i = 0; i < n; ++i)
		for (size_t k = 0; k < n / 2; ++k)
			std::swap(matrix[i], matrix[n - k - 1]);

}

void zerofyMatrix(int* matrix, size_t rows, size_t columns)
{
	std::vector<bool> zero_rows(rows, false);
	std::vector<bool> zero_cols(columns, false);

	for (size_t i = 0; i < columns; ++i)
		for (size_t j = 0; j < rows; ++j)
			if (0 == matrix[j + columns * i])
    			{
				zero_rows[j] = true;
				zero_cols[i] = true;
			}

	for (size_t i = 0; i < columns; ++i)
		for (size_t j = 0; j < rows; ++j)
			if (zero_rows[j] || zero_cols[i])
				matrix[j + columns * i] = 0;	
			
}

bool isRotation(const std::string& a, const std::string& b)
{
    if (a.size() == b.size() && a.size() > 0)
    {
        const auto aa = a + a;

        if (aa.find(b) != std::string::npos)
            return true;
    }
	
	return false;
}


