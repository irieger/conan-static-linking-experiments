# Experiments for conan dependency usage and static linking

I created this to play around with conan and better understand static linking problems on Linux.
The problem currently is linking the binary fails with the following error (output by `make VERBOSE=1`:

```
/usr/bin/c++ CMakeFiles/main-demo.dir/src/main.cpp.o -o bin/main-demo  /home/ingmar/.conan/data/glog/0.4.0/_/_/package/92f46611daf4fc8eae13b7228a9f2af28e669727/lib/libglog.a /home/ingmar/.conan/data/gflags/2.2.2/_/_/package/21e1281916d3adf618b3bd57f3098f62f2674fd4/lib/libgflags_nothreads.a /home/ingmar/.conan/data/openjpeg/2.4.0/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib/libopenjp2.a -lpthread -lm
/usr/bin/ld: /home/ingmar/.conan/data/openjpeg/2.4.0/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib/libopenjp2.a(tcd.c.o): in function `opj_tcd_rateallocate':
tcd.c:(.text+0x3ab8): undefined reference to `__exp_finite'
/usr/bin/ld: /home/ingmar/.conan/data/openjpeg/2.4.0/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib/libopenjp2.a(tcd.c.o): in function `opj_tcd_init_tile':
tcd.c:(.text+0x4b10): undefined reference to `__exp2_finite'
collect2: error: ld returned 1 exit status
```

According to my google work both functions should be linked with the math lib (`-lm`).

(I extracted this problem from trying to use openimageio which I have in the main branch)

## How I build

```bash
cd MY_DEV_FOLDER
git clone -b openjpeg https://github.com/irieger/conan-static-linking-experiments.git
mkdir conan-static-linking-experiments/build
cd conan-static-linking-experiments/build
conan install .. -s compiler.libcxx=libstdc++11 --build=missing
```

## My system

I use Ubuntu 20.04 with g++ 9.3 as the default compiler and cmake & conan installed via `pip install conan cmake`.

## Note on the barrier I hit first

At first I really struggled some time to find that on Linux I need to call with `-s compiler.libcxx=libstdc++11`.
