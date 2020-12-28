#ifndef PBRAIN_GOMOKU_EXCEPTION_HPP
# define PBRAIN_GOMOKU_EXCEPTION_HPP

# include <string>
# include <exception>

class Exception : public std::exception {
protected:
	std::string _msg;

public:
	explicit Exception(const char *msg) :
		_msg(msg) {

	};

	explicit Exception(std::string msg) :
		_msg(std::move(msg)) {

	};

	~Exception() throw() override = default;

	const char *what() const throw() override {
		return _msg.c_str();
	};
};

class InvalidBoardSize : public std::exception {
protected:
	std::string _msg;

public:
	explicit InvalidBoardSize(int size) {
		_msg += "ERROR message - ";
		if (size < 5)
			_msg += "Size has to be five minimum to be playable\n";
		else if (size > 20)
			_msg += "Size is too big\n";
		else
			_msg += "Unknown size error\n";
	};

	~InvalidBoardSize() throw() override = default;

	const char *what() const throw() override {
		return _msg.c_str();
	};
};


#endif //PBRAIN_GOMOKU_EXCEPTION_HPP
