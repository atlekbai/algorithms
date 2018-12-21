import urllib.request, urllib.parse, urllib.error
import re

chuckUrl = 'http://www.dr-chuck.com/page1.htm'
fhand = urllib.request.urlopen(chuckUrl)
for line in fhand:
    line = line.decode().strip()
    links = re.findall('href=\"(\S+)\"', line)
    print(links)
