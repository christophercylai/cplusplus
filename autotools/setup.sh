# setup script for autotools

set -e

cp -r time_is build/
cd build
autoreconf -i
./configure
make
