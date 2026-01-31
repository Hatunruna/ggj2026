#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/left-right/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right.png"
cp "$SCRIPT_DIR/left-right/marche_gauchedroite_000.png" "$SCRIPT_DIR/../../../data/animations/hero/pause-left-right.png"
