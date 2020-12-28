#include <iostream>
#include "Info.hpp"

Info::Info() :
	_timeout_turn(0),
	_timeout_match(0),
	_max_memory(0),
	_time_left(5000),
	_game_type(0),
	_rule(1),
	_evaluate(0, 0),
	_folder("")
{

}

Info::~Info()
= default;

void Info::setTimeoutTurn(int timeout_turn)
{
	_timeout_turn = timeout_turn;
}

void Info::setTimeoutMatch(int timeout_match)
{
	_timeout_match = timeout_match;
}

void Info::setMaxMemory(int max_memory)
{
	_max_memory = max_memory;
}

void Info::setTimeLeft(int time_left)
{
	_time_left = time_left;
}

void Info::setGameType(int game_type)
{
	_game_type = game_type;
}

void Info::setRule(int rule)
{
	_rule = rule;
}

void Info::setEvaluate(std::pair<int, int> evaluate)
{
	_evaluate = evaluate;
}

void Info::setFolder(const std::string &folder)
{
	_folder = "pbrain-gomoku/" + folder;
}

int Info::getTimeoutTurn() const
{
	return _timeout_turn;
}

int Info::getTimeoutMatch() const
{
	return _timeout_match;
}

int Info::getMaxMemory() const
{
	return _max_memory;
}

int Info::getTimeleft() const
{
	return _time_left;
}

int Info::getGametype() const
{
	return _game_type;
}

int Info::getRule() const
{
	return _rule;
}

std::pair<int, int> Info::getEvaluate() const
{
	return _evaluate;
}

std::string Info::getFolder() const
{
	return _folder;
}
