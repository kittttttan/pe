#!/bin/sh

cur=`pwd`
sudo cp lib/lib* /usr/local/lib
sudo ldconfig

# pushd /usr/local/lib
cd /usr/local/lib
sudo ln -sf libpe++.so.1.0.0 libpe++.so
ls -l ./
cd ${cur}
# popd
