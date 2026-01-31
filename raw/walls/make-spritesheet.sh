#/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

montage "$SCRIPT_DIR/1-*.png" "$SCRIPT_DIR/2-*.png" "$SCRIPT_DIR/3-*.png" -background none -tile 8x8 -geometry 128x128 "png32:$SCRIPT_DIR/../../data/map/walls.png"
