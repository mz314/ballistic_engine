#ifndef RENDERERABSTRACT_HPP
#define	RENDERERABSTRACT_HPP

#include <iostream>

using namespace std;

#include "singleton.hpp"
#include "types.hpp"
#include "texture.hpp"
#include "skybox.hpp"
#include "world.hpp"
#include "config.hpp"


typedef void (*flushf)();

class renderer : public singleton<renderer> {
protected:
    videoData vd;
    float frustum_start, frustum_end, frustum_x, frustum_y; 
    flushf flush_callback;
    world *w;
    virtual void renderShape(shape *s);
    virtual void renderPShape(shape *s);
    virtual void renderVertex(vertex *v) = 0;
    virtual void renderSkybox(skybox *sky) = 0;
	virtual void begin()=0;
	virtual void end()=0;
	virtual void renderAllEntities();
    virtual void assignTexture(texture *t) {
    };
    float gx,gy,gz,gr; //globalne transformacje 
public:
    renderer();
    void setFlush(flushf flush_callback);
    void init(videoData vd);

    virtual void specificInit() {

    };

    virtual void setupTexture(texture *t) {
    }

    virtual void translate(float x, float y, float z);
    virtual void rotate(float x);
    virtual ~renderer();
    void operator()();
    virtual void render() = 0;
};


#endif	/* RENDERERABSTRACT_HPP */

