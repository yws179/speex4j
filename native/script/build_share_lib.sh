#!/bin/bash

c_file=`find .. ! -path '../cmake-build-debug/*' -name '*.[hc]'`

if [ ! -d '../out' ];then
  mkdir ../out
fi

gcc $c_file  -fPIC -shared -lspeex -o ../out/libspeex4j.so