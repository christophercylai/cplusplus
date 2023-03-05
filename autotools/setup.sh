# setup script for autotools

set -e

autoreconf -i
mkdir -p build
cd build
../configure
make
