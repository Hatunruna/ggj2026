#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

bash "$SCRIPT_DIR/animations/hero/make-spritesheet.sh"
bash "$SCRIPT_DIR/walls/make-spritesheet.sh"
