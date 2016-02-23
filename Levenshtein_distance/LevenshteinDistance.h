#pragma once
#include <string>
#include <iostream>
#include <vector>

template<typename T> class MT;  // pre-declare the template class itself
template<typename T> std::ostream& operator<< (std::ostream& os, const MT<T>& m);

template<class T>
class MT
{
public:

	MT(const std::size_t M, const std::size_t N, const T& val)
		: m_data(M, std::vector<T>(N, val))
	{}

	~MT() = default;
	MT() = delete;

	std::vector<T>& operator[](const std::size_t col) { return m_data[col]; }

	const std::size_t size() const { return m_data.size(); }

private:
	std::vector<std::vector<T>> m_data;
	friend std::ostream& operator << <>(std::ostream&, const MT<T>&);
	
	// Special for range-based "for"
	typename std::vector<std::vector<T>>::const_iterator begin() const { return m_data.cbegin(); }
	typename std::vector<std::vector<T>>::const_iterator end() const { return m_data.cend(); }
};

template<class T>
std::ostream& operator << (std::ostream& os, const MT<T>& m)
{
	for (auto row : m)
	{
		for (const auto& item : row)
			os << item << " ";
		os << std::endl;
	}
	return os;
}

unsigned LevenshteinDistance(const std::string& s1, const std::string& s2);