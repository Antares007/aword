#pragma once
/*          a
Yellow....  N  .......Navy   
Purple....  N  .......Lime   
Red.......  o  .....Maroon 
Green..... OAN ....Fuchsia
Blue...... OAN ......Olive  
            s
*/
#define N(argo) void argo(long t, long a, void*b, void**o, long s)
typedef N((*n_t));
#define Usleep(v) ((void (*)(long))o[1])(v)
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define P Printf("%3ld %3ld %5ld %ld %s %s\n", a, s, t, (long)o[a-1], __FILE__, __FUNCTION__), Usleep(20000)

