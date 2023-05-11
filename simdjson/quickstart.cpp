#include <iostream>
#include "simdjson.h"
#include <stdio.h>
double getTime() {
  struct timespec time;
  clock_gettime(CLOCK_MONOTONIC, &time);
  return (double)time.tv_sec + (double)time.tv_nsec / 1000000000.0;
}

using namespace simdjson;
int main(void) {
    ondemand::parser parser;
    padded_string json = padded_string::load("twitter.json");

    double startTime = getTime();

    ondemand::document tweets = parser.iterate(json);
    uint64_t rez = uint64_t(tweets["search_metadata"]["count"]);
    double endTime = getTime();
    double executionTime = endTime - startTime;
    printf("Execution time: %f seconds\n", executionTime);

    std::cout << rez << " results." << std::endl;

}
