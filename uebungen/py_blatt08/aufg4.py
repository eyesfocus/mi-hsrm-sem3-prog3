import Image
import sys
import aufg3
import string

def xy(punkte, name, mode):
    im = Image.new("1", (400,400))
    for e in punkte:
        im.putpixel((int(e[0]), int(e[1])), 1)
    name += "_xy.png"
    im.save(name)

def xz(punkte, name, mode):
    im = Image.new("1", (400,400))
    for e in punkte:
        im.putpixel((int(e[0]), int(e[2])), 1)
    name += "_xz.png"
    im.save(name)

def yz(punkte, name, mode):
    im = Image.new("1", (400,400))
    for e in punkte:
        im.putpixel((int(e[1]), int(e[2])), 1)
    name += "_yz.png"
    im.save(name)

def machebild(punkte, name = "bild", mode ="xy"):
    if mode == "xy":
        xy(punkte, name, mode)

    if mode == "xz":
        xz(punkte, name, mode)

    if mode == "yz":
        yz(punkte, name, mode)

    if mode == "all":
        xy(punkte, name, mode)
        xz(punkte, name, mode)
        yz(punkte, name, mode)


if __name__ == '__main__':
    if len(sys.argv) > 1:
        lis = aufg3.objread(file(sys.argv[1]))
        machebild(lis, mode = "all")
