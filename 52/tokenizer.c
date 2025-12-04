#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
char ans[20001];
int t=0;
void ce(){
    printf("Compile Error\n");
    exit(0);
}
void add(char *a){
    int len=strlen(a);
    for(int i=0;i<len;i++){
        ans[t]=a[i];
        t++;
    }
}
void process(char a[]){
    int len=strlen(a);
    if(len==0) return;
    const char *reserved[16] = { "const", "int", "float", "double", "long", "static", "void", "char", "extern", "return", "break", "enum", "struct", "typedef", "union", "goto" };
    for(int i=0;i<16;i++) if(strcmp(reserved[i],a)==0){
        add("reserved ");
        return;
    }
    if((len==1&&(a[0]=='+'||a[0]=='-'||a[0]=='*'||a[0]=='/'||a[0]=='='||a[0]=='>'||a[0]=='<'))||(len==2&&((a[0]=='='&&a[1]=='=')||(a[0]=='!'&&a[1]=='=')||(a[0]=='>'&&a[1]=='=')||(a[0]=='<'&&a[1]=='=')))){
        add("operator ");
        return;
    }
    if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||(a[0]=='_')){
        for(int i=1;i<len;i++) if(!((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]=='_')||(a[i]<='9'&&a[i]>='0'))) ce();
        add("variable ");
        return;
    }
    int numpoint=0;
    for(int i=0;i<len;i++){
        if(a[i]=='.') numpoint++;
        if((a[i]<'0'||a[i]>'9')&&a[i]!='.') ce();
    }
    if(numpoint==0){
        add("integer ");
        return;
    }
    if(numpoint==1&&len>1){
        add("float ");
        return;
    }
    ce();
}
int main(){
    char *a=malloc(20001);
    char *s=a;
    while (scanf("%s", s) != EOF) { 
        for (char *pos = strchr(s, ';'); pos; s = pos + 1, pos = strchr(s, ';')) { 
            *pos = 0; 
            process(s); 
            if(t>0&&ans[t-1]==' ')ans[t-1]='\n';
            else add("\n");
        }
        process(s);
    }
    if(strlen(s)!=0) ce();
    puts(ans);
    free(a);
    return 0;
}