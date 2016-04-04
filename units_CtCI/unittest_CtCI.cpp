#include "CppUnitTest.h"
#include <string>

#include "ctci_chapter_one.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace units_CtCI
{		
	TEST_CLASS(UnitCtCIChapterOne)
	{
	public:
		
		TEST_METHOD(TestAllUnique)
		{
			const std::string unique{ "abc" }; // allunique string
			Assert::IsTrue(allUnique(unique), L"AllUnique unique data test failed");

			const std::string non_unique{ "abca" }; // allunique string
			Assert::IsFalse(allUnique(non_unique), L"AllUnique non-unique data test failed");
		}

		TEST_METHOD(TestReverseString)
		{
			char str1[] = { "abcd\0" };
			reverseString(str1);

			Assert::IsTrue(0 == strcmp(str1, "dcba"), L"ReverseString symmetric test failed");

			char str2[] = { "abcde\0" };
			reverseString(str2);

			Assert::IsTrue(0 == strcmp(str2, "edcba"), L"ReverseString asymmetric test failed");
		}

		TEST_METHOD(TestReplaceSpace)
		{
			char s[20] = { "hello world" };	
			replaceSpace(s, 13);

			Assert::IsTrue(0 == strcmp(s, "hello%20world"), L"ReplaceSpace test failed");
		}

		TEST_METHOD(TestPermutationString)
		{
			const std::string a = { "abc" };
			const std::string b = { "cba" };

			Assert::IsTrue(isPermutation(a, b), L"PermutationString test failed");
		}

		TEST_METHOD(TestCompressString)
		{
			const std::string str = { "aabbbc" };
			const std::string res = compressString(str);

			Assert::IsTrue(0 == res.compare("a2b3c"), L"PermutationString test failed");
		}
	};
}