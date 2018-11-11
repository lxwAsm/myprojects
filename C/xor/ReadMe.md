========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : skin2
========================================================================

This file contains a summary of what you will find in each of the files that
make up your skin2 application.

skin2.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

skin2.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CSkin2App application class.

skin2.cpp
    This is the main application source file that contains the application
    class CSkin2App.

skin2.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

skin2.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\skin2.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file skin2.rc.

res\skin2.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.


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
![show](https://raw.githubusercontent.com/lxwAsm/myprojects/master/C/xor/3WXFBLJRD5IEZZ(%60FHB%6014S.png)
