/*
 ============================================================================
 Name        : Test_C.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int a=10;
	int b = 30;

	list* auxiliar = newList();
	append(auxiliar,&a);
	printf("SIZE: %d",auxiliar->size);
	append(auxiliar,&a);
	printf("SIZE: %d",auxiliar->size);
	append(auxiliar,&a);
	printf("SIZE: %d",auxiliar->size);
	scanf("%*c");
	main2();
	return EXIT_SUCCESS;

}



int main2(void)
{
    time_t current_time, nacimiento_time;
    struct tm info ;

    char* c_time_string;

    /* Obtain current time as seconds elapsed since the Epoch. */
    current_time = time(NULL);

    info.tm_year = 1980 - 1900;
	info.tm_mon = 4 - 1;
	info.tm_mday = 3;
	info.tm_hour = 0;
	info.tm_min = 0;
	info.tm_sec = 1;
	info.tm_isdst = -1;


    nacimiento_time = mktime(&info);

    printf("\nEDAD: %.0f\n" , difftime(current_time,nacimiento_time) / (365*24*60*60));

    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to compute the current time.");
        return EXIT_FAILURE;
    }

    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.");
        return EXIT_FAILURE;
    }

    /* Print to stdout. */
    (void) printf("Current time is %s", c_time_string);
    return EXIT_SUCCESS;
}
