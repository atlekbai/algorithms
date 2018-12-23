# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tracksDB.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 13:23:57 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/23 13:34:25 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sqlite3
import xml.etree.ElementTree as ET

conn = sqlite3.connect('trackdb.sqlite')
cur = conn.cursor()

# fresh tables
cur.executescript(
'''
DROP TABLE IF EXISTS Artist;
DROP TABLE IF EXISTS Album;
DROP TABLE IF EXISTS Track;

CREATE TABLE Artist (
	id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
	name TEXT UNIQUE
);

CREATE TABLE Album (
	id INTEGER UNIQUE PRIMARY KEY NOT NULL AUTOINCREMENT,
	name TEXT UNIQUE,
	artist_id INTEGER
);

CREATE TABLE Track (
	id INTEGER UNIQUE PRIMARY KEY NOT NULL AUTOINCREMENT,
	name TEXT,
	album_id INTEGER,
	length INTEGER,
	rating INTEGER
);
''')

fname = input('Enter filename:')
if (len(fname) < 1): fname = 'Library.xml'

def lookup(d, key):
    found = False
    for child in d:
        if found : return child.text
        if child.tag == 'key' and child.text == key:
            found = True
    return (None)

stuff = ET.parse(fname)
all = stuff.findall('dict/dict/dict')
for entry in all:
    if (lookup(entry, 'Track ID') is None) continue
    name = lookup(entry, 'Name')
    artist = lookup(entry, 'Artist')
    album = lookup(entry, 'Album')
    rating = lookup(entry, 'Rating')
    length = lookup(entry, 'Total Time')
    if ((name is None) or (artist is None) or (album is None)):
        continue

    print(name, artist, album, rating, length)
    # ignore if exists
    cur.execute('INSERT OR IGNORE INTO Artist (name) VALUES (?)', (artist, ))
    cur.execute('SELECT id FROM Artist WHERE name = ?', (artist, ))
    artist_id = cur.fetchone()[0]

    cur.execute('INSERT OR IGNORE INTO Album (name, artist_id) VALUES (?, ?)', (album, artist_id))
    cur.execute('SELECT id FROM Album WHERE name = ?', (album, ))
    album_id = cur.fetchone()[0]

    cur.execute('INSERT OR REPLACE INTO Track (name, album_id, length, rating) VALUES (?, ?, ?, ?)', (name, album_id, length, rating))
    conn.commit()
    album_id = 
