# -*- coding: utf-8 -*-
import sys

de = 'de'
en = 'en'
lang = de

def chars(s):
    dat = file(s).read()
    return len(dat)

def words(s):
    dat = file(s).read().split()
    return len(dat)

def lines(s):
    dat = file(s).readlines()
    return len(dat)

def set_lang(l):
    global lang
    lang = l

def wc(s):
    return (lines(s), words(s), chars(s))

def wc_show(s):
    bla = wc(s)
    if lang == de:
        print "%s %s %s" % ("Die Datei", s, "hat")
        print "%s %s" % (bla[0], "Zeilen")
        print "%s %s" % (bla[1], "Wörter")
        print "%s %s" % (bla[2], "Buchstaben")
    else:
        print "%s %s %s" % ("The file", s, "contains")
        print "%s %s" % (bla[0], "lines")
        print "%s %s" % (bla[1], "words")
        print "%s %s" % (bla[2], "letters")


if __name__ == "__main__":
    fname = "/usr/share/dict/words"
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    wc_show(fname)   


    
