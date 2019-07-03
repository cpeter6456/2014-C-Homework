
#include <stdio.h>
#include <stdlib.h>

#define Size 50
struct nodeDLL{
    int coefficient,power;
    struct nodeDLL *next;
    struct nodeDLL *pre;

};
typedef nodeDLL* nodeDLLptr;

void push(nodeDLLptr* Dptr, int coefficient,int power);
void find_zero_del(nodeDLLptr* Dptr);
int add(nodeDLLptr* Pptr,nodeDLLptr* Qptr,nodeDLLptr* ADD);
int mul(nodeDLLptr* Pptr,nodeDLLptr* Qptr,nodeDLLptr* MUL);
int delall(nodeDLLptr* Dptr);
void show(nodeDLLptr* Sptr);
int main(void){

    int time=0,end_flag=0;
    printf("GOOOOOOOOOOOOOOO");

        while(1){
            time++;
            int P,Q,i,coefficient,power;
            nodeDLLptr PDLL=NULL,QDLL=NULL,ADD=NULL,MUL=NULL;

            printf("case %d\n",time);
            scanf("%d",&P);
            printf("output P = %d\n",P);
            for(i=0;i<P;i++){
                scanf("%d",&coefficient);
                scanf("%d",&power);
                push(&PDLL,coefficient,power);

                printf("output %d %d\n",coefficient,power);
            }
            show(&PDLL);
            scanf("%d",&Q);
            printf("output Q = %d\n",Q);
            for(i=0;i<Q;i++){
                scanf("%d",&coefficient);
                scanf("%d",&power);
                push(&QDLL,coefficient,power);

                printf("output %d %d\n",coefficient,power);
            }
            show(&QDLL);

			//



            delall(&QDLL);
            delall(&PDLL);
            if(P==0 && Q==0)
                break;
        }

    return  0;
}
void find_zero_del(nodeDLLptr* Dptr){
    nodeDLLptr temp2 = (*Dptr);
    while( temp2 != NULL ){
        nodeDLLptr dtemp;

        if(temp2->coefficient == 0){

            if(temp2->pre ==NULL && temp2->next==NULL){                                  //if only one
                free(temp2); (*Dptr)=NULL; temp2=NULL;

            }
            else if(temp2->pre ==NULL ){                                                //if at first
                (*Dptr)=temp2->next;
                dtemp = temp2;
                temp2=temp2->next;
                free(dtemp);
            }
            else if(temp2->next ==NULL){                                               //if at last
                dtemp=temp2;
                temp2=temp2->pre;
                free(dtemp);
            }
            else{
                dtemp=temp2;
                temp2->next->pre=temp2->pre;
                temp2->pre->next=temp2->next;

                temp2=temp2->next;

                free(dtemp);
            }

        }

        if(temp2->next != NULL )
            temp2=temp2->next;

    }

	return ;
}
void push(nodeDLLptr* Dptr, int coefficient,int power){                            // BIG Power is first
    nodeDLLptr temp2 = (*Dptr) , temp = (nodeDLLptr)malloc( sizeof(nodeDLL) );  //  temp2 = (*Dptr)  && construct temp
    temp->pre = NULL , temp->next = NULL;

    if( (*Dptr) == NULL ){                                                      //if empty
        temp->coefficient=coefficient;
        temp->power=power;

        (*Dptr)=temp;
		return ;
    }//// end if empty
    else if(temp2->next==NULL){                                                 //if only one node
        if(power > temp2->power ){
            temp2->pre=temp;
            temp->next=temp2;
            (*Dptr)=temp;
        }
        else if(power == temp2->power ){
            temp2->coefficient+=coefficient;
            if(temp2->coefficient==0){
                free(temp2);(*Dptr)=NULL;
            }
            free(temp);
        }
        else if(power < temp2->power ){
            temp2->next=temp;
            temp->pre=temp2;

        }

	return ;

    }////end if only one node
    else{                                                                   // if > one node

        while( temp2 != NULL && temp2->next != NULL && power <= temp2->next->power )
            temp2 = temp2->next;


        if(temp2->next == NULL){                                            // at least
                if(power < temp2->power ){
                    temp2->next=temp;
                    temp->pre=temp2;
                }
                else if(power == temp2->power ){
                    temp2->coefficient+=coefficient;
                    if(temp2->coefficient==0){
                        free(temp2);(*Dptr)=NULL;
                    }
                    free(temp);
                }
        }////end at least
        else if(temp2->pre == NULL){                                        // at first
            if(power == temp2->power ){
                    temp2->coefficient+=coefficient;
                    free(temp);
            }
            else if(power < temp2->power ){
                temp->next=temp2->next;
                temp2->next->pre=temp;
                temp->pre=temp2;
                temp2->next=temp;

            }
            else if(power > temp2->power ){
                temp2->pre=temp;
                temp->next=temp2;
                (*Dptr) = temp;

            }


        }
        else if(temp2->power == power){                         //at mid
            temp2->coefficient+= coefficient;
            if(temp2->coefficient == 0)
            find_zero_del(Dptr);
        }

    }
	return ;

}
int add(nodeDLLptr* Pptr,nodeDLLptr* Qptr,nodeDLLptr* ADD){			//P is added , q is add
	if( (*Pptr) == NULL){

	(*ADD)=(*Qptr);
	return 0;
	}

	if( (*Qptr) == NULL){

	(*ADD)=(*Pptr);
    return 0;
    }

    return 0;
}
int mul(nodeDLLptr* Pptr,nodeDLLptr* Qptr,nodeDLLptr* MUL){
return 0;
}
int delall(nodeDLLptr* Dptr){
	if( (*Dptr) == NULL )return 0;
	do{

        nodeDLLptr temp = (*Dptr);
        free(temp);
        (*Dptr)=(*Dptr)->next;

	}while((*Dptr) != NULL);

return 0;
}
void show(nodeDLLptr* Sptr){

    nodeDLLptr temp = (*Sptr);
    if(temp == NULL){
    printf("Result:NULL 0 0\n");
    return ;
    }
    else{
        printf("Result:");
        do{

        printf("coefficient %3d ",temp->coefficient);
        printf("power %3d\n",temp->power);
        temp=temp->next;
        }while( temp != NULL);



    }
    return;

}
