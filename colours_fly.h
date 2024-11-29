#pragma once

#define FIRSTR(a, ...) #a
#define VA_ARGS_LENGTH(...) sizeof((long[]){__VA_ARGS__}) / sizeof(long)

#define R(β, ...) (long[]){FIRSTR(__VA_ARGS__), VA_ARGS_LENGTH(__VA_ARGS__), β, __VA_ARGS__} + 3

#define οb3(r, ...)     r = (long *[]){r[0],r[1],r[2],R(r,__VA_ARGS__)}
#define οb2(r, ...)     r = (long *[]){r[0],r[1],R(r,__VA_ARGS__),r[3]}
#define οb1(r, ...)     r = (long *[]){r[0],R(r,__VA_ARGS__),r[2],r[3]}
#define οb0(r, ...)     r = (long *[]){R(r,__VA_ARGS__),r[1],r[2],r[3]}

#define οRed(...)       οb3(β, __VA_ARGS__)
#define οYellow(...)    οb2(β, __VA_ARGS__)
#define οGreen(...)     οb1(β, __VA_ARGS__)
#define οBlue(...)      οb0(β, __VA_ARGS__)

#define οMaroon(...)    οb3(α, __VA_ARGS__)
#define οOlive(...)     οb2(α, __VA_ARGS__)
#define οLime(...)      οb1(α, __VA_ARGS__)
#define οNavy(...)      οb0(α, __VA_ARGS__)

#define ΔRed            β[3]
#define ΔYellow         β[2]
#define ΔGreen          β[1]
#define ΔBlue           β[0]

#define ΔMaroon         α[3]
#define ΔOlive          α[2]
#define ΔLime           α[1]
#define ΔNavy           α[0]

