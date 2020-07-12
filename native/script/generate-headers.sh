#!/bin/bash

cd ../../speex4j/src

list=`echo com/github/yws179/speex/*.java`

for name in $list
do
  javac $name -h ../../native/
done

rm com/github/yws179/speex/*.class