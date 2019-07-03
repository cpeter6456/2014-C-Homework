#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Set{                                      //集合class
    private:
        char ch;                                //讀字串用
        int ARR[257];                           //對應的256個字元,有就1,沒就0
    public:
        void sc_string();
        void pr_string();
        void initial(){                         //使ARR初始值為{0}
             for(int i=0;i<257;i++)
                ARR[i]=0;
        };

        Set operator+(Set T);
        Set operator*(Set T);
        Set operator-(Set T);
        int operator>=(Set T);
        int in(char);
};

void Set::sc_string(){                          // 接收字串,再讓自元轉換成asc瑪

    initial();

                                                // 接收除了 \n 以外的所有字元
    scanf("%c",&ch);
    while( ch!='\n' ){
        if( (int)ch <0)            //轉換後範圍為 -128~-1
            ARR[ (int)ch+256 ]=1;      //char  範圍 0 ~ 127  -128 ~ -1   轉換後存到對應的ARR裡,有就1,沒就0
        else
            ARR[ (int)ch ]=1;        //轉換後存到對應的ARR裡,有就1,沒就0

        scanf("%c",&ch);
    }

}
void Set::pr_string(){
    for(int i=0;i<256;i++){
        if( ( ARR[i]!=0 && i>=128  )    )        //轉換後範圍為 -128~-1
            printf("%c",i-256);
        else if(ARR[i]!=0 )printf("%c",i);             //asc轉自元 輸出

    }
}
Set Set::operator+(Set T){                      //重載+
        Set temp;
        temp.initial();
        for(int i=0;i<256;i++)
            temp.ARR[i] =T.ARR[i]+ARR[i];       //兩個 0 or 1 的陣列相加 x1 or x2(P1-28
        return temp;                            //回傳物件

}
Set Set::operator*(Set T){
        Set temp;
        temp.initial();
        for(int i=0;i<256;i++)
            if(T.ARR[i]==1 && ARR[i]==1 )temp.ARR[i]=1; // x1 and  x2  (P1-28
        return temp;                                    //回傳物件
}
Set Set::operator-(Set T){                              // x1 and  (NOT x2)  (P1-28
    Set temp;
    temp.initial();
    for(int i=0;i<256;i++)
        if(ARR[i]==1 && T.ARR[i]==0 )temp.ARR[i]=1;
    return temp;                                        //回傳物件
}
int Set::operator>=(Set T){                             //判斷是否 x1 >= x2
    for(int i=0;i<256;i++)
        if(ARR[i]==0 && T.ARR[i]==1 )return 0;          //若有 x2 > x1 回傳 0

    return 1;                                           //判斷整串皆 x1 >= x2 回傳1
}
int Set::in(char x){                                     //char轉asc(int
    if( (int)x < 0    ){                               //轉換後範圍為 -128~-1
          if( ARR[ (int)x + 256 ] == 1 )
                return 1;
    }
    else if( (int)x >= 0 && ARR[ (int)x ]==1 )                           //判斷是否對應的位子有值 有->回傳1
            return 1;

        return 0;
}
