#!/bin/bash
#
# Build the document (including all the resources)
#
set -e

TEX_MAIN_FILE=main.tex
LATEX_TOC_FILE=main.toc

echo "Building pdf..."
rubber --pdf $TEX_MAIN_FILE

echo "Done!"
