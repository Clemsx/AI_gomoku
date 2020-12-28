#ifndef PBRAIN_GOMOKU_ABOUT_HPP
#define PBRAIN_GOMOKU_ABOUT_HPP

#include <string>

class About {
private:
	double _version;
	std::string _name;
	std::string _author;
	std::string _country;

public:
	//Change default value in constructor if needed
	explicit About(const double &version = 1,
		const std::string &name = "Minmax",
		const std::string &author = "Remi LAK, Clement Xia, Yoann Wargnier",
		const std::string &country = "France");
	~About();
	std::string getName() const;
	double getVersion() const;
	std::string getAuthor() const;
	std::string getCountry() const;
};


#endif //PBRAIN_GOMOKU_ABOUT_HPP
