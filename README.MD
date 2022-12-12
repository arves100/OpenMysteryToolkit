# OpenMysteryToolkit

Open source Mystery Dungeon clone powered by [nCine](https://github.com/ncine/)

## Building

### nCine setup

Download [nCline](https://github.com/nCine/ncline-artifacts).

Clone this repo and the [data repo](https://github.com/arves100/openmysterytoolkit-data) on the same root directory.

Setup the game as omt by running the following command:

`ncline set -game openmysterytoolkit`

If you are using Visual Studio 2022, make sure to let nCline know by running the following command:

`ncline set -vs2022`

Download and build ncine by typing this commands:

```bash
ncline download engine -artifact
```

### Dependencies setup

The project also requires the following dependencies:

- Pybind11
- Python3
- EnTT

You can get those by your package manager or by using [vcpkg](https://github.com/microsoft/vcpkg).

You can configure ncline to use vcpkg by typing the following command:

`ncline set -cmake-args -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake`

### Game configuration

Finally, configure the game project:

`ncline conf game`

You should now have a directory called `openmysterytoolkit-build` which inside you can build the project
like an usual C++ project.

**NOTE:** If you use vcpkg, ncline doesn't support cmake arguments for the game project, therefore you have to manually configure the project:

```bash
rmdir /s/q OpenMysteryToolkit-build
mkdir OpenMysteryToolkit-build
cmake -S "OpenMysteryToolkit" -B "OpenMysteryToolkit-build" -G "[your compiler]" -A x64 -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake -D nCine_DIR="[your ncine directory]"
```

You can view your ncine directory by opening the file `ncline.ini`
