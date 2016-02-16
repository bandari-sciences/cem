#ifndef BS_DS_COMMON_UTILS_H 
#define BS_DS_COMMON_UTILS_H 


typedef int (*void_data_compare)(void *data1, void *data2, void *param);

typedef void (*print_data)(void * data, void * param);

typedef char * (*get_key)(void *data, void *param);

typedef int (*delete_node)(void *node);







#endif

