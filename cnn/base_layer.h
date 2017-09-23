#pragma once
#include<iostream>
#include<memory>
#include<vector>
#include"util.h"
#ifdef CNN_USE_DOUBLE
typedef double float_t;
#else
typedef float float_t;
#endif

typedef std::vector<float_t> vec_t;
typedef std::vector<vec_t> node_t;

class base_layer: public std::enable_shared_from_this<base_layer> {

public:	
	base_layer() = default;

	virtual ~base_layer() = default;

	virtual void forward_propagation(const std::vector<float_t> &in_data,
		                             std::vector<float_t> &out_data)=0;

	virtual void back_propagation(const std::vector<float_t> &in_data,
	                              std::vector<float_t> &out_data,
	                              std::vector<float_t> &in_error,
		                          std::vector<float_t> &out_error) = 0;



private:
	std::vector<float_t> f_in_data_;
	std::vector<float_t> f_out_data_;
	std::vector<float_t> b_in_data_;
	std::vector<float_t> b_out_data;
};