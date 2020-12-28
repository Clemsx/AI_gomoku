#include <random>
#include <thread>
#include "Minmax.hpp"

Minmax::Minmax()
{

}

Minmax::~Minmax() = default;

bool Minmax::turn(size_t x, size_t y)
{
	Move move;

	_board.at(y).at(x) = OPPONENT;
	if (!isBoardEmpty())
	{
		move = chooseMove();
		while (_board.at(move.y).at(move.x) != EMPTY)
			move = chooseMove();
		_board.at(move.y).at(move.x) = BRAIN;
	}
	else
	{
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(static_cast<int>(_board.size() / 2 - 3), static_cast<int>(_board.size() / 2 - 3));
		move.x = uniform_dist(e1);
		move.y = uniform_dist(e1);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	std::cout << move.x << "," << move.y << std::endl;
	return true;
}

bool Minmax::begin()
{
	Move move;

	if (!isBoardEmpty())
	{
		move = chooseMove();
		while (_board.at(move.y).at(move.x) != EMPTY)
			move = chooseMove();
		_board.at(move.y).at(move.x) = BRAIN;
	}
	else
	{
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(static_cast<int>(_board.size() / 2 - 3), static_cast<int>(_board.size() / 2 - 3));
		move.x = uniform_dist(e1);
		move.y = uniform_dist(e1);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	std::cout << move.x << "," << move.y << std::endl;
	return true;
}

bool Minmax::isBoardEmpty()
{
	for (int y = 0; y < _board.size(); y++)
	{
		for (int x = 0; x < _board.size(); x++)
		{
			if (_board.at(y).at(x) != EMPTY)
				return false;
		}
	}
	return true;
}

Move Minmax::chooseMove()
{
	std::vector<Move> moves = getLegalMove();
	int bestScore = 0;
	int bestIndex = 0;
	int i;

	for (i = 0; i < moves.size(); i++)
	{
		if (moves[i].score > bestScore)
		{
			bestIndex = i;
			bestScore = moves[i].score;
		}
	}
	return moves[bestIndex];
}

std::vector<Move> Minmax::getLegalMove()
{
	std::vector<Move> v;

	for (int y = 0; y < _board.size(); y++)
	{
		for (int x = 0; x < _board.size(); x++)
		{
			if (_board.at(y).at(x) == EMPTY)
			{
				Move move(x, y);
				move = getScore(move);
				v.push_back(move);
			}
		}
	}
	return v;
}

Move Minmax::getScore(Move move)
{
	int bestScore = 0;
	int score = 0;
	
	score = checkFirstDiagonal(move, OPPONENT);
	bestScore = score > bestScore ? score : bestScore;
	score = checkSecondDiagonal(move, OPPONENT);
	bestScore = score > bestScore ? score : bestScore;
	score = checkVertical(move, OPPONENT);
	bestScore = score > bestScore ? score : bestScore;
	score = checkHorizontal(move, OPPONENT);
	bestScore = score > bestScore ? score : bestScore;
	score = checkFirstDiagonal(move, BRAIN);
	bestScore = score > bestScore ? score : bestScore;
	score = checkSecondDiagonal(move, BRAIN);
	bestScore = score > bestScore ? score : bestScore;
	score = checkVertical(move, BRAIN);
	bestScore = score > bestScore ? score : bestScore;
	score = checkHorizontal(move, BRAIN);
	bestScore = score > bestScore ? score : bestScore;
	move.score = bestScore;
	return move;
}

int Minmax::checkFirstDiagonal(Move move, int player)
{
	bool leftEnd = false;
	bool rightEnd = false;
	int score = 1;
	int x;
	int y;

	x = move.x - 1;
	y = move.y - 1;
	while (x > 0 && y > 0 &&
		_board.at(y).at(x) == player)
	{
		score++;
		x--;
		y--;
	}
	if (x > 0 && y > 0 && _board.at(y).at(x) != EMPTY)
		leftEnd = true;
	x = move.x + 1;
	y = move.y + 1;
	while (x < _board.size() && y < _board.size() &&
		_board.at(y).at(x) == player)
	{
		score++;
		x++;
		y++;
	}
	if (x < _board.size() && y < _board.size() && _board.at(y).at(x) != EMPTY)
		rightEnd = true;
	if (leftEnd && rightEnd && score != 5)
		return 0;
	return score;
}

int Minmax::checkSecondDiagonal(Move move, int player)
{
	bool leftEnd = false;
	bool rightEnd = false;
	int score = 1;
	int x;
	int y;

	x = move.x + 1;
	y = move.y - 1;
	while (x < _board.size() && y > 0 &&
		_board.at(y).at(x) == player)
	{
		score++;
		x++;
		y--;
	}
	if (x < _board.size() && y > 0 && _board.at(y).at(x) != EMPTY)
		leftEnd = true;
	x = move.x - 1;
	y = move.y + 1;
	while (x > 0 && y < _board.size() &&
		_board.at(y).at(x) == player)
	{
		score++;
		x--;
		y++;
	}
	if (x > 0 && y < _board.size() && _board.at(y).at(x) != EMPTY)
		rightEnd = true;
	if (leftEnd && rightEnd && score != 5)
		return 0;
	return score;
}

int Minmax::checkVertical(Move move, int player)
{
	bool leftEnd = false;
	bool rightEnd = false;
	int score = 1;
	int y;

	y = move.y - 1;
	while (y > 0 &&
		_board.at(y).at(move.x) == player)
	{
		score++;
		y--;
	}
	if (y > 0 && _board.at(y).at(move.x) != EMPTY)
		leftEnd = true;
	y = move.y + 1;
	while (y < _board.size() &&
		_board.at(y).at(move.x) == player)
	{
		score++;
		y++;
	}
	if (y < _board.size() && _board.at(y).at(move.x) != EMPTY)
		rightEnd = true;
	if (leftEnd && rightEnd && score != 5)
		return 0;
	return score;
}

int Minmax::checkHorizontal(Move move, int player)
{
	bool leftEnd = false;
	bool rightEnd = false;
	int score = 1;
	int x;

	x = move.x + 1;
	while (x < _board.size() &&
		_board.at(move.y).at(x) == player)
	{
		score++;
		x++;
	}
	if (x < _board.size() && _board.at(move.y).at(x) != EMPTY)
		leftEnd = true;
	x = move.x - 1;
	while (x > 0 &&
		_board.at(move.y).at(x) == player)
	{
		score++;
		x--;
	}
	if (x > 0 && _board.at(move.y).at(x) != EMPTY)
		rightEnd = true;
	if (leftEnd && rightEnd && score != 5)
		return 0;
	return score;
}