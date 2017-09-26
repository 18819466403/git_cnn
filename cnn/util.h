#pragma once
#include<vector>
#include"base_layer.h"
#include <cassert>

struct index3d {
public:
    index3d(){
		node_number_ = 0;
		width_ = 0;
		height_ = 0;
	}

	index3d(size_t node_number, size_t width, size_t height) 
		   :node_number_(node_number),width_(width),height_(height){}

	void set_3d(size_t node_number, size_t width, size_t height) {
		node_number_ = node_number;
		width_ = width;
		height_ = height;
	}

	size_t get_index(size_t node_numbers,size_t row,size_t col) {
		assert(col >= 0 && col < width_);
		assert(row >= 0 && row < height_);
		assert(node_numbers >= 0 && node_numbers < node_number_);
		return (height_*node_numbers + row)*width_ + col;
	}

private:
	size_t node_number_;
	size_t width_;
	size_t height_;
};

struct index4d {
	index4d() {
		front_ = 0;
		queen_ = 0;
		width_ = 0;
		height_ = 0;
	}

	index4d(size_t front,size_t queen,size_t width,size_t height):
		front_(front),queen_(queen),width_(width),height_(height){}

	size_t get_index(size_t front, size_t queen, size_t row, size_t col) {
		assert(col >= 0 && col < width_);
		assert(row >= 0 && row < height_);
		assert(front >= 0 && front < front_);
		assert(queen >= 0 && queen < queen_);
		return ((front*queen_ + queen)*height_+row)*width_+col;
	}
private:
	size_t front_;
	size_t queen_;
	size_t width_;
	size_t height_;
};