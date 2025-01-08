import os
## Gets the operating system name (e.g., 'posix', 'nt' for Windows).
os_name = os.name 
if(os_name == "nt"):
    os_name = "Windows"
##Gets the current working directory.
current_dir = os.getcwd()  

print("Operating system: ", os_name, "\n", "Current dir:", current_dir)