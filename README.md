## Ray Tracer in one weekend.

### About
This is an implementation of Ray Tracer in one weekend by Peter Shirley.
All the features in the first eleven chapters: sphere collision, antialiasing, diffuse; metal and dielectric materials, pinhole and lens cameras.
Vectors, points and directions have separate types where points and directions can be implicitly cast to vectors but vectors have to be explicitly cast to points or directions.
This avoids normalization errors and confusing positions with directions.
The random scene generation has a different implementation, the sphere are more random and the three main sphere in the middle are not present.


### Usage

CMake is used for this project, full instructions for building with cmake can be found [here](https://preshing.com/20170511/how-to-build-a-cmake-based-project/).
For a UNIX like system do:
```
cd /path/to/project/root/
mkdir build
cd build
cmake -DBUILD_TESTING=OFF -DCMAKE_BUILD_TYPE="Release" -G "Unix Makefiles" ..
make
```

In order to use an IDE CMake can generate various projects, example for Xcode use '-G "Xcode"'.

For Windows a cmake GUI can be installed to generate a Visual Studio solution, alternatively Visual Studio Code can be used with some plugins.

The tracer can be found inside the bin folder. It outputs an image in ppm format to std::out so the output needs to be piped into a file in order to be saved.

```
./Ray_Tracer >> render.ppm
```

The project also contains a few unit tests for common vector operations and the ppm save using the [catch2](https://github.com/catchorg/Catch2) header library.
These can be found in the tests folder under build.
Using the command line ctest can be used to run all tests.
Note: the above cmake command compiles without tests in order to reduce compile time.

### Sample

![Render](/render.png)
