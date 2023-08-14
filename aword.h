#pragma once

#define N(argo) void argo(long t, long a, void*b, void**o, long s)
typedef N((*n_t));

#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)

