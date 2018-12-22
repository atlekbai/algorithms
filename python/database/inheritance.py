# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    inheritance.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/22 14:20:57 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/22 14:27:10 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class PartyAnimal:
    x = 0
    name = ""

    def __init__(self, nam):
        self.name = nam
        print(self.name, "created")

    def party(self):
        self.x += 1
        print(self.name, "party count", self.x)

class FootballFan(PartyAnimal):
    points = 0
    def touchdown(self):
        self.points += 7
        self.party()
        print(self.name, "points", self.points)

if __name__ == '__main__':
    fan = FootballFan('adilyam')
    fan.touchdown()
