#pragma once
#include "base_layer.h"
#include "conv_params.h"
#include<time.h>
#include<random>
class convolutional_layer : public base_layer {
public:
	convolutional_layer(size_t in_width) {};

	convolutional_layer(
		size_t in_width,
		size_t in_height,
		size_t window_size,
		size_t in_channels,
		size_t out_channels,
		const connection_table &connection_table,
		bool has_bais = true,
		size_t w_stride = 1,
		size_t h_stride = 1){
		set_params(connection_table, in_width, in_height, window_size, in_channels, out_channels, has_bais, w_stride, h_stride);
	}

	convolutional_layer(
		size_t in_width,
		size_t in_height,
		size_t window_size,
		size_t in_channels,
		size_t out_channels,
		bool has_bais = true,
		size_t w_stride = 1,
		size_t h_stride = 1)
		:convolutional_layer(
			in_width,
			in_height,
			window_size,
			in_channels,
			out_channels,
			connection_table(),
			has_bais,
			w_stride,
			h_stride
		) {}

	void forward_propagation(const std::vector<float_t> &in_data,
		                     std::vector<float_t> &out_data) {
		out_data.resize(params_.this_nodes_*(params_.in_width_ - params_.window_size_ + 1)*(params_.in_height_ - params_.window_size_ + 1));
		index3d index_in_data(params_.in_nodes_, params_.in_width_, params_.in_height_);
		index3d index_out_data(params_.this_nodes_, params_.in_width_ - params_.window_size_ + 1, params_.in_height_ - params_.window_size_ + 1);
		index4d index_weight(params_.in_nodes_,params_.this_nodes_, params_.window_size_, params_.window_size_);
		for (size_t i = 0; i < params_.in_nodes_; i++) {
			for (size_t j = 0; j < params_.this_nodes_; j++) {
				if (params_.table_.is_connect(i, j)) {
					for (size_t w = 0; w < params_.in_height_ - params_.window_size_ + 1;) {
						for (size_t h = 0; h < params_.in_width_ - params_.window_size_ + 1;) {
							for (size_t m = 0; m < params_.window_size_; m++) {
								for (size_t n = 0; n < params_.window_size_; n++) {
									out_data[index_out_data.get_index(j, w, h)]+=
						            in_data[index_in_data.get_index(i, w + m, h + n)]*params_.weight_[index_weight.get_index(i,j, m, n)];
								}
							}
							h += params_.h_stride_;
						}
						w += params_.w_stride_;
					}
				}
			}
		}

		for (size_t i = 0; i < params_.this_nodes_; i++) {
			for (size_t j = 0; j < params_.in_height_ - params_.window_size_ + 1; j++) {
				for (size_t k = 0; k < params_.in_width_ - params_.window_size_ + 1; k++) {
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
		                  std::cout << "con_layer_back" << std::endl;
	}

	void convolution(const std::vector<float_t> &in_data,
		std::vector<float_t> &out_data) {



	}

	void get() {
		std::cout << "conv" << std::endl;
	}

	void set_params(
		connection_table table,
		size_t in_width,
		size_t in_height,
		size_t window_size,
		size_t in_channels,
		size_t out_channels,
		bool has_bias,
		size_t w_stride,
		size_t h_stride) {

		params_.table_ = table;
		params_.in_height_ = in_height;
		params_.in_width_ = in_width;
		params_.window_size_ = window_size;
		params_.in_nodes_ = in_channels;
		params_.this_nodes_ = out_channels;
		params_.has_bias_ = has_bias;
		params_.w_stride_ = w_stride;
		params_.h_stride_ = h_stride;
		params_.weight_.resize(out_channels*window_size*window_size);
		std::default_random_engine random;
		std::uniform_real_distribution<float_t> real_dis(-1, 1);
		index4d index(in_channels,out_channels, window_size, window_size);
		for (size_t i = 0; i < in_channels; i++) {
			for (size_t l = 0; l < out_channels; l ++) {
				std::cout << "Kernel of " << i + 1 << "th node" << std::endl;
				for (size_t j = 0; j < window_size; j++) {
					for (size_t k = 0; k < window_size; k++) {
						params_.weight_.at(index.get_index(i,l,j,k)) =
							(float_t)(real_dis(random)*sqrt(6.0 / (in_channels*window_size*window_size + out_channels*in_channels*window_size*window_size)));
						std::cout << params_.weight_.at(index.get_index(i,l,j,k)) << " ";
					}
					std::cout << std::endl;
				}
				std::cout << '\n' << '\n';

			}
		}

		if (has_bias) params_.bias_ = 0;
	}

private:
	conv_params params_;
	
 };