import re

#a
plz_re = re.compile('\d{5}')

#b

datum = re.compile('(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[012])\.\d{4}')

#c
preis = re.compile('(\d+|(\d{1,3}(.\d{3})+))(\,[0-9]{2})?(\ EUR)?')

#d
tel = re.compile('(\+\d{1,3}[-/ ]|0)\d{2,}[-/ ])*\d+')

#e
email = re.compile('\[a-zA-Z]\w+([-.]\w+)*@([a-z]+(\-[a-z])*\.)+[a-z]{2,3}')
