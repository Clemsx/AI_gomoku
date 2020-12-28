#ifndef GOMOKU_CORE_HPP
#define GOMOKU_CORE_HPP

#include <map>
#include <functional>
#include <iostream>
#include "AGomoku.hpp"
#include "Exception.hpp"

class Core {
private:
	bool _stop;
	AGomoku *_gomoku;
	std::map<std::string, std::function<void(std::string)>> _cmdFunction;

public:
	Core();
	~Core();
	void run();
	void callCmdFunction(std::string cmd);
	std::string getAllBoard(std::string cmd);
	void startCmd(std::string cmd);
	void turnCmd(std::string cmd);
	void beginCmd(std::string cmd);
	void boardCmd(std::string cmd);
	void infoCmd(std::string cmd);
	void endCmd(std::string cmd);
	void aboutCmd(std::string cmd);
};

#endif //GOMOKU_CORE_HPP
