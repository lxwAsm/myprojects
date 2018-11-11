
# 使用的皮肤库Skinsharp
```
CFile	f(filepath,CFile::modeRead);  
CString		newfile = filepath;  
newfile+=_T(".enc");  
CFile	fenc(newfile, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);  
if(!fenc || !f)  
{  
	MessageBox(_T("open file failed"));//检测  
	return;  
}  
int	size = f.GetLength();  
char	*buffer = new char[size];  
f.Read(buffer,size);  
for (int i = 0; i < size;i++)  
{
	buffer[i] ^= key[(i++) % size];  
}  
fenc.Write(buffer, size);  
f.Close();  
fenc.Close();  
MessageBox(newfile+_T(" encryption success!"));  
	
```  
![Alt text](https://raw.githubusercontent.com/lxwAsm/myprojects/master/2.png)
