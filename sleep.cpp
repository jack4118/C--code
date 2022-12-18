#ifdef __WIN32__
#include <windows.h> 
#else
#include <unistd.h>
#endif
void msleep(int milliseconds)
{
  #ifdef __WIN32__
  Sleep(milliseconds);
  #else
  usleep(static_cast<useconds_t>(milliseconds)*1000); //or use nanosleep on platforms where it's needed
  #endif
}