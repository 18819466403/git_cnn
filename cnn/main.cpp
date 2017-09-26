#include"cnn.h"
#include"conv_params.h"
#define O true
#define X false
static const bool connection[] = {
	O, X, X, X, O, O, O, X, X, O, O, O, O, X, O, O,
	O, O, X, X, X, O, O, O, X, X, O, O, O, O, X, O,
	O, O, O, X, X, X, O, O, O, X, X, O, X, O, O, O,
	X, O, O, O, X, X, O, O, O, O, X, X, O, X, O, O,
	X, X, O, O, O, X, X, O, O, O, O, X, O, O, X, O,
	X, X, X, O, O, O, X, X, O, O, O, O, X, O, O, O
};
int main() {
	network cnn;
	/*cnn << conv(2)<< pool(2);
	cnn.net_.at(1)->get();*/

	int width = 16;
	int height = 3;
   connection_table con(connection, 6, 16);
   index4d index(1,2,width, height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
		{
			std::cout << connection[index.get_index(0,1,i,j)]<<" ";
		}
		std::cout << std::endl;
	}


	//conv con(16, 16, 5, 1, 6);
	//pool pol(4, 4, 1, 2);
	//std::vector<float_t> in_data(16);
	//std::vector<float_t> out_data;
	//for (size_t i = 0; i < 16; i++) in_data[i] = i+1;
	////con.forward_propagation(in_data, out_data);
	//pol.forward_propagation(in_data, out_data);
	
}
