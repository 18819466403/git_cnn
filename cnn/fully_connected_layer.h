#pragma once
#include"base_layer.h"

class fully_connected_layer {

public:
	virtual ~fully_connected_layer() = default;

	virtual void forward_propagation(
		const std::vector<float_t> &in_data,
		std::vector<float_t> &out_data) {

	}

	virtual void back_propagation(
		const std::vector<float_t> &in_data,
		std::vector<float_t> &out_data,
		std::vector<float_t> &in_error,
		std::vector<float_t> &out_error) {
		
	}


};
