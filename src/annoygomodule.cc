#include "annoylib.h"
#include "kissrandom.h"

using namespace Annoy;

// Annoy Class
template <class D>
using AnnoyC = AnnoyIndex<int32_t, float, D, Kiss64Random, AnnoyIndexSingleThreadedBuildPolicy>;

// Annoy Interface
using AnnoyI = AnnoyIndexInterface<int32_t, float>;

extern "C" {

  void free_annidx(AnnoyI *ptr) {
    delete ptr;
  }

  void add_item(AnnoyI *ptr, int item, const float *w) {
    ptr->add_item(item, w);
  }

  void build(AnnoyI *ptr, int q) {
    ptr->build(q, 1);
  }

  bool save(AnnoyI *ptr, const char *filename, bool prefault) {
    return ptr->save(filename, prefault);
  }

//  bool save(AnnoyI *ptr, const char *filename) {
//    return ptr->save(filename, true);
//  }

  void unload(AnnoyI *ptr) {
    ptr->unload();
  }

  bool load(AnnoyI *ptr, const char *filename, bool prefault) {
    return ptr->load(filename, prefault);
  }

//  bool load(AnnoyI *ptr, const char *filename) {
//    return ptr->load(filename, true);
//  }

  float get_distance(AnnoyI *ptr, int i, int j) {
    return ptr->get_distance(i, j);
  }

// error: cannot convert ‘int32_t*’ {aka ‘int*’} to ‘std::vector<int, std::allocator<int> >*’
//  void get_nns_by_item(AnnoyI *ptr, int item, int n, int search_k, int32_t *result, float *distances) {
//    ptr->get_nns_by_item(item, n, search_k, result, distances);
//  }
//
//  void get_nns_by_vector(AnnoyI *ptr, const float *w, int n, int search_k, int32_t *result, float *distances) {
//    ptr->get_nns_by_vector(w, n, search_k, result, distances);
//  }

//  void get_nns_by_item(AnnoyI *ptr, int item, int n, int search_k, int32_t *result) {
//    ptr->get_nns_by_item(item, n, search_k, result, NULL);
//  }
//
//  void get_nns_by_vector(AnnoyI *ptr, const float *w, int n, int search_k, int32_t *result) {
//    ptr->get_nns_by_vector(w, n, search_k, result, NULL);
//  }

  int get_n_items(AnnoyI *ptr) {
    return (int)ptr->get_n_items();
  }

  void verbose(AnnoyI *ptr, bool v) {
    ptr->verbose(v);
  }

// expects pointer to vector
//  void get_item(AnnoyI *ptr, int item, float *v) {
//    ptr->get_item(item, v);
//  }

  bool on_disk_build(AnnoyI *ptr, const char *filename) {
    return ptr->on_disk_build(filename);
  }

  AnnoyC<Angular>* create_annidx_angular(int f) {
    return new AnnoyC<Angular>(f);
  }

  AnnoyC<Euclidean>* create_annidx_euclidean(int f) {
    return new AnnoyC<Euclidean>(f);
  }

  AnnoyC<Manhattan>* create_annidx_manhattan(int f) {
    return new AnnoyC<Manhattan>(f);
  }

  AnnoyC<DotProduct>* create_annidx_dot_product(int f) {
    return new AnnoyC<DotProduct>(f);
  }

}
