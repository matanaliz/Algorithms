#include <iostream>
#include <array>

#include "ctci_chapter_one.h"


int main(int argc, char* argv[])
{
	char s1[] = { "abcde\0" };
	reverseString(s1);

	char s2[] = { "hello world\0\0" };
	replaceSpace(s2, 13);

	return 0;
}