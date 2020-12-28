#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include "Core.hpp"
#include "Minmax.hpp"

Core::Core() :
	_stop(false),
	_gomoku(new Minmax()) {
	_cmdFunction["START "] = std::bind(&Core::startCmd, this, std::placeholders::_1);
	_cmdFunction["TURN "] = std::bind(&Core::turnCmd, this, std::placeholders::_1);
	_cmdFunction["BEGIN"] = std::bind(&Core::beginCmd, this, std::placeholders::_1);
	_cmdFunction["BOARD"] = std::bind(&Core::boardCmd, this, std::placeholders::_1);
	_cmdFunction["INFO"] = std::bind(&Core::infoCmd, this, std::placeholders::_1);
	_cmdFunction["END"] = std::bind(&Core::endCmd, this, std::placeholders::_1);
	_cmdFunction["ABOUT"] = std::bind(&Core::aboutCmd, this, std::placeholders::_1);
}

Core::~Core() {
	delete _gomoku;
}

void Core::run() {
	std::string cmd;

	while (!_gomoku->getEnd()) {
		cmd.clear();
		getline(std::cin, cmd);
		if (cmd == "BOARD") {
			cmd = getAllBoard(cmd);
		}
		callCmdFunction(cmd);
	}
}

std::string Core::getAllBoard(std::string cmd) {
	std::string buff;

	while (buff != "DONE") {
		buff.clear();
		getline(std::cin, buff);
		if (buff == "DONE")
			continue;
		cmd += ("\n" + buff);
	}
	return cmd;
}

void Core::callCmdFunction(std::string cmd) {
	bool error = true;

	try
	{
		if (cmd == "dump") {
			_gomoku->dump();
		}
		else {
			for (auto it : _cmdFunction) {
				if (cmd.find(it.first.c_str(), 0, it.first.length()) != std::string::npos) {
					it.second(cmd.substr(it.first.length()));
					error = false;
				}
			}
			if (error) {
				std::cout << "command not found" << std::endl;
			}
		}

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Core::startCmd(std::string cmd) {
	int size = std::stoi(cmd);
	try {
		this->_gomoku->start(size);
	}
	catch (const InvalidBoardSize &e) {
		std::cout << e.what() << std::endl;
	}

}

void Core::turnCmd(std::string cmd) {
	std::stringstream ss(cmd);
	std::string buf;
	int x;
	int y;

	std::getline(ss, buf, ',');
	x = std::stoi(buf);
	std::getline(ss, buf);
	y = std::stoi(buf);
	this->_gomoku->turn(x, y);
}

void Core::beginCmd(std::string cmd) {
	(void)cmd;
	this->_gomoku->begin();
}

void Core::boardCmd(std::string cmd) {
	int x_pos;
	int y_pos;
	int color;

	cmd.erase(0, 1); //remove the first \n
	if (cmd.empty())
		return;
	std::istringstream input(cmd);
	std::string buffInput;
	std::string lineBuff;

	while (std::getline(input, buffInput, '\n')) {
		std::istringstream line(buffInput);

		std::getline(line, lineBuff, ',');
		x_pos = std::stoi(lineBuff);
		std::getline(line, lineBuff, ',');
		y_pos = std::stoi(lineBuff);
		std::getline(line, lineBuff);
		color = std::stoi(lineBuff);
		this->_gomoku->board(x_pos, y_pos, color);
	}
}

void Core::infoCmd(std::string cmd) {
	std::string key;
	std::string value;
	std::stringstream ss(cmd);

	ss >> key;
	ss >> value;
	this->_gomoku->info(key, value);
}

void Core::endCmd(std::string cmd) {
	(void)cmd;
	this->_gomoku->end();
}

void Core::aboutCmd(std::string cmd) {
	(void)cmd;
	this->_gomoku->about();
}