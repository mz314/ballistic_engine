/**
* Zestaw klas definujący podstawowe typy używane przez silnik, nie uwzględnia struktur matematycznych (wektory,macierze), które
* obsugiwane są w klasach zawartych w Vector3d.hpp
*/

#ifndef TYPES_HPP
#define	TYPES_HPP

#include <vector>
#include <iostream>

#include "types/Vector3d.hpp"
#include "types/texture.hpp"



using namespace std;


class ColorRGB {
public:
    ColorRGB() {};
    ColorRGB(unsigned int i);
    ColorRGB(e_loc r, e_loc g,e_loc b);
    e_loc r,g,b;
    bool operator=(const ColorRGB &color);
};


class ColorRGBA : public ColorRGB {
public:
    ColorRGBA() {};
    ColorRGBA(unsigned int i);
    ColorRGBA(e_loc r, e_loc g,e_loc b, e_loc a);
    bool operator=(const ColorRGBA &color);
    e_loc a;
};

class Coords {
public:	
        Vector3d translation,rotation;
        void reset();
	Coords();
};

struct FrustumSizes {
 e_loc x,y,znear,zfar;
};


struct UV {
 e_loc u,v;
};

typedef Vector3d v_type;
typedef Vector3d n_type;

struct Frame {
	e_loc fnum,fval;
	v_type *verts;
};



#endif	/* TYPES_HPP */

