#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>

using namespace std;

class Block {
public:
	int timestamp;
	char data[1000];
	int pivot;
	char prev_hash[64];
	char hash[64];

	void print() {
		cout << timestamp << "\n" << data << "\n" << pivot << "\n" << prev_hash << "\n" << hash << endl;
	}
};

#endif
