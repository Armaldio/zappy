#!/bin/sh

make_test_command=$(make re && make tests)
err_code=$?

is_destructive='force|delete|\-f'

will_remove_protected_branch=':'$protected_branch

echo $make_test_command

if (( $err_code != 0)); then
  echo -e "\e[31mTests failed. Cannot push. Go learn how to code.\e[39m"
  exit 1
else
  echo "\e[32mNice you can push\e[39m"
fi

exit 0
