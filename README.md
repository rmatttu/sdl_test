# sdl_test
windows/linux sdl test


# コンパイル方法


## Windows


### 各ライブラリの設置

ライブラリのダウンロード


SDL version 2.0.5 (stable)

https://www.libsdl.org/download-2.0.php
> Development Libraries → Windows →  SDL2-devel-2.0.5-VC.zip (Visual C++ 32/64-bit)

SDL_image 2.0

https://www.libsdl.org/projects/SDL_image/
> Development Libraries → Windows →  SDL2_image-devel-2.0.1-VC.zip (Visual C++ 32/64-bit)

SDL_ttf 2.0

https://www.libsdl.org/projects/SDL_ttf/
> Development Libraries → Windows → SDL2_ttf-devel-2.0.14-VC.zip (Visual C++ 32/64-bit)


解凍して下記に設置

```
{ProjectDir}/sdl_test/SDL2_lib/...
```

各ライブラリの`.dll`を`{ProjectDir}/sdl_test`配下に設置

```
cd {ProjectDir}
copy sdl_test\SDL2_lib\SDL2-2.0.5\lib\x86\SDL2.dll sdl_test\
copy sdl_test\SDL2_lib\SDL2_image-2.0.1\lib\x86\SDL2_image.dll sdl_test\
copy sdl_test\SDL2_lib\SDL2_ttf-2.0.14\lib\x86\SDL2_ttf.dll sdl_test\
```


## linux

* install SDL2.0

```sh
$ apt install libsdl2-dev
```

* compile main.cpp

```sh
$ gcc main.cpp `sdl2-config --cflags --libs`
```



