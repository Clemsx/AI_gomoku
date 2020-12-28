#include <sstream>
#include "AGomoku.hpp"

AGomoku::AGomoku() {
	_end = false;
	_setInfoFunction["timeout_turn"] = std::bind(&Info::setTimeoutTurn, _info, std::placeholders::_1);
	_setInfoFunction["timeout_match"] = std::bind(&Info::setTimeoutMatch, _info, std::placeholders::_1);
	_setInfoFunction["max_memory"] = std::bind(&Info::setMaxMemory, _info, std::placeholders::_1);
	_setInfoFunction["time_left"] = std::bind(&Info::setTimeLeft, _info, std::placeholders::_1);
	_setInfoFunction["game_type"] = std::bind(&Info::setGameType, _info, std::placeholders::_1);
	_setInfoFunction["rule"] = std::bind(&Info::setRule, _info, std::placeholders::_1);
	_info.setTimeoutTurn(0);
	_info.setTimeoutMatch(0);
	_info.setMaxMemory(0);
	_info.setTimeLeft(0);
	_info.setGameType(0); //may need change
	_info.setRule(0); //may need change
	_info.setEvaluate({ 0,0 }); //may need change
	_info.setFolder("persistent.txt"); //may need change
}

AGomoku::~AGomoku() = default;

bool AGomoku::start(int size) {
	if (size < 5 || size > 20) //may need to change size restriction
	{
		throw InvalidBoardSize(size);
	}
	_size = size;
	std::vector<std::vector<int>> vec(size, std::vector<int>(size));
	_board = vec;
	std::cout << "OK" << std::endl;
	return true;
}

bool AGomoku::board(size_t x, size_t y, size_t color) {
	_board.at(y).at(x) = static_cast<int>(color);
	return true;
}

bool AGomoku::info(std::string key, std::string value) {
	if (key == "evaluate") {
		std::pair<int, int> pos;
		std::istringstream stream(value);
		std::string buff;

		std::getline(stream, buff, ',');
		pos.first = std::stoi(buff);
		std::getline(stream, buff);
		pos.second = std::stoi(buff);
		_info.setEvaluate(pos);
	}
	else if (key == "folder") {
		_info.setFolder(value);
	}
	else {
		_setInfoFunction[key](std::stoi(value));
	}
	return true;
}

void AGomoku::end() {
	_end = true;
}

bool AGomoku::about() {
	std::cout << "name=\"" << _about.getName() << "\", version=\"" << _about.getVersion() << "\", author=\""
		<< _about.getAuthor() << "\", country=\"" << _about.getCountry() << "\"" << std::endl;
	return true;
}

bool AGomoku::getEnd()
{
	return _end;
}

void AGomoku::dump()
{
	for (auto itvec : _board)
	{
		for (auto it : itvec)
		{
			std::cout << it << " ";
		}
		std::cout << std::endl;
	}
}