#include "boundingCube.hpp"

BoundingCube::BoundingCube() {
	
}

BoundingCube::BoundingCube(shape *s) {
	cout << "calc";
	this->calculate(s);
}

BoundingCube::BoundingCube(e_loc width,e_loc height,e_loc depth) {
	this->width=width;
	this->height=height;
	this->depth=depth;
	max_x=width/2;
	min_x=-width/2;
	max_y=height/2;
	min_y=-height/2;
	max_z=depth/2;
	min_z=-depth/2;
}

void BoundingCube::calculate(shape *s) {
vert_list vs=s->getVertices();
	//e_loc max_x,min_x,max_y,min_y,max_z,min_z;
	max_x=min_x=max_y=min_y=max_z=min_z=0;
	
	for (unsigned int i=0; i<vs.size(); i++) {
		if (vs[i]->x > max_x) {
			max_x=vs[i]->x;
		}

		if(vs[i]->x < min_x) {
		 min_x=vs[i]->x;
		}

		if (vs[i]->y > max_y) {
			max_y=vs[i]->y;
		}

		if(vs[i]->y < min_y) {
		 min_y=vs[i]->y;
		}

		if (vs[i]->z > max_z) {
			max_z=vs[i]->z;
		}

		if(vs[i]->z < min_z) {
		 min_z=vs[i]->z;
		}

		cout << vs[i]->x << ", ";
	}

	this->width=max_x-min_x;
	this->height=max_y-min_y;
	this->depth=max_z-min_z;
}

e_loc BoundingCube::getWidth() {
	return this->width;
}

e_loc BoundingCube::getHeight() {
	return this->height;
}

e_loc BoundingCube::getDepth() {
	return this->depth;
}

void BoundingCube::print() {
// cout << "Max x " << max_x << "|" << "Min y " << min_y << 
}