#!/bin/bash

# inspired by https://github.com/EpicGames/raddebugger/blob/master/build.sh

set -eu
cd "$(dirname "$0")"
command_args=""

# --- Unpack Arguments --------------------------------------------------------
while [[ $# -gt 0 ]]; do
  declare $1='1'
  shift
done

if [[ "${clean:-0}" == 1 ]]; then
  echo "[clean build folder]"
  rm -rf build
fi

mkdir -p build

asan_flags=""
if [[ "${asan:-0}" == 1 ]]; then
  echo "[enable asan]"
  asan_flags="-fsanitize=address -fno-omit-frame-pointer"
fi

compiler=clang++
# common_build_flags="-g -std=c99 $asan_flags  -Wall -Werror -o build/main main.c"
common_build_flags="-g -std=c++11 $asan_flags  -Wall -Werror -o build/main main.cpp"
if [[ "${release:-0}" == 1 ]]; then
  echo "[release mode]"
  compile="$compiler -O2 $common_build_flags"
else
  echo "[debug mode]"
  compile="$compiler -O0 $common_build_flags -Wno-unused-variable -Wno-unused-but-set-variable -DBUILD_DEBUG=1"
  echo "$compile"
fi

echo "[building main]"
$compile

if [[ "${run:-0}" == "1" ]]; then
  echo "[running main]"
  ./build/main
fi
