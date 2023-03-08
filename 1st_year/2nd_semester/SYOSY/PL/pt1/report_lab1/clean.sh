#!/bin/bash
#
# Cleanup all the built files (include pdf)
#

set -e

TEX_MAIN_FILE=main.tex

echo "Cleaning up built latex files..."
rubber --clean --pdf $TEX_MAIN_FILE
rm -f main.fdb_latexmk main.fls

echo "Done!"
