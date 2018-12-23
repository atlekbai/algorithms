# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rosterDB.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 15:06:26 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/23 15:18:52 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sqlite3
import json

conn = sqlite3.connect('rosterdb.sqlite')
cur = conn.cursor()

cur.executescript(
'''
DROP TABLE IF EXISTS User;
DROP TABLE IF EXISTS Course;
DROP TABLE IF EXISTS Member;

CREATE TABLE User (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE
);

CREATE TABLE Course (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE
);

CREATE TABLE Member (
	user_id INTEGER,
	course_id INTEGER,
	role INTEGER,
	PRIMARY KEY (user_id, course_id)
);
''')

fname = input('Enter name: ')
if (len(fname) < 1) : fname = 'roster.json'

str_data = open(fname).read()
data = json.loads(str_data)
for item in data:
    name = item[0]
    course = item[1]
    role = item[2]

    cur.execute('INSERT OR IGNORE INTO User (name) VALUES (?)', (name, ))
    cur.execute('SELECT id FROM User WHERE name = ?', (name, ))
    user_id = cur.fetchone()[0]

    cur.execute('INSERT OR IGNORE INTO Course (name) VALUES (?)', (course, ))
    cur.execute('SELECT id FROM Course WHERE name = ?', (course, ))
    course_id = cur.fetchone()[0]

    cur.execute('INSERT OR REPLACE INTO Member (user_id, course_id, role) VALUES(?, ?, ?)',
                (user_id, course_id, role))
    conn.commit()
