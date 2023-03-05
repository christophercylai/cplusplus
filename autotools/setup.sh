# setup script for autotools

set -e

cp -r src build_dir/
cd build_dir
autoreconf -i
./configure
make
