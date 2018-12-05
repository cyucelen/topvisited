#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>

class Entry{
private:
	std::string key;
	int value;
	Entry *link;
public:
	Entry(const std::string&, const int&);
	Entry();
	Entry(const Entry&);
	Entry& operator=(const Entry&);

	std::string getKey() const;
	int getValue() const;
	Entry* getLink() const;

	void setValue(const int &);
	void incrementValue();
	void setLink(Entry*);

	~Entry();
};

#endif