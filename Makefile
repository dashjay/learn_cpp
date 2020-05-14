.PHONY: voc cpp17

all: voc cpp17

voc:
	clang++ -Wc++11-extensions -o vocabulary vocabulary.cpp;
	./vocabulary

cpp17:
	clang++ -std=c++17 -o ./build/cpp17test cpp17test.cpp
	./build/cpp17test
