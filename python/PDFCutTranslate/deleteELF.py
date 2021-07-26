#!/usr/bin/python
import pyperclip
import re

''' READ ME
    Automatically splice and wrap PDF text, and output the result to the pasteboard.
    It is convenient for translation and use md format on articles.
'''

'''
TESTSTRING = """
    sfdsa AAAAB3NzaCLkc3M
    
    gadsgadsg AAAB3NzaCl / Ezfl
    
    dogjasdpgpds AAAB3Nza / ClBAm + 4lj
"""
'''

def main():
    string = pyperclip.paste() # Read a string from the clipboard
    # Read string from file : need 4 indentation
    #    with open("PDFSTRING.txt", encoding='UTF-8') as text_file:
    #        string = text_file.read()

    #Failed : How to replace variables which Last string on each line
    '''
    lastwords = re.findall(r'\s*([\S]+)$', TESTSTRING, re.MULTILINE) #For last word add "Space"
    print (lastwords)

    for i in lastwords :
        stringLast = TESTSTRING.replace('$lastwords[i]', '$lastwords[i]+object')
    print(stringLast)
    '''

    stringLast = string.replace('    ', '')
    stringLast = stringLast.replace('\n', '').replace('\r', ' ')
    stringLast = stringLast.replace('. ', '.\r\n\r\n')
    stringLast = stringLast.replace('•', '\r\n- ')
    print (stringLast)
    pyperclip.copy(stringLast)


if __name__ == "__main__":
    main()