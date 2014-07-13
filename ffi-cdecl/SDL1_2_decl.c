#include <SDL/SDL.h>

#include "ffi-cdecl.h"
#include "ffi-cdecl-luajit.h"

cdecl_type(Uint32)
cdecl_type(Sint32)
cdecl_type(Uint16)
cdecl_type(Sint16)
cdecl_type(Uint8)
cdecl_type(Sint8)

//cdecl_type(SDLKey)
//cdecl_type(SDLMod)
cdecl_struct(SDL_keysym)

cdecl_type(SDL_EventType)
cdecl_type(SDL_EventMask)

cdecl_struct(SDL_ActiveEvent)
cdecl_struct(SDL_KeyboardEvent)
cdecl_struct(SDL_MouseMotionEvent)
cdecl_struct(SDL_MouseButtonEvent)
cdecl_struct(SDL_JoyAxisEvent)
cdecl_struct(SDL_JoyBallEvent)
cdecl_struct(SDL_JoyHatEvent)
cdecl_struct(SDL_JoyButtonEvent)
cdecl_struct(SDL_ResizeEvent)
cdecl_struct(SDL_ExposeEvent)
cdecl_struct(SDL_QuitEvent)
cdecl_struct(SDL_UserEvent)
cdecl_struct(SDL_SysWMEvent)
cdecl_union(SDL_Event)

cdecl_struct(SDL_Rect)
cdecl_struct(SDL_Color)
cdecl_struct(SDL_Palette)
cdecl_struct(SDL_PixelFormat)
cdecl_struct(SDL_Surface)

cdecl_func(SDL_Init)
cdecl_func(SDL_WasInit)
cdecl_func(SDL_Quit)
cdecl_func(SDL_SetVideoMode)
cdecl_func(SDL_EnableKeyRepeat)
cdecl_func(SDL_WaitEvent)
cdecl_func(SDL_PollEvent)
cdecl_func(SDL_GetTicks)
cdecl_func(SDL_Delay)
cdecl_func(SDL_LockSurface)
cdecl_func(SDL_UnlockSurface)
cdecl_func(SDL_FillRect)
cdecl_func(SDL_Flip)
cdecl_func(SDL_MapRGB)

cdecl_const(SDL_INIT_TIMER)
cdecl_const(SDL_INIT_AUDIO)
cdecl_const(SDL_INIT_VIDEO)
cdecl_const(SDL_INIT_CDROM)
cdecl_const(SDL_INIT_JOYSTICK)
cdecl_const(SDL_INIT_NOPARACHUTE)
cdecl_const(SDL_INIT_EVENTTHREAD)
cdecl_const(SDL_INIT_EVERYTHING)

cdecl_const(SDL_SWSURFACE)
cdecl_const(SDL_HWSURFACE)
cdecl_const(SDL_ASYNCBLIT)

cdecl_const(SDL_ANYFORMAT)
cdecl_const(SDL_HWPALETTE)
cdecl_const(SDL_DOUBLEBUF)
cdecl_const(SDL_FULLSCREEN)
cdecl_const(SDL_OPENGL)
cdecl_const(SDL_OPENGLBLIT)
cdecl_const(SDL_RESIZABLE)
cdecl_const(SDL_NOFRAME)

cdecl_const(SDL_HWACCEL)
cdecl_const(SDL_SRCCOLORKEY)
cdecl_const(SDL_RLEACCELOK)
cdecl_const(SDL_RLEACCEL)
cdecl_const(SDL_SRCALPHA)
cdecl_const(SDL_PREALLOC)
