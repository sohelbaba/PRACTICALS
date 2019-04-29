#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}

void preorder(struct node* r)
{
    printf("%d\t",r->value);
    preorder(r->left);
    preorder(r->right);
}

//read data from file
void read_from_file()
{
    FILE *in_file;
    int n;

    in_file = fopen("BSTtree.txt","r");

    if(in_file == NULL)
    {
        printf("error101\n");
    }
    while(fscanf(in_file,"%d",&n) != EOF)
    {
		root=insert(root,n);
    }
    fclose(in_file);
}


int main()
{
	read_from_file();
	preorder(root);
}

