/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fibonnaci_threads.h"


void
fib_thread_1(char *host, int c_thread)
{
	CLIENT *clnt;
	int  *result_1;
	int  fib_1_arg = c_thread;

#ifndef	DEBUG
	clnt = clnt_create (host, fib_thread, fib_ver_1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	printf("Chosen thread: %d\n", fib_1_arg);
	result_1 = fib_1(&fib_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		if(*result_1 == 1){
			printf("You won!!  :) \n");
		}else {
			printf("You lost!! :( \n");
		}
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];

	if(atoi(argv[2]) > 3 && atoi(argv[2]) < 1){
		printf("Thread number must be 1, 2 or 3.\n");
	}

	fib_thread_1 (host, atoi(argv[2]));
	exit (0);
}
