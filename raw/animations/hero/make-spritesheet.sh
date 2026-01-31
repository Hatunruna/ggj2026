#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/left-right/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right.png"
cp "$SCRIPT_DIR/left-right/marche_gauchedroite_000.png" "$SCRIPT_DIR/../../../data/animations/hero/pause-left-right.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/up/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-up.png"
cp "$SCRIPT_DIR/up/run_down_000.png" "$SCRIPT_DIR/../../../data/animations/hero/pause-up.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/down/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-down.png"
cp "$SCRIPT_DIR/down/run_down_000.png" "$SCRIPT_DIR/../../../data/animations/hero/pause-down.png"
