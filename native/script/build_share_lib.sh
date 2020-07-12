#!/bin/bash

c_file=`find .. ! -path '../cmake-build-debug/*' -name '*.[hc]'`

gcc $c_file  -fPIC -shared -lspeex -o ../out/libspeex4j.so