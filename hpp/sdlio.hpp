#ifndef SDLIO_HPP
#define	SDLIO_HPP

#include <SDL/SDL.h>
#include <boost/thread/thread.hpp>
#include "rendererAbstract.hpp"
#include "rendererGL.hpp"
#include "singleton.hpp"
#include "engineState.hpp"

class sdlIO  :  public singleton<sdlIO> {
private:
    static SDL_Surface *screen;
    static SDL_Renderer* displayRenderer;
	static SDL_Window *window;
public:
    static void flush();
    static void initWindow();
    void eventLoop();
	virtual void operator()();
    sdlIO();
    ~sdlIO();
};

#endif 