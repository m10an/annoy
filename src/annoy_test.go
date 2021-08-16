package annoy

import "testing"
import "fmt"

func TestCreateAndFree(t *testing.T) {
	index := NewAnnoyIndexAngular(3)
	index.Verbose(true)
	index.OnDiskBuild("index.ann")
	v1 := []float32{0, 0, 1}
	v2 := []float32{0, 1, 0}
	v3 := []float32{1, 0, 0}
	index.AddItem(0, v1)
	index.AddItem(1, v2)
	index.AddItem(2, v3)
	index.Build(10)
	index.Save("index.ann", false)
	println(index.GetNItems())
	a, b := index.GetNnsByItem(0, 4, -1)
	fmt.Println(a, b)
	w := []float32{0.77, 0, -1}
	a, b = index.GetNnsByVector(w, 3, -1)
	fmt.Println(a, b)
	a, b = index.GetNnsByVector(w, 2, -1)
	fmt.Println(a, b)
	fmt.Println(index.GetItem(0))
	fmt.Println(index.GetItem(1))
	fmt.Println(index.GetItem(2))
	DeleteAnnoyIndex(index)
}
