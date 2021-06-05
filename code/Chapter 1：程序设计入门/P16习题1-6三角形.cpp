//该题要求判定的是直角三角形。利用勾股定理可判定，所以只需要对三条边进行排序，分出直角边和斜边即可.
//当然如果不喜欢这种方法，也可以这样去判断直角三角形是否成立：
//  if (a*a+b*b == c*c || b*b+c*c == a*a || a*a+c*c == b){...}

//在书中的P12页介绍过三整数排序，所以在这里也沿用书中的方法，暂不使用冒泡或者快排。
//实际上，书中的方法也是一种比较排序，应该是为了便于萌新理解，且要排序的数只有三个，就用了 if 去实现。
#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int t; //用来替换的变量，和A，B交换需要C同理。

    //第一步，a和b比较，条件成立则互换
    if(a>b){
        t = a;
        a = b;
        b = t;
    }
    //第二步，a和c比较，条件成立则互换
    if(a>c){
        t = a;
        a = c;
        c = t;
    }
    //第三步，b和c比较，条件成立则互换;这段程序结束后，a,b,c就变成了 a<b<c 这样子。
    if(b>c){
        t = b;
        b = c;
        c = t;
    }
    printf("a=%d b=%d c=%d\n",a,b,c);

    //判断直角三角形是否成立
    if (a*a+b*b == c*c)
    {
        printf("yes");
    }else{
        //判断三角形是否成立
        if (a+b>c && a+c>b && b+c>a )
        {
            printf("no");
        }else{
            printf("not a triangle");
        }
    }
    return 0;
}