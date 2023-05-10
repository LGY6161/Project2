#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int file1_mon, file1_day, file1_hour, file1_min;
int file2_mon, file2_day, file2_hour, file2_min;

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


// 파일1의 시간 정보를 가져오는 함수
void filetime1()
{
    printf("Get text1 file time\n");
    time1 = localtime(&stat1.st_mtime);
    file1_mon = time1->tm_mon+1;
    file1_day = time1->tm_mday;
    file1_hour = time1->tm_hour;
    file1_min = time1->tm_min;
    printf("text1 수정시간 : %d월 %d일 %d시 %d분 \n",file1_mon, file1_day, file1_hour, file1_min);

}

// 파일2의 시간 정보를 가져오는 함수
void filetime2()
{
    printf("Get text2 file time\n");
    time2 = localtime(&stat2.st_mtime);
    file2_mon = time2->tm_mon+1;
    file2_day = time2->tm_mday;
    file2_hour = time2->tm_hour;
    file2_min = time2->tm_min;
    printf("text2 수정시간 : %d월 %d일 %d시 %d분 \n",file2_mon, file2_day, file2_hour, file2_min);
}

// 두 파일의 블록 사이즈를 비교하는 함수
void blockcmp()
{
    int blk_size1 = (int)stat1.st_blocks; // stat1의 블록사이즈 저장
    int blk_size2 = (int)stat2.st_blocks; // stat2의 블록사이즈 저장

    if(blk_size1 > blk_size2) //text1의 block size가 큰 경우
    {
        prinf("text1 block size is bigger\n")
    }
    else if(blk_size1 < blk_size2) //text2의 block size가 큰 경우
    {
        prinf("text2 block size is bigger\n")
    }
    else //block size가 같은 경우
    {
        prinf("block size equal\n")
    }
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

