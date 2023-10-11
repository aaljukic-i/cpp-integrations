package main

/*
#cgo CFLAGS: -Wall -I${SRCDIR}/../pqxdh-sdk/
#cgo LDFLAGS: -L${SRCDIR}/../pqxdh-sdk/ -lencryption
#include <stdlib.h>
char* encrypt(const char* data, int shift);
*/
import "C"
import (
	"fmt"
)

func main() {
	message := C.CString("Hello World")
	shift := C.int(3)

	encryptedMessage := C.encrypt(message, shift)
	fmt.Println(C.GoString(message), "=>", C.GoString(encryptedMessage))
}
