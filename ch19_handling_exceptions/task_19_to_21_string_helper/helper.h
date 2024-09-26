#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <fstream> // TASK 21
namespace strhelper
{
	//				     v-- TASK 21 --------v
	double loadParameter(std::ifstream &infile, std::string word);

	//                             v---- TASK 20
	size_t findKeyword(std::string &fileContent, std::string word);

	struct KeywordException
	{
		std::string message;
	};
	struct ValueException
	{
		std::string message;
	};

	//                           v-- TASK 21 --v
	double loadOptionalParameter(std::ifstream &src, std::string word, double value);

	// TASK 20
	void deleteComments(std::string &fileContent);
}

namespace SH = strhelper;
#endif // HELPER_H