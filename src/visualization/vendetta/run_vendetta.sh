#!/bin/bash

PATH_TO_THIS_DIR=`dirname $0`

pushd $PATH_TO_THIS_DIR
make && java -cp classes vendetta.Vendetta $*
popd
