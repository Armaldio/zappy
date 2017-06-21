#!/usr/bin/env bats

@test "netcat command available" {
  command -v nc
}

@test "basic connection" {
  run bash -c "echo 'Exit' | netcat 127.0.0.1 6666"
  [ "$output" = "WELCOME" ]
}
