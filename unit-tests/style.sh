#!/bin/bash

./unit-tests/norme.py . -malloc -return -comment | grep -v 'login' | grep -v 'header' | grep -v 'pedantic' | grep -v 'Header du Makefile invalide' | grep -v 'Options de debug' > out
#cat out


if [ -s out ]; then
  cat out
  exit 1
else
  echo -e "No norme error found\nCongrats !"
fi

rm out
