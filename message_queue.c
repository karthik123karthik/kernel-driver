// MESSAGE QUEUE is used for IPC.
// unlike pipes and fifo we will not use it for stream oriented communication 
// we use it for message oriented communication

/* SEND FUNCTION */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

int main(int argc, char** argv){

    mqd_t mq;
    struct mq_attr attr;
    size_t len;

    mq = mq_open("/myqueue", O_CREAT | O_RDWR, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(1);
    }

    if(mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr");
        exit(1);
    }

    printf("ATTRIBUTE DETAILS are msg_size: %ld, max_msg: %ld, cur_msg: %ld\n",
           attr.mq_msgsize, attr.mq_maxmsg, attr.mq_curmsgs);

    len = strlen(argv[1]);
    if(mq_send(mq, argv[1], len, 0) == -1){
        perror("SEND FAILED");
        exit(1);
    }

    return 0;
}

/* RECIEVE FUNCTION */

#include <stdio.h>
#include <unistd.h>
#include <mqueue.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    mqd_t mq;
    size_t len;
    struct mq_attr attr;
    ssize_t bytes_received;
    char *buf;

    mq = mq_open("/myqueue", O_RDONLY);
    if (mq == (mqd_t)-1)
    {
        perror("mq_open");
        exit(1);
    }

    if (mq_getattr(mq, &attr) == -1)
    {
        perror("mq_getattr");
        exit(1);
    }

    len = attr.mq_msgsize;
    buf = malloc(len);
    if (buf == NULL)
    {
        perror("malloc");
        exit(1);
    }

    bytes_received = mq_receive(mq, buf, len, NULL);
    if (bytes_received == -1)
    {
        perror("mq_receive");
        exit(1);
    }

    printf("Received message: %s\n, len:%u", buf, len);

    mq_close(mq);
    return 0;
}
