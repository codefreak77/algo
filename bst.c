#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *get_node(int k)
{
    struct node *x = NULL;
    x = (struct node *)malloc(sizeof(struct node));
    if (!x) {
        printf("\nMemory allocation error\n");
        goto out;
    }

    x->key = k;
    x->left = NULL;
    x->right = NULL;

out:
    return x;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL) {
        return (get_node(key));
    }

    if (key > node->key) {
        node->right = insert(node->right, key);
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    }

    return node;
}

static struct node *root = NULL;

void inorder_traversal(struct node *x)
{
    if (x == NULL) {
        return;
    }

    inorder_traversal(x->left);
    printf("%d  ", x->key);
    inorder_traversal(x->right);
}


void destroy(struct node *x)
{
    if (x == NULL) {
        return;
    }

    destroy(x->left);
    destroy(x->right);
    printf("%d  ", x->key);
    x->left = NULL;
    x->right = NULL;
    free(x);
}

struct node *min_value(struct node *x)
{
    if (x == NULL) {
        goto out;
    }

    while(x->left != NULL) {
        x = x->left;
    }

out:
    return x;
}

struct node *get_key(struct node *x, int key)
{
    struct node *node = NULL;

    if (x == NULL) {
        goto out;
    }

    if (key < x->key) {
        node = get_key(x->left, key);
    } else if (key > x->key) {
        node = get_key(x->right, key);
    } else if (key == x->key) {
        node = x;
    }

out:
    return node;
}


struct node *delete_node(struct node *x, int key)
{
    struct node *y = NULL;
    struct node *tmp = NULL;

    if (x == NULL) {
        goto out;
    }

    if (key < x->key) {
        x->left = delete_node(x->left, key);
    } else if (key > x->key) {
        x->right = delete_node(x->right, key);
    } else {
        if (x->right == NULL) {
            tmp = x->left;
            if (tmp) {
                printf("\n right is null returning tmp %d", tmp->key);
            } else {
                printf("\n left is null as well");
            }
            free(x);
            return (tmp);
        } else {
            tmp = min_value(x->right);
            printf("\nmin value from x->key %d is = %d\n", x->key, tmp->key);
            x->key = tmp->key;
            x->right = delete_node(x->right, tmp->key);
        }
    }

out:
    return x;
}

main()
{
    struct node *x = NULL, *y = NULL;
    printf("\nDBG: add values\n");
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 3);
    //root = insert(root, 4);
    root = insert(root, 23);
    root = insert(root, 9);
    root = insert(root, 21);
    root = insert(root, 89);
    root = insert(root, 2);

    printf("\nDBG: inorder traversal: ");
    inorder_traversal(root);
  
    x = min_value(root);
    printf("\nmin value from root %d\n", x->key);

    y = get_key(root, 23);
    if (y) {
        printf("\nfound node for 23 %d\n", y->key);
    } else {
        printf("\nNOT found node for 23\n");
    }
    
    x = min_value(y);
    printf("\nmin value from node 23 %d\n", x->key);

    printf("\ndelete node with key 3 root %p\n", root);
    root = delete_node(root, 23);
    printf("\nafter: delete node with key 23 root %p\n", root);
    inorder_traversal(root);

    printf("\nDBG: destroy tree: ");
    destroy(root);
    printf("\n");
}
