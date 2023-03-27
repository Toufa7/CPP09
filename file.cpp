#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h> 

int main()
{
    struct timeval start, end;
    long sec, micro;

    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);

    sec = end.tv_sec - start.tv_sec;
    micro = end.tv_usec - start.tv_usec;
    long diff = (sec / 1000000) + (micro);

    std::cout << "Micro " << diff;
}