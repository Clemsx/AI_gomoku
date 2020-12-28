#include "About.hpp"

About::About(const double &version,
	const std::string &name,
	const std::string &author,
	const std::string &country) :
	_version(version),
	_name(name),
	_author(author),
	_country(country) {

}

About::~About() = default;

std::string About::getName() const {
	return _name;
}

double About::getVersion() const {
	return _version;
}

std::string About::getAuthor() const {
	return _author;
}

std::string About::getCountry() const {
	return _country;
}
