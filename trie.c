#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
#define CHAR_OFFSET(c) ((int)c - (int)'a')

struct trie {
    bool is_leaf;
    struct trie *next[ALPHABET_SIZE];
};

struct trie *get_node(void)
{
    struct trie *x = NULL;
    int i = 0;

    x = (struct trie *)malloc(sizeof(struct trie));
    if (!x) {
        return NULL;
    }

    x->is_leaf = false;
    for (i=0; i<ALPHABET_SIZE; i++) {
        x->next[i] = NULL;
    }

    return x;
}

void destroy(struct trie *node)
{
    int i = 0;

    if (node == NULL) {
        return;
    }

    for (i=0; i<ALPHABET_SIZE; i++) {
        destroy(node->next[i]);
    }

    free(node);
    return;
}

bool insert(struct trie *node, const char *key)
{
    int len = strlen(key);
    int i = 0, idx = 0;
    bool status = false;

    for (i=0; i<len; i++) {
        idx = CHAR_OFFSET(key[i]);

        if (node->next[idx] == NULL) {
            node->next[idx] = get_node();
        }
        
        if (node->next[idx] == NULL) {
            goto out;
        }

        node = node->next[idx];

    } /* end of for loop */

    node->is_leaf = true;
    status = true;

out:

    return status;
}

bool search(struct trie *node, const char *key)
{
    int len = strlen(key);
    int i = 0, idx = 0;
    bool status = false;

    for (i=0; i<len; i++) {
        idx = CHAR_OFFSET(key[i]);

        if (node->next[idx] == NULL) {
            printf("\n no match!");
            goto out;
        }

        node = node->next[idx];

    } /* end of for loop */

    if (node->is_leaf) {
        printf("\nPerfect match");
    } else {
        printf("\nPartial match");
    }

    status = true;

out:
    return status;
}

main()
{
    struct trie *root = get_node();
    printf("start: trie\n");

    if (insert(root, "partha")) {
        printf("\ninsert successfull");
    } else {
        printf("\ninsert failed");
    }

    if (insert(root, "is")) {
        printf("\ninsert successfull");
    } else {
        printf("\ninsert failed");
    }

    if (search(root, "partha")) {
        printf("\nPartha is in the list");
    } else {
        printf("\nPartha is NOT in the list");
    }
    
    if (search(root, "par")) {
        printf("\npar is in the list");
    } else {
        printf("\npar is NOT in the list");
    }

    printf("\n");

    if (search(root, "calcutta")) {
        printf("\ncalcutta is in the list");
    } else {
        printf("\ncalcutta is NOT in the list");
    }

    destroy(root);
    printf("\nend: trie\n");
}
