# setup script for autotools

set -e

cd time_is
autoreconf -i
./configure
make
