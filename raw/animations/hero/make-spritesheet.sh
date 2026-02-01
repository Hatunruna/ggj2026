#!/bin/bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/left-right/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right-red.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/left-right/green/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right-green.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/left-right/blue/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-left-right-blue.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/left-right/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-left-right-red.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/left-right/green/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-left-right-green.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/left-right/blue/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-left-right-blue.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/up/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-up.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/up/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-up.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/down/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-down-red.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/down/green/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-down-green.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/run/down/blue/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/run-down-blue.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/down/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-down-red.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/down/green/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-down-green.png"
magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/pause/down/blue/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/pause-down-blue.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/wear-mask/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/wear-mask-red.png"

magick montage -background transparent -tile 8x8 -geometry 128x128 "$SCRIPT_DIR/remove-mask/red/*" "png32:$SCRIPT_DIR/../../../data/animations/hero/remove-mask-red.png"
