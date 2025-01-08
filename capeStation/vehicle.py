import cv2
import os

class Vehicle:

    # Initializing parameters
    def __init__(self):
        self.webCam = cv2.VideoCapture(0)      # Initialize webcam
        self.externalCam = cv2.VideoCapture(1) # Initialize external cam        #self.operatingSystem = operatingSystem
        #self.pathDir = pathDir

    ## VEHICLE INFORMATION | DATA
    # 1) Get operating system
    def get_os(self):
        os_name = os.name
        print("Operating system: ", os_name)

        if(os_name == "nt"):
            os_name = "Windows" 
        else:
            os_name = "Other"

        print("Operating system: ", os_name)
        return "Operating System: " + os_name
    # 2) Get current working directory
    def get_path_dir(self):
        current_dir = os.getcwd()
        print("Current dir:", current_dir)
        return "Current directory: " + current_dir
    ## DISPLAY VIDEO CAMERA
    webCam = cv2.VideoCapture(0)
    externalCam = cv2.VideoCapture(1)

    def generate_frames1(self):
        while True:
            ret, frame = self.webCam.read()
            if not ret:
                break
            else:
                # Encode the frame as JPEG
                _, buffer = cv2.imencode('.jpg', frame)
                frame = buffer.tobytes()
                yield (b'--frame\r\n'
                    b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')
                                # Encode the frame as JPEG

    def generate_frames2(self):
        while True:
            ret, frame2= self.externalCam.read()
            if not ret:
                break
            else:
                # Encode the frame as JPEG
                _, buffer2 = cv2.imencode('.jpg', frame2)
                frame2 = buffer2.tobytes()
                yield (b'--frame\r\n'
                    b'Content-Type: image/jpeg\r\n\r\n' + frame2 + b'\r\n')