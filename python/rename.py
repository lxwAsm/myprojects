import filetype
import os,sys

class Color:

    @staticmethod
    def _wrap_colour(colour, a, prints):
        a = colour + '{}'.format(a) + '\033[0m'
        return a
    @classmethod
    def blue(cls, a, prints=True):
        return cls._wrap_colour('\033[94m', a, prints)

    @classmethod
    def bold(cls, a, prints=True):
        return cls._wrap_colour('\033[1m', a, prints)

    @classmethod
    def cyan(cls, a, prints=True):
        return cls._wrap_colour('\033[96m', a, prints)

    @classmethod
    def darkblue(cls, a, prints=True):
        return cls._wrap_colour('\033[34m', a, prints)

    @classmethod
    def darkcyan(cls, a, prints=True):
        return cls._wrap_colour('\033[36m', a, prints)

    @classmethod
    def green(cls, a, prints=True):
        return cls._wrap_colour('\033[92m', a, prints)

    @classmethod
    def pink(cls, a, prints=True):
        return cls._wrap_colour('\033[95m', a, prints)

    @classmethod
    def purple(cls, a, prints=True):
        return cls._wrap_colour('\033[35m', a, prints)

    @classmethod
    def red(cls, *args):
        for a in args:
            print('\033[91m{}\033[0m'.format(a))

    @classmethod
    def underline(cls, a, prints=True):
        return cls._wrap_colour('\033[4m', a, prints)

    @classmethod
    def yellow(cls, a, prints=True):
        return cls._wrap_colour('\033[93m', a, prints)

    @classmethod
    def background(cls, a, prints=True):
        return cls._wrap_colour('\033[0;7m', a, prints)

def     main():
    if len(sys.argv) < 2:
        print(Color.red("[-]args error"))

    if os.path.isfile(sys.argv[1]):
        f = sys.argv[1]
        tp = filetype.guess(f)
        if tp != None:
            if '.' not in f:
                os.rename(f, f + '.' + tp.extension)
                print(Color.green("[+]done!"))
        else:
            print(Color.red("[-]can't guess"))
    else:
        os.chdir(os.getcwd() + "\\" + sys.argv[1])
        files = os.listdir('.')
        for f in files:
            if os.path.isfile(f):
                tp = filetype.guess(f)
                if tp != None:
                    if '.' not in f:
                        os.rename(f, f + '.' + tp.extension)
                else:
                    print(Color.red("[-]can't guess"))
        print(Color.green('done!'))
if __name__=="__main__":
    main()