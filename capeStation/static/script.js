function alertMessage() 
{
    alert('Hello from Flask Front-End!');
}

function videoRoute()
{
    window.location.href = '/video/'; 
}

function aboutRoute()
{
    window.location.href = '/about'; 
}

function startVideo() {
    const videoFeed = document.getElementById('videoFeed');

    // Set the video feed source to the Flask route
    videoFeed.src = '/video_feed';
    videoFeed.autoplay = true;
}

function startVideo() {
    // Open a new popup window for the video feed
    const popup = window.open("", "VideoStream", "width=800,height=600");
    if (popup) {
        popup.document.write(`
            <html>
            <body>
                <h1>Video Stream</h1>
                <img id="videoFeed" src="/video_feed" style="width:100%;border:1px solid black;" />
            </body>
            </html>
        `);

        // Automatically close the popup when the user clicks the X button
        popup.onbeforeunload = () => {
            console.log("Popup closed");
        };
    } else {
        alert("Popup blocked. Please allow popups for this site.");
    }
}

function takePhoto()
{
    window.location.href = '/take_photo';
}