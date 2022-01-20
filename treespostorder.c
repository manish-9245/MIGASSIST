#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void insert(int d)
{
    struct node *temp;
    temp=root;
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    if(root==NULL)
    {
        root=new;
    }
    else
    {
        while(1)
        {
            if(d<(temp->data))
            {
                if(temp->left!=NULL)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left=new;
                    break;
                }
            }
            else
            {
                if(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=new;
                    break;
                }
            }
            
        }
    }
    
}
void postorder(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->data);
    }
}
int main()
{
    int d;
    do{
      
        scanf("%d",&d);
        if(d>0)
        {
            insert(d);
        }
    }while(d>0);
 
    printf("Post order Traversal:\n");
    postorder(root);
    return 0;
}
