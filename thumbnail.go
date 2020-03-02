package thumbnail

// #cgo pkg-config: Qt5Core Qt5Gui
// #include <stdlib.h>
// int thumbnail(const char* input, const char* output, int width, int height);
import "C"
import (
	"errors"
	"unsafe"
)

func Generate(infile, outfile string, width, height int) error {
	instr, outstr := C.CString(infile), C.CString(outfile)
	defer C.free(unsafe.Pointer(instr))
	defer C.free(unsafe.Pointer(outstr))
	re := C.thumbnail(instr, outstr, 200, 200)
	if re >= 0 {
		return nil
	} else {
		return errors.New("failed")
	}
}
