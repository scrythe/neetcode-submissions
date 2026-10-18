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

common_build_flags="-g $asan_flags  -Wall -Werror -o build/main main.cpp"
if [[ "${release:-0}" == 1 ]]; then
  echo "[release mode]"
  compile="clang++ -O2 $common_build_flags"
else
  echo "[debug mode]"
  compile="clang++ -O0 $common_build_flags -Wno-unused-variable -Wno-unused-but-set-variable -DBUILD_DEBUG=1"
fi

echo "[building main]"
$compile

if [[ "${run:-0}" == "1" ]]; then
  echo "[running main]"
  ./build/main
fi
