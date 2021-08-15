package annoy

// #include "annoygomodule.h"
import "C"
import "unsafe"

type Index struct {
	pointer unsafe.Pointer
}

func NewAnnoyIndexAngular(f int) Index {
	return Index{C.create_annidx_angular(C.int(f))}
}

//func (idx *Index) AddItem(i int, item []float32) {
//	C.add_item(idx.pointer, i, item)
//}

func CreateAndFree() {
	ptr := C.create_annidx_angular(10)
	C.free_annidx(ptr)
}
