package main

import (
	"bytes"
	"crypto/aes"
	"crypto/cipher"
	"encoding/base64"
	"fmt"
)

func padding(src []byte, blocksize int) []byte {
	padnum := blocksize - len(src)%blocksize
	pad := bytes.Repeat([]byte{byte(padnum)}, padnum)
	return append(src, pad...)
}

func unpadding(src []byte) []byte {
	n := len(src)
	unpadnum := int(src[n-1])
	return src[:n-unpadnum]
}

func encryptAES(src []byte, key []byte) []byte {
	block, _ := aes.NewCipher(key)
	src = padding(src, block.BlockSize())
	blockmode := cipher.NewCBCEncrypter(block, key)
	blockmode.CryptBlocks(src, src)
	return src
}

func decryptAES(src []byte, key []byte) []byte {
	block, _ := aes.NewCipher(key)
	blockmode := cipher.NewCBCDecrypter(block, key)
	blockmode.CryptBlocks(src, src)
	src = unpadding(src)
	return src
}

func main() {
	data := "9FlnslSSxk6K7bgQdEXat5L2OXIFs3GJ5mHL92AsDFpbThfomZ9TjeMOnVVlvcbtoFBkx0KchXR5juzG+aDy6OPJyVuJFzXZQvVCwSKizsXeLn/gV0CZH6qLHCzGgF5VgKaeCqQxEw4PSMMqqncJTBK1gO8KN8lzCAzGY62rp5f6/JhZJ3x6unE7jDqnMTWirrAe9+QIoyHULsNIVGfOj36OY+NeTqECb+VhxCxZ8z32ii4AoHdH00sBPNqkzC2AK+9V4JXR19APeGLXeKbvfZur6fdjlwMRWkjYIn/YjpEbM1kkupQLHu6r4ZzOAYpi"
	b, err := base64.StdEncoding.DecodeString(data)
	if err != nil {
		panic(err)
	}
	key := []byte("USTCORiX")
	x2 := decryptAES(b, key)
	fmt.Print(string(x2))
}
