#pragma once
#include"base_layer.h"

class network {
public:
	std::vector<base_layer *> net_;


};

network &operator<<(network &n, base_layer &&l) {
	n.net_.push_back(&l);
	return n;
};