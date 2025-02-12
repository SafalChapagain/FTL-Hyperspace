#!/bin/bash
set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/../build-one-variant.sh build-linux-1.6.13-debug amd64-linux-ftl ON Debug
