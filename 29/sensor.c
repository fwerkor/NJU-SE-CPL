#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    
    char name[101];
    int pre;
    double frac;
    double factor;
    char unit;
    
    scanf("%s %d %lf %lf %c", name, &pre, &frac, &factor, &unit);
    double value = pre + frac;
    
    if(strlen(name)>=2){
        printf("%c%c: %d (%.5lf) | %.5lE %.5lf %c\n", name[0], name[1], pre, frac, value, value * factor, unit - 32);
    }else{
        printf("%c: %d (%.5lf) | %.5lE %.5lf %c\n", name[0], pre, frac, value, value * factor, unit - 32);
    }
    
    
    return 0;
}