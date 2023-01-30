#include "Video.hpp"
#include <iostream>

int main(){
	Video v1{"../media/video.mp4"};
	std::cerr << v1.getLink() << "\n";

	v1.run();
}