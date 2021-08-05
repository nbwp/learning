/*
 * @Author: dapei
 * @Date: 2021-08-05 09:54:19
 * @Last Modified by: dapei
 * @Last Modified time: 2021-08-05 09:54:19
 * @Description: 
*/
/*多进程*/
#include <iostream>


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>

#define MESLENGTH 2048
void* read_func(void * arg){
    int newfd,nbytes;
    char buf[MESLENGTH];
    newfd = *((int *)arg);
    free(arg);
        while (1)
        {
            nbytes = read(newfd, buf ,sizeof(buf));
        if(nbytes == 0){
            
            close(newfd);
            exit(0);
        }
        else if(nbytes == -1){
            perror("read error");
            exit(-1);
        }
               
        printf("I have received:%s\n",buf);
        }
        
        

           
        
     
}

int main(int argc,char*argv[])
{
    
    int sockfd,port,n;
    int *pcon_socket;
    pthread_t tid;
    struct sockaddr_in serveraddr;
    socklen_t addrlen;
    char buf[MESLENGTH];
    if (argc != 3 ){
        printf("参数不足/n");
        exit(1);
    }
    bzero(&serveraddr,sizeof(struct sockaddr_in));
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET,argv[1],&(serveraddr.sin_addr.s_addr));
    port = atoi(argv[2]);
    serveraddr.sin_port = htons(port);
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    addrlen = sizeof(struct sockaddr_in);
    connect(sockfd,(struct sockaddr *)(&serveraddr),addrlen);
    //创建线程
    pcon_socket = NULL;
    pcon_socket = (int *)malloc(sizeof(int));
    *pcon_socket = sockfd;
    pthread_create(&tid,NULL,read_func,(void*)pcon_socket); 
    while (1){
        printf("Input message:");
        memset(buf, 0, sizeof(buf));
        scanf("%s",buf);
        n = write(sockfd,buf,strlen(buf));
        if(n ==-1){
        fprintf(stderr,"Write Error:%s\n",strerror(errno));
        exit(1);
        }
    }
     
    return 0;
}


