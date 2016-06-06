#include<stdio.h>
#include<stdlib.h>
#define max 1000
struct tree{
    int info;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree node;
void push_stack(node *item);
node *pop_stack();
int stack_empty();

void inorder(node *ptr);
void postorder(node *ptr);
void preorder(node *ptr);
void nrec_inorder(node *root);
void nrec_postorder(node *root);
void nrec_preorder(node *root);
node *insert(node *root, int k);
node *insert_rec(node *root, int k);
node *del_rec(node *ptr, int key);
int height(node *root);

node *stack[max];
int top = -1;
void push_stack(node *item){
    if(top == max-1){
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}
node *pop_stack(){
    node *item;
    if(top == -1){
        printf("Stack underflow\n");
        return;
    }
    item = stack[top];
    top = top - 1;
    return item;
}
int stack_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}
void inorder(node *ptr){
    if(ptr == NULL)
        return;
    inorder(ptr->lchild);
    printf("%d ", ptr->info);
    inorder(ptr->rchild);

}
void nrec_inorder(node *root){
    node *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    push_stack(ptr);
    while(!stack_empty()){
        ptr = pop_stack();
        printf("%d ", ptr->info);
        if(ptr->rchild != NULL)
            push_stack(ptr->rchild);
        if(ptr->lchild != NULL)
            push_stack(ptr->lchild);
    }
    printf("\n");
}

void preorder(node *ptr){
    if(ptr == NULL)
        return;
    printf("%d ", ptr->info);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void nrec_preorder(node *root){
    node *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr->lchild;
        }

        while(ptr->rchild == NULL){
            printf("%d ", ptr->info);
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        printf("%d ", ptr->info);
        ptr = ptr->rchild;
    }
    printf("\n");
}
void postorder(node *ptr){
    if(ptr == NULL)
        return;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->info);
}
void nrec_postorder(node *root){
    node *q, *ptr = root;
    if(ptr == NULL){
        printf("Tree is empty\n");
        return;
    }
    q = root;
    while(1){
        while(ptr->lchild != NULL){
            push_stack(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild == q){
            printf("%d ", ptr->info);
            q = ptr;
            if(stack_empty())
                return;
            ptr = pop_stack();
        }
        push_stack(ptr);
        ptr = ptr->rchild;
    }
    printf("\n");
}
node *insert(node *root, int k){
    node *ptr, *temp, *prnt = NULL;
    ptr = root;
    while(ptr != NULL){
        prnt = ptr;
        if(k < ptr->info)
            ptr = ptr->lchild;
        else if(k > ptr->info)
            ptr = ptr->rchild;
        else{
            printf("Duplicate found\n");
            return root;
        }
    }
    temp = (node *)malloc(sizeof(node));
    temp->info = k;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(prnt == NULL)
        root = temp;
    else if(k < prnt->info)
        prnt->lchild = temp;
    else
        prnt->rchild = temp;
    return root;

}
node *insert_rec(node *ptr, int k){
    if(ptr == NULL){
        ptr = (node *)malloc(sizeof(node));
        ptr->info = k;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if(k < ptr->info)
        ptr->lchild = insert_rec(ptr->lchild, k);
    else if(k > ptr->info)
        ptr->rchild = insert_rec(ptr->rchild, k);
    else
        printf("Duplicate found\n");
    return ptr;
}
node *del_rec(node *ptr, int key){
    node *temp, *succ;
    if(ptr == NULL){
        printf("Key not found\n");
        return ptr;
    }
    if(key < ptr->info)
        ptr->lchild = del_rec(ptr->lchild, key);
    else if(key > ptr->info)
        ptr->rchild = del_rec(ptr->rchild, key);
    else{                                               /// if match
        if(ptr->lchild != NULL && ptr->rchild != NULL){     /// 2 child
            succ = ptr->rchild;
            while(succ->lchild != NULL)
                succ = ptr->lchild;
            ptr->info = succ->info;
            ptr->rchild = del_rec(ptr->rchild, succ->info);
        }
        else{
            temp = ptr;
            if(ptr->lchild != NULL)     /// only left child
                ptr = ptr->lchild;
            else if(ptr->rchild != NULL)        /// only right child
                ptr = ptr->rchild;
            else
                ptr = NULL;
            free(temp);
        }
    }
    return ptr;
}
int height(node *ptr){
    int l_height, r_height;
    if(ptr == NULL)
        return 0;
    l_height = height(ptr->lchild);
    r_height = height(ptr->rchild);
    if(l_height > r_height)
        return 1 + l_height;
    else
        return 1 + r_height;
}
int main(){

    node *root = NULL;
    while(1){
        printf("1.Insert\n");
        printf("2.Inorder\n");
        printf("3.Preorder\n");
        printf("4.Postorder\n");
        printf("5.Deletion\n");
        printf("6.Height\n");
        int val;
        scanf("%d", &val);
        switch(val){
            case 1:{
                printf("Enter the value to insert: ");
                int value;
                scanf("%d", &value);
                root = insert(root, value);
                break;
            }
            case 2:{
                inorder(root);
                printf("\n");
                break;
            }
            case 3:{
                preorder(root);
                printf("\n");
                break;
            }
            case 4:{
                postorder(root);
                printf("\n");
                break;
            }
            case 5:{
                int key;
                printf("Enter the key to delete\n");
                scanf("%d", &key);
                root = del_rec(root, key);
                break;
            }
            case 6:{
                printf("Height of the given tree is %d\n", height(root));
                break;
            }
        }
    }


}
