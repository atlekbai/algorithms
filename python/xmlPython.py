# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xmlPython.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 22:10:29 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 22:13:04 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import xml.etree.ElementTree as ET

data = '''<person>
		<name>Adilyam</name>
		<phone type="intl">
			+7 774 232 12 12
		</phone>
		<email hide="yes"/>
	</person>'''
tree = ET.fromstring(data)
print('Name:', tree.find('name').text)
print('Email:', tree.find('email').get('hide'))
