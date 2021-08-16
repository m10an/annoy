#ifndef __GO_H__
#define __GO_H__

#include <stdbool.h>
#include <stdint.h>

void free_annidx(void *);
void add_item(void *, int, const float *);
void build(void *, int);
bool save(void *, const char *, bool);
//bool save(void *, const char *);
void unload(void *);
bool load(void *, const char *, bool);
//bool load(void *, const char *);
float get_distance(void *, int, int);
int get_nns_by_item(void *, int, int, int, int32_t *, float *);
int get_nns_by_vector(void *, const float *w, int, int, int32_t *, float *);
int get_n_items(void *);
void verbose(void *, bool);
void get_item(void *, int, float *);
bool on_disk_build(void *, const char *);
void* create_annidx_angular(int);
void* create_annidx_euclidean(int);
void* create_annidx_manhattan(int);
void* create_annidx_dot_product(int);

#endif
