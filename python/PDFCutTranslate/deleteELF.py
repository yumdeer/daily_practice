import pyperclip

''' READ ME
    Automatically splice and wrap PDF text, and output the result to the pasteboard.
    It is convenient for translation.
'''

def main():
    string = pyperclip.paste() # Read a string from the clipboard
    # Read string from file
    #    with open("PDFSTRING.txt", encoding='UTF-8') as text_file:
    #        string = text_file.read()
    #
    stringLast = string.replace('    ', '')
    stringLast = stringLast.replace('\n', '').replace('\r', '')
    stringLast = stringLast.replace('. ', '\r\n.\r\n')
    print (stringLast)
    pyperclip.copy(stringLast)

if __name__ == "__main__":
    main()