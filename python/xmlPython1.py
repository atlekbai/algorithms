# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    xmlPython1.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 22:14:51 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/21 22:18:05 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import xml.etree.ElementTree as ET
input = '''
<stuff>
	<users>
		<user x="2">
			<id>001</id>
			<name>adilyam</name>
		</user>
		<user x="7">
			<id>009</id>
			<name>ali</name>
		</user>
	</users>
</stuff>'''

stuff = ET.fromstring(input)
lst = stuff.findall('users/user')
print('User count:', len(lst))
for user in lst:
    print('Name:', user.find('name').text)
    print('id:', user.find('id').text)
    print('attribute:', user.get('x'))
