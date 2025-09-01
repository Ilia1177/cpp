#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
# include <fstream>
# include <iostream>
#include <string>
#include <sstream>   // optional, if you're also using stringstream

# define USAGE_MSG "arg 1: file_name, arg 2: old_string, arg 3: new_string"

class FileHandler {
	public:
		FileHandler();
		~FileHandler();
		int		edit(const std::string& old_str, const std::string& new_str);
		int		openInfile(const std::string& file_name);

	private:
		std::string		_fileName;
		std::ifstream	_inFile;
		std::ofstream	_outFile;
};

#endif
