# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bs4Python.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 21:41:56 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 21:45:37 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl

#ignore SSL
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter - ')
html = urllib.request.urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')

#get all anchor tags
tags = soup('a')
for tag in tags:
    print(tag.get('href', None))
