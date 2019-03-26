##使用方法
python main.py -s="teststring"
output: 

char szLabel[12]={17, 32, 253, 74, 106, 59, 84, 235, 230, 46}; 

unsigned char MvMxI[10]={101, 69, 142, 62, 25, 79, 38, 130, 136, 73}; 

int Jrtuw; 

for(Jrtuw=0; Jrtuw<10; Jrtuw++){ 

    szLabel[Jrtuw]^= MvMxI[Jrtuw]; 
    
} 

szLabel[Jrtuw++]=0; 

szLabel[Jrtuw]=0; 

printf(szLabel); 
