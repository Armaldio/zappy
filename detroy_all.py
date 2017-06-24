#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import os
import logging
import logging.handlers
import subprocess
import threading
import socket
import time

# data = [var1, var2, var3, var4, var5, var6, var7, var8, var9, var10,
# var11, var12, var13, var14, var15, var16, var17, var18, var19, var20,
# var21, var22, var23, var24, var25, var26, var27, var28, var29, var30]

# for value in data:
# 	value = subprocess.

fake_data = "salut\n"

def netcat():
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect(('127.0.0.1', 4242))
	while 1:
		s.sendall(fake_data.encode())
		time.sleep(1)


a = 0

while (a < 1000):
	t1 = threading.Thread(target=netcat)
	t1.start()
	a += 1

t1.join()
