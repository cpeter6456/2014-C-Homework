#include<stdio.h>
#include<stdlib.h>

/**
Author：雷皓博 (B013040033)
Date：2013/10/26
Purpose：習題 9 給予一串數字，找出所有出現次數為奇數之數字 (tree searching之應用)


**/
struct node{
    int data;
    node *left;
    node *right;
    node *father;
};
node *get_node(int in_data);
void input_data_to_tree( int in_data ,node **root,node* father);
void delet_bin_tree( node **root , int in_data );
node* while_find_most_left(node *root);
void rec_inder_printf_tree(node* root);/** 助教要求的輸出格式**/
void rec_inder_printf_tree_left(node* root);/** 助教要求的輸出格式**/
void rec_inder_printf_tree_right(node* root);/** 助教要求的輸出格式**/
void del_all(node *);
int main(){


    node *top=NULL;
    int data=0;
    do{
        scanf("%d",&data);
        if(data==-1)
        break;

        input_data_to_tree(data,&top,NULL);
        //printf("\n%8x\n",top);
        printf("\nnode :");
        rec_inder_printf_tree(top);
        printf("\nleft :");
        rec_inder_printf_tree_left(top);
        printf("\nright:");
        rec_inder_printf_tree_right(top);
    }while(1);
        printf("\nans  :");
        rec_inder_printf_tree(top);
		del_all(top);
    return 0;
}
node *get_node(int in_data){
    node * temp = (node*)malloc(sizeof(node));
    temp->data=in_data;
    temp->right=NULL ;
    temp->left=NULL ;
    temp->father=NULL;
    return temp;

}
void input_data_to_tree( int in_data ,node **root,node* father){
    if((*root) == NULL){

        (*root) = get_node(in_data);
        if((*root)==NULL)printf("not");
        (*root)->father=father;
        return;
    }
    if( (*root)->data == in_data ){
        //printf("find equal\n");
        delet_bin_tree( root , in_data);
        return;
    }
    if( (*root)->data > in_data ){
        input_data_to_tree(in_data,&((*root)->left),(*root));

    }

    if( (*root)->data < in_data ){
        input_data_to_tree(in_data,&((*root)->right),(*root));

    }

    return;
}
void delet_bin_tree( node **root , int in_data ){
    /** no son star**/
    if( (*root)->left==NULL && (*root)->right==NULL ){
            node *temp=(*root);
        //printf("%8x",temp);
        free(temp);(*root)=NULL; return;

    }
    /** no son end**/

    /** has only one subtree star**/

        if((*root)->left==NULL && (*root)->right!=NULL){

            if((*root)->father==NULL){
                node* temp=(*root);
                (*root)=(*root)->right;
                (*root)->father=NULL;
                free(temp);
                return;
            }
            if((*root)->father->right!=NULL&&(*root)->father->right->data==in_data){
                 node * temp=(*root),*father=(*root)->father;/** Because root will changed , so store father at first **/
                (*root)->father->right=(*root)->right;/** IN this line root will change to root->right**/
                (*root)->father=father;/** Because root will changed   **/
                 free(temp); /** don't use free((*root))  **/
                return;
            }
            else{
                    node *temp=(*root),*father=(*root)->father;

                //printf("%8x\n",(*root));
                (*root)->father->left=(*root)->right;

               // printf("%8x",(*root));
                (*root)->father=father;

                free(temp);


                 return;
            }
        }
        if((*root)->left!=NULL && (*root)->right==NULL){
            if((*root)->father==NULL){
                node* temp=(*root);
                (*root)=(*root)->left;
                (*root)->father=NULL;
                free(temp);
                return;
            }
            if((*root)->father->right!=NULL&&(*root)->father->right->data==in_data){
                node * temp=(*root),*father=(*root)->father;
                (*root)->father->right=(*root)->left;
                (*root)->father=father;
                free(temp);
                return;
            }
            else{
                    node *temp=(*root),*father=(*root)->father;
                (*root)->father->left=(*root)->left;
                (*root)->father=father;
               free(temp);return;

            }
        }

    /** has only one subtree end**/


    /** has two subtrees star **/
    if((*root)->left!=NULL && (*root)->right!=NULL){
        node *temp=while_find_most_left((*root)->right);
        //printf("i find %d",temp->data);
        //if((*root)->father == NULL)

        (*root)->data=temp->data;
        //printf("two root %d %8x %8x\n",(*root)->data,*root,(*root)->father);

        input_data_to_tree(temp->data,&((*root)->right),(*root));
        //printf("\nWWWWWWWWWWWtwo root %d %8x %8x\n",(*root)->data,*root,(*root)->father);

    return;
    }
    /** has two subtrees end **/

    return;
}
node* while_find_most_left(node *root){
    while( root -> left != NULL ){
        root=root->left;

    }
    return root;
}
void rec_inder_printf_tree(node* root){/** 助教要求的輸出格式**/
    //printf("qwe");
    if(root == NULL)
        return;

    rec_inder_printf_tree(root->left);
    printf("%3d",root->data);

    rec_inder_printf_tree(root->right);
    return;
}

void rec_inder_printf_tree_left(node* root){/** 助教要求的輸出格式**/
    //printf("qwe");
    if(root == NULL)
        return;

    rec_inder_printf_tree_left(root->left);

    if(root->left!=NULL)
        printf("%3d",root->left->data);
    else
        printf(" -1");

    rec_inder_printf_tree_left(root->right);
    return;
}

void rec_inder_printf_tree_right(node* root){/** 助教要求的輸出格式**/
    //printf("qwe");
    if(root == NULL)
        return;

    rec_inder_printf_tree_right(root->left);


    if(root->right!=NULL)
        printf("%3d",root->right->data);
    else
        printf(" -1");

    rec_inder_printf_tree_right(root->right);
    return;
}

void del_all(node * root){

if(root == NULL)
        return;

    del_all(root->left);

    del_all(root->right);
	free(root);
    return;

}
