#ifndef SDLIO_HPP
#define	SDLIO_HPP

#include <SDL/SDL.h>
#include "rendererAbstract.hpp"
#include "rendererGL.hpp"
#include "singleton.hpp"

class sdlIO  :  public singleton<sdlIO> {
private:
    SDL_Surface *screen;
    videoData vd;
    bool exit;
    rendererGL *renderer_i;
public:
    void initWindow(videoData vd,renderer *r);
    void eventLoop();
    sdlIO();
    ~sdlIO();
};

#endif 