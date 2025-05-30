#include "FileHandler.hpp"

FileHandler::~FileHandler( void ) {
    if (_inFile.is_open()) {
        _inFile.clear();  
        _inFile.close();
    }
    if (_outFile.is_open()) {
        _outFile.clear();
        _outFile.close();
    }
}

FileHandler::FileHandler( void )
	:  _fileName("") {}

int	FileHandler::openInfile(const std::string& file_name) {

	_fileName = file_name;
	_inFile.open(file_name.c_str());
	if (!_inFile.is_open() || !_inFile) {
        std::cerr << "Failed to open file!" << std::endl;
        return (1);
    }
	return (0);
}

int	FileHandler::edit(const std::string& old_str, const std::string& new_str) {

	const std::string	newName = _fileName + ".replace";
	std::string			curr_line;
	std::size_t			index;
	int					found;

	found = 0;
	if (old_str == "") {
		std::cout << "Cannot replace empty string." << std::endl;
		return (3);
	}
	while (std::getline(_inFile, curr_line)) {
		index = curr_line.find(old_str);
		while (index != std::string::npos) {
			found = 1;
			if (!_outFile.is_open()) {
				_outFile.open(newName.c_str());
				if (!_outFile.is_open() || !_outFile) {
					std::cerr << "error opening file" << std::endl;
					return (2);
				}
			} 
			_outFile.write(curr_line.c_str(), index);
			_outFile.write(new_str.c_str(), new_str.length());
			curr_line = curr_line.substr(index + old_str.length());
			index = curr_line.find(old_str);
		} 
		_outFile << curr_line << std::endl;
	}
	if (found) {
		std::cout << old_str << " has been replaced." << std::endl;
	} else if (!found) {
		std::cout << old_str << " not found." << std::endl;
	}
	return (0);
}
