package annoy

// #include "annoygomodule.h"
import "C"
import "unsafe"

type Index struct {
	self      unsafe.Pointer
	nFeatures int
}

func NewAnnoyIndexAngular(f int) Index {
	return Index{C.create_annidx_angular(C.int(f)), f}
}

func (i *Index) AddItem(item int, w []float32) {
	C.add_item(i.self, C.int(item), (*C.float)(&w[0]))
}

func (i *Index) GetNItems() int {
	return int(C.get_n_items(i.self))
}

func (i *Index) Build(nTrees int) {
	C.build(i.self, C.int(nTrees))
}

func (i *Index) GetNnsByItem(item int, n int, kSearch int) ([]int32, []float32) {
	result := make([]int32, n)
	distances := make([]float32, n)
	found := C.get_nns_by_item(i.self,
		C.int(item),
		C.int(n),
		C.int(kSearch),
		(*C.int)(&result[0]),
		(*C.float)(&distances[0]))
	return result[:found], distances[:found]
}

func (i *Index) GetNnsByVector(w []float32, n int, kSearch int) ([]int32, []float32) {
	result := make([]int32, n)
	distances := make([]float32, n)
	found := C.get_nns_by_vector(i.self,
		(*C.float)(&w[0]),
		C.int(n),
		C.int(kSearch),
		(*C.int)(&result[0]),
		(*C.float)(&distances[0]))
	return result[:found], distances[:found]
}

func (i *Index) GetItem(item int) []float32 {
	vector := make([]float32, i.nFeatures)
	C.get_item(i.self, C.int(item), (*C.float)(&vector[0]))
	return vector
}
