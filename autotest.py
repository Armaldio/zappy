#!/usr/bin/env python3.6
# -*- coding: UTF-8 -*-

from __future__ import print_function
import os
import logging
import logging.handlers
import subprocess
import threading
import socket
import time

# basic commande
commande_team = "Team1\n"
commande_forward = "Forward\n"
commande_right = "Right\n"
commande_left = "Left\n"
commande_look = "Look\n"
commande_inventory = "Inventory\n"
commande_connect = "Connect_nbr\n"
commande_fork = "Fork\n"
commande_eject = "Eject\n"
commande_take1 = "Take food\n"
commande_take2 = "Take linemate\n"
commande_set1 = "Set sibur\n"
commande_set2 = "Set phiras\n"
commande_incantation = "Incantation\n"

# multiple commande
multiple1 = "Right\nForward\n"
multiple2 = "Take food\nSet food\n"
multiple3 = "Eject\nInventory\nForward\nLeft\n"

# wrong commande

error1 = "Forward left\n"
error2 = "Inven tory\n"
error3 = "Take hamza\n"
error4 = "Set Inventory\n"
error5 = "Eject 3\n"

print("Connection: ")

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 4242))
s.sendall(commande_team.encode())
time.sleep(1)
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')
print("OK")

print("Commande: " + commande_forward, end='')
s.sendall(commande_forward.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_right, end='')
s.sendall(commande_right.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_left, end='')
s.sendall(commande_left.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_look, end='')
s.sendall(commande_look.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_inventory, end='')
s.sendall(commande_inventory.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_connect, end='')
s.sendall(commande_connect.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

time.sleep(3)
print("Commande: " + commande_fork, end='')
s.sendall(commande_fork.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_eject, end='')
s.sendall(commande_eject.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_take1, end='')
s.sendall(commande_take1.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_take2, end='')
s.sendall(commande_take2.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_set1, end='')
s.sendall(commande_set1.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + commande_set2, end='')
s.sendall(commande_set2.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

# s.sendall(commande_incantation.encode())
print("\n\nMultiple commande")

time.sleep(2)

print("Commande: " + multiple1, end='')
s.sendall(multiple1.encode())
time.sleep(5)
answer = s.recv(25000)
print("Answer: " + answer.decode("utf-8"), end='')

time.sleep(2)
print("Commande: " + multiple2, end='')
s.sendall(multiple2.encode())
time.sleep(5)
answer = s.recv(25000)
print("Answer: " + answer.decode("utf-8"), end='')

time.sleep(2)
print("Commande: " + multiple3, end='')
s.sendall(multiple3.encode())
time.sleep(5)
answer = s.recv(25000)
print("Answer: " + answer.decode("utf-8"), end='')

time.sleep(2)

print("\n\nError commande")
print("Commande: " + error1, end='')
s.sendall(error1.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + error2, end='')
s.sendall(error2.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + error3, end='')
s.sendall(error3.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + error4, end='')
s.sendall(error4.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')

print("Commande: " + error5, end='')
s.sendall(error5.encode())
answer = s.recv(250)
print("Answer: " + answer.decode("utf-8"), end='')
print("end")
