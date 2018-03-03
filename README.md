# justDoIt
[![travis][travis-img]](https://travis-ci.org/krthkj/cmake-template)

[travis-img]: https://img.shields.io/travis/krthkj/cmake-template/master.svg?label=Linux+Build

sample project for using cmake

## How-To generate Makefile, examples (out-of-source)

Simple:
```sh
cmake -H. -B_builds
```

Debug and Release variant:
```sh
cmake -H. -B_builds/Debug -DCMAKE_BUILD_TYPE=Debug
cmake -H. -B_builds/Release -DCMAKE_BUILD_TYPE=Release
```

Options/feature customizations:
```sh
cmake -H. -B_builds/feature-on -DFOO_FEATURE=ON
cmake -H. -B_builds/feature-off -DFOO_FEATURE=OFF
```

Generators:
```sh
cmake -H. -B_builds/xcode -G Xcode
cmake -H. -B_builds/make -G "Unix Makefiles"
```

Platforms:
```sh
cmake -H. -B_builds/osx -G Xcode
cmake -H. -B_builds/ios -G Xcode -DCMAKE_TOOLCHAIN_FILE=/.../ios.cmake
```

## Build instructions/command
Simple:
```sh
cmake --build _builds
```

Debug and Release variant:
```sh
cmake --build _builds/Debug
cmake --build _builds/Release
```

Options/feature customizations:
```sh
cmake --build _builds/feature-on
cmake --build _builds/feature-off
```

Generators:
```sh
cmake --build _builds/xcode
cmake --build _builds/make
```

Platforms:
```sh
cmake --build _builds/osx
cmake --build _builds/ios
```

## Testing
Test commands are placed the parent `CMakeFile.txt` file.
example:
```txt
add_test( testname Exename arg1 arg2 ... )
add_test(Square_No justDoIt 36)
```

To perform testing,
```sh
cd _builds
ctest       # minimal verbose level
ctest -V    # verbose
ctest -V    # Extra verbose
```

## Building installer
After performing a successful build,
```sh
cd _builds
cpack --config CPackConfig.cmake        # Create binary distribution
cpack --config CPackSourceConfig.cmake  # Create Source distribution
```



## Reference
- https://cmake.org/cmake-tutorial/
- https://cgold.readthedocs.io/en/latest/index.html
- https://cmake.org/Wiki/CMake/Testing_With_CTest
