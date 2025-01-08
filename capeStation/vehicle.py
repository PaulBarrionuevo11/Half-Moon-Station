import cv2
import os

class Vehicle:

    # Initializing parameters
    def __init__(self):
        pass
    # Get operating system
    def get_os():
        os_name = os.name
        if(os_name == "nt"):
            os_name = "Windows" 
        if (os_name != "nt"):
            os_name = "Other"
        return "Operating System:" + os_name
    # Get current working directory
    def get_path_dir():
        current_dir = os.getcwd()
        return "Current directory: " + current_dir
