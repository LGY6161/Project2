#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

void filetime1()
{
    time1 = localtime(&stat1.st_mtime);
    printf("text1 수정시간 : %d월 %d일 %d시 %d분 \n",time1->tm_mon+1, time1->tm_mday, time1->tm_hour, time1->tm_min);

}

void filetime2()
{
    time2 = localtime(&stat2.st_mtime);
    printf("text1 수정시간 : %d월 %d일 %d시 %d분 \n",time2->tm_mon+1, time2->tm_mday, time2->tm_hour, time2->tm_min);
}