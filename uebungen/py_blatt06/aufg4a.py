import os
import random, sys, string

fordir = "/usr/share/games/fortunes/"

def filenames():
    return [d for d in os.lisdir(fordir) if not d.endswith(".dat") and not d.endswith(".u8")]



def files():
    lf = []
    for f in filenames():
        lf.extend(file(os.path.join(fordir, f)).read().split("\n%\n"))

    return lf


if __name__ == '__main__':
    lf = files()
    print random.choice(lf)

