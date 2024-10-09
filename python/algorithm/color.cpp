// #include <stdio.h>
#include<iostream>
using namespace std;
int total=0;
int color[8];
int data0[8][8]={{0,0,0,0,0,0,0,0},{0,0,1,0,0,1,0,1},{0,1,0,0,1,0,1,0},{0,0,0,0,0,0,1,1},{0,0,1,0,0,0,1,1},{0,1,0,0,0,0,0,1},{0,0,1,1,1,0,0,0},{0,1,0,1,1,1,0,0}};
int colorsame(int s)
{
    int i,flag;
    flag=0;
    for(i=1;i<=s-1;i++)
        if(data0[i][s] == 1 && color[i] == color[s])
            flag=1;
    return flag;
}

void output()
{
    int i;
    for(i=1;i<=7;i++)
        printf("%d",color[i]);
    printf("\n");
    total++;
}

void trypaint(int s)
{
    int i;
    if (s > 7)
    {
        output(); // 输出可行解
    }
    else
    {	// 搜索尝试不同的着色
        for (i = 1; i <= 4; i++)
        {
            color[s] = i;
            if (!colorsame(s))
            {
                trypaint(s + 1);
            }
            color[s] = 0;
        }
    }
}

int main()
{
    int i;
    for(i=0;i<=7;i++)
        color[i]=0;
    total=0;
    trypaint(1);
    printf("Total=%d\n",total);
	return 0;
}