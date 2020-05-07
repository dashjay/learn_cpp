.PHONY: voc

all: voc

voc:
	g++ -o vocabulary vocabulary.cpp;
	./vocabulary


