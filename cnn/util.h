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
		return (height_*node_numbers + row)*height_ + col;
	}

private:
	size_t node_number_;
	size_t width_;
	size_t height_;
};