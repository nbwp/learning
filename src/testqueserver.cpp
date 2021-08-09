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
int main()
{
    
    //struct msqid_ds *ms;
    int msqid;
    key_t key1;
    mymesg msg1;
    
    memset(&msg1, 0, sizeof(msg1));
    //ms = (struct msqid_ds *)malloc(sizeof(struct msqid_ds));
    //memset(ms,0,sizeof(struct msqid_ds));
    //cout << sizeof(struct msqid_ds);
    key1 = ftok("/tmp",1);
    if ((msqid = msgget(key1, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        exit(1);
    }
    while (1)
    {
        char buf[512];
        memset(buf, 0, 512);
        msg1.mytype = 1;
        cout << "input message:";
        cin.get(buf, '\n');
        strcpy(msg1.mtext,buf);
        if(msgsnd(msqid, (void *)&msg1, 512, 0) < 0){
            cout << "send msg errro" << endl; 
            exit(1);
        };
        if(strncmp(buf, "quit", 4) == 0){
            cout << "program exit" << endl;
            break;
        }    
    }
    if(msgctl(msqid, IPC_RMID ,NULL) < 0){
        cout << "del msgq error\n";
        exit(1);
    } 
    return 0;
}