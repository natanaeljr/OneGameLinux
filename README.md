# OneGameLinux

## Cloning

Clone the repository with the `recursive` flag, so as to also pull all submodules linked to this project.

```
git clone --recursive https://github.com/natanaeljr/OneGameLinux.git
```

## Updating

```
git pull
git submodule update --init --recursive
```

## Building

Assuming you are in the directory where you cloned the repository, the following commands will create a build tree, configure  and build the entire project.

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Running

The final binary is located at `./build/FirstGameLinux/bin`.

Copy the binary to your bin path, or just run it from the given build path.

## Development

1. The root directory contains only dependencies, setup files, tools and the project source directory.

2. The source code is all under `FirstGameLinux` subdirectory.

3. When developing source code, it's recommended to use `FirstGameLinux` as the root directory.

4. For that, firstly, build the entire project here, following the *Building* section.

5. From then on, all project library dependencies will be available at `./build/external/`.

6. Now use `FirstGameLinux` as root directory for development and simply set `CMAKE_PREFIX_PATH`:

   ```
   cd FirstGameLinux
   mkdir build
   cd build
   cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=$(realpath ../../build/external)
   cmake --build .
   ```

7. **Note:** Both super-project and sub-project  should be configured with matching build types: `CMAKE_BUILD_TYPE=Debug`.
8. For IDE or LSP, use compilation database  generated at `build/compilation_database.json`.
9. That's it, all setup, just dev!
