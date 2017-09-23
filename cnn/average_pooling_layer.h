#pragma once
#include "base_layer.h"
#include"pool_params.h"
class average_pooling_layer : public base_layer {
public:
	average_pooling_layer(size_t in_width) {};

	average_pooling_layer(size_t in_width, size_t in_height, size_t in_nodes, size_t window_size) {
		set_params(in_width, in_height, in_nodes,  window_size);
	}

	void forward_propagation(const std::vector<float_t> &in_data,
		                     std::vector<float_t> &out_data) {
		out_data.resize(params_.in_nodes_*(params_.in_width_ / params_.window_size_)*(params_.in_height_ / params_.window_size_));
		index3d index_in_data(params_.in_nodes_, params_.in_width_, params_.in_height_);
		index3d index_out_data(params_.this_nodes_, params_.in_width_ / params_.window_size_, params_.in_height_ / params_.window_size_);
		for (size_t i = 0; i < params_.this_nodes_; i++) {
			for (size_t j = 0; j < params_.in_height_;) {
				for (size_t k = 0; k < params_.in_width_;) {
					for (size_t m = 0; m < params_.window_size_; m++) {
						for (size_t n = 0; n < params_.window_size_; n++) {
							out_data[index_out_data.get_index(i, j / params_.window_size_, k / params_.window_size_)] += 
								(float)(1.0 / params_.window_size_ / params_.window_size_)*in_data[index_in_data.get_index(i, j + m, k  + n)];
						}
					}
					k += params_.window_size_;
				}
				j += params_.window_size_;
			}
		}
		for (size_t i = 0; i < params_.this_nodes_; i++) {
			for (size_t j = 0; j < params_.in_height_ / params_.window_size_; j++) {
				for (size_t k = 0; k < params_.in_width_ / params_.window_size_; k++) {
					std::cout << out_data[index_out_data.get_index(i, j, k)] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

	}

	void back_propagation(const std::vector<float_t> &in_data,
		                  std::vector<float_t> &out_data,
		                  std::vector<float_t> &in_error,
	                      std::vector<float_t> &out_error) {
		std::cout << "pool_layer_back" << std::endl;
	}

	void get() {
		std::cout << "poll" << std::endl;
	}

	void set_params(size_t in_width, size_t in_height, size_t in_nodes, size_t window_size) {
		params_.in_width_ = in_width;
		params_.in_height_ = in_height;
		params_.in_nodes_ = in_nodes;
		params_.this_nodes_ = in_nodes;
		params_.window_size_ = window_size;
		
	}

private:
	pool_params params_;

};