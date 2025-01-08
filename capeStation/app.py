from flask import Flask, jsonify, request, Response, render_template
import cv2
from videoStream import generate_frames
from takePhoto import take_photo

app = Flask(__name__)
            
@app.route('/')
def home():
    return render_template("home.html")

# Extra features
@app.route('/home')
def projects():
    return render_template("home.html")

@app.route('/video/')
def video():
    return render_template("video.html")

@app.route('/video_feed')
def videoFeed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/take_photo')
def takePhoto():
    return Response(take_photo(), mimetype='multipart/x-mixed-replace; boundary=frame')

@app.route('/about')
def about():
    return render_template("about.html")

if __name__ == '__main__':
    app.run(debug=True)

