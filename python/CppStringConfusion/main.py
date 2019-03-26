#!/usr/bin/python
# -*- coding: UTF-8 -*-
import  random,string,argparse

def     randName(size=5):
        symbol=string.ascii_letters
        result=""
        for i in range(size):
            result+=symbol[random.randint(0,100)%52]
        return result
def     main():
        parser = argparse.ArgumentParser()
        parser.add_argument("-s", "--string", help="plain string")
        parser.add_argument("--file",help="plain file --file=\"filename\"")
        parser.add_argument("--o",help="write result to file -o filename")
        args = parser.parse_args()
        if args.string:
            s = args.string.encode("gbk")
        if args.file:
            with open(args.file,"r") as fr:
                s=fr.read().encode('gbk')
        size = len(s)
        cipher = []
        if size>100:
            t=0
            for i in range(size):
                t=s[i]
                t-=(i+1)%26
                cipher.append(t)
                cppStr = "char szLabel[%d]={%s};" % (size + 2, str(cipher).replace("[", "").replace("]", ""))
                indexName=randName()
                tempName = randName()
                resultCode = '''
                unsigned int %s,%s;
                for ( %s= 0, %s = 0; %s < %d; %s++)
                {
                    %s = szLabel[%s];
                    %s += (%s+1)%%26;
                    szLabel[%s] = %s;
                }
                szLabel[%s++]=0;
                szLabel[%s]=0;
                printf(szLabel);
                '''%(indexName,tempName,indexName,tempName,indexName,size,indexName,tempName,indexName,tempName,indexName,indexName,tempName,indexName,indexName)

        else:
            key = []
            for i in range(size):
                key.append(random.randint(10,150))
                cipher.append(key[i]^(s[i]))
            keyName = randName()
            indexName = randName()
            cppKey="unsigned char %s[%d]={%s};"%(keyName,size,str(key).replace("[","").replace("]",""))
            #print(cppKey)
            cppStr="char szLabel[%d]={%s};"%(size+2,str(cipher).replace("[","").replace("]",""))
            cppStr=cppStr+"\n"+cppKey+"\n"
            resultCode='''
            int %s;
            for(%s=0; %s<%d; %s++){
                szLabel[%s]^= %s[%s];
            }
            szLabel[%s++]=0;
            szLabel[%s]=0;
            printf(szLabel);
            '''%(indexName,indexName,indexName,size,indexName,indexName,keyName,indexName,indexName,indexName)
            #print(randName())
        if args.o:
            with open(args.o,"w+") as f:
                f.write(cppStr+"\n")
                f.write(resultCode)
        else:
            print(cppStr)
            print(resultCode)
if      __name__=="__main__":
        main()