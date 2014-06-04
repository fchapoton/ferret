#!/bin/bash
set -e
set -u
cd $(dirname $0)
cd ..
. ./ferret.vars
cd YAPB++/tests
./run_tests.sh
cd ../..
for j in ""; do
  make $j > /dev/null
  cd tst
  for i in *.tst; do
      echo 'echo '\''Test("'$i'");'\'' | '${GAPEXEC}
  done | parallel -j4
  wait
  cd ..
done
