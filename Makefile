MAKEFLAGS += --no-print-directory

BUILD_DIR = build

build:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build clean
