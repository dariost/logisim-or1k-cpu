#!/bin/bash

mkdir -p /tmp/or1k
mkdir -p "$HOME""/or1k/bin"
pushd /tmp/or1k
wget "http://ftp.gnu.org/gnu/binutils/binutils-2.25.1.tar.bz2"
wget "ftp://sourceware.org/pub/newlib/newlib-2.3.0.20160104.tar.gz"
git clone "https://github.com/openrisc/or1k-gcc.git"
export PREFIX="$HOME""/or1k"
export PATH="$PATH:$PREFIX/bin"
tar xjvf "binutils-2.25.1.tar.bz2"
tar xzvf "newlib-2.3.0.20160104.tar.gz"
mkdir build-binutils
cd build-binutils
../binutils-2.25.1/configure --target=or1k-elf --prefix=$PREFIX --enable-shared \
--disable-itcl --disable-tk --disable-tcl --disable-winsup --disable-gdbtk \
--disable-libgui --disable-rda --disable-sid --disable-sim --with-sysroot
make -j4
make install
cd ..
mkdir build-gcc-stage1
cd build-gcc-stage1
../or1k-gcc/configure --target=or1k-elf --prefix=$PREFIX --enable-languages=c --disable-shared --disable-libssp
make -j4
make install
cd ..
mkdir build-newlib
cd build-newlib
../newlib-2.3.0.20160104/configure  --target=or1k-elf --prefix=$PREFIX
make -j4
make install
cd ..
mkdir build-gcc-stage2
cd build-gcc-stage2
../or1k-gcc/configure --target=or1k-elf --prefix=$PREFIX --enable-languages=c,c++ --disable-shared --disable-libssp --with-newlib
make -j4
make install
cd ..
popd

