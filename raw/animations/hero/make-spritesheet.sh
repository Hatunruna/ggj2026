#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/left-right/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause-left-right/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-left-right.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/up/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-up.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause-up/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-up.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/down/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-down.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause-down/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-down.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/wear-mask/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/wear-mask-red.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/remove-mask/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/remove-mask-red.png"
