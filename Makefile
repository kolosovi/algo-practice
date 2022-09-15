.PHONY: cpp-cmake
cpp-cmake:
	cmake -S . -B build

.PHONY: cpp-build
cpp-build: cpp-cmake
	cmake --build build

.PHONY: cpp-test
cpp-test: cpp-build
	ctest --test-dir build

.PHONY: cpp-format
cpp-format:
	./scripts/cpp-format.sh

.PHONY: go-test
go-test:
	go test -v ./...
