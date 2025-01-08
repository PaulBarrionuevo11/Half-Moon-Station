import cv2
import os

def take_photo():
    # Open the webcam
    capture = cv2.VideoCapture(0)
    ret, frame = capture.read()

    if ret:  # Check if the frame was captured successfully
        # Define the save path
        save_path = 'capeStation/images/webcamphoto.jpg'
        os.makedirs(os.path.dirname(save_path), exist_ok=True)  # Create the directory if it doesn't exist
        
        # Save the image
        cv2.imwrite(save_path, frame)
        print(f"Photo saved to {save_path}")
    else:
        print("Failed to capture photo.")

    # Release the webcam
    capture.release()
