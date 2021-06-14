/**
 * 相传韩信才智过人，从不直接清点自己军队的人数，只要让士兵先后以三人一排、五人一排、七人一排地变换队形，
 * 而他每次只掠一眼队伍的排尾就知道总人数了。输入包含多组数据，每组数据包含3个非负整数a，b，c，表示每种
 * 队形排尾的人数（a＜3，b＜5，c＜ 7），输出总人数的最小值（或报告无解）。已知总人数不小于10，不超过100。
 * 输入到文件结束为止。
 * 样例输入：
 * 2 1 6
 * 2 1 3
 * 样例输出： 
 * Case 1: 41
 * Case 2: No answer
 * 
 * 如何处理多组数据并让程序知道我已经结束了输入？
 */

#include<stdio.h>
int main(){
    int a,b,c;
    int kase = 0;
    while (scanf("%d%d%d",&a,&b,&c) == 3) //这个判断条件是解决多组输入的核心，scanf会返回输入数据的个数。
    {
        for (int n = 10; n <= 100; n++)
        {
            if (n%3==a && n%5==b && n%7==c)
            {
                printf("case %d:%d\n",++kase,n);
                break;
            }else{
                if (n == 100)
                {
                    printf("case %d:No answer\n",++kase,n);
                }
            }
        }
    }
    return 0;
}
