run: build
	./bin/main
	rm -rf ./bin

build:
	mkdir bin | clang++ ./src/main.cpp ./src/tree_node.cpp ./src/binary_tree.cpp -o ./bin/main
