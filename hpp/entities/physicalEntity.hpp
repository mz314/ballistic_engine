#ifndef PHYSICAL_ENTITY_H
#define PHYSICAL_ENTITY_H

#include "types/types.hpp"
#include "types/mathTypes.hpp"
#include "entities/entity.hpp"
#include "time/timer.hpp"

class TrRot {
public:
	MathTypes::Vector3d t,r;
	void reset();
	TrRot();
};

class PhysicalEntity : public Entity {
protected:
	
	void setIfNotZero(e_loc &a,e_loc &b);
public:
	TrRot velocity,acceleration;
        e_loc weight;
	PhysicalEntity();
	Coords nextCoords(time_int diff);
	void changeVelocity(TrRot velocity);
	void setVelocity(TrRot velocity);
        bool no_physics;
	//void resetT();
	TrRot getVelocity();
	void printVelocity();
	

};

#endif