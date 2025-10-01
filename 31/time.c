#include <stdio.h>
#include <string.h>
int main(){
    char month[101], weekday[101];
    int day, year, hour, minute, second;
    scanf("%s %d %d %s %d %d %d",&month, &day, &year, &weekday, &hour, &minute, &second);
    printf("%.3s %.3s %02d %02d:%02d:%02d %04d\n",weekday,month,day,hour,minute,second,year);
    return 0;
}