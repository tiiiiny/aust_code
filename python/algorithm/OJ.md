
```cpp
#include <iostream>
 
using namespace std;
 
int amount,Board[100][100];
 
void Cover(int tr,int tc,int dr,int dc,int size)
{
    int s,t;
    if(size<2)
        return ;
    amount++;
    t=amount;
    s=size/2;
    if(dr<tr+s&&dc<tc+s)//残缺在左上角
    {
        //覆盖中间位置
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s-1]=t;
        Board[tr+s][tc+s]=t;
 
        Cover(tr,tc,dr,dc,s);//覆盖左上
        Cover(tr,tc+s,tr+s-1,tc+s,s);//覆盖右上
        Cover(tr+s,tc,tr+s,tc+s-1,s);//覆盖左下
        Cover(tr+s,tc+s,tr+s,tc+s,s);//覆盖右下
    }
    else if(dr<tr+s&&dc>=tc+s)//残缺在右上角
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s][tc+s-1]=t;
        Board[tr+s][tc+s]=t;
 
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,dr,dc,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else if(dr>=tr+s&&dc<tc+s)//残缺在左下
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s]=t;
 
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,dr,dc,s);
        Cover(tr+s,tc+s,tr+s,tc+s,s);
    }
    else
    {
        Board[tr+s-1][tc+s-1]=t;
        Board[tr+s-1][tc+s]=t;
        Board[tr+s][tc+s-1]=t;
 
        Cover(tr,tc,tr+s-1,tc+s-1,s);
        Cover(tr,tc+s,tr+s-1,tc+s,s);
        Cover(tr+s,tc,tr+s,tc+s-1,s);
        Cover(tr+s,tc+s,dr,dc,s);
    }
}
 
void Print(int s)
{
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=s;j++)
            printf("%5d",Board[i][j]);
        printf("\n");
    }
}
 
int main()
{
    int s=1,k,x,y;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        s*=2;
    scanf("%d %d",&x,&y);
    Board[x][y]=0;
    Cover(1,1,x,y,s);
    Print(s);
    return 0;
}
```

```cpp
// 循环赛日程表
#include<iostream>
#include<cmath>
using namespace std;

void schedule(int k, int n, int** array);

int main()
{
    int k;
    cin >> k;
    int n = pow(2, k);
    int** array = new int* [n+1];
    for (int i = 0;i < n+1;i++) 
        array[i] = new int[n+1];
    schedule(k, n, array);
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            printf("%3d",array[i][j]);
        cout << "\n";
    }
    for (int i = 0;i < n + 1;i++)
        delete[] array[i];
    delete[] array;
    return 0;
}

void schedule(int k, int n, int** array)
{
    for (int i = 1;i <= n;i++)
        array[1][i] = i;
    int m = 1;
    for (int s = 1;s <= k;s++)
    {
        n = n / 2;
        for (int t = 1;t <= n;t++)
        {
            for (int i = m + 1;i <= 2 * m;i++)
            {
                for (int j = m + 1;j <= 2 * m;j++)
                {
                    array[i][j + (t - 1) * m * 2] = array[i - m][j + (t - 1) * m * 2 - m];
                    array[i][j + (t - 1) * m * 2 - m] = array[i - m][j + (t - 1) * m * 2];
                }
            }
        }
        m *= 2;
    }
}
```
