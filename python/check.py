import os,sys,re

recoding=True
types = ("AT_any","AT_py","AT_swf","AT_lisp","AT_ps","AT_com","AT_inno","AT_dex","AT_elf","AT_text","AT_lnk","AT_pe","AT_smrtinst","AT_vbs","AT_vmregn","AT_xlsheet","AT_docm","AT_rar","AT_bom","AT_zip","AT_au3","AT_autoit","AT_js","AT_7z","AT_bat","AT_gz","AT_macho","AT_cmdln","AT_nsi","AT_x97m","AT_nsis","AT_arj","AT_bz2","AT_ne","AT_tar","AT_irc","AT_cab","AT_eicar","AT_le","AT_mz","AT_ole","AT_sfxinfo","AT_reg","AT_php","AT_html",)
property=[r'D:\hr_repositories\virdb\mpat\property_false.sig',r'D:\hr_repositories\virdb\mpat\property.sig']

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

def initProperty():
    global property
    props = []
    for i in property:#start to read files
        #{ prop = "!Attr.Virus.Virut.NBP",
        content = open(i,"rb").read()
        d = re.findall(b'{\s*prop\s*=\s*"(.*?)"',content)
        for k in d:
            props.append(k.decode().lstrip("!"))
    return props

def check_contain_chinese(check_str):
    for ch in check_str:
        if u'\u4e00' <= ch <= u'\u9fff' or ord(ch)>128:
            return True
    return False

def isHexString(s):
    s = s.lower()
    for c in s:
        if c not in "1234567890abcdef?{,}":
            return False
    return True

def     concat(*s):
    p=""
    for i in s:
        p+=str(i)
    return p
def     check_error(filename):
    global recoding,props
    content = open(filename, 'rb').readlines()
    size = len(content)
    for i in range(size):
        index = content[i].rfind(b"--")
        if index!=-1:
            content[i]=re.sub(b"--.*",b"",content[i][index:]).rstrip()
    for l in range(size):
        if content[l].strip().startswith(b'--') or len(content[l])==0:
            continue
        clean = content[l].rstrip().decode('utf-8')
        if check_contain_chinese(clean):
            print("Line:",l+1,"Contains Chinese:",clean)
        if len(clean) > 0:
            if len(re.findall("{\sname\s=\s\"", clean, re.IGNORECASE)) > 0:
                recoding = False
                if not clean.endswith(','):
                    print("Line:", l + 1, "Error!Missing dot:", clean)
            elif clean[:2] == "},":
                recoding = True
            elif len(re.findall("type\s=\sAT_", clean)) > 0:
                if not clean.endswith(','):
                    print("Line:", l + 1, "Error!Missing dot:", clean)
                data = re.findall("type\s=\s(.*?),", clean)[0]
                if data not in types:
                    print("Line:", l + 1, "Error!Type seems not supporting:", clean)
            elif len(re.findall("rsts\s=\s{", clean, re.IGNORECASE)) > 0:
                data = re.findall("rsts\s=\s{(.*?)}", clean, re.IGNORECASE)
                if len(data) == 0:  # old struct
                    rsts = content[l + 1].strip().decode()
                    if len(re.findall('"\s.*?"', rsts, re.IGNORECASE)) > 0:
                        print("Line:", l + 1, "rsts No Content", clean)
                else:
                    rsts = [k.strip() for k in data[0].split(",")]
                    for g in rsts:
                        if len(re.findall('"\s.*?"',g, re.IGNORECASE)) > 0:
                            print("Line:", l + 1, "rsts No Content", clean)
                    if not clean.endswith(",") and (content[l+1].find(b'},')==-1):
                        print("Line:", l + 1, "Error!Missing dot:", clean)
            elif clean.find("B(") != -1:
                bin = re.findall('B\(\"(.*?)"',clean)
                if len(bin)==0:
                    print("Line:", l + 1, "Error!Wrong format:", clean)
                bin = bin[0]
                if "{" in bin[:6]:
                    print("Line:", l + 1, "Error!At least 3 bytes by using{}", clean)
                bin = re.sub("\{.*?\}", "", bin)
                if len(bin) % 2 != 0:
                    print("Line:", l + 1, "Error!Binary not x2:", clean)
                if not isHexString(bin):
                   print("Line:", l + 1, "Error!Not Hex String", clean)
                if not clean.endswith(",") and content[l + 1].find(b'},')==-1:
                   print("Line:", l + 1, "Error!Missing dot:",clean)

            elif clean.find("S(") != -1:
                d = re.findall('S\(\"(.*?)"', clean)
                if len(d)==0:
                    print(Color.red(concat("Line:", l + 1, "Error!Wrong format:", clean)))
                if (not clean.endswith(",") and len(content[l + 1].strip())==0):
                    continue
                if (not clean.endswith(",") and content[l + 1].find(b'},')==-1):
                    print(Color.red(concat("Line:", l + 1, "Error!Missing dot:", clean)))
            elif clean.find("P(") != -1:
                d = re.findall('P\(\"(.*?)"',clean)
                if len(d)>0:
                    p = d[0]
                    if p not in props:
                        print(Color.red(concat("Line:", l + 1, "Error!prop not in database:", p)))
                else:
                    print("Line:", l + 1, "Error!Wrong format:", clean)
                if not clean.endswith(",") and content[l + 1].find(b'},')==-1:
                    print(Color.red(concat("Line:", l + 1, "Error!Missing dot:", clean)))
            elif clean.find("}") != -1:
                if not clean.endswith(","):
                    print(Color.red(concat("Line:", l + 1, "Error!Missing dot:", clean)))
            else:
                if recoding == True:
                    print(Color.red(concat("Line:", l + 1, "Nosense:", clean)))
if len(sys.argv)<2:
    print("arg error")
    exit(0)
if len(property)==0:
    print("no property file path!")

props=initProperty()
if os.path.isfile(sys.argv[1]):
    os.chdir(sys.argv[1])
    files = os.listdir('.')
    for f in files:
        if os.path.isfile(f):
            print("checking %s"%(f))
else:
    check_error(sys.argv[1])