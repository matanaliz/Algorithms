#include "CppUnitTest.h"

#include "LevenshteinDistance.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittest_Levenshtein_distance
{		
	TEST_CLASS(LevenshteinDistanceTest)
	{
	public:
		
		TEST_METHOD(LevenshteinDistanceEqualStringsTest)
		{
			const std::string s1("test");
			const std::string s2("test");
			const unsigned int res = LevenshteinDistance(s1, s2);

			Assert::IsTrue(0 == res, L"Equal strings test failed");
		}

		TEST_METHOD(LevenshteinDistanceEmptyStringsTest)
		{
			const std::string s1("");
			const std::string s2("");
			const unsigned int res = LevenshteinDistance(s1, s2);

			Assert::IsTrue(0 == res, L"Empty strings test failed");
		}

		TEST_METHOD(LevenshteinDistanceOneEmptyStringsTest)
		{
			const std::string s1("");
			const std::string s2("test");
			const unsigned int res = LevenshteinDistance(s1, s2);

			Assert::IsTrue(4 == res, L"OneEmpty strings test failed");
		}

		TEST_METHOD(LevenshteinDistanceSundayTest)
		{
			const std::string s1("Saturday");
			const std::string s2("Sunday");
			const unsigned int res = LevenshteinDistance(s1, s2);

			// Answer will be 3, looked up in Wikipedia
			Assert::IsTrue(3 == res, L"Sunday test failed");
		}

	};
}