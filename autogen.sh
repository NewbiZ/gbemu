#!/bin/bash

hash autoreconf 2> /dev/null || { echo >&2 "error: autoreconf is required to run this script"; exit 1; }

autoreconf --install 2>&1
