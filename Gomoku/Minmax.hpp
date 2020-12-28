#ifndef PBRAIN_GOMOKU_MINMAX_HPP
#define PBRAIN_GOMOKU_MINMAX_HPP

#include <limits>
#include "AGomoku.hpp"

struct Move
{
	int x;
	int y;
	int score;
	Move() {};
	Move(int x, int y, int score = 0) :
	x(x), y(y), score(score) {};
};

class Minmax : public AGomoku
{
private:
	int iaProfondeurMax;
public:
	Minmax();
	~Minmax() override;
	bool turn(size_t x, size_t y) override;
	bool begin() override;
	Move chooseMove();
	std::vector<Move> getLegalMove();
	Move getScore(Move move);
	bool isBoardEmpty();

	int checkFirstDiagonal(Move move, int player);
	int checkSecondDiagonal(Move move, int player);
	int checkVertical(Move move, int player);
	int checkHorizontal(Move move, int player);
};

#endif //PBRAIN_GOMOKU_MINMAX_HPP
