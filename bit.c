#include <stdio.h>
#include <stdlib.h>
#define Item int 

struct bit_node {
    Item k;
    struct bit_node *l, *r; 
};

typedef struct bit_node *Bit_node; 

Bit_node bit_new(Item k);
void print_bitnode(Bit_node node);
void bit_preorder(Bit_node root);
void bit_inorder(Bit_node root);
void bit_postorder(Bit_node root);
void bit_printsumarray(Bit_node root, int spaces);
Bit_node bit_arr2tree(Item *a, int size, int i); 

int main (void) {
int a[9] = {69,89,28,39,66,44,12,2,71}; 
Bit_node r = bit_arr2tree(a,9,0); 
bit_printsumarray(r,0);
}

Bit_node bit_new(Item k) {
    Bit_node new = malloc(sizeof(struct bit_node)); 
    new -> k = k; 
    new -> l = NULL; 
    new -> r = NULL; 
    return new; 
}

void print_bitnode(Bit_node node) {
    printf("%d\n", node -> k); 
}

void bit_preorder(Bit_node root) {
    if (root) {
        print_bitnode(root);
        bit_preorder(root -> l); 
        bit_preorder(root -> r);
    }
}

void bit_inorder(Bit_node root) {
    if (root) {
        bit_inorder(root -> l); 
        print_bitnode(root);
        bit_inorder(root -> r);
    }
}

void bit_postorder(Bit_node root) {
     if (root) {
        bit_postorder(root -> l); 
        bit_postorder(root -> r);
        print_bitnode(root);
    }
}

void bit_printsumarray(Bit_node root, int spaces) {
    int i;  

    if (root) {
        for(i = 0; i< spaces; i++) 
        printf(" "); 
    printf("*"); 
    print_bitnode(root); 

    bit_printsumarray(root -> l, spaces+1); 
    
    bit_printsumarray(root -> r, spaces+1);
    } else {
        for(i = 0; i< spaces; i++) 
        printf(" "); 
        printf("*\n"); 
    }

}

Bit_node bit_arr2tree(Item *a, int size, int i) {
    Bit_node root;
    root = bit_new(a[i]);

    if (i< size/2) {
        root -> l = bit_arr2tree(a,size,2*i +1); 
        root -> r = bit_arr2tree(a,size,2*i +2); 
    }

    return root; 
} 