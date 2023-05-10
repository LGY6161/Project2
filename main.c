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

void filestat1()
{
    // stat1에 text1의 파일 정보를 저장
    if(stat("text1", &stat1) == 0)
    {
        printf("text1의 파일정보를 가져옵니다. \n");
    }
    else
    {
        printf("text1의 파일정보를 가져오는데 실패합니다. \n");
    }
}

void filestat2()
{
    // stat2에 text2의 파일 정보를 저장
    if(stat("text2", &stat2) == 0)
    {
        printf("text2의 파일정보를 가져옵니다. \n");
    }
    else
    {
        printf("text2의 파일정보를 가져오는데 실패합니다. \n");
    }
}

void sizecmp()
{
    int size1, size2;

    // size값을 가져옴
    size1 = stat1.st_size;
    size2 = stat2.st_size;

    printf("size compare\n");
    // size 비교
    if(size1 > size2)
        printf("text1 is bigger\n");
    else if(size1 < size2)
        printf("text2 is bigger\n");
    else
        printf("sizes are equal\n"); 
}