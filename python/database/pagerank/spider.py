# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    spider.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 18:19:46 by atlekbai          #+#    #+#              #
#    Updated: 2018/12/23 18:56:33 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sqlite3
import urllib.error
import ssl
from urllib.parse import urljoin
from urllib.parse import urlparse
from urllib.request import urlopen
from bs4 import BeautifulSoup

#ignore certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

conn = sqlite3.connect('spider.sqlite3')
cur = conn.cursor()

cur.execute('''
CREATE TABLE IF NOT EXISTS Pages (
	id INTEGER PRIMARY KEY,
	url TEXT UNIQUE,
	html TEXT,
	error INTEGER,
	old_rank REAL,
	new_rank REAL
)''')
cur.execute('''
CREATE TABLE IF NOT EXISTS Links (
	from_id INTEGER,
	to_id INTEGER
)''')
cur.execute('CREATE TABLE IF NOT EXISTS Webs (url TEXT UNIQUE)')

cur.execute('SELECT id, url FROM Pages WHERE html is NULL and error is NULL ORDER BY RANDOM() LIMIT 1')
row = cur.fetchone()
if (row is not None):
    print('Restarting existing crawl.')
else:
    starturl = input('Enter url:')
    if (len(starturl) < 1): starturl = 'http://www.dr-chuck.com/'
    if (starturl.endswith('/')): starturl = starturl[:-1]
    web = starturl
    if (starturl.endswith('.htm') or starturl.endswith('.html')):
        pos = starturl.rfind('/')
        web = starturl[:pos]
    
    if (len(web) > 1):
        cur.execute('INSERT OR IGNORE INTO Webs (url) VALUES (?)', (web, ))
        cur.execute('INSERT OR IGNORE INTO Pages (url, html, new_rank) VALUES (?, NULL, 1.0)', (starturl, ))
        conn.commit()

cur.execute('SELECT url FROM Webs')
webs = list()
for row in cur:
    webs.append(str(row[0]))

print(webs)

many = 0
while (True):
    if (many < 1):
        sval = input('Number of pages:')
        if (len(sval) < 1): break
        many = int(sval)
    many -= 1

    cur.execute('SELECT id, url FROM Pages WHERE html is NULL and error is NULL ORDER BY RANDOM() LIMIT 1')
    try:
        row = cur.fetchone()
        #print row
        fromid = row[0]
        url = row[1]
    except:
        print('NO HTML pages found')
        many = 0
        break

    print(fromid, url, end = ' ')
    cur.execute('DELETE FROM Links WHERE from_id=?', (fromid, ))
    try:
        document = urlopen(url, context=ctx)
        html = document.read()
        if (document.getcode() != 200):
            print('Error on page:', document.getcode())
            cur.execute('UPDATE Pages SET error=? WHERE url=?', (document.getcode(), url))
        if (document.info().get_content_type() != 'text/html'):
            print('Ignore non text/html pages')
            cur.execute('DELETE FROM Pages WHERE url=?', (url, ))
            cur.execute('UPDATE Pages SET error=0 WHERE url=?', (url, ))
            conn.commit()
            continue
        print('({})'.format(len(html)), end=' ')
        soup = BeautifulSoup(html, 'html.parser')
    except KeyboardInterrupt:
        print('')
        print('Program interrupted by user')
        break
    except:
        print('Unable to get pages')
        cur.execute('UPDATE Pages SET error=-1 WHERE url=?', (url, ))
        conn.commit()
        continue
    
    cur.execute('INSERT OR IGNORE INTO Pages (url, html, new_rank) VALUES(?, NULL, 1.0)', (url, ))
    cur.execute('UPDATE Pages SET html=? WHERE url=?', (memoryview(html), url))
    conn.commit()

    tags = soup('a')
    count = 0
    for tag in tags:
        href = tag.get('href', None)
        up = urlparse(href)
        if (len(up.scheme) < 1):
            href = urljoin(url, href)
        ipos = href.find('#')
        if (ipos > 1): href = href[:ipos]
        if (href.endswith('.png') or href.endswith('.jpg')) : continue
        if (href.endswith('/')): href = href[:-1]
        if (len(href) < 1): continue

        found = False
        for web in webs:
            if (href.startswith(web)):
                found = True
                break
        if not found: continue

        cur.execute('INSERT OR IGNORE INTO Pages (url, html, new_rank) VALUES (?, NULL, 1.0)', (href, ))
        count += 1
        conn.commit()
        
        cur.execute('SELECT id FROM Pages WHERE url=? LIMIT 1', (url, ))
        try:
            row = cur.fetchone()
            toid = row[0]
        except:
            print('couldn\'t get id')
            continue
        cur.execute('INSERT OR IGNORE INTO Links (from_id, to_id) VALUES (?, ?)', (fromid, toid))
    print(count)
cur.close()
