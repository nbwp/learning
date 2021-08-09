#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <bits/types.h>
using namespace std;

#pragma pack(push, 4)
struct mymesg    
{
    long mytype; //正的整型消息类型
    char mtext[512];//消息数据
};//c++中结构体叫类型
#pragma pack(pop)
int main(int argc ,char *argv[])
{
    key_t key;
    int msq_id;
    mymesg msg;
    
    key = ftok("/tmp",1);
    msq_id = msgget(key, IPC_CREAT|0666);
    while(1)
    {
        

       if( msgrcv(msq_id,(void*)&msg,512,1,0) < 0){
           cout << "recevie error\n";
            exit(1);
       }
       cout << "data:" << msg.mtext << endl;
       if(strncmp(msg.mtext,"quit",4) == 0){
           
           break;
       }
        
    }
    
    
    
    return 0;


}