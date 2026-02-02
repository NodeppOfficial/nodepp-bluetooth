# nodepp-bluetooth: Cross-Platform Bluetooth Interface

The `nodepp-bluetooth` component provides a modern C++ interface for Bluetooth communication (Classic and LE). It abstracts the complexities of the underlying operating system APIs, allowing you to write portable C++ code for device discovery, connection, and data exchange.

## Dependencies & CMake Integration
```bash
# Bluez ( Linux & Mac Only )
  🐧: sudo apt install libbluetooth-dev
```
```bash
include(FetchContent)

FetchContent_Declare(
	nodepp
	GIT_REPOSITORY   https://github.com/NodeppOfficial/nodepp
	GIT_TAG          origin/main
	GIT_PROGRESS     ON
)
FetchContent_MakeAvailable(nodepp)

FetchContent_Declare(
	nodepp-bluetooth
	GIT_REPOSITORY   https://github.com/NodeppOfficial/nodepp-bluetooth
	GIT_TAG          origin/main
	GIT_PROGRESS     ON
)
FetchContent_MakeAvailable(nodepp-bluetooth)

#[...]

target_link_libraries( #[...]
	PUBLIC nodepp nodepp-bluetooth #[...]
)
```

## Key Features
- **Platform Abstraction:** Uses the Linux BlueZ stack on POSIX systems and native windows.h APIs on Windows.
- **Minimal Dependency:** Only requires the base nodepp library for core utilities.
- **Simple CMake Integration:** Designed for drop-in use via FetchContent.

## Build & Run
```bash
🪟: g++ -o main main.cpp -I ./include -lws2_32    ; ./main
🐧: g++ -o main main.cpp -I ./include -lbluetooth ; ./main
```

## License
**Nodepp-Bluetooth** is distributed under the MIT License. See the LICENSE file for more details.