#ifndef PBRAIN_GOMOKU_INFO_HPP
#define PBRAIN_GOMOKU_INFO_HPP

#include <string>
#include <utility>

class Info {
private:
	int _timeout_turn;
	int _timeout_match;
	int _max_memory;
	int _time_left;
	int _game_type;
	int _rule;
	std::pair<int, int> _evaluate;
	std::string _folder;

public:
	Info();
	~Info();
	void setTimeoutTurn(int timeout_turn);
	void setTimeoutMatch(int timeout_match);
	void setMaxMemory(int max_memory);
	void setTimeLeft(int time_left);
	void setGameType(int game_type);
	void setRule(int rule);
	void setEvaluate(std::pair<int, int> evaluate);
	void setFolder(const std::string &folder);
	int getTimeoutTurn() const;
	int getTimeoutMatch() const;
	int getMaxMemory() const;
	int getTimeleft() const;
	int getGametype() const;
	int getRule() const;
	std::pair<int, int> getEvaluate() const;
	std::string getFolder() const;
};


#endif //PBRAIN_GOMOKU_INFO_HPP
