#ifndef PBRAIN_GOMOKU_AGOMOKU_HPP
#define PBRAIN_GOMOKU_AGOMOKU_HPP

#include <iostream>
#include <functional>
#include <map>
#include "IGomoku.hpp"
#include "Info.hpp"
#include "About.hpp"
#include "Exception.hpp"

#define EMPTY 0
#define BRAIN 1
#define OPPONENT 2
#define RENJU 3

class AGomoku : public IGomoku
{
protected:
	std::vector<std::vector<int> > _board;
	int _size;

private:
	Info _info;
	About _about;
	bool _end;
	std::map<std::string, std::function<void(int)> > _setInfoFunction;

public:
	AGomoku();
	virtual ~AGomoku();
	bool start(int size) override;
	bool board(size_t pos_x, size_t pos_y, size_t color) override;
	bool info(std::string key, std::string value) override;
	void end() override;
	bool about() override;
	bool turn(size_t x, size_t y) override = 0;
	bool begin() override = 0;
	bool getEnd();
	void dump();
};

#endif //PBRAIN_GOMOKU_AGOMOKU_HPP