/*
    現在の時刻を表示する
*/

#include <time.h>
#include <stdio.h>

/*--- 現在の時刻を表示する ---*/
void put_time(void)
{
  time_t current;
  struct tm *local;

  time(&current);              /* 現在の時刻を取得 */
  local = localtime(&current); /* 地方時の構造体に変換 */
  printf("%02d時%02d分%02d秒", local->tm_hour, local->tm_min, local->tm_sec);
}

int main(void)
{
  printf("現在の時刻は");
  put_time();
  printf("です。\n");

  return (0);
}