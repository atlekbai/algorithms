# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    httpRequest.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 16:37:40 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 16:40:01 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import socket

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect(('data.pr4e.org', 80))
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode()
mysock.send(cmd)

while (True):
    data = mysock.recv(512)
    if (len(data) < 1):
        break
    print(data.decode())
mysock.close()
