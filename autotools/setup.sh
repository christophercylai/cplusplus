# setup script for autotools

set -e

autoreconf -i
./configure
make
