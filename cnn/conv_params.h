#pragma once
#include<deque>
#include<vector>
struct connection_table {
	connection_table():rows_(0),cols_(0) {};
	connection_table(const bool*connect_ar, size_t rows, size_t cols)
		:connected_(rows*cols),rows_(rows),cols_(cols) {
		std::copy(connect_ar, connect_ar + rows*cols, connected_.begin());
	}

	bool is_connect(size_t x, size_t y){
		return is_empty() ? true : connected_[x*cols_ + y];
	}

	bool is_empty(){
		return 0==rows_ && 0==cols_;
	}

	std::deque<bool> connected_;
	size_t rows_;
	size_t cols_;

};

class conv_params {
public:
	connection_table table_;
	size_t in_width_;
	size_t in_height_;
	size_t window_size_;
	size_t in_nodes_;
	size_t this_nodes_;
	bool has_bias_;
	size_t w_stride_;
	size_t h_stride_;
	std::vector<float_t> weight_;
	float_t bias_;
};
