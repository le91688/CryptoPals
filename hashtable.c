

// linked lists
typedef struct _list_t_{
    char *string;
    struct_list_t_ *next;
} list_t;

// hash table struct

typedef struct _hash_table_t_ {
    int size;  //size of the table
    list_t **table; //table elements
} hash_table_t;