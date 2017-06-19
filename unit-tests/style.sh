#!/bin/bash

./unit-tests/norme.py . -malloc -return -comment | grep -v 'login' | grep -v 'header' | grep -v 'pedantic' | grep -v 'Header' | grep -v 'Options de debug' | grep -v 'Wall' > out
#cat out


if [ -s out ]; then
  cat out
  rm out
  exit 1
else
  echo -e "No norme error found\nCongrats !"
  rm out
fi
