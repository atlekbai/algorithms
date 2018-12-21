# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    jsonPython1.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 22:28:16 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 22:28:16 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json

data = '''
[
	{
		"id"	:	"001",
		"x"		:	"2",
		"name"	:	"adilyam"
	},
	{
		"id"	:	"009",
		"x"		:	"7",
		"name"	:	"aali"
	}
]
'''

info = json.loads(data)
print('User count:', len(info))
for user in info:
	print('Name:', user['name'])
	print('x:', user['x'])
	print('id:', user['id'])