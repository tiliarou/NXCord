# Unofficial Nintendo Switch Discord client
Currently WIP and not really usable for regular people. Also Discord's TOS forbids the use of third party clients, thus use at your own risk!. Also a lot of code has been taken from https://github.com/yourWaifu/Unofficial-Discord-3DS-Client, so thanks a lot for yourWaifu's 3ds client.

## Status
| Feature         | Working   | Status                  |
|-----------------|-----------|-------------------------|
| HTTPS           | Yes       | 100%                    |
| Websocket       | Yes       | 100%                    |
| Receive content | Yes       | 100%                    |
| Send content    | Yes       | 100%                    |
| UDP connection  | Yes       | 100%                    |
| Receive voice   | Partially | 90% - When multiple people speak, audio will bug out. Wrong mixing? |
| Send voice      | Yes       | 100%                   |
| Sysmodule       | Yes       | 100%                   |
| GUI             | Yes       | 10% - Really basic UI for now. |
| IPC             | Yes       | 5%                     |

## Dependencies
For building you need to install dependencies first.

Assuming you have devkitpro and libnx installed, just run:
```
(dkp-)pacman -S devkitpro-pkgbuild-helpers switch-pkg-config switch-libsodium switch-mbedtls switch-zlib switch-sdl2 switch-sdl2_ttf switch-sdl2_image switch-sdl2_gfx switch-sdl2_mixer switch-mesa switch-glad switch-glm switch-libdrm_nouveau switch-libwebp switch-libpng switch-freetype switch-bzip2 switch-libjpeg-turbo switch-opusfile switch-libopus
```

### Building NXCord
```
git clone --recurse-submodules git@github.com:Grarak/NXCord.git
cd NXCord
make
```

Since IPC is not fully done yet client only works with nxcord library bundled in. You can create such build with:
```
$ cd client
$ make standalone
```
But make sure to have dependencies installed and built first.
