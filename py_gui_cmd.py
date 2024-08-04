import tkinter
import subprocess
from tkinter.font import Font
import time

window = tkinter.Tk()
window.title('video')
window.geometry('300x50+50+50')
font = Font(family="微软雅黑", size=10, weight="bold")
url = tkinter.StringVar()

def download():
    start_time = time.time()
    command = r'C: && cd C:\Users\chenrongbin\OneDrive\Applications\Listary && test '
    subprocess.run(command, shell=True)
    print(time.time() - start_time)

def clear():
    entry_frame.delete(0,'end')

def toggle_stay_on_top():
    if window.attributes('-topmost'):
        window.attributes('-topmost', False)
        stay_on_top_button.config(text='置顶')
    else:
        window.attributes('-topmost', True)
        stay_on_top_button.config(text='取消置顶')

url_frame = tkinter.Label(text='url: ', font=font)
url_frame.grid(row=0,column=0)

clear_button = tkinter.Button(text='clear', font=font,command=clear)
clear_button.grid(row=0,column=1)

entry_frame = tkinter.Entry(window,textvariable=url)
entry_frame.grid(row=0,column=2)

download_button = tkinter.Button(text='download', font=font,command=download)
download_button.grid(row=0,column=3)

stay_on_top_button = tkinter.Button(text='置顶', font=font, command=toggle_stay_on_top)
stay_on_top_button.grid(row=0, column=4)

window.mainloop()
