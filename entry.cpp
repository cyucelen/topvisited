#include "entry.h"

Entry::Entry():
	key(""),
	value(1)
{
	link = NULL;
}

Entry::Entry(const std::string &key, const int &value):
	key(key), 
	value(value)
{
	link = NULL;
}

Entry::Entry(const Entry &other): 
	key(other.key),
	value(other.value)
{
	link = NULL;
}

Entry& Entry::operator=(const Entry &other) {
	key = other.key;
	value = other.value;
	link = NULL;

	return *this;
}

std::string Entry::getKey() const{
	return key;
}

int Entry::getValue() const{
	return value;
}

Entry* Entry::getLink() const{
	return link;
}

void Entry::setValue(const int &value) {
	this->value = value;
}

void Entry::incrementValue() {
	value++;
}

void Entry::setLink(Entry *next) {
	link = next;
};


Entry::~Entry(){
}
