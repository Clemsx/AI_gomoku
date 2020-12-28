#ifndef GOMOKU_IGOMOKU_HPP
#define GOMOKU_IGOMOKU_HPP

#include <vector>
#include <string>
#include <algorithm>

class IGomoku
{
public:
	virtual bool start(int size) = 0;
	virtual bool turn(size_t x, size_t y) = 0;
	virtual bool begin() = 0;
	virtual bool board(size_t pos_x, size_t pos_y, size_t color) = 0;
	virtual bool info(std::string key, std::string value) = 0;
	virtual void end() = 0;
	virtual bool about() = 0;
};

#endif //GOMOKU_IGOMOKU_HPP
