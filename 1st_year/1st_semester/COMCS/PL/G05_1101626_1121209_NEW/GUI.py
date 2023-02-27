#####################################
#       ISEP * MESCC * COMCS        #
#                                   #
#  Group 5                          #
#    -> Carlos Rijo - 1101626       #
#    -> Eduardo Maia - 1121209      #
#                                   #
#####################################

# Import Libraries
import tkinter as tk
from tkinter import ttk
from tkinter.messagebox import showinfo
from subprocess import check_output
from datetime import datetime
import ttkthemes as tkT
import subprocess

# Define Client Script file name
FILE_NAME = "tcp_client"

# Create a Window (Tkinter variable)
windowF = tkT.ThemedTk()

# Create a window frame
windowF.title("COMCS Group 5 GUI")  # Window Title
windowF.geometry('270x300') # Window Size
windowF.resizable(width=False, height=False) # Block Resize

# Define Variables to interact with widgets
ipAddr = tk.StringVar()
port = tk.StringVar()
msg_rate = tk.StringVar()

def validate_ip(ip_addr):
    """ 
        Method to Validate IPv4 address
        Input:  IP String
        Return: True/False
    """
    ip_string = ip_addr.split('.')
    if len(ip_string) != 4:
        return False
    for x in ip_string:
        if not x.isdigit():
            return False
        i = int(x)
        if i < 0 or i > 255:
            return False
    return True

def checkCOM():
    """ 
        Method to Check if the ip address and port are valid
        Input:  None
        Return: None
    """
    if not ipAddr.get():   # IP address field empty
        tk.messagebox.showinfo(
            title='Error',
            message='IP Address field empty')
        
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': Error field empty!')
        return False

    elif not port.get():   # Port Number field empty
        tk.messagebox.showinfo(
            title='Error',
            message='Port Number field empty')
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': Error field empty!')
        return False

    elif port.get() and not port.get().isdigit(): # Wrong Port Number format
        tk.messagebox.showinfo(
            title='Error',
            message='Wrong Port Number format')
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': Error wrong format!')
        return False

    elif validate_ip(ipAddr.get()) is True and port.get().isdigit(): # IP and Port are OK
        command = "check"
        cmd = subprocess.Popen("./{} {} {} {}".format(FILE_NAME, ipAddr.get(), port.get(), command), stdout=subprocess.PIPE, shell=True)
        (cmd_output, err) = cmd.communicate()   # Get stdout
        cmd_status = cmd.wait() # Get stderr

        if cmd_status == 0: 
            comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': COM OK')
            return True
        elif cmd_status == 127:
            comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': No file found')
            return False
        elif cmd_status == 1:
            comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': No COM Established')
            return False

    else:
        tk.messagebox.showinfo(
            title='Error',
            message='Wrong IP Address format')
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': Error wrong format!')
        return False

def getVal():
    """ 
        Method to ask for the temperature value
        Input:  None
        Return: None
    """
    
    if checkCOM() is True:
        command = "get"
        resp = subprocess.Popen("./{} {} {} {}".format(FILE_NAME, ipAddr.get(), port.get(), command), stdout=subprocess.PIPE, shell=True)
        (cmd_output, err) = resp.communicate()
        cmd_status = resp.wait()
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': COM Established')
        
        if cmd_output.decode("utf-8") == '':
            temperatureVal.configure(text= 'No Value')
        else:
            temperatureVal.configure(text= cmd_output.decode("utf-8") + ' C')
    else:
        pass

def setVal():
    """ 
        Method to set a new data acquisition rate
        Input:  None
        Return: None
    """
    if msg_rate.get().isdigit() and int(msg_rate.get()) > 0:
        if checkCOM() is True:
            command = "set"
            resp = subprocess.Popen("./{} {} {} {} {}".format(FILE_NAME, ipAddr.get(), port.get(), command, msg_rate.get()), stdout=subprocess.PIPE, shell=True)
            (cmd_output, err) = resp.communicate()
            cmd_status = resp.wait()
            comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': COM Established')
        elif checkCOM() is False:
            pass
    else:
        tk.messagebox.showinfo(
            title='Error',
            message='Data Rate must be a number and bigger than zero')
        comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ': Error wrong format!')



# Create Label Frames
ip_frame = ttk.LabelFrame(
    windowF,
    text='IP Address and Port Configuration'
)
ip_frame.grid(
    column=0,
    row=0,
    padx=10,
    pady=10,
    columnspan=3,
    ipadx=5,
    ipady=5,
    sticky="NSEW")

get_frame = ttk.LabelFrame(
    windowF,
    text='Get Temperature Data'
)
get_frame.grid(
    column=0,
    row=1,
    padx=10,
    pady=10,
    columnspan=3,
    ipadx=5,
    ipady=5,
    sticky="NSEW")

set_frame = ttk.LabelFrame(
    windowF,
    text='Set Data Acquisition Rate'
)
set_frame.grid(
    column=0,
    row=2,
    padx=10,
    pady=10,
    columnspan=3,
    ipadx=5,
    ipady=5,
    sticky="NSEW")

# IP & PORT Widgets
labelPORT = ttk.Label(
    ip_frame,
    text="IPV4 Address:",
    font=("TkDefaultFont", 10))
labelPORT.grid(column=0, row=0, padx=5)

ip_entry = ttk.Entry(
    ip_frame,
    justify="center",
    textvariable=ipAddr,
    width=15,
)
ip_entry.grid(column=1, row=0, padx=5, columnspan=2)

ip_label = ttk.Label(
    ip_frame,
    text="Port Number:",
    font=("TkDefaultFont", 10)
)
ip_label.grid(column=0, row=1, padx=5)

port_entry = ttk.Entry(
    ip_frame,
    justify="center",
    textvariable=port,
    width=15
)
port_entry.grid(column=1, row=1, padx=5)

# Get Values Widgets
getButton = ttk.Button(
    get_frame,
    text="Get",
    command=getVal,
    width=10
)
getButton.grid(column=0, row=0, padx=5)

temperatureVal = ttk.Label(
    get_frame,
    anchor="center",
    relief=tk.SUNKEN,
    width=15
)
temperatureVal.grid(column=1, row=0, padx=5)
temperatureVal.configure(text='None')  # Initial Value

# Set data rate Widgets
setButton = ttk.Button(
    set_frame,
    text="Set",
    command=setVal,
    width=10
)
setButton.grid(column=0, row=0, padx=5)

rate_entry = ttk.Entry(
    set_frame,
    justify="center",
    textvariable=msg_rate,
    width=15
)
rate_entry.grid(column=1, row=0, padx=5)

# COM Status Widgets
emptyLabel = ttk.Label(
    windowF,
    text="",
    width=30
)
emptyLabel.grid(column=0, row=3, padx=5, columnspan=3)

comLabel = ttk.Label(
    windowF,
    width=30
)
comLabel.grid(column=0, row=4, padx=5, columnspan=3)
comLabel.configure(text = '[' + datetime.now().strftime("%H:%M:%S") + ']' + ':   Begin')

#######################
# Loop for GUI
windowF.mainloop()
