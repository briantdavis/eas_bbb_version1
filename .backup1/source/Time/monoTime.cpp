#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*DOES NOT ACCOUNT FOR ERRORS
* Simple time interval
* Will output the time to execute according to CPU time
* MUST COMPILE USING "gcc -lrt -o time time.cpp"
* the -lrt as far as I can tell is for the "librt" library
* For my module, I get a pretty stable 3 micro seconds per run
* but that's not running anything aside from this...
*/
int main(){
	struct timespec timestart, timeend;
	int i=0;
	double mono = 0.0;
	long lowest=1000000, highest=0, stamp = 0;
	for(; i<25000000; i++){
		clock_gettime(CLOCK_MONOTONIC, &timestart);
		clock_gettime(CLOCK_MONOTONIC, &timeend);
		stamp = (timeend.tv_nsec-timestart.tv_nsec);
		//printf("%lu monoNS\n", stamp);
		if(stamp > highest){
			highest = stamp;
		}
		else if(stamp < lowest){
			lowest = stamp;
		}
		mono+= abs(stamp)*(1.0e-9);
	}
	printf("%f monoNS Final\n", (mono/i)*(1.0e9));
	printf("%d highest: %d lowest\n", highest, lowest);
}
