# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    jsonPython.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 22:24:28 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 22:24:49 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import json

data = '''
{
	"name"	:	"Adilyam",
	"phone"	:	{
		"type"		:	"intl",
		"number"	:	"+7 705 123 12 23"
	},
	"email"	:	{
		"hide"		:	"yes"
	}
}'''

info = json.loads(data)
print('Name:', info['name'])
print('Hide:', info['email']['hide'])
print(type(info))
