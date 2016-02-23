#include "LevenshteinDistance.h"
#include <algorithm>

unsigned LevenshteinDistance(const std::string& s1, const std::string& s2)
{
	const std::size_t len1(s1.size());
	const std::size_t len2(s2.size());

	if (0 == len1) return len2;
	if (0 == len2) return len1;

	MT<unsigned> m(len1 + 1, len2 + 1, 0);

	// Initialize initial costs
	// First row
	for (std::size_t i = 0; i < m[0].size(); ++i)
		m[0][i] = i;

	// First column
	for (std::size_t i = 0; i < m.size(); ++i)
		m[i][0] = i;

	for (std::size_t i = 1; i <= len1; ++i)
	for (std::size_t j = 1; j <= len2; ++j)
		{
			m[i][j] = std::min({
				m[i - 1][j] + 1,									//deleting
				m[i][j - 1] + 1,									//insertion
				m[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1)	//substitution
			});
		}

	std::cout << m << std::endl;

	return m[len1][len2];
}


int main(int argc, char* argv[])
{
	const std::string s2("kitten");
	const std::string s1("sitting");
	return LevenshteinDistance(s1, s2);
}

