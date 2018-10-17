# linux-chat-server

### Travis-CI
[![Build Status](https://travis-ci.org/Rabenda/linux-chat-server.svg?branch=master)](https://travis-ci.org/Rabenda/linux-chat-server)

### dependence
```bash
conan install . -s build_type=Release
```

### Compile
```
mkdir build
cd build
cmake ..
make -j4
```