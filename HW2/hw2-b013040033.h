#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Set{                                      //���Xclass
    private:
        char ch;                                //Ū�r���
        int ARR[257];                           //������256�Ӧr��,���N1,�S�N0
    public:
        void sc_string();
        void pr_string();
        void initial(){                         //��ARR��l�Ȭ�{0}
             for(int i=0;i<257;i++)
                ARR[i]=0;
        };

        Set operator+(Set T);
        Set operator*(Set T);
        Set operator-(Set T);
        int operator>=(Set T);
        int in(char);
};

void Set::sc_string(){                          // �����r��,�A���ۤ��ഫ��asc��

    initial();

                                                // �������F \n �H�~���Ҧ��r��
    scanf("%c",&ch);
    while( ch!='\n' ){
        if( (int)ch <0)            //�ഫ��d�� -128~-1
            ARR[ (int)ch+256 ]=1;      //char  �d�� 0 ~ 127  -128 ~ -1   �ഫ��s�������ARR��,���N1,�S�N0
        else
            ARR[ (int)ch ]=1;        //�ഫ��s�������ARR��,���N1,�S�N0

        scanf("%c",&ch);
    }

}
void Set::pr_string(){
    for(int i=0;i<256;i++){
        if( ( ARR[i]!=0 && i>=128  )    )        //�ഫ��d�� -128~-1
            printf("%c",i-256);
        else if(ARR[i]!=0 )printf("%c",i);             //asc��ۤ� ��X

    }
}
Set Set::operator+(Set T){                      //����+
        Set temp;
        temp.initial();
        for(int i=0;i<256;i++)
            temp.ARR[i] =T.ARR[i]+ARR[i];       //��� 0 or 1 ���}�C�ۥ[ x1 or x2(P1-28
        return temp;                            //�^�Ǫ���

}
Set Set::operator*(Set T){
        Set temp;
        temp.initial();
        for(int i=0;i<256;i++)
            if(T.ARR[i]==1 && ARR[i]==1 )temp.ARR[i]=1; // x1 and  x2  (P1-28
        return temp;                                    //�^�Ǫ���
}
Set Set::operator-(Set T){                              // x1 and  (NOT x2)  (P1-28
    Set temp;
    temp.initial();
    for(int i=0;i<256;i++)
        if(ARR[i]==1 && T.ARR[i]==0 )temp.ARR[i]=1;
    return temp;                                        //�^�Ǫ���
}
int Set::operator>=(Set T){                             //�P�_�O�_ x1 >= x2
    for(int i=0;i<256;i++)
        if(ARR[i]==0 && T.ARR[i]==1 )return 0;          //�Y�� x2 > x1 �^�� 0

    return 1;                                           //�P�_���� x1 >= x2 �^��1
}
int Set::in(char x){                                     //char��asc(int
    if( (int)x < 0    ){                               //�ഫ��d�� -128~-1
          if( ARR[ (int)x + 256 ] == 1 )
                return 1;
    }
    else if( (int)x >= 0 && ARR[ (int)x ]==1 )                           //�P�_�O�_��������l���� ��->�^��1
            return 1;

        return 0;
}
