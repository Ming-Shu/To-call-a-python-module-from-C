#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h> 
#include <sys/time.h>
#include <python2.7/Python.h>
#include "interface.h"
#include "eth_socket.h"
int  main(void){
	int tcp_fd,max_fd,nReady,tcp_clifd;
	fd_set rdfds;
	struct timeval timeout;

	timeout.tv_sec = 2;
	timeout.tv_usec = 0;
	tcp_fd = pyTCP_listener("localhost",54321);
	//tcp_fd = createTCP_listener("home/pi/C_call_python",54321);
	while(1)
	{
		FD_ZERO(&rdfds);
		FD_SET(tcp_fd,&rdfds);

		if(tcp_fd>max_fd)
			max_fd = tcp_fd;

		if ( (nReady=select(max_fd+1, &rdfds,NULL, NULL,NULL/*&timeout*/)) < 0 )
			printf("nReady:%d\n",nReady);
			sleep(1);
		if(!nReady){
			printf("NOW is Time Out!!\n\n\n");
		}
		if(FD_ISSET(tcp_fd,&rdfds)){
			tcp_clifd = getCli_fd(tcp_fd);
			pyTCP_acceptMsg(tcp_clifd);
		}
	}//while
	return 0;  
} 
